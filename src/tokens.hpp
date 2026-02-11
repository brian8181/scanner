// File Name:  tokens.hpp
// Build Date:
// Version:    0.0.1

#ifndef _TOKENS_HPP
#define _TOKENS_HPP

#include "Lexer.hpp"

//int on_token_action(const state& s, token& tok);

// VBAR                = |
// COLON               = :
// LBRACKET            = [
// RBRACKET            = ]
// LBRACE              = {
// RBRACE              = }
// LPAREN              = (
// RPAREN              = )
// COMMA               = ,
// SEMI_COLON          = ;
// DOUBLE_QUOTE        = \
// SINGLE_QUOTE        = '
// SLASH               = /
// BACK_SLASH          = \\
// AT                  = @
// PLUS                = +
// MINUS               = -
// ASTERIK             = *
// EQUAL               = =
// NOT_EQUAL           = !=
// DOT                 = .
// INDIRECT_MEMBER     = ->
// PERCENT             = %
// AMPERSAND           = &
// NOT                 = !
// AND                 = &&
// OR                  = ||
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

static int index = 0;
static int id = index + 2;

//const int TSIZE = 12;
// token* tokens[TSIZE] =  {
//                     new token{ ++id, "VBAR", "string", 0, 0,       "\\|",          "\\|",    ++index, string("null") },
//                     new token{ ++id, "COLON", "string", 0, 0,       ":",          ":",    ++index, string("null") },
//                     new token{ ++id, "LBRACKET", "string", 0, 0,       "\\[",          "\\[",    ++index, string("null") },
//                     new token{ ++id, "RBRACKET", "string", 0, 0,       "\\]",          "\\]",    ++index, string("null") },
//                     new token{ ++id, "LBRACE", "string", 0, 0,       "\\{",          "\\{",    ++index, string("null") },
//                     new token{ ++id, "RBRACE", "string", 0, 0,       "\\}",          "\\}",    ++index, string("null") },
//                     new token{ ++id, "ASTERICK",    "string", 0, 0,       "\\*",          "\\*",    ++index, string("null") },
//                     new token{ ++id, "NOT_EQUAL",    "string", 0, 0,   "!=",         "!=",      ++index, string("null") },
//                     new token{ ++id, "EQUAL",    "string", 0, 0,       "=",              "=",      ++index, string("null") },
//                     new token{ ++id, "COMMA",    "string", 0, 0,       "\\,",          "\\,",    ++index, string("null") },
//                     new token{ ++id, "DOT",      "string", 0, 0,       "\\.",          "\\.",    ++index, string("null") },
//                     new token{ ++id, "SYBMOL",   "string", 0, 0,       "\\$[a-zA-Z]+", "\\$abc", ++index, string("null") }
//                 };

vector<token*> tokens = {
                    new token{ ++id, "VBAR",       "string", 0, 0,       "\\|",          "\\|",    ++index, string("null") },
                    new token{ ++id, "COLON",      "string", 0, 0,       ":",            ":",      ++index, string("null") },
                    new token{ ++id, "LBRACKET",   "string", 0, 0,       "\\[",          "\\[",    ++index, string("null") },
                    new token{ ++id, "RBRACKET",   "string", 0, 0,       "\\]",          "\\]",    ++index, string("null") },
                    new token{ ++id, "LBRACE",     "string", 0, 0,       "\\{",          "\\{",    ++index, string("null") },
                    new token{ ++id, "RBRACE",     "string", 0, 0,       "\\}",          "\\}",    ++index, string("null") },
                    new token{ ++id, "ASTERICK",   "string", 0, 0,       "\\*",          "\\*",    ++index, string("null") },
                    new token{ ++id, "NOT_EQUAL",  "string", 0, 0,       "!=",           "!=",     ++index, string("null") },
                    new token{ ++id, "EQUAL",      "string", 0, 0,       "=",            "=",      ++index, string("null") },
                    new token{ ++id, "COMMA",      "string", 0, 0,       "\\,",          "\\,",    ++index, string("null") },
                    new token{ ++id, "DOT",        "string", 0, 0,       "\\.",          "\\.",    ++index, string("null") },
                    new token{ ++id, "SYBMOL",     "string", 0, 0,       "\\$[a-zA-Z]+", "\\$abc", ++index, string("null") },
                    new token{ ++id, "WHITESPACE", "string", 0, 0,       "[ \\t]+",      "\\t",    ++index, string("null") }
                };

// token* tokens[TSIZE] =  {
//                     new token{ ++id, "VBAR", "string", 0, 0,       "\\|",          "\\|",    ++index, string("null") },
//                     new token{ ++id, "NOT_EQUAL",    "string", 0, 0,   "!=",         "!=",      ++index, string("null") },
//                     new token{ ++id, "EQUAL",    "string", 0, 0,       "=",              "=",      ++index, string("null") } };

//const string expression = "(\\|)|(:)|(\\[)|(\\])|(\\{)|(\\})|(\\*)|(!=)|(\\,)|(\\.)|(\\$[a-zA-Z]+)";
const string expression =   "(\\|)|(:)|(\\[)|(\\])|(\\{)|(\\})|(\\*)|(!=)|(=)|(\\,)|(\\.)|(\\$[a-zA-Z]+)|([ \\t]+)";
//                          "(\\|)|(:)|(\\[)|(\\])|(\\{)|(\\})|(\\*)|(!=)|(=)|(\\,)|(\\.)|(\\$[a-zA-Z]+)|([ \\t]+)"

#define VBAR                10
#define COLON               20
#define LBRACKET            30
#define RBRACKET            40
#define LBRACE              50
#define RBRACE              60
#define LPAREN              70
#define RPAREN              80
#define COMMA               90
#define SEMI_COLON         100
#define DOUBLE_QUOTE       110
#define SINGLE_QUOTE       120
#define SLASH              130
#define BACK_SLASH         140
#define AT                 150
#define PLUS               160
#define MINUS              170
#define ASTERIK            180
#define EQUAL              190
#define NOT_EQUAL          200
#define DOT                210
#define INDIRECT_MEMBER    220
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
#define NO_ACTION           -1
#define ERROR               -2
#define SCAN_EOF             0

int on_token_action(const state& s, token& tok)
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
        case SEMI_COLON:
        case DOUBLE_QUOTE:
        case SINGLE_QUOTE:
        case SLASH:
        case BACK_SLASH:
        case AT:
        case PLUS:
        case MINUS:
        case ASTERIK:
        case EQUAL:
        case NOT_EQUAL:
        case DOT:
        case INDIRECT_MEMBER:
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
        case NO_ACTION:
            return NO_ACTION;
        case SCAN_EOF:
            return EOF;
        default:
            return ERROR;
    }
    return ERROR;
}
#endif
