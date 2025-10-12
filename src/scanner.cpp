/*
 * @file Name:  ./scanner.cpp
 * @date: Thu, Sep 11, 2025  4:06:25 PM
 * @version:    0.0.1
 */

#include <iostream>
#include <cstring>
#include <unistd.h>         /* for STDIN_FILENO */
#include <sys/select.h>     /* for pselect   */
#include <string>
#include <getopt.h>
#include <regex>
#include <map>
#include <vector>
#include <utility>
#include <fmt/color.h>
#include "Lexer.hpp"
#include "fileio.hpp"
#include "scanner.hpp"
#include "config.hpp"
#include "utility.hpp"

using namespace std;

const int EXEs_IDX = 0;
const int SRC_IDX = 1;
const int CONFIG_IDX = 2;

/**
 * @brief parse command line options
 * @param argc
 * @param argv
 * @return
 */
int parse_options(int argc, char* argv[])
{
    int opt;
    const char* optstring = "hVf:";
    const struct option longopts[] = {
        {"help",        no_argument,        NULL,   'h'},
        {"version",     no_argument,        NULL,   'V'},
        {"file",        required_argument,  NULL,   'f'},
        {NULL,          0,                  NULL,    0 }
    };
    string file = argv[SRC_IDX];
    while ((opt = getopt_long(argc, argv, optstring, longopts, NULL)) != -1)
    {
        switch (opt)
        {
            case 'h':
                cout << "Help message" << endl;
                return 0;
            case 'V':
                cout << "Version 0.0.1" << endl;
                return 0;
            case 'f':
                file = optarg;
                break;
            default:
                cerr << "Unknown option" << endl;
                return 1;
        }
    }
    // begin lexing ...
    Lexer lexer;
    if(argc > 1)
    {
        cout << "configuartion loading ..." << endl;
        string config = argv[CONFIG_IDX];
        lexer.load_config(config);
        lexer.dump_config();
    }
    else
    {
        cout << "missing config paramater @ index 3 ..." << std::endl;
    }
    //lexer.start(file);
    return 0;
}

/**
 * @brief  stdin_ready function
 * @param  int filedes : the file handle
 * @return ready or error code
 */
int stdin_ready (int filedes)
{
        fd_set set;
        // declare/initialize zero timeout
#ifndef CYGWIN
        struct timespec timeout = { .tv_sec = 0 };
#else
        struct timeval timeout = { .tv_sec = 0 };
#endif
        // initialize the file descriptor set
        FD_ZERO(&set);
        FD_SET(filedes, &set);

        // check stdin_ready is ready on filedes
#ifndef CYGWIN
        return pselect(filedes + 1, &set, NULL, NULL, &timeout, NULL);
#else
        return select(filedes + 1, &set, NULL, NULL, &timeout);
#endif
}

/**
 * @brief main function
 * @param argc : param count in argv
 * @param argv : command line parameters
 * @return 0 success : or error
 */
int main(int argc, char* argv[])
{
	try
	{
		char* argv_cpy[ ( sizeof(char*) * argc ) + 1 ];
		if(stdin_ready(STDIN_FILENO))
		{
			std::string buffer;
			std::cin >> buffer;
			memcpy(argv_cpy, argv, sizeof(char*) * argc);
			argv_cpy[argc] = &buffer[0];
			++argc;
			return parse_options(argc, argv_cpy);
		}
		return parse_options(argc, argv);
	}
	catch(std::runtime_error& ex)
	{
	 	std::cout << ex.what() << std::endl;
		std::exit(-1);
	}
	catch(std::logic_error& ex)
	{
		std::cout << ex.what() << std::endl;
		std::exit(-1);
	}
}
