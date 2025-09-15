#ifndef _scanner_HPP_
#define _scanner_HPP_
#include <string>
#include <vector>
#include <utility>
#include <regex>

#include <iostream>

using namespace std;
/**
 * @file scanner.hpp
 * @brief Header file for scanner.cpp
 * @author Your Name
 * @version 1.0
 * @date 2024-06-01
 *
 * This file contains declarations for functions and constants used in the scanner implementation.
 */
void lex(const string& src, /* out*/ vector<pair<int, string>>& escapes);
/**
 * @brief parse command line options
 * @param argc
 * @param argv
 * @return
 */
int parse_options(int argc, char* argv[]);
/**
 * @brief check if stdin is ready for reading
 * @param filedes
 * @return
 */
int stdin_ready (int filedes);
/**
 * @brief scanner entry point for the application
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]);

#endif // _scanner_HPP_
