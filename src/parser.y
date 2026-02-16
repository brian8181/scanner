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

%type<sval> stmt
%type<ival> literal add
%token<ival> INTEGER
%token END_OF_FILE PLUS SEMI_COLON NEWLINE
%start file

%%

file:
       stmts YYEOF                          { printf("PARSER:file:blocks END_OF_FILE\n"); exit(0); }
               ;

stmts:
    stmt
    | stmts stmt
    ;

stmt:
    add SEMI_COLON { }

add:
    literal PLUS literal {
        printf("%s + %s\n", $1, $3);
        $$ = $1 + $3;
    }

literal:
    INTEGER {
                printf("Literal: %d\n", $1);
                $$=$1;
           }

%%

int yyerror(const char * s)
{
    fprintf(stderr, "%s\n", s);
    return 0;
};
