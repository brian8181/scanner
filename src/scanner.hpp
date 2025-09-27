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
#include <utility>
#include <vector>
#include <regex>

using namespace std;

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
