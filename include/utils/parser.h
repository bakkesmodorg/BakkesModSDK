#pragma once

#include <algorithm> 
#include <cctype>
#include <fstream>
#include <functional> 
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <windows.h>
#undef min
#undef max

static inline int random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

static inline float random(float min, float max) {
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

static inline float random_with_exclude(float min, float max, float minExclude, float maxExclude) {
	float total_exclude = maxExclude - minExclude;
	float new_max = max - total_exclude;
	float result = random(min, new_max);
	return result > minExclude ? result + total_exclude : result;
}

static inline float get_safe_float_range(std::string val)
{
	std::string lower = val.substr(1, val.find(","));
	std::string upper = val.substr(val.find(",") + 1, val.size() - 1);
	float lowFloat = stof(lower);
	float highFloat = stof(upper);
	if (lowFloat > highFloat) {
		float temp = highFloat;
		highFloat = lowFloat;
		lowFloat = temp;
	}
	return random(lowFloat, highFloat);
}

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 4)
{
	if (a_value <= 0.01f && a_value >= -0.01f)
		return "0.0000";
	std::ostringstream out;
	out << std::fixed << std::setprecision(n) << a_value;
	return out.str();
}

static inline bool string_ends_with(std::string const & value, std::string const & ending)
{
	if (ending.size() > value.size()) return false;
	return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

static inline bool string_starts_with(std::string const & value, std::string const & begin) {
	return value.compare(0, begin.length(), begin) == 0;
}

static inline bool is_parsable(std::string val) {
	return string_starts_with(val, "(") && string_ends_with(val, ")") && val.find(",") != std::string::npos;
}

static inline size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, std::min((size_t)pos, txt.size()) - initialPos));
	return strs.size();
}


static inline float get_safe_float_range_exclude(std::string val)
{
	val = val.substr(1, val.size() - 1);
	std::vector<std::string> values;
	int range = random(0, (int)(floor(split(val, values, ',') / 2)) - 1);
	float lower = stof(values.at(range * 2));
	float upper = stof(values.at(range * 2 + 1));
	return random(lower, upper);
}

static inline float get_safe_float(std::string val) {
	try {
		if (is_parsable(val))
		{
			return get_safe_float_range_exclude(val);
			/*int comma_amount = std::count(val.begin(), val.end(), ',');
			if (comma_amount == 3)
			{
			return get_safe_float_range_exclude(val);
			}
			else
			{
			return get_safe_float_range(val);
			}*/

		}
		return (float)atof(val.c_str());
	}
	catch (std::invalid_argument&) {
		return 0;
	}
	catch (std::out_of_range&) {
		return 0;
	}
}

static inline int get_safe_int(std::string val) {
	try {
		if (is_parsable(val))
		{
			std::string lower = val.substr(1, val.find(","));
			std::string upper = val.substr(val.find(",") + 1, val.size() - 1);
			int lowInt = stoi(lower);
			int highInt = stoi(upper);
			if (lowInt > highInt) {
				int temp = highInt;
				highInt = lowInt;
				lowInt = temp;
			}
			return random(lowInt, highInt);
		}
		return stoi(val);
	}
	catch (std::invalid_argument&) {
		return 0;
	}
	catch (std::out_of_range&) {
		return 0;
	}
}

static inline bool get_safe_bool(std::string val) {
	float f = get_safe_float(val);
	return f >= 0.5;
}

static inline LinearColor get_safe_color_rgba(std::string val)
{
    LinearColor output = {0,0,0,0};
    try
    {
        if(is_parsable(val))
        {
            val = val.substr(1, val.size() - 1);
            std::vector<std::string> values;
            split(val, values, ',');
            if(values.size() == 4)
            {
                output.R = stof(values.at(0));
                output.G = stof(values.at(1));
                output.B = stof(values.at(2));
                output.A = stof(values.at(3));
            }
        }
        return output;
    }
    catch (...)
    {
		return output;
	}
}

//Hexdecimal and LinearColor conversions
static inline bool is_hex_valid(std::string val)
{
	//If empty, invalid
	if(val.empty()) { return false; }

	//Remove the hashtag if there is one at the front
    if(val.at(0) == '#') { val.erase(0,1); }

	//Check if there are enough characters
	if(val.size() < 6) { return false; }

	//Check if all characters are within charSet
	static const std::string chars = "0123456789ABCDEF";
	for(const auto& it : val)
	{
		if(chars.find(toupper(it)) == std::string::npos)
		{
			return false;
		}
	}

	return true;
}

static int single_hex_char_to_int(char input)
{
    static const std::string Letters = "ABCDEF";
	static const std::string Numbers = "0123456789";

    if(Letters.find(input) != std::string::npos)
    {
        return input - 'A' + 10;
    }
	if(Numbers.find(input) != std::string::npos)
    {
        return input - '0';
    }

	return 0;
}

static int hex_chars_to_int(std::string input)
{
    //Convert 2 hex characters to their respective int (0-255)
    if(input.size() < 2) { return 0; }

    for(auto& c : input)
	    c = toupper(c);
	
    int bigboi = single_hex_char_to_int(input.at(0)) * 16;
    int lilboi = single_hex_char_to_int(input.at(1));
    
    return bigboi + lilboi;
}

static char single_hex_char_from_int(int input)
{
    if(input >= 0 && input <= 9)
    {
        return ('0' + input);
    }

    return ('A' + input - 10);
}

static std::string int_to_hex_chars(int input)
{
    //Convert int (0-255) to its respective 2 hex chars

    int bignum = input / 16;
    int lilnum = input - (16 * bignum);

    char bigboi = single_hex_char_from_int(bignum);
    char lilboi = single_hex_char_from_int(lilnum);

    std::string output;
    return output + bigboi + lilboi;
}

static inline LinearColor get_color_from_hex(std::string val)
{
    //Color output will be in 0-255 range
    LinearColor output = {0,0,0,0};

    if(!is_hex_valid(val)) { return output; }

    //Remove beginning # if it exists
    if(val.at(0) == '#') { val.erase(0,1); }

    //Add alpha characters if they don't exist
    if(val.size() < 8)
    {
        if(val.size() == 6) { val += "FF"; }
        if(val.size() == 7) { val += "F";  }
    }

    int R = hex_chars_to_int(val.substr(0,2));
    int G = hex_chars_to_int(val.substr(2,2));
    int B = hex_chars_to_int(val.substr(4,2));
    int A = hex_chars_to_int(val.substr(6,2));

    return LinearColor{static_cast<float>(R), static_cast<float>(G), static_cast<float>(B), static_cast<float>(A)};
}

static inline std::string get_hex_from_color(LinearColor val)
{
    //Color input must be in 0-255 range
    int R = static_cast<int>(val.R);
    int G = static_cast<int>(val.G);
    int B = static_cast<int>(val.B);
    int A = static_cast<int>(val.A);

    std::string output = "#";
    output += int_to_hex_chars(R) + int_to_hex_chars(G) + int_to_hex_chars(B) + int_to_hex_chars(A);

    return output;
}

static inline std::string to_string_color(const LinearColor val)
{
    return "(" + std::to_string(val.R) + ", " + std::to_string(val.G) + ", " + std::to_string(val.B) + ", " + std::to_string(val.A) + ")";
}

// trim from start
static inline std::string &ltrim(std::string &s) {
    /* error C2039 : 'ptr_fun' : is not a member of 'std'. */
    //s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c); }));

    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    /* error C2039 : 'ptr_fun' : is not a member of 'std'. */
    //s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c); }).base(), s.end());

    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
	return ltrim(rtrim(s));
}

inline static std::vector<std::vector<std::string>>* parseConsoleInput(std::string input)
{
	std::vector<std::vector<std::string>>* commands = new std::vector<std::vector<std::string>>();
	std::vector<std::string> currentParams;
	std::string currentString;

	char currentQuote = '\0';
	for (std::string::size_type i = 0; i < input.length(); i++)
	{
		char c = input[i];
		// Start/stop quoted block.
		if ((c == '"' || c == '\'') && (i == 0 || input[i - 1] != '\\'))
		{
			if (currentQuote == c)
			{
				currentQuote = '\0';
				currentParams.push_back(currentString);
				currentString.clear();
			}
			else if (currentQuote == '\0')
				currentQuote = c;
			else
				currentString += c;
		}
		else if (c == '\\' && i + 1 < input.length() && (input[i + 1] == '"' || input[i + 1] == '\''))
			continue;
		// Check if we are in a quoted block.
		else if (currentQuote != '\0')
			currentString += c;
		// Split params.
		else if (c == ' ')
		{
			if (!currentString.empty())
			{
				currentParams.push_back(currentString);
				currentString.clear();
			}
		}
		// Grouped params.
		else if (c == '(')
		{
			currentString += "(";
			while (++i < input.length() && input[i] != ')')
				currentString += input[i];
			currentString += ")";
		}
		// New command.
		else if (c == ';')
		{
			currentParams.push_back(currentString);
			commands->push_back(currentParams);
			currentParams.clear();
			currentString.clear();
		}
		// Break on comments.
		else if (c == '/' && i + 1 < input.length() && input[i + 1] == '/')
			break;
		else
			currentString += c;
	}
	if (!currentString.empty())
		currentParams.push_back(currentString);
	if (!currentParams.empty())
		commands->push_back(currentParams);

	return commands;
}

static inline bool replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

//inline static std::string to_string(std::string s) {
//	return s;
//}
//
//
//inline static std::string to_string(const char* s) {
//	return std::string(s);
//}

//inline static std::string to_string(char* s) {
//	return std::string(s);
//}
inline static std::string bool_to_string(bool s) {
	return s ? "1" : "0";
}

//inline static std::string to_string(int s) {
//	return std::to_string(s);
//}
//inline static std::string to_string(float s) {
//	return std::to_string(s);
//}
//
//inline static std::string to_string(long s) {
//	return std::to_string(s);
//}
//
//inline static std::string to_string(double s) {
//	return std::to_string(s);
//}

/*
base64.cpp and base64.h

Copyright (C) 2004-2008 René Nyffenegger

This source code is provided 'as-is', without any express or implied
warranty. In no event will the author be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this source code must not be misrepresented; you must not
claim that you wrote the original source code. If you use this source code
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original source code.

3. This notice may not be removed or altered from any source distribution.

René Nyffenegger rene.nyffenegger@adp-gmbh.ch

*/

static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


static inline bool is_base64(unsigned char c) {
	return (isalnum(c) || (c == '+') || (c == '/'));
}

inline static std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
	std::string ret;
	int i = 0;
	int j = 0;
	unsigned char char_array_3[3];
	unsigned char char_array_4[4];

	while (in_len--) {
		char_array_3[i++] = *(bytes_to_encode++);
		if (i == 3) {
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (i = 0; (i <4); i++)
				ret += base64_chars[char_array_4[i]];
			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 3; j++)
			char_array_3[j] = '\0';

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
			ret += base64_chars[char_array_4[j]];

		while ((i++ < 3))
			ret += '=';

	}

	return ret;

}

inline static std::vector<BYTE> base64_decode_bytearr(std::string const& encoded_string) {
	size_t in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	size_t char_array_4[4], char_array_3[3];
	std::vector<BYTE> ret;

	while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
		char_array_4[i++] = encoded_string[in_]; in_++;
		if (i == 4) {
			for (i = 0; i <4; i++)
				char_array_4[i] = base64_chars.find((char)char_array_4[i]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret.push_back((char)char_array_3[i]);
			i = 0;
		}
	}

	if (i) {
		for (j = i; j <4; j++)
			char_array_4[j] = 0;

		for (j = 0; j <4; j++)
			char_array_4[j] = base64_chars.find((char)char_array_4[j]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) ret.push_back((char)char_array_3[j]);
	}

	return ret;
}

inline static std::string base64_decode(std::string const& encoded_string) {
	size_t in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	size_t char_array_4[4], char_array_3[3];
	std::string ret;

	while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
		char_array_4[i++] = encoded_string[in_]; in_++;
		if (i == 4) {
			for (i = 0; i <4; i++)
				char_array_4[i] = base64_chars.find((char)char_array_4[i]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret += (char)char_array_3[i];
			i = 0;
		}
	}

	if (i) {
		for (j = i; j <4; j++)
			char_array_4[j] = 0;

		for (j = 0; j <4; j++)
			char_array_4[j] = base64_chars.find((char)char_array_4[j]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) ret += (char)char_array_3[j];
	}

	return ret;
}

/*
Binary writer which optimizes for bit size. Programmer has to specify the number of LSB bits to store
*/
template<typename A>
class BitBinaryWriter
{
public:
	const int type_size = sizeof(A) * 8;
	int current_bit = 0;
	A* buffer;
	BitBinaryWriter(int bufferSize)
	{
		buffer = (A*)calloc(bufferSize, type_size);
	}

	~BitBinaryWriter()
	{
		delete buffer;
	}

	template<typename T>
	void WriteBits(T t, int useLSBcount = sizeof(T)*8)
	{
		T t2 = t;
		for (int i = 0; i < useLSBcount; i++)
		{
			if (t2 & 1) {
				buffer[current_bit / type_size] |= (1 << (current_bit % type_size));
			}
			else
			{
				buffer[current_bit / type_size] &= ~(1 << (current_bit % type_size));
			}
			current_bit++;
			t2 >>= 1;
		}
	}

	void WriteBool(bool b)
	{
		WriteBits(b ? 1 : 0, 1); //Use ternary to ensure last bit contains true false
	}

	uint8_t CalculateCRC(int startByte, int endByte)
	{
		uint8_t crc = 0b11111111;
		for (int i = startByte; i < endByte; i++)
		{
			crc = crc ^ buffer[i];
		}
		return crc;
	}

	std::string ToHex()
	{
		return base64_encode(buffer, current_bit / type_size + 1);
	}
};

template<typename A>
class BitBinaryReader
{
public:
	const int type_size = sizeof(A) * 8;
	int current_bit = 0;
	A* buffer;

	BitBinaryReader(std::string hexString)
	{
		std::vector<BYTE> decodedVector = base64_decode_bytearr(hexString);
		//std::string decoded = base64_decode(hexString);
		//const char* data = decoded.c_str();
		buffer = (A*)malloc(decodedVector.size());
		memcpy(buffer, &decodedVector[0], decodedVector.size());
	}

	BitBinaryReader(A* inBuf)
	{
		buffer = inBuf;
	}

	~BitBinaryReader()
	{
		delete buffer;
	}

	template<typename T>
	T ReadBits(int useLSBcount = sizeof(T) * 8)
	{
		T t = 0;
		for (int i = 0; i < useLSBcount; i++)
		{
			t |= ((buffer[current_bit / type_size] >> (current_bit % type_size)) & 1) << i;
			current_bit++;
		}
		return t;
	}
	uint8_t CalculateCRC(int startByte, int endByte)
	{
		uint8_t crc = 0b11111111;
		for (int i = startByte; i < endByte; i++)
		{
			crc = crc ^ buffer[i];
		}
		return crc;
	}
	bool VerifyCRC(uint8_t crc, int startByte, int endByte)
	{
		return (crc ^ CalculateCRC(startByte, endByte)) == 0;
	}

	bool ReadBool()
	{
		return ReadBits<bool>(1) & 1; //Use ternary to ensure last bit contains true false
	}
};


#include <stdarg.h>  // For va_start, etc.
#include <memory>    // For std::unique_ptr
//Source: https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
static inline std::string string_format(const std::string fmt_str, ...) {
	int final_n, n = ((int)fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
	std::unique_ptr<char[]> formatted;
	va_list ap;
	while (1) {
		formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
		strcpy_s(&formatted[0], n, fmt_str.c_str());
		va_start(ap, fmt_str);
		final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
		va_end(ap);
		if (final_n < 0 || final_n >= n)
			n += abs(final_n - n + 1);
		else
			break;
	}
	return std::string(formatted.get());
}

static inline std::string wstring_to_string(const std::wstring& InWString)
{
    if (InWString.empty()) return std::string();

    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &InWString[0], (int)InWString.size(), NULL, 0, NULL, NULL);
    std::string strTo(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &InWString[0], (int)InWString.size(), &strTo[0], size_needed, NULL, NULL);

    return strTo;
}
