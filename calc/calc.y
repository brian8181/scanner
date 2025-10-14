%code top {
  #include <assert.h>
  #include <ctype.h>  /* isdigit. */
  #include <stdio.h>  /* printf. */
  #include <stdlib.h> /* abort. */
  #include <string.h> /* strcmp. */

  int yylex (void);
  void yyerror (char const *);
}

%define api.header.include {"calc.h"}

/* generate YYSTYPE from the types used in %token and %type  */
%define api.value.type union
%token <double> NUM "number"
%type  <double> expr term fact

/* Generate the parser description file (calc.output).  */
%verbose

/* error messages with details */
%define parse.error detailed

/* enable run-time traces (yydebug) */
%define parse.trace

/* formatting semantic values in debug traces  */
%printer { fprintf (yyo, "%g", $$); } <double>;

%% /* grammar */
input:
  %empty
| input line
;

line:
  '\n'
| expr '\n'  { printf ("%.10g\n", $1); }
| error '\n' { yyerrok; }
;

expr:
  expr '+' term { $$ = $1 + $3; }
| expr '-' term { $$ = $1 - $3; }
| term
;

term:
  term '*' fact { $$ = $1 * $3; }
| term '/' fact { $$ = $1 / $3; }
| fact
;

fact:
  "number"
| '(' expr ')' { $$ = $2; }
;

%%

int yylex (void)
{
  int c;
  /* ignore white space, get first nonwhite character */
  while ((c = getchar ()) == ' ' || c == '\t')
    continue;

  if (c == EOF)
    return 0;

  /* char starts a number => parse the number */
  if (c == '.' || isdigit (c))
    {
      ungetc (c, stdin);
      if (scanf ("%lf", &yylval.NUM) != 1)
        abort ();
      return NUM;
    }

  /* any other character is a token by itself */
  return c;
}

/* called by yyparse on error  */
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main (int argc, char const* argv[])
{
  /* enable parse traces on option -p */
  for (int i = 1; i < argc; ++i)
    if (!strcmp (argv[i], "-p"))
      yydebug = 1;
  return yyparse ();
}
