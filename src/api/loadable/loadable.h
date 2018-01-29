

#ifndef LOADABLE_H
#define LOADABLE_H

#include "loader_respondable.h"
#include "loader_gettable.h"

namespace ARK
{
namespace API
{

/*  ==========================  */
/*  PUBLIC: ARK::API::Loadable  */
class Loadable : public Loader::Gettable, virtual ARK::Utilities::Network::Connectable
{
	public:
/*  ==========================================================================  */
		/*  /api/loader/status  */
		ARK::API::Loader::Respondable::Status loaderStatus()
		{
						return ARK::API::Loader::Gettable::status(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/loader/status/sync  */
		ARK::API::Loader::Respondable::Sync loaderSync()
		{
						return ARK::API::Loader::Gettable::sync(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/loader/autoconfigure  */
		ARK::Network loaderAutoconfigure()
		{
						return ARK::API::Loader::Gettable::autoconfigure(this->netConnector);
		};
/*  ==========================================================================  */
};
/*  ==========================  */
/*  ==========================================================================  */

};
};

#endif
