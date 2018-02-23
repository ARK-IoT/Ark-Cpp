

#ifndef HELPERS_H
#define HELPERS_H

namespace ARK
{
namespace API
{
namespace Helpers
{

  int substringCount(const char* str, const char* sub)
  {
    String string = str;
    String subString = sub;

    if (subString.length() == 0)
      return 0;
    int count = 0;
    for (size_t offset = string.indexOf(sub);
        offset != std::string::npos;
        offset = string.indexOf(sub, offset + subString.length()))
    {
      ++count;
    }
    return count;
  };

};
};
};

#endif
