%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "parser.tab.h"
    #include "../src/scanner.h"

    int yylex(void);
    int yyerror(const char * s);

    /* string literal buffer */
    char buf[100];
    char *s;
%}

%union
{
    int ival;
    char* sval;
};

%type<sval> block
%token END_OF_FILE
%start file;

%%

file:
        blocks END_OF_FILE                          { printf("PARSER:file:blocks END_OF_FILE\n"); exit(0); }
               ;

blocks:
    block
    | blocks block
    ;

block:
    /* empty */
    block: '+' {}

%%

int yyerror(const char * s)
{
    fprintf(stderr, "%s\n", s);
    return 0;
};
