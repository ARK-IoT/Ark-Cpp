

#ifndef delegate_h
#define delegate_h

namespace ARK {
  namespace Model {
    
    struct Delegate {
      public:
        String username;
        String address;
        String publicKey;
        String vote;
        long int producedblocks;
        long int missedblocks;
        long int rate;
        double approval;
        double productivity;

        Delegate (  String _username,
                    String _address,
                    String _publicKey,
                    String _vote,
                    long int _producedblocks,
                    long int _missedblocks,
                    long int _rate,
                    double _approval,
                    double _productivity) {
          this->username = _username;
          this->address = _address;
          this->publicKey = _publicKey;
          this->vote = _vote;
          this->producedblocks = _producedblocks;
          this->missedblocks = _missedblocks;
          this->rate = _rate;
          this->approval = _approval;
          this->productivity = _productivity;
        };

        String getDescription() {
          String resp;
          resp += "username: ";
            resp += this->username;
            resp += "\n";
          resp += "address: ";
            resp += this->address;
            resp += "\n";
          resp += "publicKey: ";
            resp += this->publicKey;
            resp += "\n";
          resp += "vote: ";
            resp += this->vote;
            resp += "\n";
          resp += "producedblocks: ";
            resp += this->producedblocks;
            resp += "\n";
          resp += "missedblocks: ";
            resp += this->missedblocks;
            resp += "\n";
          resp += "rate: ";
            resp += this->rate;
            resp += "\n";
          resp += "approval: ";
            resp += this->approval;
            resp += "%\n";
          resp += "productivity: ";
            resp += this->productivity;
            resp += "%\n";
          return resp;
        };
        
    };



  };
};

#endif
