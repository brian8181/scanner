/**
 * @file     fileio.cpp
 * @date:    Wed, Sep 17, 2025  2:03:48 PM
 * @version: 0.0.1
 */

#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include "fileio.hpp"

using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::pair;
using std::ios;

/**
 * @brief  read a character from a file stream
 * @param  strm The file stream to read from
 * @param  c : the character to read
 * @return file stream
 */
ifstream& read_char(ifstream& strm, /* out */ char& c)
{
    if (strm.is_open())
    {
        strm.get(c);
        if (!strm.good())
        {
            std::cerr << "Error: Unable to read character." << std::endl;
            exit(-1);
        }
    }
    else
    {
        std::cerr << "Error: Unable to open file for reading character." << std::endl;
    }
    return strm;
}

/**
 * @brief  write a character to a file stream
 * @param  strm file stream to write
 * @param  c : character to write
 * @return file stream
 */
ofstream& write_char(ofstream& strm, /* in */ const char& c)
{
    if (strm.is_open())
    {
        strm.put(c);
        if (!strm.good())
        {
            std::cerr << "Error: Unable to write character." << std::endl;
            exit(-1);
        }
    }
    else
    {
        std::cerr << "Error: Unable to open file for writing character." << std::endl;
    }
    return strm;
}

/**
 * @brief  read a file into a buffer
 * @param  file The file to read from
 * @param  buf : The buffer to store the file contents
 * @param  len : length of the buffer
 * @return number of bytes read, or -1 on error
 */
int read_buf(const string& file, /* out */ unsigned char* buf, const int& len)
{
    ifstream stream(file, std::ifstream::in );
    if (stream.is_open())
    {
        stream.read((char*)buf, len);
        stream.close();
        return stream.good() ? stream.gcount() : -1;
    }
    return -1;
}

/**
 * @brief  write a buffer to a file
 * @param  file : file to write to
 * @param  buf : buffer to write
 * @param  len : length of the buffer
 * @return number of bytes written, or -1 on error
 */
int write_buf(const string& file, /* in */ const unsigned char* buf, const int& len)
{
	std::ofstream stream(file, std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
	if (stream.is_open())
	{
		stream.write((char*)buf, len);
        stream.close();
		return stream.good() ? len : -1;
	}
	return -1;
}

/**
 * @brief  read a file into a string
 * @param  file : file to read from
 * @param  out : string to store the file contents
 * @return number of characters read, or -1 on error
 */
int read_str(const string& file, /* out */ string& out)
{
    ifstream stream(file, ios::in);
    if (stream.is_open())
    {
        stringstream ss;
        char c;
        while (stream.get(c))
        {
            ss << c;
        }
        out = ss.str();
        return (int)ss.str().size();
    }
    return -1;
}

/**
 * @brief  write a string to a file
 * @param  file The file to write to
 * @param  in : string to write
 * @return number of characters written, or -1 on error
 */
int write_str(const string& file, /* in */ const string& in)
{
    ofstream stream;
    stream.open(file, ios::out);
    if (stream.is_open())
    {
        stringstream ss;
        ss << in;
        stream << ss.str();
        stream.close();
        return (int)ss.str().size();
    }
    return -1;
}

/**
 * @brief  read a file into a stringstream
 * @param  file : file to read from
 * @param  sstrm : stringstream to store the file contents
 * @return number of characters read, or -1 on error
 */
int read_sstream(const string& file, /* out */ stringstream& sstrm)
{
    ifstream stream(file, ios::in);
    if (stream.is_open())
    {
        char c;
        while (stream.get(c))
        {
            sstrm << c;
        }
        stream.close();
        return sstrm.str().size();
    }
    return -1;
}

/**
 * @brief  write a stringstream to a file
 * @param  file : file to write to
 * @param  sstrm : stringstream to write
 * @return number of characters written, or -1 on error
 */
int write_sstream(const string& file, /* in */ const stringstream& sstrm)
{
    ofstream stream(file, ios::out);
    if (stream.is_open())
    {
        stream << sstrm.str();
        stream.close();
        return sstrm.str().size();
    }
    return -1;
}

/**
 * @brief  read lines from a file into a vector of strings
 * @param  file : file to read from
 * @param  lines : vector to store the lines
 * @return number of lines read, or -1 on error
 */
vector<string>& read_lines(const string& file, /* out */ vector<string>& lines)
{
    ifstream stream(file, ios::in );
    if (stream.is_open())
    {
        string line;
        while (getline(stream, line))
        {
            lines.push_back(line);
        }
        stream.close();
    }
    return lines;
}

/**
 * @brief  write lines to a file
 * @param  file : file to write to
 * @param  lines : lines to write
 * @return number of lines written, or -1 on error
 */
int write_lines(const string& file, /* in */ const vector<string>& lines)
{
    std::ofstream os(file, std::ofstream::out | std::ofstream::trunc);
	if (os.is_open())
	{
        string line;
        int len = lines.size();
        for(int i = 0; i < len; ++i)
        {
            line = lines[i];
            line.append("\n");  // append new line
		    os.write(line.c_str(), line.size());
        }
        return len;
	}
    os.close();
    return -1;
}
