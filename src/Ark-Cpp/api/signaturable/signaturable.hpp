

#ifndef SIGNATURABLE_HPP
#define SIGNATURABLE_HPP

#include "signature_gettable.hpp"

namespace ARK
{
namespace API
{
/*************************************************
* 	PUBLIC: ARK::API::Signaturable
*   	public Signature::Gettable
*   	virtual ARK::Utilities::Network::Connectable
*    
*		API's Signature Loader Model
**************************************************/
class Signaturable : public Signature::Gettable,
										 virtual ARK::Utilities::Network::Connectable
{
public:
	/*************************************************
	*		/api/signatures/fee
	*		@return:	Balance
	*   @method:	signaturesFee()
	*   calls:	ARK::API::Signature::Gettable::fee(this->netConnector)
	*
	*   @brief:	Gets cost of Signature from a Node via API.
	**************************************************/
	Balance signaturesFee()
	{
		return ARK::API::Signature::Gettable::fee(this->netConnector);
	};
	/*************************************************/
};

// namespace signature_cb {
//   struct addSignatureResponse : virtual ARK::API::Helpers::Successable {};
// };
};
};

#endif
