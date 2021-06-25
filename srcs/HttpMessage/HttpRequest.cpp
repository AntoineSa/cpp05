#include "HttpRequest.hpp"

HttpRequest::HttpRequest(void): HttpMessage()
{
	return;	
}

HttpRequest::HttpRequest(HttpRequest const& to_copy) : HttpMessage(to_copy)
{
	_isValid = to_copy._isValid;
	_methodLine = to_copy._methodLine;
	_method = to_copy._method;
	_methodArgument = to_copy._methodArgument;
	_requestLine = to_copy._requestLine;
	_errorCode = to_copy._errorCode;

}

HttpRequest::HttpRequest(std::string str_message) : HttpMessage(str_message)
{
	parseFromString(_stringMessage);
}

HttpRequest::~HttpRequest(void)
{
	
}



HttpRequest&	HttpRequest::operator=(HttpRequest const& to_copy)
{
	HttpMessage::operator=(to_copy)	;
//	HttpMessage::_headers = to_copy._headers;
	_isValid = to_copy._isValid;
	_methodLine = to_copy._methodLine;
	_method = to_copy._method;
	_methodArgument = to_copy._methodArgument;
	_requestLine = to_copy._requestLine;
	_errorCode = to_copy._errorCode;
	return (*this);
}

void		HttpRequest::clear(void)
{
	HttpMessage::clear();
	_isValid = 0;
	_methodLine.clear();
	_methodArgument.clear();
	_errorCode = 0;
	_requestLine.method.clear();
	_requestLine.target.clear();
	_requestLine.protocol.first = 0;
	_requestLine.protocol.second = 0;
}
/* probablement optimisable sans trop de difficulté en cas de besoin */
int				HttpRequest::parseFromString(std::string str_request)
{
	size_t pos_body = str_request.find("\r\n\r\n");
	if (pos_body == str_request.npos)
		return (-1); // cela signifie que la requete n'a pas un format conforme

	std::string head_block = str_request.substr(0, pos_body);
	std::cout << "head_block: " << std::endl << head_block << std::endl << std::endl;

	if (pos_body + 4 < str_request.length())
	{
		_body = str_request.substr(pos_body + 4);
		std::cout << "body: "<< std::endl << _body << std::endl << std::endl;
	}
	size_t		pos_runner = head_block.find("\r\n");
	_methodLine = head_block.substr(0, pos_runner);
	std::cout << "method line: " << std::endl << _methodLine << std::endl << std::endl;

	std::string	header_string = head_block.substr(pos_runner);
//	_parseHeaderBlock(header_string); // a ajouter quand module correspondant est terminé

	std::cout << "header string: " << std::endl << header_string << std::endl << std::endl;
	return (0);	
}

void				HttpRequest::addRequestLine(std::string& method, std::string& target)
{
	_requestLine.method = method;	
	_requestLine.target = target;
}

void				HttpRequest::setValidity(bool validity)
{
	_isValid = validity;
}

void				HttpRequest::setErrorCode(int errorCode)
{
	_errorCode = errorCode;
}

int const&				HttpRequest::getErrorCode() const
{
	return (_errorCode);
}

void				HttpRequest::setProtocolVersion(int bigVersion, int smallVersion)
{
	_requestLine.protocol.first = bigVersion;
	_requestLine.protocol.second = smallVersion;
}

std::string const&		HttpRequest::toString() const
{
	return (_stringMessage);
}

