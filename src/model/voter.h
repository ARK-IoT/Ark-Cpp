

#ifndef voter_h
#define voter_h

namespace ARK {
    
  struct Voter {
    public:
      String username;
      String address;
      String publicKey;
      String balance;

      Voter();

      Voter(String _username, String _address, String _publicKey, String _balance);

      String description();

  };

};

ARK::Voter::Voter() {
  this->username = "";
  this->address = "";
  this->publicKey = "";
  this->balance = "";
}

ARK::Voter::Voter(String _username, String _address, String _publicKey, String _balance) { 
  this->username = _username;
  this->address = _address;
  this->publicKey = _publicKey;
  this->balance = _balance;
}

String ARK::Voter::Voter::description() {
  String resp;
    resp += "username: ";
      resp += this->username; resp += "\n";
    resp += "address: ";
      resp += this->address; resp += "\n";
    resp += "publicKey: ";
      resp += this->publicKey; resp += "\n";
    resp += "balance: ";
      resp += this->balance;
  return resp;
}


#endif
