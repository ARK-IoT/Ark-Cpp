

#ifndef HTTP_H
#define HTTP_H

#include "platform.h"

namespace ARK
{
namespace Utilities
{
namespace Network
{
/*************************************************
* ARK::Utilities::Network::Connectable 
*   Forward Declaration for inheritance
**************************************************/
class HTTPConnectable;
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::Utilities::Network::HTTP 
*   Currently using ESP8266 libs
*
* The purpose of this class is to serve as an
*   entry point for integrating the HTTPClient
*   library for different boards/chipsets
**************************************************/
class HTTP
{
public:
	HTTP();

	void printConnection(const char *peer, int port);
	void printDelay(const char *request);

	const char *get(const char *const peer, int port, const char *const request);

};
/*************************************************/

};
};
};

/*************************************************
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
class ARK::Utilities::Network::HTTPConnectable
{
public:
	ARK::Utilities::Network::HTTP http;
};
/*************************************************/

#endif
