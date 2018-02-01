

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
public:
  char arktoshi[17 * sizeof(int)] = {'\0'};
  char ark[18 * sizeof(int)] = {'\0'};

  Balance()
  {
    this->setBalance("0");
  };

  Balance(String _balanceStr)
  {
    bool isNumeric = true;

    for (auto i : _balanceStr) {
      if (!isDigit(i))
        isNumeric = false;
    }
    if (isNumeric)
      this->setBalance(_balanceStr);
  };


private:

  void setArktoshi(String balanceStr) {
    for (unsigned int i = 0; i < balanceStr.length() + 1; i++)
    {
      this->arktoshi[i] = balanceStr[i];
    };
  }

  void setArk(String balanceStr)
  {
    int length = balanceStr.length();
    if (length < 8) {
      for (int i = 0; i < length; i++)
        this->ark[i] = balanceStr[i];
    }
    else
    {
      for (int i = length; i >= 0; i--)
      {
        if (i < length - 8) { this->ark[i] = balanceStr[i]; }
        if (i == length - 8) { this->ark[i] = '.'; }
        if (i > length - 8 && i <= length) { this->ark[i] = balanceStr[i - 1]; }
      };
    };
  }

  void setBalance(String _balanceStr)
  {
    if (_balanceStr == "0")
    {
      this->arktoshi[0] = '0';
      this->ark[0] = '0';
    }
    else
    {
      this->setArktoshi(_balanceStr);
      this->setArk(_balanceStr);
    };
  };
};

#endif