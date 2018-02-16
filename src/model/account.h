

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
*   ARK::Account
**************************************************/
struct Account
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

    void printTo(HardwareSerial &serial);
};
/*************************************************/


};

/*************************************************
*   printTo(Serial)
**************************************************/
void ARK::Account::Account::printTo(HardwareSerial &serial)
{
    serial.print("address.value: ");
    serial.print(address.value);
    serial.print("\nunconfirmedBalance.ark: ");
    serial.print(this->unconfirmedBalance.ark());
    serial.print("\nbalance.ark: ");
    serial.print(this->balance.ark());
    serial.print("\npublicKey.value: ");
    serial.print(this->publicKey.value);
    serial.print("\nunconfirmedSignature: ");
    serial.print(this->unconfirmedSignature);
    serial.print("\nsecondSignature: ");
    serial.print(this->secondSignature);
    serial.print("\nsecondPublicKey.value: ");
    serial.print(this->secondPublicKey.value);
    serial.print("\nmultisignatures.value: ");
    serial.print(this->multisignatures.value);
    serial.print("\nu_multisignatures.value: ");
    serial.print(this->u_multisignatures.value);
    serial.println();
    serial.flush();
}
/*************************************************/

#endif
