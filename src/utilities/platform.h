#ifndef PLATFORM_H
#define PLATFORM_H

#if (defined ARDUINO || defined ESP8266 || defined ESP32)

#define USE_IOT

#include <Arduino.h>
#include <pgmspace.h>

#if (defined ARDUINO)
#include <WString.h>
#else
#undef String
#include <string>
#define String std::string
#endif


// undef the C macros to allow the C++ STL to take over
// This is to have compatibility with various board implementations of the STL
#undef min
#undef max


#include <Printable.h>
#include <Print.h>

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
  for (auto offset = str.indexOf(sub);
       offset != -1;
       offset = str.indexOf(sub, offset + sub.length()))
  {
    ++count;
  }
  return count;
}

}
}
}

inline int RNG(uint8_t *dest, unsigned size) {
  // Use the least-significant bits from the ADC for an unconnected pin (or connected to a source of 
  // random noise). This can take a long time to generate random data if the result of analogRead(0) 
  // doesn't change very frequently.
  while (size) {
    uint8_t val = 0;
    for (unsigned i = 0; i < 8; ++i) {
      int init = analogRead(0);
      int count = 0;
      while (analogRead(0) == init) {
        ++count;
      }
      
      if (count == 0) {
         val = (val << 1) | (init & 0x01);
      } else {
         val = (val << 1) | (count & 0x01);
      }
    }
    *dest = val;
    ++dest;
    --size;
  }
  // NOTE: it would be a good idea to hash the resulting random data using SHA-256 or similar.
  return 1;
}

#else

#define PROGMEM

#define String std::string

#include <string>
#include <random>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>

inline int convert_to_int(const std::string& s) {
	return std::stoi(s);
}

inline float convert_to_float(const std::string& s) {
	return std::stof(s);
}

template <typename IntType>
inline int random(IntType min, IntType max) {
	std::default_random_engine generator;
	std::uniform_int_distribution<IntType> distribution(min, max);
	return distribution(generator);
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

}
}
}

class Print;

class Printable {
public:
	virtual size_t printTo(Print& p) const = 0;
};

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Print {
public:
	Print() = default;

	int getWriteError() { return 0; }

	void cleanWriteError() { }

	virtual size_t write(uint8_t i) {
		std::cout << i;
		return 1;
	}

	size_t write(const char* str) {
		if (str == nullptr) { return 0; }
		return write((const uint8_t*)str, std::strlen(str));	
	}
	
	virtual size_t write(const uint8_t* buffer, size_t size) {
		return 0;
	}
	
	virtual int availableForWrite() { return 0; }

	//size_t print(const __FlashStringHelper *);
	template <typename T>
	size_t print(const T& t) {
		const auto start = std::cout.tellp();
		std::cout << t;
		const auto end = std::cout.tellp();
		return static_cast<size_t>(end - start);
	}

	template <typename T>
	typename std::enable_if<std::is_integral<T>::value, size_t>::type print(T t, int radix) {
		const auto start = std::cout.tellp();
		switch (radix) {
		case HEX:
			std::cout << std::hex << t;
			break;

		case OCT:
			std::cout << std::oct << t;
			break;

		case BIN:
			std::cout << std::hex << t;
			break;

		case DEC:
		default:
			std::cout << std::dec << t;
			break;
		}
		const auto end = std::cout.tellp();
		return end - start;
	}

    //size_t print(const String&);
    //size_t print(const char[]);
    //size_t print(char);
    //size_t print(unsigned char, int = DEC)
    //size_t print(int, int = DEC);
    //size_t print(unsigned int, int = DEC);
    //size_t print(long, int = DEC);
    //size_t print(unsigned long, int = DEC);
    size_t print(double d, int precision = 2) {
		const auto start = std::cout.tellp();
		std::cout << std::setprecision(2) << d;
		const auto end = std::cout.tellp();
		return static_cast<size_t>(end - start);
	}
    size_t print(const Printable& p) {
		//throw std::runtime_error("not implemented");
		return 0;
	}

	template <typename T>
	size_t println(const T& t) {
		const auto bytes_written = print(t);
		std::cout << std::endl;
		return bytes_written;
	}

	template <typename T>
	size_t println(const T& t, int radix_or_precision) {
		const auto bytes_written = print(t, radix_or_precision);
		std::cout << std::endl;
		return bytes_written;
	}
    //size_t println(const __FlashStringHelper *);
    //size_t println(const String &s);
    //size_t println(const char[]);
    //size_t println(char);
    //size_t println(unsigned char, int = DEC);
    //size_t println(int, int = DEC);
    //size_t println(unsigned int, int = DEC);
    //size_t println(long, int = DEC);
    //size_t println(unsigned long, int = DEC);
    //size_t println(double, int = 2);
    //size_t println(const Printable&);
    //size_t println(void);

    virtual void flush() { std::cout << std::flush; }
};

#endif

#endif
