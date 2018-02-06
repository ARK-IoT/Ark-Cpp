

#ifndef DELEGATABLE_H
#define DELEGATABLE_H

#include "delegate_respondable.h"
#include "delegate_gettable.h"

namespace ARK
{
namespace API
{

/*  ==========================================================================  */
/*  =============================  */
/*  PUBLIC: ARK::API::Delegatable  */
class Delegatable :
		public Delegate::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
	public:
/*  ==========================================================================  */
		/*  /api/delegates/count  */
		int delegatesCount()
		{
			return ARK::API::Delegate::Gettable::count(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/delegates/search?q=sleepdeficit  */
		ARK::API::Delegate::Respondable::Search delegateSearch(const char* const _username)
		{
			return ARK::API::Delegate::Gettable::search(this->netConnector, _username);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/delegates/voters?publicKey=_pubKey  */
		ARK::API::Delegate::Respondable::Voters delegateVoters(const Publickey& _publicKey)
		{
			return ARK::API::Delegate::Gettable::voters(this->netConnector, _publicKey);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/* 
			/api/delegates/get?username=sleepdeficit
			/api/delegates/get?publicKey=_pubKey
		*/
		ARK::Delegate delegate(const char* const _parameter)
		{
			return ARK::API::Delegate::Gettable::delegate(this->netConnector, _parameter);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
/*  ==========================================================================  */
		/*    BROKEN: fix for large callbacks    */
		/*  Delegates callback is ~13,564 bytes  */
		/*  /api/delegates  */
		// String getDelegates()
		// { return ARK::API::DelegateGettable::delegates(this->netConnector); }; 
		// /*  =====================  */
		// /*  ARK::DelegateResponse  */
		// struct DelegatesResponse
		// {
		// public:
		// 	int count;
		// 	ARK::Delegate list[5]; // = {{}};
		// 	DelegatesResponse(int);
		// 	String description();
		// };
		// /*  =====================  */
		/*  =============  */
		/*  ARK::DelegatesResponse  */
		/*  Constructor  */
		// ARK::DelegatesResponse::DelegatesResponse(int _count)
		// {
		//         this->count = _count;
		// }
		/*  =====  */
		/*  Description  */
		// String ARK::DelegatesResponse::DelegatesResponse::description()
		// {
		//		String resp;
		//		if (this->count > 0)
		//		{
		//			for (int i = 0; i < this->count; i++)
		//			{
		//				resp += "\ndelegate ";
		//				resp += i + 1;
		//				resp += ":\n";
		//				resp += this->list[i].description();
		//				resp += "\n";
		//			};
		//		};
		//		return resp;
		// }
/*  ==========================================================================  */
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/delegates/fee  */
		Balance delegateFee()
		{
			return ARK::API::Delegate::Gettable::fee(this->netConnector);
		};
/*  ==========================================================================  */

/*  ==========================================================================  */
		/*  /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey  */
		ARK::API::Delegate::Respondable::ForgedByAccount delegateForgedByAccount(const Publickey& _generatorPublicKey)
		{
			return ARK::API::Delegate::Gettable::forgedByAccount(this->netConnector, _generatorPublicKey);
		};

		/*  ==========================================================================  */

		/*  /api/delegates/getNextForgers  */
		ARK::API::Delegate::Respondable::NextForgers delegateNextForgers()
		{
			return ARK::API::Delegate::Gettable::nextForgers(this->netConnector);
		};
/*  ==========================================================================  */
};
/*  =============================  */
/*  ==========================================================================  */

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
