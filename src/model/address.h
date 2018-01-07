


#ifndef address_h
#define address_h

namespace ARK {  

   class Address {
      #define ADDRESS_LENGTH 34
      public:
        String description;
        Address(String _address);
      private:
        bool isValid(String _address);
    };

};

#endif
