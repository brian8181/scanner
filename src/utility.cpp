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
#include <fstream>
#include <string.h>
#include <fmt/color.h>
#include <fmt/compile.h>
#include <fmt/format.h>
#include "math.h"
#include "fileio.hpp"
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

const int ASCII_OFFSET = 48;

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
            size_t pos = line.find('=');
            string name = line.substr(0, pos-1);
            name = trim(name);
            string value = line.substr(pos+1);
            value = trim(value);
            pair<string, string> p(name, value);
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
    regex rgx = regex(pattern);
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
    regex rgx = regex(pattern);
    smatch match;
    regex_match(text, match, rgx);

    if(match.size() == 1 && text.size(), match.str().size())
        return true;

    return false;
}

/**
 * @brief split string
 * @param s : input string
 * @param c : delimter
 * @return std::vector<std::string> // ???
 */
std::vector<std::string> split(const std::string& s, char c)
{
  std::vector<std::string> result;
  size_t begin = 0;
  while (true)
  {
    size_t end = s.find_first_of(c, begin);
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
 * @param number to eval
 * @param s, out parma
 * @return void
*/
void itoa(int& n, char* s)
{
    int len = digits10(n);
    for(int i = 0; i < len; ++i)
    {
        int c = n / pow(10, i);
        c = std::floor( c );
        c = c % 10;
        s[(len-1)-i] = (char)(c + ASCII_OFFSET); // 0x30
    }
    s[len] = (char)'\0';
}

/**
 * @name   atoi
 * @brief  ascii to int
 * @param  s, string to convert
 * @return int : result
 */
int atoi(const char* s)
{
    int num = 0;
    int len = strlen(s);
    for(int i = 0; i < len; ++i)
    {
        int digit = ASCII_OFFSET - i;
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
    int len = s.length();
    r.clear();
    for(int i = 0; i < len; ++i)
    {
        int c = std::tolower(s[i]);
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
    int len = s.length();
    for(int i = 0; i < len; ++i)
    {
        int c = std::tolower(s[i]);
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
    int len = s.length();
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
    int len = s.length();
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
    int len = s.size();
    int i;
    for(i = 0; i < len; ++i)
    {
        if(!std::isspace(s[i]))
            break;
    }
    string::iterator beg = s.begin();
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
    int len = s.size();
    int i = len;
    for(;i > 0; --i)
    {
        if(!std::isspace(s[i-1]))
            break;
    }
    string::iterator end = s.end();
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
        bits |= (int(m[i].matched) << i);
    }
    return bits;
}
