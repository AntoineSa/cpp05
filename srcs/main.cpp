/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:27:02 by asablayr          #+#    #+#             */
/*   Updated: 2021/09/10 16:21:36 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#include "webserv.hpp"
#include "serverClass.hpp"
#include "ConnectionClass.hpp"

int main(int ac, char** av)
{
	std::vector<serverClass*>			server_map;
	std::vector<serverClass*> 			serv_up;
	std::map<int, ConnectionClass>		connection_map;
	std::map<int, ConnectionClass&>		input_pipe_map;
	std::map<int, ConnectionClass&>		output_pipe_map;
	fd_set								rfds, rfds_copy;
	fd_set								wfds, wfds_copy;

	if (ac == 2)//&& av[1] == *.conf
		server_map = setup_server(av[1]);
	else
		server_map = setup_server(DEFAULT_CONF_FILE);

	FD_ZERO(&rfds);//memset fd_set
	FD_ZERO(&wfds);//memset fd_set
	for (std::vector<serverClass*>::iterator it = server_map.begin(); it != server_map.end(); it++)
	{
		try 
		{
			(*it)->startServer();
			std::cout << "server started on : " << (*it)->_listen << std::endl;
			serv_up.push_back(*it);
			FD_SET((*it)->_server_socket, &rfds);//add server socket to fd_set
		}
		catch (char const*)
		{
			for (std::vector<serverClass*>::iterator i = serv_up.begin(); i != serv_up.end(); i++)
			{
				if ((*it)->_port == (*i)->_port)
				{
					(*it)->_server_socket = (*i)->_server_socket;
					break ;
				}
			}
		}
	}
	if (serv_up.empty())
	{
		for (std::vector<serverClass*>::iterator i = server_map.begin(); i != server_map.end(); i++)
			delete *i;
		exit(EXIT_FAILURE);
	}
	while (true)
	{
		rfds_copy = rfds;
		wfds_copy = wfds;
		if (select(FD_SETSIZE, &rfds_copy, &wfds_copy, NULL, NULL) < 0)
		{
			std::perror("select eror");
			for (std::vector<serverClass*>::iterator i = server_map.begin(); i != server_map.end(); i++)
				delete *i;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < FD_SETSIZE; i++)
		{
			if (FD_ISSET(i, &rfds_copy))
			{
				bool check = false;
				for (std::vector<serverClass*>::iterator it = server_map.begin(); it != server_map.end(); it++)
				{
					if (i == (*it)->_server_socket)//new connection on server n°j
					{
						int client_socket = accept(i, (*it)->_addr->ai_addr, &((*it)->_addr->ai_addrlen));
						if (client_socket < 0)
							std::perror("accept");
						else
						{
							connection_map[client_socket] = ConnectionClass(client_socket, *it);
							connection_map[client_socket].setServers(server_map, i);
							FD_SET(client_socket, &rfds);
							check = true;
						}
						break;
					}
				}
				if (check)
					continue; 
				if (output_pipe_map.count(i))
				{
					cgiReadOnPipe(output_pipe_map[i]);
					if (!output_pipe_map[i].HasToReadOnPipe())
					{
						FD_CLR(output_pipe_map[i].getOutputFd(), &rfds);
						output_pipe_map[i].setHasDoneCgi(1);
						output_pipe_map.erase(i);
					}
					continue;
				}
				if (connection_map[i].receiveRequest() <= 0) // close connection if error while receiving paquets
				{
					connection_map[i].closeConnection();
				}
				std::cout << "pipeline length of map after receive: " << connection_map[i]._request_pipeline.size() << std::endl;
				if (connection_map[i].getStatus() == CO_ISCLOSED) // erases if connection has encoutered an error
				{
					FD_CLR(i, &rfds);
					connection_map.erase(i);
				}
				else if (connection_map[i].getStatus() == CO_ISREADY) // at least one request ready to be answered
				{
					FD_CLR(i, &rfds);
					FD_SET(i, &wfds);
				}
			}
			else if (FD_ISSET(i, &wfds_copy))
			{
				if (input_pipe_map.count(i))
				{
					cgiWriteOnPipe(input_pipe_map[i]);
					FD_SET(input_pipe_map[i].getOutputFd(), &rfds);
					output_pipe_map.insert(std::pair<int, ConnectionClass&>(input_pipe_map[i].getOutputFd(), input_pipe_map[i]));
					FD_CLR(input_pipe_map[i].getInputFd(), &wfds);
					input_pipe_map.erase(i);
					continue;
				}
				std::cout << "in write loop for fd: " << i << std::endl; 
				if (!connection_map[i].HasToWriteOnPipe() && !connection_map[i].HasToReadOnPipe())
					answer_connection(connection_map[i]);
				if (connection_map[i].HasToWriteOnPipe() && !input_pipe_map.count(i))
				{
					input_pipe_map.insert(std::pair<int, ConnectionClass&>(connection_map[i].getInputFd(), connection_map[i]));
					std::cout << "pipeline length of inserted map: " << connection_map[i]._request_pipeline.size() << std::endl;
					FD_SET(connection_map[i].getInputFd(), &wfds);
					continue;
				}
				connection_map[i].setStatus(CO_ISDONE);
				if (connection_map[i].getStatus() == CO_ISCLOSED || !connection_map[i].isPersistent()) // erase if connection is not persistent or respond has encountered an error
				{
					connection_map[i].closeConnection();
					FD_CLR(i, &wfds);
					connection_map.erase(i);
				}
				else if (connection_map[i].getStatus() == CO_ISDONE) // all requests have been answered
				{
					FD_CLR(i, &wfds);
					FD_SET(i, &rfds);
				}
			}
		}
/*		for (std::map<int, ConnectionClass>::iterator i = connection_map.begin(); i != connection_map.end(); i ++)// TODO unit test
		{
			if (!i->second.isPersistent())
				continue;
			if (time(0) - i->second.getTimer() > i->second._server->getKeepAliveTimeout())// TODO switch from sec to ms
			{
				if (FD_ISSET(i->first, &rfds))
				{
					connection_map[i->first].closeConnection();
					FD_CLR(i->first, &rfds);
				}
				else if (FD_ISSET(i->first, &wfds))
				{
					connection_map[i->first].closeConnection();
					FD_CLR(i->first, &wfds);
				}
			}
		}
*/	}
}
