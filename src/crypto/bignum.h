

#ifndef BIGNUM_H
#define BIGNUM_H

namespace ARK
{
namespace Crypto
{
namespace BigNum
{

static BigNumber processToBigNumber(BigNumber& bigNum,  char *sha256Buffer)
{
  int sha256StrLen = strlen(sha256Buffer);
  Serial.println(sha256StrLen);
  Serial.println(sha256Buffer);
  Serial.println(bigNum);

  
  for (int i = 0; i < sha256StrLen; i += 2)
  {
    if (sha256Buffer[i] != 0)
    {
      char buff[2] = { "\0" };
        buff[0] = sha256Buffer[i];
        buff[1] = sha256Buffer[i + 1];
      char *ptr;
    
      BigNumber decFromHex = strtoll(buff, &ptr, 16);

      BigNumber exponent = ((sha256StrLen - i) - 2) ;

      BigNumber base = 16;
      BigNumber multiplier = base.pow(exponent);

      BigNumber newValue = decFromHex * multiplier;
      
      bigNum += newValue;
    }
    else
    {
      bigNum += "0";
      i--;
    }
  }
  // sha256Buffer[sha256StrLen + 1] = { "\0" };
  return bigNum;
}

};
};
};

#endif
