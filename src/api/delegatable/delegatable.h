

#ifndef delegatable_h
#define delegatable_h

#include "delegate_gettable.h"

namespace ARK {
  namespace API {

    /*  =============================  */
    /*  PUBLIC: ARK::API::Delegatable  */

    class Delegatable : public DelegateGettable, virtual ARK::Utilities::Network::Managable {
      public: 

/*  ==========================================================================  */

        /*  /api/delegates/count  */
        int delegatesCount()
        { return ARK::API::DelegateGettable::count(this->netManager); };

/*  ==========================================================================  */

        /*  /api/delegates/search?q=sleepdeficit  */
        ARK::Delegate::SearchResponse delegateSearch(String _username)
        { return ARK::API::DelegateGettable::search(this->netManager, _username); };

/*  ==========================================================================  */

        /*  /api/delegates/voters?publicKey=_pubKey  */
        ARK::VotersResponse delegateVoters(Publickey _publicKey)
        { return ARK::API::DelegateGettable::voters(this->netManager, _publicKey); };

/*  ==========================================================================  */

        /* 
          /api/delegates/get?username=sleepdeficit
          /api/delegates/get?publicKey=_pubKey
        */
        ARK::Delegate delegate(String _parameter)
        { return ARK::API::DelegateGettable::delegate(this->netManager, _parameter); };

/*  ==========================================================================  */
    /*    BROKEN: fix for large callbacks    */
    /*  Delegates callback is ~13,564 bytes  */
        /*  /api/delegates  */
        // String getDelegates()
        // { return ARK::API::DelegateGettable::delegates(this->netManager); };
/*  ==========================================================================  */

        /*  /api/delegates/fee  */
        Balance delegateFee()
        { return ARK::API::DelegateGettable::fee(this->netManager); };

/*  ==========================================================================  */

        /*  /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  */
        String delegateForgedByAccount(Publickey _generatorPublicKey)
        { return ARK::API::DelegateGettable::forgedByAccount(this->netManager, _generatorPublicKey); };

/*  ==========================================================================  */

        /*  /api/delegates/getNextForgers  */
        ARK::Delegate::NextForgersResponse delegateNextForgers()
        { return ARK::API::DelegateGettable::nextForgers(this->netManager); };

/*  ==========================================================================  */

    };
    /*  =============================  */


    // namespace Delegate {
    //   namespace delegates_cb {
    //     struct addDelegateResponse : virtual ARK::API::Helpers::Successable {};
    //     struct enableForgingResponse : virtual ARK::API::Helpers::Successable {};
    //     struct disableForgingResponse : virtual ARK::API::Helpers::Successable {};
    //   };      
    // };


  };
};


#endif
