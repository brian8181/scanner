/**
 * @file    tokens.hpp
 * @version 0.0.1
 * @date    Wed Feb 11 17:23:05 CST 2026
 */
#ifndef TOKENS_HPP_
#define TOKENS_HPP_

#include "Lexer.hpp"

// VBAR                = \|
// COLON               = :
// LBRACKET            = \[
// RBRACKET            = \]
// LBRACE              = \{
// RBRACE              = \}
// LPAREN              = \(
// RPAREN              = \)
// COMMA               = ,
// SEMI_COLON          = ;
// DOUBLE_QUOTE        = \
// SINGLE_QUOTE        = '
// SLASH               = /
// BACK_SLASH          = \\
// AT                  = @
// PLUS                = \+
// MINUS               = -
// ASTERISK             = \*
// EQUAL               = =
// NOT_EQUAL           = !=
// MY_DOT                 = \.
// CARROT              = \^
// INDIRECT_MEMBER     = ->
// PERCENT             = %
// AMPERSAND           = &
// NOT                 = !
// AND                 = &&
// OR                  = \|\|
// DOLLAR              = \$
// LESS_THAN           = <
// LESS_THAN_EQUAL     = <=
// GREATER_THAN        = >
// GREATER_THAN_EQUAL  = >=
// NUMERIC_LITERAL     = [0-9]+
// REQUIRE             = require
// CONFIG_LOAD         = config_load
// INSERT              = insert
// INCLUDE             = include
// FILE_ATTRIB         = file
// ASSIGN              = assign
// VAR_ATTRIB          = var
// VALUE_ATTRIB        = value
// FROM_ATTRIB         = from
// ITEM_ATTRIB         = item
// KEY_ATTRIB          = key
// NAME_ATTRIB         = name
// CAPITALIZE          = captialize
// CAT                 = cat
// COUNT_CHARACTERS    = count_chacters
// COUNT_PARAGRAPHS    = count_paragraphs
// COUNT_SENTENCES     = count_sentences
// COUNT_WORDS         = count_words
// DATE_FORMAT         = date_format
// DEFAULT             = default
// ESCAPE              = escape
// INDENT              = indent
// LOWER               = lower
// UPPER               = upper
// STRIP               = strip
// NL2BR               = nl2br
// REGX_REPLACE        = regx_replace
// REPLACE             = replace
// SPACIFY             = spacify
// STRING_FORMAT       = string_format
// STRIP_TAGS          = strip_tags
// TRUNCATE            = truncate
// WORDWRAP            = wordwrap
// VALID_CHARS         = [A-Za-z0-9*@_.~+-]
// FIRST_CHAR          = [A-Za-z*@_.~+-]
// ID                  = [A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*
// SYMBOL              = \$[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*
// CONST_SYMBOL        = #[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#
// ARRAY               = [A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\]
// COMMENT             = \{[ \t]*\*[^*}]*\*[ \t]*\}
// FILE_NAME           = [A-Za-z0-9_.-~+#@]

static int index_ = 0;
static int id = 0;

//const int TSIZE = 12;
// token* tokens[TSIZE] =  {
//                     new token{ ++id, "VBAR", "string", 0, 0,       "\\|",          "\\|",    ++index, string("null") },
//                     new token{ ++id, "COLON", "string", 0, 0,       ":",          ":",    ++index, string("null") },
//                     new token{ ++id, "LBRACKET", "string", 0, 0,       "\\[",          "\\[",    ++index, string("null") },
//                     new token{ ++id, "RBRACKET", "string", 0, 0,       "\\]",          "\\]",    ++index, string("null") },
//                     new token{ ++id, "LBRACE", "string", 0, 0,       "\\{",          "\\{",    ++index, string("null") },
//                     new token{ ++id, "RBRACE", "string", 0, 0,       "\\}",          "\\}",    ++index, string("null") },
//                     new token{ ++id, "ASTERISK",    "string", 0, 0,       "\\*",          "\\*",    ++index, string("null") },
//                     new token{ ++id, "NOT_EQUAL",    "string", 0, 0,   "!=",         "!=",      ++index, string("null") },
//                     new token{ ++id, "EQUAL",    "string", 0, 0,       "=",              "=",      ++index, string("null") },
//                     new token{ ++id, "COMMA",    "string", 0, 0,       "\\,",          "\\,",    ++index, string("null") },
//                     new token{ ++id, "MY_DOT",      "string", 0, 0,       "\\.",          "\\.",    ++index, string("null") },
//                     new token{ ++id, "SYMBOL",   "string", 0, 0,       "\\$[a-zA-Z]+", "\\$abc", ++index, string("null") }
//                 };

inline vector tokens = {
                    new token{  1,  "VBAR",          "string",   0, 0,       "\\|",           "\\|",            1, string("null") },
                    new token{  2,  "COLON",         "string",   0, 0,       ":",             ":",              2, string("null") },
                    new token{  3,  "DOUBLE_QUOTE",  "string",   0, 0,       "\"",            "\"",             3, string("null") },
                    new token{  4,  "LBRACKET",      "string",   0, 0,       "\\[",           "\\[",            4, string("null") },
                    new token{  5,  "RBRACKET",      "string",   0, 0,       "\\]",           "\\]",            5, string("null") },
                    new token{  6,  "LBRACE",        "string",   0, 0,       "\\{",           "\\{",            6, string("null") },
                    new token{  7,  "RBRACE",        "string",   0, 0,       "\\}",           "\\}",            7, string("null") },
                    new token{  8,  "LPAREN",        "string",   0, 0,       "\\(",           "\\(",            8, string("null") },
                    new token{  9,  "RPAREN",        "string",   0, 0,       "\\)",           "\\)",            9, string("null") },
                    new token{ 10,  "ASTERISK",      "string",   0, 0,       "\\*",           "\\*",           10, string("null") },
                    new token{ 11,  "NOT_EQUAL",     "string",   0, 0,       "!=",            "!=",            11, string("null") },
                    new token{ 12,  "EQUAL",         "string",   0, 0,       "=",             "=",             12, string("null") },
                    new token{ 13,  "COMMA",         "string",   0, 0,       "\\,",           "\\,",           13, string("null") },
                    new token{ 14,  "MY_DOT",           "string",   0, 0,       "\\.",           "\\.",           14, string("null") },
                    new token{ 15,  "CARROT",        "string",   0, 0,       "\\^",           "\\^",           15, string("null") },
                    new token{ 16,  "QUESTION_MARK", "string",   0, 0,       "\\?",           "\\?",           16, string("null") },
                    new token{ 17,  "BACKSLASH",     "string",   0, 0,       "\\\\",          "\\\\",          17, string("null") },
                    new token{ 18,  "PLUS",          "string",   0, 0,       "\\+",           "\\+",            18, string("null") },
                    new token{ 19,  "MINUS",         "string",   0, 0,       "-",             "-",              19, string("null") },
                    new token{ 20,  "SYMBOL",        "string",   0, 0,       "\\$[a-zA-Z]+",  "\\$abc",        20, string("null") },
                    new token{ 23,  "DOLLAR_SIGN",   "string",   0, 0,       "\\$",           "$",             21, string("null") },
                    new token{ 21,  "WHITESPACE",    "string",   0, 0,       "[ \\t]",        "\\t",           22, string("null") },
                    new token{ 22,  "ANYTHING",      "string",   0, 0,       ".",             "~#",            23, string("null") },

                    //new token{ 16, "EOF", "string",   0, 0,          "0",               "0", 16, string("null" }
                };

// token* tokens[TSIZE] =  {
//                     new token{ ++id, "VBAR", "string", 0, 0,       "\\|",          "\\|",    ++index, string("null") },
//                     new token{ ++id, "NOT_EQUAL",    "string", 0, 0,   "!=",         "!=",      ++index, string("null") },
//                     new token{ ++id, "EQUAL",    "string", 0, 0,       "=",              "=",      ++index, string("null") } };

// .[{()\*+?|^$
// [[.NUL.]] matches a NUL character.
//const string expression = "(\\|)|(:)|(\\[)|(\\])|(\\{)|(\\})|(\\*)|(!=)|(\\,)|(\\.)|(\\$[a-zA-Z]+)";
const string expression =   R"((\|)|(:)|(\[)|(\])|(\{)|(\})|(\*)|(!=)|(=)|(\,)|(\.)|(\$[a-zA-Z]+)|([ \t])|(.))";
//                          "(\\|)|(:)|(\\[)|(\\])|(\\{)|(\\})|(\\*)|(!=)|(=)|(\\,)|(\\.)|(\\$[a-zA-Z]+)|([ \\t]+)"

// states
#define INITIAL_ 0
#define COMMENT_ 1
#define ESCAPED_  2

// tokens
#define VBAR                10
#define COLON               20
#define LBRACKET            30
#define RBRACKET            40
#define LBRACE              50
#define RBRACE              60
#define LPAREN              70
#define RPAREN              80
#define COMMA               90
//#define SEMI_COLON         100
#define DOUBLE_QUOTE       110
#define SINGLE_QUOTE       120
#define SLASH              130
#define BACK_SLASH         140
#define AT                 150
//#define PLUS               160
#define MINUS              170
#define ASTERIK            180
#define EQUAL              190
#define NOT_EQUAL          200
#define MY_DOT                210
#define INDIRECT_MEMBER_OPER    220
#define PERCENT            230
#define AMPERSAND          240
#define NOT                250
#define AND                260
#define OR                 270
#define LESS_THAN          280
#define LESS_THAN_EQUAL    290
#define GREATER_THAN       300
#define GREATER_THAN_EQUAL 400
#define NUMERIC_LITERAL    410
#define REQUIRE            420
#define CONFIG_LOAD        430
#define INSERT             440
#define INCLUDE            450
#define FILE_ATTRIB        460
#define ASSIGN             470
#define VAR_ATTRIB         480
#define VALUE_ATTRIB       490
#define FROM_ATTRIB        500
#define ITEM_ATTRIB        510
#define KEY_ATTRIB         520
#define NAME_ATTRIB        530
#define CAPITALIZE         540
#define CAT                550
#define COUNT_CHARACTERS   560
#define COUNT_PARAGRAPHS   570
#define COUNT_SENTENCES    580
#define COUNT_WORDS        590
#define DATE_FORMAT        600
#define DEFAULT            610
#define ESCAPE             620
#define INDENT             630
#define LOWER              640
#define UPPER              650
#define STRIP              660
#define NL2BR              670
#define REGX_REPLACE       680
#define REPLACE            690
#define SPACIFY            700
#define STRING_FORMAT      710
#define STRIP_TAGS         720
#define TRUNCATE           730
#define WORDWRAP           740
#define VALID_CHARS        750
#define FIRST_CHAR         760
#define ID                 770
#define SYMBOL             780
#define CONST_SYMBOL       790
#define ARRAY              800
#define COMMENT            810
#define FILE_NAME          820
#define WHITESPACE         822
#define SKIP_TOKEN           -1
#define ERROR               -2
#define SCAN_EOF             0
#define ANYTHING            -3

inline int on_state(const state_t& s )
{
    switch (s.id)
    {
        case INITIAL_:
            return INITIAL_;
    }
    return ERROR;
}

inline int on_token_action(const state_t& s, const token_def& tok)
{
    switch (s.id)
    {
        case INITIAL_:
        {
            switch(tok.id)
            {
                case VBAR:
                    cout << "VBAR" << endl;
                    return VBAR;
                case COLON:
                case LBRACKET:
                    cout << "LBRACKET" << endl;
                    return LBRACKET;
                case RBRACKET:
                case LBRACE:
                case RBRACE:
                case LPAREN:
                case RPAREN:
                case COMMA:
        //        case SEMI_COLON:
                case DOUBLE_QUOTE:
                case SINGLE_QUOTE:
                case SLASH:
                case BACK_SLASH:
                case AT:
 //               case PLUS:
                case MINUS:
                case ASTERIK:
                case EQUAL:
                case NOT_EQUAL:
                case MY_DOT:
                case INDIRECT_MEMBER_OPER:
                case PERCENT:
                case AMPERSAND:
                case NOT:
                case AND:
                case OR:
                case LESS_THAN:
                case LESS_THAN_EQUAL:
                case GREATER_THAN:
                case GREATER_THAN_EQUAL:
                case NUMERIC_LITERAL:
                case REQUIRE:
                case CONFIG_LOAD:
                case INSERT:
                case INCLUDE:
                case FILE_ATTRIB:
                case ASSIGN:
                case VAR_ATTRIB:
                case VALUE_ATTRIB:
                case FROM_ATTRIB:
                case ITEM_ATTRIB:
                case KEY_ATTRIB:
                case NAME_ATTRIB:
                case CAPITALIZE:
                case CAT:
                case COUNT_CHARACTERS:
                case COUNT_PARAGRAPHS:
                case COUNT_SENTENCES:
                case COUNT_WORDS:
                case DATE_FORMAT:
                case DEFAULT:
                case ESCAPE:
                case INDENT:
                case LOWER:
                case UPPER:
                case STRIP:
                case NL2BR:
                case REGX_REPLACE:
                case REPLACE:
                case SPACIFY:
                case STRING_FORMAT:
                case STRIP_TAGS:
                case TRUNCATE:
                case WORDWRAP:
                case VALID_CHARS:
                case FIRST_CHAR:
                case ID:
                case SYMBOL:
                case CONST_SYMBOL:
                case ARRAY:
                case COMMENT:
                case FILE_NAME:
                    return tok.id;
                case WHITESPACE:
                case SKIP_TOKEN:
                    return SKIP_TOKEN;
                case SCAN_EOF:
                    return EOF;
                case ANYTHING:
                    cout << "error: " << tok.value << "is invalid." << endl;
                    return ERROR;
                default:
                    return ERROR;
            }
        }
        default: ;
    }
    return ERROR;
}
#endif
