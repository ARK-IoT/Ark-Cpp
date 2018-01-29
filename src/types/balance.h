

#ifndef BALANCE_H
#define BALANCE_H
#pragma once


/********************************************************************************
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
    this->setBalance(_balanceStr);
  };

private:
  void setBalance(String _balanceStr)
  {
    int _length = _balanceStr.length();
    if (_balanceStr == "0")
    {
      this->arktoshi[0] = '0';
      this->ark[0] = '0';
    }
    else
    {
      for (int i = 0; i < _length + 1; i++)
      {
        this->arktoshi[i] = _balanceStr[i];
      };
      for (int i = 0; i < _length + 1; i++)
      {
        if (i < _length - 8)
        {
          this->ark[i] = this->arktoshi[i];
        }
        if (i == _length - 8)
        {
          this->ark[i] = '.';
        }
        if (i > _length - 8 && i <= _length)
        {
          this->ark[i] = this->arktoshi[i - 1];
        };
      };
    };
  };
};

#endif