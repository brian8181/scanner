// File Name:  fileio.cpp
// Build Date: Sat Nov 25 06:03:48 AM CST 2023
// Version:    3.6.7

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
 * @brief Read a character from a file stream
 * @param stream The file stream to read from
 * @param c The character to read
 * @return The file stream
 */
ifstream& read_char(ifstream& stream, /* out */ char& c);
/**
 * @brief Write a character to a file stream
 * @param stream The file stream to write to
 * @param c The character to write
 * @return The file stream
 */
ofstream& write_char(ofstream& stream, /* in */ const char& c);
/**
 * @brief Read a file into a buffer
 * @param file The file to read from
 * @param buf The buffer to store the file contents
 * @param len The length of the buffer
 * @return The number of bytes read, or -1 on error
 */
int read_buf(const string& file, /* out */ unsigned char* buf, const int& len);
/**
 * @brief Write a buffer to a file
 * @param file The file to write to
 * @param buf The buffer to write
 * @param len The length of the buffer
 * @return The number of bytes written, or -1 on error
 */
int write_buf(const string& file, /* in */ const unsigned char* buf, const int& len);
/**
 * @brief Read a file into a string
 * @param file The file to read from
 * @param out The string to store the file contents
 * @return The number of characters read, or -1 on error
 */
int read_str(const string& file, /* out */ string& out);
/**
 * @brief Write a string to a file
 * @param file The file to write to
 * @param in The string to write
 * @return The number of characters written, or -1 on error
 */
int write_str(const string& file, /* in */ const string& out);
/**
 * @brief Read a file into a stringstream
 * @param file The file to read from
 * @param sstrm The stringstream to store the file contents
 * @return The number of characters read, or -1 on error
 */
int read_sstream(const string& file, /* out */ stringstream& sstrm);
/**
 * @brief Write a stringstream to a file
 * @param file The file to write to
 * @param sstrm The stringstream to write
 * @return The number of characters written, or -1 on error
 */
int write_sstream(const string& file, /* in */ const stringstream& sstrm);
/**
 * @brief Read lines from a file into a vector of strings
 * @param file The file to read from
 * @param lines The vector to store the lines
 * @return The number of lines read, or -1 on error
 */
vector<string>& read_lines(const string& file, /* out */ vector<string>& lines);
/**
 * @brief Write lines from a vector of strings to a file
 * @param file The file to write to
 * @param lines The vector of lines to write
 * @return The number of lines written, or -1 on error
 */
int write_lines(const string& file, /* in */ const vector<string>& lines);

#endif
