

#ifndef voter_h
#define voter_h

namespace ARK {
    
  /*  ==========  */
  /*  ARK::Voter  */
  struct Voter {
    public:
      String username;
      Address address;
      Publickey publicKey;
      Balance balance;

      Voter();
      Voter(String, Address, Publickey, Balance);
      String description();
  };
  /*  ==========  */


/*  ========================  */


  /*  ===========  */
  /*  ARK::Voters  */
  struct VotersResponse {
    public:

      int count;

      ARK::Voter list[10];// = {{}};

      VotersResponse(int);

      String description();

  };
  /*  ===========  */
};




/*  ==========  */
/*  ARK::Voter  */

/*  Constructor  */
ARK::Voter::Voter() {
  this->username = "";
  this->address =  { "" };
  this->publicKey = { "" } ;
  this->balance = { "" } ;
}

/*  =====  */

/*  Constructor  */
ARK::Voter::Voter(
  String _username,
  Address _address,
  Publickey _publicKey,
  Balance _balance) :
    username(_username),
    address( { _address } ),
    publicKey( { _publicKey } ),
    balance( { _balance } ){}

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
/*  ==========  */


/*  ========================  */


/*  ===================  */
/*  ARK::VotersResponse  */

/*  Constructor  */
ARK::VotersResponse::VotersResponse(int _count){
  this->count = _count;
}

/*  =====  */

/*  Description  */
String ARK::VotersResponse::VotersResponse::description() {
  String resp;

  if (this->count > 0) {
    for (int i = 0; i < this->count; i++) {
      resp += "\nvoter ";
      resp += i + 1;
      resp += ":\n";
      resp += this->list[i].description();
      resp += "\n";
    };
  };
  return resp;
}
/*  ===================  */


#endif
