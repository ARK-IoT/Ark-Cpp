#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef ARDUINO_ARCH_ESP8266

inline int convert_to_int(const String& s) {
	return s.toInt();
}

inline float convert_to_float(const String& s) {
	return s.toFloat();
}

namespace ARK
{
namespace API
{
namespace Helpers
{

inline int substringCount(const String &str, const String &sub)
{
  if (sub.length() == 0)
    return 0;
  int count = 0;
  for (size_t offset = str.indexOf(sub);
       offset != std::string::npos;
       offset = str.indexOf(sub, offset + sub.length()))
  {
    ++count;
  }
  return count;
}

}
}
}

#else

#define String std::string

#include <string>
#include <random>

inline int convert_to_int(const std::string& s) {
	return std::stoi(s);
}

inline float convert_to_float(const std::string& s) {
	return std::stof(s);
}

namespace ARK
{
namespace API
{
namespace Helpers
{

inline int substringCount(const std::string &str, const std::string &sub)
{
  if (sub.length() == 0)
    return 0;
  int count = 0;
  for (auto offset = str.find(sub);
       offset != std::string::npos;
       offset = str.find(sub, offset + sub.length()))
  {
    ++count;
  }
  return count;
}

template <typename IntType>
inline int random(IntType min, IntType max) {
	std::default_random_engine generator;
	std::uniform_int_distribution<IntType> distribution(min, max);
	return distribution(generator);
}

}
}
}

#endif

#endif
