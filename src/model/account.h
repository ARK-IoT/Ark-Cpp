

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

      void description(char* buf, size_t len);
  };
/*  ============  */
/*  ================================================  */

};

/*  ================================================  */
/*  ============  */
/*  Description  */
void ARK::Account::Account::description(char* const buf, size_t len)
{
    //TODO:  check len for sufficient size  
    strcpy(buf, "address: ");
    strcat(buf, address.description());
    strcat(buf, "\nunconfirmedBalance.ark: ");
    strcat(buf, this->unconfirmedBalance.ark());
    strcat(buf, "\nbalance.ark: ");
    strcat(buf, this->balance.ark());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey.description());
    strcat(buf, "\nunconfirmedSignature: ");
    sprintf(buf + strlen(buf), "%d", this->unconfirmedSignature);
    strcat(buf, "\nsecondSignature: ");
    sprintf(buf + strlen(buf), "%d", this->secondSignature);
    strcat(buf, "\nsecondPublicKey.description: ");
    strcat(buf, this->secondPublicKey.description());
    strcat(buf, "\nmultisignatures.description: ");
    strcat(buf, this->multisignatures.description());
    strcat(buf, "\nu_multisignatures.description: ");
    strcat(buf, this->u_multisignatures.description());
}
/*  ============  */
/*  ================================================  */

#endif
