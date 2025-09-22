/**
 * @file scanner.hpp
 * @brief Header file for scanner.cpp
 * @author Your Name
 * @version 1.0
 * @date 2024-06-01
 */

#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <regex>

using namespace std;


void load_config( const string &path );

void start(string file);

 /**
 * @brief tokenize
 * @param exp The regular expression to match
 * @param text The text to search for matches
 */
void tokenize(const string &exp, const string &text);

void lex(const string& src, /* out*/ vector<pair<int, string>>& escapes);

/**
 * @brief Lexical analysis of the input source code.
 * @param src The source code to analyze.`
 * @param escapes A vector to store the escape sequences found.
 */
void _lex(const string& src, /* out*/ vector<pair<int, string>>& escapes);

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

#endif // _SCANNER_HPP_
