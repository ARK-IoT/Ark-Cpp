

#ifndef account_h
#define account_h

namespace ARK {
  namespace Model {
  

   class Address {

      #define ADDRESS_LENGTH 34

      public:

        String description;

        Address(String _address) {
          if (this->isValid(_address))
            this->description = _address;
        };

      private:
      
        bool isValid(String _address) {      
          bool is_valid = (_address.length() == ADDRESS_LENGTH);
          for (int i = 0; i < ADDRESS_LENGTH; i++) {
            if (!isAlphaNumeric(_address[i]) || isWhitespace(_address[i]))
              is_valid = false;
          };
          return is_valid;
        };

    };


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

        Account(  String _address,
                  String _unconfirmedBalance,
                  String _balance,
                  String _publicKey,
                  int _unconfirmedSignature,
                  int _secondSignature,
                  String _secondPublicKey,
                  String _multisignatures,
                  String _u_multisignatures) {          
          this->address = Address(_address).description;
          this->unconfirmedBalance = _unconfirmedBalance;
          this->balance = _balance;
          this->publicKey = _publicKey;
          this->unconfirmedSignature = _unconfirmedSignature;
          this->secondSignature = _secondSignature;
          this->secondPublicKey = _secondPublicKey;
          this->multisignatures = _multisignatures;
          this->u_multisignatures = _u_multisignatures;
        };

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
};

#endif
