/**
 * @file     fileio.hpp
 * @date:    Wed, Sep 17, 2025  2:03:48 PM
 * @version: 0.0.1
 */

#ifndef _FILEIO_HPP_
#define _FILEIO_HPP_

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;

/**
 * @brief  read a character from a file stream
 * @param  strm The file stream to read from
 * @param  c : the character to read
 * @return file stream
 */
ifstream& read_char(ifstream& stream, /* out */ char& c);

/**
 * @brief  write a character to a file stream
 * @param  strm file stream to write
 * @param  c : character to write
 * @return file stream
 */
ofstream& write_char(ofstream& stream, /* in */ const char& c);

/**
 * @brief  read a file into a buffer
 * @param  file The file to read from
 * @param  buf : The buffer to store the file contents
 * @param  len : length of the buffer
 * @return number of bytes read, or -1 on error
 */
int read_buf(const string& file, /* out */ unsigned char* buf, const int& len);

/**
 * @brief  write a buffer to a file
 * @param  file : file to write to
 * @param  buf : buffer to write
 * @param  len : length of the buffer
 * @return number of bytes written, or -1 on error
 */
int write_buf(const string& file, /* in */ const unsigned char* buf, const int& len);

/**
 * @brief  read a file into a string
 * @param  file : file to read from
 * @param  out : string to store the file contents
 * @return number of characters read, or -1 on error
 */
int read_str(const string& file, /* out */ string& out);

/**
 * @brief  write a string to a file
 * @param  file The file to write to
 * @param  in : string to write
 * @return number of characters written, or -1 on error
 */
int write_str(const string& file, /* in */ const string& out);

/**
 * @brief  read a file into a stringstream
 * @param  file : file to read from
 * @param  sstrm : stringstream to store the file contents
 * @return number of characters read, or -1 on error
 */
int read_sstream(const string& file, /* out */ stringstream& sstrm);

/**
 * @brief  write a stringstream to a file
 * @param  file : file to write to
 * @param  sstrm : stringstream to write
 * @return number of characters written, or -1 on error
 */
int write_sstream(const string& file, /* in */ const stringstream& sstrm);

/**
 * @brief  read lines from a file into a vector of strings
 * @param  file : file to read from
 * @param  lines : vector to store the lines
 * @return number of lines read, or -1 on error
 */
vector<string>& read_lines(const string& file, /* out */ vector<string>& lines);

/**
 * @brief  write lines to a file
 * @param  file : file to write to
 * @param  lines : lines to write
 * @return number of lines written, or -1 on error
 */
int write_lines(const string& file, /* in */ const vector<string>& lines);

#endif
