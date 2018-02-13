

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

    Voter() : username() { }

    Voter(
        const char* const u, 
        const char* const a, 
        const char* const pk,
        const char* const b
    ) : username(), address(a), publicKey(pk), balance(b) {
        strncpy(username, u, sizeof(username) / sizeof(username[0]));
    }

    void description(char* const buf, size_t size);
};
/*  ==========  */
/*  ================================================  */

};


#endif
