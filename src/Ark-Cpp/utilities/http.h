

#ifndef HTTP_H
#define HTTP_H

#include "platform.h"

<<<<<<< HEAD
#include <memory>
#include <string>

=======
>>>>>>> master
namespace ARK
{
namespace Utilities
{
namespace Network
{
<<<<<<< HEAD

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
  class HTTPConnectable;
/*  ==========================================================================  */




/*  ==========================================================================  */
/**************************************************
=======
/*************************************************
* ARK::Utilities::Network::Connectable 
*   Forward Declaration for inheritance
**************************************************/
class HTTPConnectable;
/*************************************************/

/**************************************************************************************************/

/*************************************************
>>>>>>> master
* ARK::Utilities::Network::HTTP 
*   Currently using ESP8266 libs
*
* The purpose of this class is to serve as an
*   entry point for integrating the HTTPClient
*   library for different boards/chipsets
**************************************************/
<<<<<<< HEAD
class HTTPInterface {
protected: 
    HTTPInterface() = default;

public:
    virtual String get(const String& peer, int port, const String& request) = 0;
};
/*  ==========================================================================  */

// HTTP object factory
std::unique_ptr<HTTPInterface> make_http();

}
}
}



/*  ==========================================================================  */
/**************************************************
=======
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
>>>>>>> master
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
class ARK::Utilities::Network::HTTPConnectable
{
public:
<<<<<<< HEAD
	std::unique_ptr<ARK::Utilities::Network::HTTPInterface> http;

	HTTPConnectable() : http(make_http()) { }
};
/*  ==========================================================================  */
=======
	ARK::Utilities::Network::HTTP http;
};
/*************************************************/
>>>>>>> master

#endif
