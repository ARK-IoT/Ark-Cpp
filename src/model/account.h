

#ifndef ACCOUNT_H
#define ACCOUNT_H

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
*   ARK::account_t
**************************************************/
struct account_t
{

public:
    Address address;
    Balance unconfirmedBalance;
    Balance balance;
    Publickey publicKey;
    int unconfirmedSignature;
    int secondSignature;
    Publickey secondPublicKey;
    Signature multisignatures;
    Signature u_multisignatures;
};
/*************************************************/


/*************************************************
*   ARK::Account
**************************************************/
struct Account :
		public account_t
{
	public:

		Account(
			const char* const newAddress,
			const char* const newUnconfirmedBalance,
			const char* const newBalance,
			const char* const newPublickey,
			int newUnconfirmedSignature,
			int newSecondSignature,
			const char* const newSecondPublickey,
			const char* const newMultisignatures,
			const char* const newU_Multisignatures
		)
		{
			address = Address(newAddress);
			unconfirmedBalance = Balance(newUnconfirmedBalance);
			balance = Balance(newBalance);
			publicKey = Publickey(newPublickey);
			unconfirmedSignature = newUnconfirmedSignature;
			secondSignature = newSecondSignature;
			secondPublicKey = Publickey(newSecondPublickey);
			multisignatures = Signature(newMultisignatures);
			u_multisignatures = Signature(newU_Multisignatures);
		}


    void printTo(HardwareSerial &serial);
};
/*************************************************/


};

/*************************************************
*   printTo(Serial)
**************************************************/
void ARK::Account::Account::printTo(HardwareSerial &serial)
{
    serial.print("address: ");
    serial.print(address.getValue());
    serial.print("\nunconfirmedBalance: ");
    serial.print(this->unconfirmedBalance.ark());
    serial.print("\nbalance: ");
    serial.print(this->balance.ark());
    serial.print("\npublicKey: ");
    serial.print(this->publicKey.getValue());
    serial.print("\nunconfirmedSignature: ");
    serial.print(this->unconfirmedSignature);
    serial.print("\nsecondSignature: ");
    serial.print(this->secondSignature);
    serial.print("\nsecondPublicKey: ");
    serial.print(this->secondPublicKey.getValue());
    serial.print("\nmultisignatures: ");
    serial.print(this->multisignatures.getValue());
    serial.print("\nu_multisignatures: ");
    serial.print(this->u_multisignatures.getValue());
    serial.println();
    serial.flush();
}
/*************************************************/

#endif
