// File Name:  fileio.cpp
// Build Date: Sat Nov 25 06:03:48 AM CST 2023
// Version:    3.6.7

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

ifstream& read_char(ifstream& stream, /* out */ char& c)
{
    if (stream.is_open())
    {
        stream.get(c);
        if (!stream)
        {
            std::cerr << "Error: Unable to read character." << std::endl;
            exit(-1);
        }
    }
    else
    {
        std::cerr << "Error: Unable to open file for reading character." << std::endl;
    }
    return stream;
}

ofstream& write_char(ofstream& stream, /* in */ const char& c)
{
    if (stream.is_open())
    {
        stream.put(c);
        if (!stream)
        {
            std::cerr << "Error: Unable to write character." << std::endl;
            exit(-1);
        }
    }
    else
    {
        std::cerr << "Error: Unable to open file for writing character." << std::endl;

    }
    return stream;
}

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
    return 0;
}

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
    return 0;
}

void read_sstream(const string& file, /* out */ stringstream& sstrm)
{
    ifstream stream(file, ios::in);
    if (stream.is_open())
    {
        string line;
        while (getline(stream, line))
        {
            sstrm << line;
        }
        stream.close();
    }
}

void write_sstream(const string& file, /* in */ const stringstream& sstrm)
{
    ofstream stream;
    stream.open(file, ios::out);
    if (stream.is_open())
    {
        stream << sstrm.str();
        stream.close();
    }
}

vector<string>& read_lines(const string& file, /* out */ vector<string>& lines)
{
    ifstream stream;
    stream.open(file, ios::out);
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

void write_lines(const string& file, /* in */ const vector<string>& lines)
{
    std::ofstream os(file, std::ofstream::out | std::ofstream::trunc);
	if (os.is_open())
	{
        string s;
        int len = lines.size();
        for(int i = 0; i < len; ++i)
        {
            s = lines[i];
            s.append("\n");  // append new line
		    os.write(s.c_str(), s.size());
        }
	}
    os.close();
}
