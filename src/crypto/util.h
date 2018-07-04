#ifndef ARK_CRYPTO_UTIL_H
#define ARK_CRYPTO_UTIL_H

#include <vector>
#include <string>

template<typename T>
std::string HexStr(const T itbegin, const T itend, bool fSpaces = false)
{
	std::string rv;
	const char hexmap[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	rv.reserve((itend - itbegin) * 3);
	for (T it = itbegin; it < itend; ++it)
	{
		unsigned char val = (unsigned char)(*it);
		if (fSpaces && it != itbegin)
			rv.push_back(' ');
		rv.push_back(hexmap[val >> 4]);
		rv.push_back(hexmap[val & 15]);
	}

	return rv;
}

template<typename T>
inline std::string HexStr(const T& vch, bool fSpaces = false)
{
	return HexStr(vch.begin(), vch.end(), fSpaces);
}

std::vector<unsigned char> ParseHex(const char* psz);
std::vector<unsigned char> ParseHex(const std::string& str);

#endif
