

#ifndef account_h
#define account_h

namespace ARK {

    struct Account {
      public:
        String address;
        String unconfirmedBalance;
        String balance;
        String publicKey;
        int unconfirmedSignature;
        int secondSignature;
        String secondPublicKey;
        String multisignatures;
        String u_multisignatures;


        String getDescription() {
          String resp;
          resp += "address: ";
            resp += this->address;
            resp += "\n";
          resp += "unconfirmedBalance: ";
            resp += this->unconfirmedBalance;
            resp += "\n";
          resp += "balance: ";
            resp += this->balance;
            resp += "\n";
          resp += "publicKey: ";
            resp += this->publicKey;
            resp += "\n";
          resp += "unconfirmedSignature: ";
            resp += this->unconfirmedSignature;
            resp += "\n";
          resp += "secondSignature: ";
            resp += this->secondSignature;
            resp += "\n";
          resp += "secondPublicKey: ";
            resp += this->secondPublicKey;
            resp += "\n";
          resp += "multisignatures: ";
            resp += this->multisignatures;
            resp += "\n";
          resp += "u_multisignatures: ";
            resp += this->u_multisignatures;
            resp += "\n";
          return resp;
        };

    };

};

#endif
