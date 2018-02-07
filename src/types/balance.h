

#ifndef BALANCE_H
#define BALANCE_H
#pragma once


/********************************************************************************
*
* Currently very verbose, needs bigint implementation using pow(10,8)
*
* Balance: 
*   arktoshi : "100000000"
*   ark : "1.00000000"
*   
*   Big Integer/Floating Point | 8-decimal places/pow(10,8)
*   
*   Currenty Block Supply total ~ 1.3e16 (12984403000000000:arktoshi)/(129844030.00000000:ark)
*
********************************************************************************/




struct Balance
{
private:
    static const auto ARKTOSHI_SIZE = 17 * sizeof(int);
    static const auto ARK_SIZE = 18 * sizeof(int);

    char arktoshi_[ARKTOSHI_SIZE];
    char ark_[ARK_SIZE];

public:
  Balance() : arktoshi_(), ark_()
  {
    this->setBalance("0");
  };

  explicit Balance(const char* const balanceStr) : arktoshi_(), ark_()
  {
        bool isNumeric = true;

        for (auto i = 0; i < strlen(balanceStr); ++i) {
          if (!isDigit(balanceStr[i])) {
                isNumeric = false;
                break;
            }
        }
        if (isNumeric) {
          this->setBalance(balanceStr);
        }
  };


    const char* const ark() const { return ark_; }
    const char* const arktoshi() const { return arktoshi_; }

    void setArktoshi(const char* const balanceStr) {
        strncpy(arktoshi_, balanceStr, ARKTOSHI_SIZE);
    }

  void setArk(const char* const balanceStr)
  {
    const auto length = strlen(balanceStr);
    if (length < 8) {
      for (int i = 0; i < length; ++i)
      {
        this->ark_[i] = balanceStr[i];
      }
    }
    else
    {
      for (int i = length; i >= 0; --i)
      {
        if (i < length - 8) { this->ark_[i] = balanceStr[i]; }
        if (i == length - 8) { this->ark_[i] = '.'; }
        if (i > length - 8 && i <= length) { this->ark_[i] = balanceStr[i - 1]; }
      };
    };
  }

  void setBalance(const char* const _balanceStr)
  {
    if (strcmp(_balanceStr, "0") == 0)
    {
      this->arktoshi_[0] = '0';
      this->ark_[0] = '0';
    }
    else
    {
      this->setArktoshi(_balanceStr);
      this->setArk(_balanceStr);
    };
  };
};

#endif