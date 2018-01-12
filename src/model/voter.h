

#ifndef voter_h
#define voter_h

namespace ARK {
  // namespace Model { API???
    
    struct Voter {
      public:
        String username;
        String address;
        String publicKey;
        int balance;

        Voter() {
          this->username = "";
          this->address = "";
          this->publicKey = "";
          this->balance = 0;
        };

        Voter(String _username, String _address, String _publicKey, int _balance) { 
          this->username = _username;
          this->address = _address;
          this->publicKey = _publicKey;
          this->balance = _balance;
        };

        String description() {
          String resp;
            resp += "username: ";
              resp += this->username; resp += "\n";
            resp += "address: ";
              resp += this->address; resp += "\n";
            resp += "publicKey: ";
              resp += this->publicKey; resp += "\n";
            resp += "balance: ";
              resp += this->balance; resp += "\n";
          return resp;
        };


    };

#define array_length( x )  ( sizeof( x ) / sizeof( *x ) )

    struct Voters {

      public:
      String voters;

      Voters(){
        this->voters = "";
      };

      void add(Voter _voter) {
        this->voters += _voter.description();
        this->voters += ",\n";
      };

      // String description() {
      //   String resp;
      //   for (int i = 0; i < sizeof(this->voters); i++ {
      //     resp += "voter ";
      //       resp += i;
      //       resp+= ": ";
      //       resp += "\n";
      //       resp += this->voters[i].description();
      //       resp += "\n";
      //   };
      //   return resp;
      // };
    };

  // };
};

#endif
