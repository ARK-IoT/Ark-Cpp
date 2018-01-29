

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

/*  ================================================  */
/*  ============  */
/*  ARK::Account  */
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

      String description();
  };
/*  ============  */
/*  ================================================  */

};

/*  ================================================  */
/*  ============  */
/*  Description  */
String ARK::Account::Account::description()
{
  String resp;
  resp += "address: ";
  resp += this->address.description();
  resp += "\n";
  resp += "unconfirmedBalance.ark: ";
  resp += this->unconfirmedBalance.ark;
  resp += "\n";
  resp += "balance.ark: ";
  resp += this->balance.ark;
  resp += "\n";
  resp += "publicKey.description: ";
  resp += this->publicKey.description();
  resp += "\n";
  resp += "unconfirmedSignature: ";
  resp += this->unconfirmedSignature;
  resp += "\n";
  resp += "secondSignature: ";
  resp += this->secondSignature;
  resp += "\n";
  resp += "secondPublicKey.description: ";
  resp += this->secondPublicKey.description();
  resp += "\n";
  resp += "multisignatures.description: ";
  resp += this->multisignatures.description();
  resp += "\n";
  resp += "u_multisignatures.description: ";
  resp += this->u_multisignatures.description();
  return resp;
}
/*  ============  */
/*  ================================================  */

#endif
