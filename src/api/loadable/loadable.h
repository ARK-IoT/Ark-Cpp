

#ifndef LOADABLE_H
#define LOADABLE_H

#include "api/loadable/loader_respondable.h"
#include "api/loadable/loader_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
*	PUBLIC: ARK::API::Loadable
*	public Loader::Gettable
*	virtual ARK::Utilities::Network::Connectable
*    
*	API's Network Loader Model
**************************************************/
class Loadable :
		public Loader::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		*	/api/loader/autoconfigure 
		*
		*	@return:	ARK::Network
		*
		*	@brief:	Returns an auto-configured network from a Networks NetHash from a Node via API. 
		**************************************************/
		ARK::Network loaderAutoconfigure()
		{
			return ARK::API::Loader::Gettable::autoconfigure(this->netConnector);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/loader/status
		*
		*	@return:	ARK::API::Loader::Respondable::Status
		*
		*	@brief:	Gets Ark Network Status from a Node via API.
		**************************************************/
		ARK::API::Loader::Respondable::Status loaderStatus()
		{
			return ARK::API::Loader::Gettable::status(this->netConnector);
		};
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/loader/status/sync
		*
		*	@return:	ARK::API::Loader::Respondable::Sync
		*
		*	@brief:	Gets Ark Network Sync Status from a Node via API. 
		**************************************************/
		ARK::API::Loader::Respondable::Sync loaderSync()
		{
			return ARK::API::Loader::Gettable::sync(this->netConnector);
		};
		/*************************************************/
		
};
/*************************************************/

};
};

#endif
