#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <stdlib.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

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

static inline unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	unsigned int pos = txt.find(ch);
	unsigned int initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos));
	return strs.size();
}

static inline float get_safe_float_range(std::string val) 
{
	string lower = val.substr(1, val.find(","));
	string upper = val.substr(val.find(",") + 1, val.size() - 1);
	float lowFloat = stof(lower);
	float highFloat = stof(upper);
	if (lowFloat > highFloat) {
		float temp = highFloat;
		highFloat = lowFloat;
		lowFloat = temp;
	}
	return random(lowFloat, highFloat);
}

static inline float get_safe_float_range_exclude(std::string val) 
{
	val = val.substr(1, val.size() - 1);
	std::vector<string> values;
	int range = random(0, floor(split(val, values, ',') / 2) - 1);
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
		return stof(val);
	}
	catch (std::invalid_argument& ia) {
		return 0;
	}
	catch (std::out_of_range& oa) {
		return 0;
	}
}

static inline int get_safe_int(std::string val) {
	try {
		if (is_parsable(val))
		{
			string lower = val.substr(1, val.find(","));
			string upper = val.substr(val.find(",") + 1, val.size() - 1);
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
	catch (std::invalid_argument& ia) {
		return 0;
	}
	catch (std::out_of_range& oa) {
		return 0;
	}
}

static inline bool file_exists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

static bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

inline static std::vector<std::vector<std::string>>* parseConsoleInput(std::string input) {
	std::vector<std::vector<std::string>>* commands = new std::vector<std::vector<std::string>>();
	std::vector<std::string> currentParams;
	std::string currentString;
	for (size_t i = 0; i<input.length(); i++) {
		char c = input[i];
		if (c == ' ') 
		{
			if (!currentString.empty()) 
			{
				currentParams.push_back(currentString);
				currentString.clear();
			}
		}
		else if (c == '\"' && (i == 0 || input[i - 1] != '\\'))
		{
			i++;
			while (i < input.length() && input[i] != '\"' && (i == 0 || input[i - 1] != '\\') )
			{ 
				currentString += input[i]; 
				i++; 
			}
		}
		else if (c == '(')
		{
			i++;
			currentString += "(";
			while (i < input.length() && input[i] != ')') {
				currentString += input[i];
				i++;
			}
			currentString += ")";
		}
		else if (c == ';') 
		{
			currentParams.push_back(currentString);
			commands->push_back(currentParams);
			currentParams.clear();
			currentString.clear();
		} 
		else if (c == '/') {
			i++;
			if (i < input.length()) {
				if (input[i] == '/') {
					break;
				}
			}
		}
		else 
		{
			currentString += c;
		}
	}
	currentParams.push_back(currentString);
	commands->push_back(currentParams);
	return commands;
}

static std::istream& safeGetline(std::istream& is, std::string& t)
{
	t.clear();

	// The characters in the stream are read one-by-one using a std::streambuf.
	// That is faster than reading them one-by-one using the std::istream.
	// Code that uses streambuf this way must be guarded by a sentry object.
	// The sentry object performs various tasks,
	// such as thread synchronization and updating the stream state.

	std::istream::sentry se(is, true);
	std::streambuf* sb = is.rdbuf();

	for (;;) {
		int c = sb->sbumpc();
		switch (c) {
		case '\n':
			return is;
		case '\r':
			if (sb->sgetc() == '\n')
				sb->sbumpc();
			return is;
		case EOF:
			// Also handle the case when the last line has no line ending
			if (t.empty())
				is.setstate(std::ios::eofbit);
			return is;
		default:
			t += (char)c;
		}
	}
}



// trim from start
static inline std::string &ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
	return ltrim(rtrim(s));
}

static inline bool replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

template<typename T>
void save_struct(std::string file, T data)
{
	std::fstream inbal(file.c_str(), std::ios::out | std::ios::binary);
	inbal.write((char *)&data, sizeof(T));
	inbal.close();
};

template<typename T>
T load_struct(std::string file)
{
	T loaded_data;
	std::fstream inbal(file.c_str(), std::ios::in | std::ios::binary);
	inbal.read((char *)&loaded_data, sizeof(T));
	inbal.close();
	return loaded_data;
};

static inline long long milliseconds_now() {
	static LARGE_INTEGER s_frequency;
	static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
	if (s_use_qpc) {
		LARGE_INTEGER now;
		QueryPerformanceCounter(&now);
		return (1000LL * now.QuadPart) / s_frequency.QuadPart;
	}
	else {
		return GetTickCount();
	}
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

template<typename T>
void write_pod(std::ofstream& out, T& t)
{
	out.write(reinterpret_cast<char*>(&t), sizeof(T));
}
template<typename T>
void read_pod(std::ifstream& in, T& t)
{
	in.read(reinterpret_cast<char*>(&t), sizeof(T));
}