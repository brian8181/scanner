/**
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
#include <filesystem>
#include "utility.hpp"
#include "fileio.hpp"
#include "scanner.hpp"
#include "config.hpp"
#include "constants.hpp"

using namespace std;

// /**
//  * @brief default constructor
//  */
// Lexer::Lexer() {}

// /**
//  * @brief consturctor
//  * @param const string& file
//  */
// Lexer::Lexer(const string& file);
// {

// }

// /**
//  * @brief  load_config: load confiuration from file
//  * @param  const string &path
//  * @return void
//  */
// void Lexer::load_config( const string &path )
// {
//      const unsigned int ID_NAME_VALUE_PAIR = 0;
//     const unsigned int ID_NAME = 1;
//     const unsigned int ID_VALUE = 2;
//     const unsigned int ID_NUMERIC_LITERAL = 2;
//     const unsigned int ID_STRING_LITERAL = 3;

//     // get configuration file by lines
//     vector<string> lines;
//     lines = read_lines(path, lines);
//     // create one only section (global)
//     string section_name = "global";
//     map<string, string> section_map;
//     pair<string, map<string, string>> sp(section_name, section_map);
//     map_sections_config.insert(sp);

//     int len = lines.size();
//     for (int i = 0; i < len; ++i)
//     {
//         string line = lines[i];
//         regex rgx = regex(CONFIG_PAIR);
//         smatch match;
//         regex_match(line, match, rgx);

//         if (match[ID_NAME_VALUE_PAIR].matched)
//         {
//             // get name
//             string symbol_name = match[ID_NAME].str();
//             // get value
//             string value = (match[ID_VALUE].matched) ? match[ID_NUMERIC_LITERAL].str() : match[ID_STRING_LITERAL].str();
//             // create pair
//             pair<string, string> p(symbol_name, value);
//             map_sections_config[section_name].insert(p);
//         }
//     }
// }

// /**
//  * @brief start tokenizing file
//  * @param file
//  * @return void
//  */
// void Lexer::start(string file)
// {
//     cout << "Starting lexical analysis on file: " << file << endl;
//     stringstream sstrm;
//     ifstream strm(file, ios::in);
//     if (strm.is_open())
//     {
//         cout << file << "-> opened ..." << endl;
//         char c;
//         while (strm.get(c))
//         {
//             sstrm << c;
//         }
//     }
//     else
//     {
//         cout << "Error: Unable to open file for reading." << endl;
//         return;
//     }

//     string str = sstrm.str();
//     //  string s = "'[A-Za-z0-9_\\[\\]{}#()<>%:;.\"]'";
//     tokenize(EVERYTHING, str);

//     std::string s ("int abc; if( x == 2);");
//     std::smatch m;
//     std::regex e (EVERYTHING);
//     std::regex_search ( s, m, e );

//     for (unsigned i=0; i <m.size(); ++i)
//     {
//         std::cout << "match " << i << " (" << m[i] << ") ";
//         std::cout << "at position " << m.position(i) << std::endl;
//     }
// }

// /**
//  * @brief tokenize
//  * @param exp The regular expression to match
//  * @param text The text to search for matches
//  */
// void Lexer::tokenize(const string &exp, const string &text)
// {
//       cout << "tokenize ..." << endl;
//     regex rexp = regex(exp, regex::ECMAScript);

//     sregex_iterator begin = sregex_iterator(text.begin(), text.end(), rexp);
//     sregex_iterator end;
//     for (std::sregex_iterator iter = begin; iter != end; ++iter)
//     {
//         std::smatch match = *iter;
//         for (unsigned i=0; i < match.size(); ++i)
//         {
//             std::cout << "match " << i << " (" << match(i) << std::endl;
//             std::cout << "at position " << match.position(i) << std::endl;
//         }
//     }
// }

// map
map<string, string> map_config;
// todo : revert to no configuration sections!
map<string, map<string, string>> map_sections_config;
map<string, string> map_vars;
map<string, string> map_const;
map<string, vector<string>> map_arrays;
map<string, pair<string, vector<string>>> map_objects;
map<int, string> token_map;

void load_config(const string &path)
{
    const unsigned int ID_NAME_VALUE_PAIR = 0;
    const unsigned int ID_NAME = 1;
    const unsigned int ID_VALUE = 2;
    const unsigned int ID_NUMERIC_LITERAL = 2;
    const unsigned int ID_STRING_LITERAL = 3;

    // get configuration file by lines
    vector<string> lines;
    lines = read_lines(path, lines);
    // create one only section (global)
    string section_name = "global";
    map<string, string> section_map;
    pair<string, map<string, string>> sp(section_name, section_map);
    map_sections_config.insert(sp);

    int len = lines.size();
    for (int i = 0; i < len; ++i)
    {
        string line = lines[i];
        regex rgx = regex(CONFIG_PAIR);
        smatch match;
        regex_match(line, match, rgx);

        if (match[ID_NAME_VALUE_PAIR].matched)
        {
            // get name
            string symbol_name = match[ID_NAME].str();
            // get value
            string value = (match[ID_VALUE].matched) ? match[ID_NUMERIC_LITERAL].str() : match[ID_STRING_LITERAL].str();
            // create pair
            pair<string, string> p(symbol_name, value);
            map_sections_config[section_name].insert(p);
        }
    }
}

/**
 * @brief start the lexical analysis process
 * @param file The file to analyze
 */
void start(string file)
{
    cout << "Starting lexical analysis on file: " << file << endl;
    stringstream sstrm;
    ifstream strm(file, ios::in);
    if (strm.is_open())
    {
        cout << file << "-> opened ..." << endl;
        char c;
        while (strm.get(c))
        {
            sstrm << c;
        }
    }
    else
    {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    string str = sstrm.str();
    cout << EVERYTHING << endl;
    tokenize(EVERYTHING, str);
}

/**
 * @brief tokenize
 * @param exp The regular expression to match
 * @param text The text to search for matches
 */
void tokenize(const string &exp, const string &text)
{
    cout << "tokenize ..." << endl;
    regex rexp = regex(exp, regex::ECMAScript);

    sregex_iterator begin = sregex_iterator(text.begin(), text.end(), rexp);
    sregex_iterator end;
    for (std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch match = *iter;
        cout << "token = '" << match.str() << "' : pos = " << match.position(0) << endl;
        //for (unsigned i=0; i < match.size(); ++i)
        //{
            //std::cout << "match " << i << " (" << match(i) << std::endl;
            //std::cout << "at position " << match.position(i) << std::endl;
        //}
    }
}

int get_token(stringstream strm, string& token)
{
    while( !strm.eof() )
    {
        char c;
        strm.get(c);
        if(isspace(c))
        {
            if(!token.empty())
            {
                return 1;
            }
            continue;
        }

        switch(c)
        {
            case '(':
                token += c;
                return ID_OPEN_PAREN;
            case '{':
                token += c;
                return ID_OPEN_BRACE;
            case '[':
                token += c;
                return ID_OPEN_BRACKET;
            case ';':
                token += c;
                return ID_SEMI_COLON;
            case '.':
                token += c;
                return ID_DOT;
            case ':':
            case '^':
                token += c;
                return ID_CARROT;
            case '*':
                token += c;
                return ID_ASTERIK;
            case '+':
                token += c;
                return ID_PLUS;
            case '=':
                token += c;
                return ID_EQUAL;
            case '>':
                token += c;
                return ID_GREATER_THAN;
            case '&':
                token += c;
                return ID_AMPERSAND;
            case ')':
                token += c;
                return ID_CLOSE_PAREN;
            case '}':
                token += c;
                return ID_CLOSE_BRACE;
            case ']':
                token += c;
                return ID_CLOSE_BRACKET;
            case ',':
                token += c;
                return ID_COMMA;
            case '?':
                token += c;
                return ID_QUESTION_MARK;
            case '~':
                token += c;
                return ID_TILDE;
            case '%':
                token += c;
                return ID_PERCENT;
            case '/':
                token += c;
                return ID_FORWARD_SLASH;
            case '-':
                token += c;
                return ID_MINUS;
            case '<':
                token += c;
                return ID_LESS_THAN;
            case '!':
                token += c;
                return ID_LOGICAL_NOT;
            case '|':
                token += c;
                return ID_LOGICAL_OR;

            default:
            {
                if ( isalnum( c ) || c == '_' )
                {
                    continue;
                    }
                else
                    {
                    if ( !token.empty( ) )
                        {
                        return 1;
                        }
                    token += c;
                    return 1;
                    }
                break;
            }
        }
        }
    return ID_UNDEFINED;
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
    const char* optstring = "hVf:";
    const struct option longopts[] = {
        {"help",        no_argument,        NULL,   'h'},
        {"version",     no_argument,        NULL,   'V'},
        {"file",        required_argument,  NULL,   'f'},
        {NULL,          0,                  NULL,    0 }
    };
    string file = argv[1];
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

    map<string, string> pairs;
    get_name_value_pairs("test/config_match.txt", pairs);
    auto end = pairs.end();
    for (auto iter = pairs.begin(); iter != end; ++iter)
    {
        cout << "name = " << iter->first << " : value = " << iter->second << endl;
    }

    start(file);
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
