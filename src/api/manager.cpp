

#include "api/manager.h"

namespace ARK
{
namespace API
{
/*************************************************
*	Default: Empty Constructor
**************************************************/
Manager::Manager()
{
	this->connect(ARK::Network());
};
/*************************************************/

/*************************************************
*	Constructor
**************************************************/
Manager::Manager(
		const ARK::Network& network
)
{
	this->connect(network);
};
/*************************************************/

/*************************************************
*	@brief:	private:	ARK::API::Manager::connect
**************************************************/
void Manager::connect(
		const ARK::Network& network
)
{
	this->netConnector = ARK::Utilities::Network::Connector(network);
};
/*************************************************/

};
};
