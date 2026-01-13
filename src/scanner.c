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
#include <set>
#include "scanner.h"
#include "Lexer.h"
//#include "constants.hpp"
#include "config.hpp"
#include "parser.tab.h"
#include "bash_color.h"

using namespace std;

const int SRC_IDX_OFFSET = 0;
const int CONFIG_IDX_OFFSET = 1;

#define lex yylex

static string g_config_file;
static string g_scan_file;
static bool initialized = false;
static Lexer lexer;

/**
 * @brief
 * @param
 * @return
 */
int lex(void)
{
    if(!initialized)
    {
        lexer.init(g_scan_file, g_config_file);
        initialized = true;
    }
    unsigned int token;
    lexer.get_token(token);
    return 0;
}

/**
 * @brief parse command line options
 * @param argc
 * @param argv
 * @return
 */
int parse_options(int argc, char* argv[])
{
    int opt;
    const char* optstring = "hV";
    const struct option longopts[] = {
        {"help",        no_argument,        NULL,   'h'},
        {"version",     no_argument,        NULL,   'V'},
        {NULL,          0,                  NULL,    0 }
    };

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
            default:
                cerr << "Unknown option" << endl;
                return 1;
        }
    }

    // configure scannner ...
    cout << "configure scannner ..." << optind << endl;

    cout << "load configuartion ..." << endl;
    string file = argv[optind + SRC_IDX_OFFSET];
    string config_file = ".config/default.txt";

    g_config_file = config_file;
    g_scan_file = file;

    if( argc > (optind + CONFIG_IDX_OFFSET) )
        config_file = argv[optind + CONFIG_IDX_OFFSET];
    cout << "configuartion loaded." << endl;

    // begin lexer ...
    Lexer lexer(file, config_file);
    cout << "sannner configured." << endl;

    cout << "scanning ..." << endl;
    unsigned int token = 0;
    while( lexer.get_token( token ) )
    {
        //lexer.print_token();
    }
    cout << "finished scanning. " << endl;

    cout << "dumping configuration ... " << endl;
    lexer.dump_config();
    cout << "configuration dumped." << endl;

    cout << "print expression ..." << endl;
    lexer.print_expr();
    cout << "printed." << endl;

    string s("testing std:string ....");

    string CUSTOM_FMT(FMT_FG_GREEN + FMT_ITALIC);
    cout << CUSTOM_FMT << s << FMT_FG_CYAN << "more text" << FMT_RESET <<  endl;
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

#ifdef BISON_BRIDGE
#define BISON_BRIDGE

#include <ctype.h>
#include <stdlib.h>
#define NUM 1
#define YYEOF 0

char* yylval;
int yyparse();

/**
 * @brief
 * @param
 * @return
 */
int yylex (void)
{
    int c = getchar ();
    /* skip white space */
    while (c == ' ' || c == '\t')
        c = getchar ();
    /* Process numbers. */
    if (c == '.' || isdigit (c))
    {
        ungetc (c, stdin);
        if (scanf ("%lf", &yylval) != 1)
            abort ();
        return NUM;
    }
    /* return end-of-input */
    else if (c == EOF)
        return YYEOF;
    /* return a single char */
    else
        return c;
}

/**
 * @brief
 * @param
 */
void yyerror (char const *s)
{
    printf("%s\n", s);
}


/**
 * @brief main function
 * @param argc : param count in argv
 * @param argv : command line parameters
 * @return 0 success : or error
 */

int __main(int argc, char* argv[])
{
    return yyparse();
}

#endif
