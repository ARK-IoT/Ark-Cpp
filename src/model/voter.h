

#ifndef voter_h
#define voter_h

namespace ARK {
    
/*  ================================================  */
  /*  ==========  */
  /*  ARK::Voter  */
  struct Voter {
    public:
      char username[64];
      Address address;
      Publickey publicKey;
      Balance balance;

      void description(char* const buf, size_t size);
  };
/*  ==========  */
/*  ================================================  */

};


/*  ================================================  */
/*  =====  */
/*  Description  */
void ARK::Voter::Voter::description(char* const buf, size_t size) {
    strcpy(buf, "username: ");
    strcat(buf, this->username);
    strcat(buf, "\naddress.description: ");
    strcat(buf, this->address.description());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey.description());
    strcat(buf, "\nbalance.ark: ");
    strcat(buf, this->balance.ark());
}
/*  =====  */
/*  ================================================  */


#endif
