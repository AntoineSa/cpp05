/*	This class is used to handle the socket-level part of individual connections. For now 
	it only reads and assemble requests, write responses and closes 
	connections. In the future, it could alson be used to store information 
	about connection status, addresses, timestamps or logs recording
	activity (if it happens to be useful)

	How to use it, schematically:


	// we create a map that centralizes all the individual connections,
	// the key is the socket fd, the mapped type is the connection object

	std::map<int, ConnectionClass>	connection_map;

	** we are now inside the main loop **

	// a new client arrives and gives me a fd:
	s2 = accept(bla bla bla); 

	// I initialize the connection object with the socket fd and insert it in the map:
	connection_map.insert(std::pair<int, ConnectionClass>(s2, ConnectionClass(s2)));

	** some code happens, and suddenly, we have some data to read on our fd, and 
	** we want to handle the connection:                                         

	// I send the right connection object to the connection handle:
	handle_connection(connection_map[fd]);

*/



#ifndef CONNECTIONCLASS_H
# define CONNECTIONCLASS_H

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <utility>
#include "HttpMessage.hpp"
#include "HttpRequest.hpp"
#include "serverClass.hpp"
#include <vector>

#define	READING_BUF_SIZE 32 //ces tailles sont très petites
#define	SINGLE_READ_SIZE 8	// pour voir plus facilement les bugs
#define	MAX_LINE_LENGTH 12000	// POUR SECURITY
#define	MAX_HEAD_LINES 100	// POUR SECURITY
#define	MAX_URI_SIZE 1000 // POUR SECURITY
#define CO_ISOPEN 1
#define CO_ISCLOSED 2

/*
Ce buffer/structure sert à lire et concaténer les données reçues dans le 
socket. c'est un buffer circulaire (je crois), du coup ça 
limite les appels a malloc, memset et compagnie. 
*/
struct readingBuffer
{
	char			buf[READING_BUF_SIZE + 1];
	/* 	IMPORTANT: deb corresponds to the index of the first character of the relevant
	***	buffer part (usually beginnin of the current line), however end corresponds to the
	***	index of the character AFTER the last character read.  */
	int				deb;
	int				end;
	static int const		cap = READING_BUF_SIZE;
};

class ConnectionClass {

public:
	ConnectionClass(ConnectionClass const& to_copy);

	/* only useful constructor: initializes with socket fd */
	ConnectionClass(int socknum, serverClass* server);


	~ConnectionClass(void);

	ConnectionClass&	operator=(ConnectionClass const& to_copy);

	/* main function, reads on the socket and returns a pair containing:
		- return value of the last "recv" call (to see if it failed or if the connection was closed)
		- std::string containing the request*/
//	std::pair<int, std::string>			receiveRequest(void);
	int						receiveRequest(std::vector<HttpRequest>& requestPipeline);

	int				sendResponse(std::string response);
	int				closeConnection(void);
	int				_socketNbr;
	serverClass*	_server;
	int				getStatus();

	// this constructor should be private, but it doesn't work for now when it is.
	//need to fix, probably an unwanted copy at some point.
	ConnectionClass(void); 


private:
	typedef struct readingBuffer readingBuffer;

//	readingBuffer			_buffer;

	/* connection status, we'll see if we really need it */
	int				_status;
	bool				_isPersistent;

	int		_read_long_line(std::string& str, readingBuffer& buffer, int& length_parsed);
	int		_read_buffer(readingBuffer& buffer, std::vector<HttpRequest>& requestPipeline);
	int		_read_line(readingBuffer& buffer, int& length_parsed, int& line_count, HttpRequest& currentRequest);
	int		_get_next_request(readingBuffer &buffer, HttpRequest& currentRequest, int& length_parsed);
	void		_initializeBuffer(readingBuffer& buffer);
	int		_read_first_line(readingBuffer& buffer, int& length_parsed, HttpRequest& currentRequest);
	int		_parse_line(const char *line, int len, int& line_count, HttpRequest& currentRequest);
	int		_parse_first_line(const char *line, int len, HttpRequest& currentRequest);
	int		_check_header_compliancy(HttpRequest& CurrentRequest);
	int		_parseProtocol(HttpRequest& currentRequest, std::string& protocol);
	int		_read_request_content(HttpRequest& CurrentRequest, int&	length_parsed);
	void				_printBufferInfo(readingBuffer& buffer, std::string msg);
	int		_invalidRequestProcedure(HttpRequest& currentRequest, int errorCode);
	int				_findInBuf(std::string to_find,char *buf, int findlen, int buflen, int begsearch);
};

#endif
