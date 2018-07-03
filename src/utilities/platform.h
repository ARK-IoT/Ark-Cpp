#ifndef PLATFORM_H
#define PLATFORM_H

#include <sstream>

#if (defined ARDUINO || defined ESP8266 || defined ESP32)

#include <cstdio>

#include "arduino/stl/details/to_string.h"

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

#include <string>
#include <cstring>
#include <WString.h>
#include <Printable.h>
#include <Print.h>

inline int convert_to_int(const std::string& s)
{
	return atoi(s.c_str());
}

inline float convert_to_float(const std::string& s)
{
	return atof(s.c_str());
}

inline uint64_t convert_to_uint64(const std::string& s) {
	return strtoull(s.c_str(), nullptr, 10);
}

/*************************************************
* substringCount(const char *str, const char* substr)
*
*		Returns number of times a substring(subStr)
*   appears in a provided string(str)
**************************************************/
inline int substringCount(const char* str, const char* subStr) {
	if (strlen(subStr) == 0) { return -1; }
	int count = 0;
	for (const auto* s = str; (s = strstr(s, subStr)); ++s) {
		++count;
	}
	return count;
}
/*************************************************/

inline uint32_t generate_random_number(uint32_t min, uint32_t max, bool /* static_seed */ = false) {
	return random(min, max);
}

#else

#define PROGMEM
#define PGM_P const char*

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

inline uint64_t convert_to_uint64(const std::string& s) {
	return std::stoull(s);
}

uint32_t generate_random_number(uint32_t min, uint32_t max, bool static_seed = false);

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

template <typename T>
std::string convert_to_string(T t) {
	std::ostringstream ss;
	ss << t;
	return ss.str();
}

#endif
