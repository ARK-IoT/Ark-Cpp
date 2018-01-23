#ifndef balance_h
#define balance_h
#pragma once


struct Balance {
  public:
    
    char arktoshi[17] = { '\0' };   
    char ark[18] = { '\0' };

    Balance(){
      this->setBalance("0");
    };

    Balance(String _balanceStr) {
      this->setBalance(_balanceStr);
    };

    private:
    
      void setBalance(String _balanceStr) {                
        int _length = _balanceStr.length();
        if (_balanceStr == "0") {
          this->arktoshi[0] = '0';
          this->ark[0] = '0';
        } else {   
          for (int i = 0; i < _length + 1; i++) {
            this->arktoshi[i] = _balanceStr[i];
          };
          for (int i = 0; i < _length + 1; i++) {
            if (i < _length - 8) { this->ark[i] = this->arktoshi[i]; }
            if (i == _length - 8) { this->ark[i] = '.' ;}
            if (i > _length - 8 && i <= _length) { this->ark[i] = this->arktoshi[i - 1];  };
          };
        };
      };

};



#endif