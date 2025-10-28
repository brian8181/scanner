#ifndef _utility_HPP
#define _utility_HPP

#include <iostream>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

/**
 * @name   get_config
 * @param  path to config file
 * @param  config, out parmas
 * @return map<string, string>&
 */
std::map<string, string>& get_config(const string& path, /* out */ map<string, string>& config);

/**
 * @brief print color
 * @param s
 */
void color_print(const string& s, fmt::text_style ts);

/**
 * @brief to_lower: transform string chars to lower case
 * @param s: string parameter to transform
 * @param r: out param same as return value
 * @return string&: same as out param
 */
string& to_lower(const string& s, /* out */ string& r);

/**
 * @brief to_lower: transform string chars to lower case
 * @param s: string parameter to transform
 * @return string&
 */
string& to_lower(string& s);

/**
 * @brief to_upper: transform string chars to upper case
 * @param s: string parameter to transform
 * @param r: out param same as return value
 * @return string&: same as out param
 */
string& to_upper(const string& s, /* out */ string& r);

/**
 * @brief to_upper: transform string chars to upper case
 * @param s: string parameter to transform
 * @return string&
 */
string& to_upper(string& s);

/**
 * @brief left trim
 * @param s : input string
 * @return string&
 */
string& ltrim(std::string &s);

/**
 * @brief right trim
 * @param s : input string
 * @return string&
 */
string& rtrim(std::string &s);

/**
 * @brief trim left & right
 * @param s : input string
 * @return string&
 */
string& trim(std::string &s);

/**
 * @brief trim left & right
 * @param s : input string
 * @param c : char to trim
 * @return string&
 */
string& trim(string &s, char c);

/**
 * @name   digits10
 * @param  n, number to eval
 * @return number of base 10 digits
 */
int digits10(int n);

/**
 * @name itoa
 * @brief int to ascii
 * @param number to eval
 * @param s, out parma
 * @return void
*/
void itoa(int& n, char* s);

/**
 * @name   atoi
 * @brief  ascii to int
 * @param  s, string to convert
 * @return int : result
 */
int atoi(const char* s);



typedef string line_t;
typedef vector<line_t> lines_t;
typedef string field_t;
typedef vector<field_t> record_t;
typedef vector<record_t> table_t;

std::vector<std::string> split(const std::string& s, char c);
vector<long>& psieve(const int& end, vector<long>& ret);

template <typename T> bool equal(const T& a, const T& b);

void redim(int from, int to);
string rebase(const unsigned int n, const unsigned int base);

template <typename ...Args>
void print(const Args& ...args);

#endif
