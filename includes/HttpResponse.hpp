/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:07:21 by asablayr          #+#    #+#             */
/*   Updated: 2021/08/02 18:13:03 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPRESPONSE_HPP
# define HTTPRESPONSE_HPP

#define HTTP_VERSION "HTTP/1.1"

#include "HttpMessage.hpp"

class HttpResponse: public HttpMessage {

public:

	HttpResponse(void);
	HttpResponse(HttpResponse const& to_copy);
	HttpResponse(unsigned short code, std::string path_to_body);
	virtual ~HttpResponse(void);

	HttpResponse&				operator = (HttpResponse const& to_copy);

	std::string					toString() const;
	void						setStatusCode(std::string const& status_str);
	void						setStatusCode(unsigned short status_str);
	void						setHeader(unsigned short code = 0);
	void						setBody(std::string const& body_path);

private:

	std::string					headerToString() const;
	std::string					bodyToString() const;
	
	std::string			_status_line;
	std::string			_http_version; //should be in httpMessage
	std::string			_status_code;
	std::string			_reason_phrase;

	std::string			_date;
	std::string			_server_name;
	std::string			_content_length;
	std::string			_content_type;
	std::string			_connection;

	int					_lineCount;
	long				_contentLength;
	std::string			_content;

};

#endif
