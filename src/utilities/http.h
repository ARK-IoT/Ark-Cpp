

#ifndef HTTP_H
#define HTTP_H

#include "platform.h"

//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>

namespace ARK
{
namespace Utilities
{
namespace Network
{

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
  class HTTPConnectable;
/*  ==========================================================================  */




/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::HTTP 
*   Currently using ESP8266 libs
*
* The purpose of this class is to serve as an
*   entry point for integrating the HTTPClient
*   library for different boards/chipsets
**************************************************/
  class HTTP {
    public: 
     // bool isReachable = false;

      HTTP(){};

     String get(const String& peer, int port, const String& request);
  };
/*  ==========================================================================  */


};
};
};



/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::Network::Connectable 
*   Inheritable HTTPConnectable object
**************************************************/
class ARK::Utilities::Network::HTTPConnectable
{
public:

  ARK::Utilities::Network::HTTP http;
};
/*  ==========================================================================  */

#endif
