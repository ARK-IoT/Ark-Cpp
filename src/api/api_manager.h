

#ifndef api_manager_h
#define api_manager_h

namespace ARK {
  namespace API {
    
    /*  =================  */
    /*  ARK::API::Manager  */
    class Manager :
      public ARK::API::Accountable, 
      public ARK::API::Blockable,
      public Delegatable, 
      public Loadable,
      public MultiSignaturable,
      public Peerable,
      public Signaturable,
      public Transactionable,
      virtual ARK::Utilities::Network::Managable {

      public:

        /*  Constructor */
        Manager() {
          ARK::Network _network;
          this->connect(_network);
        };

        /*  Constructor */
        Manager(ARK::Network _network) {          
          this->connect(_network);
        };

      private:

        /*  Method */
        void connect(ARK::Network _network) {
          this->netManager = ARK::Utilities::Network::Manager(_network);
        };

    };
    /*  =================  */

  };
};

#endif
