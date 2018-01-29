

#ifndef voter_h
#define voter_h

namespace ARK {
    
/*  ================================================  */
  /*  ==========  */
  /*  ARK::Voter  */
  struct Voter {
    public:
      String username;
      Address address;
      Publickey publicKey;
      Balance balance;

      String description();
  };
/*  ==========  */
/*  ================================================  */

};


/*  ================================================  */
/*  =====  */
/*  Description  */
String ARK::Voter::Voter::description() {
  String resp;
    resp += "username: ";
      resp += this->username; resp += "\n";
    resp += "address.description: ";
      resp += this->address.description(); resp += "\n";
    resp += "publicKey.description: ";
      resp += this->publicKey.description(); resp += "\n";
    resp += "balance.ark: ";
      resp += this->balance.ark;
  return resp;
}
/*  =====  */
/*  ================================================  */


#endif
