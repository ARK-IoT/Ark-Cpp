

#ifndef LOADABLE_HPP
#define LOADABLE_HPP

#include "loader_respondable.hpp"
#include "loader_gettable.hpp"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Loadable
*   	public Loader::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Network Loader Model
**************************************************/
class Loadable : public Loader::Gettable,
								 virtual ARK::Utilities::Network::Connectable
{
public:
	/*************************************************
	*		/api/loader/status
	*		@returnType:	ARK::API::Loader::Respondable::Status
	*   @method:	loaderStatus()
	*   @outs:	ARK::API::Loader::Gettable::status(this->netConnector)
	*
	*   @brief:	Gets Ark Network Status from a Node via API.
	**************************************************/
	ARK::API::Loader::Respondable::Status loaderStatus()
	{
		return ARK::API::Loader::Gettable::status(this->netConnector);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*		/api/loader/status/sync
	*		@return:	ARK::API::Loader::Respondable::Sync
	*   @method:	loaderSync()
	*   @outs:	ARK::API::Loader::Gettable::sync(this->netConnector)
	*
	*   @brief:
	*			Gets Ark Network Sync Status from a Node via API. 
	**************************************************/
	ARK::API::Loader::Respondable::Sync loaderSync()
	{
		return ARK::API::Loader::Gettable::sync(this->netConnector);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	*		/api/loader/autoconfigure 
	*		@return:	ARK::Network
	*   @method:	loaderAutoconfigure()
	*   @outs:	ARK::API::Loader::Gettable::autoconfigure(this->netConnector)
	*
	*   @brief:
	*			Returns an auto-configured network
	*			from a Networks NetHash from a Node via API. 
	**************************************************/
	ARK::Network loaderAutoconfigure()
	{
		return ARK::API::Loader::Gettable::autoconfigure(this->netConnector);
	};
	/*************************************************/
};
/*************************************************/
};
};

#endif
