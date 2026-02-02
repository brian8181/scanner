#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "lex.hpp"
#include "scanner.hpp"

//char* TOKS[] = { "3", "+", "2", ";", "\n", "\0" };
//symbol_type (int token, const value_type& value)
//int yylex (value_type* yylval, type1 arg1, . . .)
typedef yy::parser::symbol_type sym_t;

yy::parser::symbol_type llex()
{
    //int token = lex();

    static int i = 0;
    static int count = 0;
    switch(int stage = count++)
    {
    case 0:
        return yy::parser::make_NUMBER(42);
    case 1:
        return yy::parser::make_END();
    }
    return 0;
}
