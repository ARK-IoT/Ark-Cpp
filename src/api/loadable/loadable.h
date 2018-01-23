

#ifndef loadable_h
#define loadable_h

#include "loader_gettable.h"

namespace ARK {
  namespace API {

    /*  ==========================  */
    /*  PUBLIC: ARK::API::Loadable  */
    class Loadable : public LoaderGettable, virtual ARK::Utilities::Network::Managable {
      public: 

/*  ==========================================================================  */

        /*  /api/loader/status  */
        ARK::Loader::StatusResponse loaderStatus()
        { return ARK::API::LoaderGettable::status(this->netManager); };

/*  ==========================================================================  */

        /*  /api/loader/status/sync  */
        ARK::Loader::SyncResponse loaderSync()
        { return ARK::API::LoaderGettable::sync(this->netManager); };

/*  ==========================================================================  */

        /*  /api/loader/autoconfigure  */
        ARK::Network loaderAutoconfigure()
        { return ARK::API::LoaderGettable::autoconfigure(this->netManager); };

/*  ==========================================================================  */

    };
    /*  ==========================  */


  };
};


#endif
