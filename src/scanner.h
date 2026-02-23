/**
 * @file scanner.hpp
 * @brief Header file for scanner.cpp
 * @author Your Name
 * @version 1.0
 * @date 2024-06-01
 */
#ifndef SCANNER_HPP_
#define SCANNER_HPP_

#include "../build/pparser.tab.hh"

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

/**
 * @brief
 * @param
 * @return
 */
int yylex ();

/**
 * @brief
 * @param
 */
//void yyerror (char const *);

//#define lex yylex

//yy::parser parser;
typedef yy::parser::symbol_type sym_t;

yy::parser::symbol_type llex();
// yy::parser::symbol_type llex()
// {
//     //int token = lex();
//
//     static int i = 0;
//     static int count = 0;
//     switch(int stage = count++)
//     {
//         case 0:
//             return yy::parser::make_NUMBER(42);
//         case 1:
//             return yy::parser::make_END();
//     }
//     return 0;
// }





#endif // _SCANNER_HPP_
