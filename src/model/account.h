

#ifndef account_h
#define account_h


namespace ARK {

  /*  ============  */
  /*  ARK::Account  */
    struct Account {
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

      Account();
      Account(Address, Balance, Balance, Publickey, int, int, Publickey, Signature, Signature);
      String description();

      struct BalanceResponse;

  };
  /*  ============  */

};

/*  ==========================================================================  */

/*  ============  */
/*  ARK::Account  */

/*  Constructor  */
ARK::Account::Account() {
  address = { "" };
  unconfirmedBalance = { "" };
  balance = { "" };
  publicKey = { "" };
  unconfirmedSignature = 0;
  secondSignature = 0;
  secondPublicKey = { "" };
  multisignatures = { "" };
  u_multisignatures = { "" };
}

/*  =====  */

/*  Constructor  */
ARK::Account::Account(
  Address _address,
  Balance _unconfirmedBalance,
  Balance _balance,
  Publickey _publicKey,
  int _unconfirmedSignature,
  int _secondSignature,
  Publickey _secondPublicKey,
  Signature _multisignatures,
  Signature _u_multisignatures) :
    address( Address(_address) ),
    unconfirmedBalance( Balance(_unconfirmedBalance) ),
    balance( Balance(_balance) ),
    publicKey( Publickey(_publicKey) ),
    unconfirmedSignature(_unconfirmedSignature),
    secondSignature(_secondSignature),
    secondPublicKey( Publickey(_secondPublicKey) ),
    multisignatures( Signature(_multisignatures) ),
    u_multisignatures( Signature(_u_multisignatures) ) {}

/*  =====  */

/*  Description  */
String ARK::Account::Account::description() {
  String resp;
    resp += "address: ";
      resp += this->address.description(); resp += "\n";
    resp += "unconfirmedBalance.ark: ";
      resp += this->unconfirmedBalance.ark; resp += "\n";
    resp += "balance.ark: ";
      resp += this->balance.ark; resp += "\n";
    resp += "publicKey.description: ";
      resp += this->publicKey.description(); resp += "\n";
    resp += "unconfirmedSignature: ";
      resp += this->unconfirmedSignature; resp += "\n";
    resp += "secondSignature: ";
      resp += this->secondSignature; resp += "\n";
    resp += "secondPublicKey.description: ";
      resp += this->secondPublicKey.description(); resp += "\n";
    resp += "multisignatures.description: ";
      resp += this->multisignatures.description(); resp += "\n";
    resp += "u_multisignatures.description: ";
      resp += this->u_multisignatures.description();
  return resp;
}
/*  ============  */

/*  ==========================================================================  */

/*  ============  */
/*  ARK::Account::Account::BalanceResponse  */
/*  Definition  */
struct ARK::Account::Account::BalanceResponse {
  public:
    Balance confirmed;
    Balance unconfirmed;
    String description();
};

/*  =====  */

/*  Description  */
String ARK::Account::Account::BalanceResponse::BalanceResponse::description() {
  String resp;
    resp += "confirmed balance.ark: ";
        resp += this->confirmed.ark; resp += "\n";
    resp += "confirmed balance.arktoshi: ";
        resp += this->confirmed.arktoshi; resp += "\n\n";
    resp += "unconfirmed balance.ark: ";
        resp += this->unconfirmed.ark; resp += "\n";
    resp += "unconfirmed balance.arktoshi: ";
        resp += this->unconfirmed.arktoshi;
  return resp;
}
/*  ============  */


#endif
