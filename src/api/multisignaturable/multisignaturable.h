

#ifndef MULTISIGNATURABLE_H
#define MULTISIGNATURABLE_H

#include "api/multisignaturable/multisignature_gettable.h"

namespace ARK
{
namespace API
{
/*************************************************
*	PUBLIC: ARK::API::MultiSignaturable
*	public MultiSignature::Gettable
*	virtual ARK::Utilities::Network::Connectable
*    
*	API's Multisignature Loader Model
**************************************************/
class MultiSignaturable :
		public MultiSignature::Gettable,
		virtual ARK::Utilities::Network::Connectable
{
public:
	/*************************************************
	*	/api/multisignatures/pending?publicKey=
	*
	*	@param: const Publickey& publicKey
	*	@returnType:	const char*
	*
	*	@brief:	Gets Pending Multisignatures of	Account by Publickey from a Node via API.
	**************************************************/
	const char *multisignaturesPending(
			const Publickey &publicKey
	)
	{
		return ARK::API::MultiSignature::Gettable::pending(this->netConnector, publicKey);
	};
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************/
	/*************************************************/
	// /*  Only on Mainnet?  */
	//     /*  /api/multisignatures/accounts?publicKey=  */
	//     String multisignaturesAccounts(String _publicKey)
	//     { return ARK::API::MultiSignature::Gettable::accounts(this->netConnector, _publicKey); };
	/*************************************************/
	/*************************************************/

};

};
};

#endif
