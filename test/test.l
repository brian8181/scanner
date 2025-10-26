
%{
#include <math.h>
%}

TAG \$\{.*\}
%x ESCAPE

%%

{TAG} {
        // replace tags
        printf("BOO");
    }
<<EOF>>

%%

int main(int  argc, char** argv )
{
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
}
