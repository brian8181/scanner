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

ifstream& read_char(ifstream& stream, /* out */ char& c);
ofstream& write_char(ofstream& stream, /* in */ const char& c);
int read_buf(const string& file, /* out */ unsigned char* buf, const int& len);
int write_buf(const string& file, /* in */ const unsigned char* buf, const int& len);
int read_str(const string& file, /* out */ string& out);
int write_str(const string& file, /* in */ const string& out);
void read_sstream(const string& file, /* out */ stringstream& sstrm);
void write_sstream(const string& file, /* in */ const stringstream& sstrm);
vector<string>& read_lines(const string& file, /* out */ vector<string>& lines);
void write_lines(const string& file, /* in */ const vector<string>& lines);

#endif
