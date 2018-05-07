#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "utilities/platform.h"
#include "bip39/bip39.h"
#include "constants/networks.h"
#include "types/address.h"
#include "types/balance.h"
#include "types/hash.h"
#include "types/publickey.h"
#include "types/signature.h"
#include <cstring>
#include <cstdio>

/********************************************************************************
*
* account: 
*    {  
*      "success":true,
*      "account":{  
*         "address":  Address,
*         "unconfirmedBalance": Balance,
*         "balance":  Balance,
*         "publicKey":  Publickey,
*         "unconfirmedSignature": int,
*         "secondSignature":  int,
*         "secondPublicKey":  Publickey,
*         "multisignatures":  [ Signature ],
*         "u_multisignatures":  [ Signature ]
*      }
*    }
*
********************************************************************************/
namespace ARK
{
/*************************************************
*   ARK::Account
**************************************************/
struct Account :
		public Printable
{
	private:
		Address		address_;
		Balance		unconfirmedBalance_;
		Balance		balance_;
		Publickey	publicKey_;
		int				unconfirmedSignature_;
		int				secondSignature_;
		Publickey	secondPublicKey_;
		// Hash			*multisignatures_;		//	FIXME
		// Hash			*u_multisignatures_;	//	FIXME

	public:
		/*************************************************
		*	Constructor
		**************************************************/
		Account(
				const char *const newAddress,
				const char *const newUnconfirmedBalance,
				const char *const newBalance,
				const char *const newPublickey,
				int 							newUnconfirmedSignature,
				int 							newSecondSignature,
				const char *const newSecondPublickey//,
				// Hash              newMultisignatures[], //	FIXME
				// Hash							newU_Multisignatures[] //	FIXME
		);
    
		Account(
			const char* const public_key,
			const char* const address
		);
		/*************************************************/

		/*************************************************
		*	Constructor
		**************************************************/
		const Address& address()							const noexcept { return address_; }
		const Balance& unconfirmed_balance()	const noexcept { return unconfirmedBalance_; }
		const Balance& balance()							const noexcept { return balance_; }
		const Publickey& public_key()					const noexcept { return publicKey_; }
		int		unconfirmed_signature()					const noexcept { return unconfirmedSignature_; }
		int		second_signature()							const noexcept { return secondSignature_; }
		const Publickey& second_public_key()	const noexcept { return secondPublicKey_; }
		// const Hash& multi_signatures()		const noexcept { return *multisignatures_; }
		// const Hash& u_multi_signatures()	const noexcept { return *u_multisignatures_; }
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/

};
/*************************************************/

/*************************************************
* Creates an account from the network id and passphrase
* Network id defaults to mainnet
* Passphrase defaults to a new randomly generated mnemonic
**************************************************/
Account make_account(
	uint8_t network = ARK::Constants::Networks::Network_ADV::main.pubKeyHash,
	const std::string& passphrase = ARK::Crypto::BIP39::generate_mnemonic()
);

}

#endif
