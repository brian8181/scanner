/** @name:  ./utility.cpp
  * @date: Thu Dec 21 09:06:55 AM CST 2023
  * @version    0.0.2
*/

#include <sstream>
#include <fstream>
#include <map>
#include <regex>
#include <vector>
#include <iostream>
#include <string.h>
#include <fmt/color.h>
#include <fmt/compile.h>
#include <fmt/format.h>
#include "math.h"
#include "utility.hpp"

using std::regex;
using std::smatch;
using std::string;
using std::map;
using std::vector;
using std::ostringstream;
using std::ifstream;
using std::ifstream;
using std::pair;
using std::ios;

constexpr int ASCII_OFFSET = 48;

/**
 * @brief print color
 * @param s
 */
void color_print(const string& s, fmt::text_style ts)
{
    fmt::print(ts, "{}", s);
}

// string color_fmt(const string& s, fmt::text_style ts)
// {
//     string out = fmt::format(s, ts);
//     return out;
// }

/**
 * @name   get_config
 * @param  path to config file
 * @param  config, out parmas
 * @return map<string, string>&
 */
map<string, string>& get_config(const string& path, /* out */ map<string, string>& config)
{
    ifstream file;
    file.open(path, ios::out); //open a file
    pair<string, string> config_pair;

    if (file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            const size_t pos = line.find('=');
            string name = line.substr(0, pos-1);
            name = trim(name);
            string value = line.substr(pos+1);
            value = trim(value);
            pair p(name, value);
            config.insert(p);
        }
        file.close(); //close the file
    }
    return config;
}

/**
 * @brief single match
 * @param pattern
 * @param text
 * @param match
 * @return true if only one match & match string size equals text size
 */
bool match_single(const string& pattern, const string& text, /* out */ smatch& match)
{
    const auto rgx = regex(pattern);
    regex_match(text, match, rgx);
    if(match.size() == 1 && match.str().size() == text.size())
        return true;

    return false;
}

/**
 * @brief single match
 * @param pattern
 * @param text
 * @return true if only one match & match string size equals text size
 */
bool match_single(const string& pattern, const string& text)
{
    const auto rgx = regex(pattern);
    smatch match;
    regex_match(text, match, rgx);

    if(match.size() == 1 && text.size())
        return true;
    return false;
}

/**
 * @brief split string
 * @param s : input string
 * @param c : delimter
 * @return std::vector<std::string> // ???
 */
std::vector<std::string> split(const std::string& s, const char c)
{
  std::vector<std::string> result;
  size_t begin = 0;
  while (true)
  {
    const size_t end = s.find_first_of(c, begin);
    result.push_back(s.substr(begin, end - begin));
    if (end == std::string::npos)
    {
      break;
    }
    begin = end + 1;
  }
  return result;
}

/**
 * @brief split string
 * @param str: std::string
 * @param regex : std::string
 * @return std::vector<std::string>
 * */
std::vector<std::string> split(const std::string &str, const std::string &regex)
{
    const std::regex r{ regex };
    std::sregex_token_iterator start{ str.begin(), str.end(), r, -1 };
    const std::sregex_token_iterator end;
    return std::vector<std::string>(start, end);
}

/**
 * @name   digits10
 * @param  n, number to eval
 * @return number of base 10 digits
 */
int digits10(int n)
{
    return std::floor(std::log10(n) + 1);
}

/**
 * @name itoa
 * @brief int to ascii
 * @param n, to eval
 * @param s, out parma
 * @return void
*/
void itoa(const int& n, char* s)
{
    const int len = digits10(n);
    for(int i = 0; i < len; ++i)
    {
        int c = n / pow(10, i);
        c = std::floor( c );
        c = c % 10;
        s[len-1-i] = static_cast<char>(c + ASCII_OFFSET); // 0x30
    }
    s[len] = '\0';
}

/**
 * @name itos
 * @brief int to string
 * @param i : number to eval
 * @return string
 */
string itos(const int i)	// convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

/**
 * @name   atoi
 * @brief  ascii to int
 * @param  ptr, string to convert
 * @return int : result
 */
int atoi(const char* ptr)
{
    int num = 0;
    const int len = strlen(ptr);
    for(int i = 0; i < len; ++i)
    {
        const int digit = ASCII_OFFSET - i;
        if(digit < 0 || digit > 10)
            return -1;
        num += digit * pow(10, i);
    }
    return num;
}

/**
 * @brief to_lower: transform string chars to lower case
 * @param s: string parameter to transform
 * @param r: out param same as return value
 * @return string&: same as out param
 */
string& to_lower(const string& s, /* out */ string& r)
{
    const int len = s.length();
    r.clear();
    for(int i = 0; i < len; ++i)
    {
        const int c = std::tolower(s[i]);
        r.push_back(c);
    }
    return r;
}

/**
 * @brief to_lower: transform string chars to lower case
 * @param s: string parameter to transform
 * @return string&
 */
string& to_lower(string& s) // in place
{
    const int len = s.length();
    for(int i = 0; i < len; ++i)
    {
        const int c = std::tolower(s[i]);
        s[i] = c;
    }
    return s;
}

/**
 * @brief to_upper: transform string chars to upper case
 * @param s: string parameter to transform
 * @param r: out param same as return value
 * @return string&: same as out param
 */
string& to_upper(const string& s, /* out */ string& r)
{
    const int len = s.length();
    r.clear();
    for(int i = 0; i < len; ++i)
    {
        int c = std::toupper(s[i]);
        r.push_back(c);
    }
    return r;
}

/**
 * @brief to_upper: transform string chars to upper case
 * @param s: string parameter to transform
 * @return string&
 */
string& to_upper(string& s) // in place
{
    const int len = s.length();
    for(int i = 0; i < len; ++i)
    {
        int c = std::toupper(s[i]);
        s[i] = c;
    }
    return s;
}

/**
 * @brief left trim
 * @param s : input string
 * @return string&
 */
string& ltrim(std::string &s)
{
    const int len = s.size();
    int i;
    for(i = 0; i < len; ++i)
    {
        if(!std::isspace(s[i]))
            break;
    }
    const auto beg = s.begin();
    s.erase(beg, beg+i);
    return s;
}

/**
 * @brief right trim
 * @param s : input string
 * @return string&
 */
string& rtrim(std::string &s)
{
    const int len = s.size();
    int i = len;
    for(;i > 0; --i)
    {
        if(!std::isspace(s[i-1]))
            break;
    }
    const auto end = s.end();
    s.erase(end-(len-i), end);
    return s;
}

/**
 * @brief trim left & right
 * @param s : input string
 * @return string&
 */
string& trim(std::string &s)
{
    rtrim(s);
    ltrim(s);
    return s;
}

/**
 * @brief trim left & right
 * @param s : input string
 * @param c : char to trim
 * @return string&
 */
string& trim(string &s, char c)
{
    if(s.at(s.length()-1) == c)
        s.pop_back();
    return s;
}


/**
 * @brief
 * @param m
 * @return
 */
int read_bits(const smatch& m)
{
    int len = m.size();
    unsigned int bits = 0;
    for(int i = 0; i < len && i < 32; ++i)
    {
        bits |= static_cast<int>(m[i].matched) << i;
    }
    return bits;
}
