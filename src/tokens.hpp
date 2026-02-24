/**
 * @file    tokens.hpp
 * @version 0.0.1
 * @date    Wed Feb 11 17:23:05 CST 2026
 */
#ifndef TOKENS_HPP_
#define TOKENS_HPP_

#include <iostream>
#include "Lexer.hpp"
#include "pparser.tab.hh"

using std::cerr;
using std::cout;
using std::endl;

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
    new token{1, "VBAR", "string", 0, 0, "\\|", "\\|", 1, string("null")},
    new token{2, "COLON", "string", 0, 0, ":", ":", 2, string("null")},
    new token{3, "DOUBLE_QUOTE", "string", 0, 0, "\"", "\"", 3, string("null")},
    new token{4, "LBRACKET", "string", 0, 0, "\\[", "\\[", 4, string("null")},
    new token{5, "RBRACKET", "string", 0, 0, "\\]", "\\]", 5, string("null")},
    new token{6, "LBRACE", "string", 0, 0, "\\{", "\\{", 6, string("null")},
    new token{7, "RBRACE", "string", 0, 0, "\\}", "\\}", 7, string("null")},
    new token{8, "LPAREN", "string", 0, 0, "\\(", "\\(", 8, string("null")},
    new token{9, "RPAREN", "string", 0, 0, "\\)", "\\)", 9, string("null")},
    new token{10, "ASTERISK", "string", 0, 0, "\\*", "\\*", 10, string("null")},
    new token{11, "NOT_EQUAL", "string", 0, 0, "!=", "!=", 11, string("null")},
    new token{12, "EQUAL", "string", 0, 0, "=", "=", 12, string("null")},
    new token{13, "COMMA", "string", 0, 0, "\\,", "\\,", 13, string("null")},
    new token{14, "MY_DOT", "string", 0, 0, "\\.", "\\.", 14, string("null")},
    new token{15, "CARROT", "string", 0, 0, "\\^", "\\^", 15, string("null")},
    new token{16, "QUESTION_MARK", "string", 0, 0, "\\?", "\\?", 16, string("null")},
    new token{17, "BACKSLASH", "string", 0, 0, "\\\\", "\\\\", 17, string("null")},
    new token{18, "PLUS", "string", 0, 0, "\\+", "\\+", 18, string("null")},
    new token{19, "MINUS", "string", 0, 0, "-", "-", 19, string("null")},
    new token{20, "SYMBOL", "string", 0, 0, "\\$[a-zA-Z]+", "\\$abc", 20, string("null")},
    new token{23, "DOLLAR_SIGN", "string", 0, 0, "\\$", "$", 21, string("null")},
    new token{21, "WHITESPACE", "string", 0, 0, "[ \\t]", "\\t", 22, string("null")},
    new token{22, "ANYTHING", "string", 0, 0, ".", "~#", 23, string("null")}
};

/**
 * @brief lex states
**/
inline vector state_initial = {
    token{6, "LBRACE", "string", 0, 0, "\\{", "\\{", 6, string("null")},
    token{22, "COMMENT", "string", 0, 0, R"(\{[ \t]*\*[^*}]*\*[ \t]*\})", R"(\\\* test \\*\)", 23, string("null")},
    token{22, "UNESCAPED_TEXT", "string", 0, 0, R"([^{]+)", "anything", 23, string("null")}
};

inline vector state_comment = {

/**
 */
new token{1, "VBAR", "string", 0, 0, "\\|", "\\|", 1, string("null")},
new token{2, "COLON", "string", 0, 0, ":", ":", 2, string("null")},
new token{10, "ASTERISK", "string", 0, 0, "\\*", "\\*", 10, string("null")},
new token{13, "COMMA", "string", 0, 0, "\\,", "\\,", 13, string("null")},
new token{14, "DOT_", "string", 0, 0, "\\.", "\\.", 14, string("null")},
new token{15, "CARROT", "string", 0, 0, "\\^", "\\^", 15, string("null")},
new token{16, "QUESTION_MARK", "string", 0, 0, "\\?", "\\?", 16, string("null")},
new token{17, "BACKSLASH", "string", 0, 0, "\\\\", "\\\\", 17, string("null")},
new token{18, "PLUS", "string", 0, 0, "\\+", "\\+", 18, string("null")},
new token{19, "MINUS", "string", 0, 0, "-", "-", 19, string("null")},
new token{20, "SYMBOL", "string", 0, 0, "\\$[a-zA-Z]+", "\\$abc", 20, string("null")},
new token{23, "DOLLAR_SIGN", "string", 0, 0, "\\$", "$", 21, string("null")},

/**
 */
new token{4, "LBRACKET", "string", 0, 0, "\\[", "\\[", 4, string("null")},
new token{5, "RBRACKET", "string", 0, 0, "\\]", "\\]", 5, string("null")},
new token{6, "LBRACE", "string", 0, 0, "\\{", "\\{", 6, string("null")},
new token{7, "RBRACE", "string", 0, 0, "\\}", "\\}", 7, string("null")},
new token{8, "LPAREN", "string", 0, 0, "\\(", "\\(", 8, string("null")},
new token{9, "RPAREN", "string", 0, 0, "\\)", "\\)", 9, string("null")},

/**
 */
new token{11, "NOT_EQUAL", "string", 0, 0, "!=", "!=", 11, string("null")},
new token{12, "EQUAL", "string", 0, 0, "=", "=", 12, string("null")},
new token{13, "GREATER_THAN", "string", 0, 0, ">", ">", 19, string("null")},
new token{14, "LESS_THAN", "string", 0, 0, "<", "<", 19, string("null")},
new token{15, "GREATER_THAN_EQUAL", "string", 0, 0, ">=", ">=", 19, string("null")},
new token{16, "LESS_THAN_EQUAL", "string", 0, 0, "<=", "<=", 19, string("null")},
new token{17, "GREATER_THAN", "string", 0, 0, ">", ">", 19, string("null")},
new token{18, "SINGLE_QUOTE", "string", 0, 0, "'", "'", 19, string("null")},
new token{19, "DOUBLE_QUOTE", "string", 0, 0, "\"", "\"", 19, string("null")},
new token{20, "SLASH", "string", 0, 0, "/", "/", 19, string("null")},
new token{21, "BACK_SLASH", "string", 0, 0, "\\", "\\", 19, string("null")},

/**
 */
new token{22, "NUMERIC_LITERAL", "string", 0, 0, "[0-9]+", "12345", 19, string("null")},
new token{23, "ARRAY", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\])", "/", 19, string("null")},
new token{24, "ID", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/", 19, string("null")},
new token{ 25, "SYMBOL", "string", 0, 0, R"(\$[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/", 19, string("null")},
new token{26, "CONST_SYMBOL", "string", 0, 0, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", "/", 19, string("null")},
new token{27, "UNESCAPED_TEXT", "string", 0, 0, R"([^{]+)", "testing ...", 19, string("null")},
new token{28, "WHITESPACE", "string", 0, 0, "[ \\t]", "\\t", 22, string("null")},
new token{29, "ANYTHING", "string", 0, 0, ".", "~#", 23, string("null")},

/**
 */
new token{30, "REQUIRE", "string", 0, 0, "require", "require", 23, string("null")},
new token{31, "INCLUDE", "string", 0, 0, "include", "include", 23, string("null")},
new token{32, "CONFIG_LOAD", "string", 0, 0, "config_load", "config_load", 23, string("null")}
};

inline vector state_escaped = {
    // new token{3, "DOUBLE_QUOTE", "string", 0, 0, "\"", "\"", 3, string("null")},
    // new token{3, "SINGLE_QUOTE", "string", 0, 0, "'", "'", 3, string("null")},
    // new token{3, "AT", "string", 0, 0, "@", "@", 3, string("null")},

    new token{1, "VBAR", "string", 0, 0, "\\|", "\\|", 1, string("null")},
    new token{2, "COLON", "string", 0, 0, ":", ":", 2, string("null")},
    new token{4, "LBRACKET", "string", 0, 0, "\\[", "\\[", 4, string("null")},
    new token{5, "RBRACKET", "string", 0, 0, "\\]", "\\]", 5, string("null")},
    new token{6, "LBRACE", "string", 0, 0, "\\{", "\\{", 6, string("null")},
    new token{7, "RBRACE", "string", 0, 0, "\\}", "\\}", 7, string("null")},
    new token{8, "LPAREN", "string", 0, 0, "\\(", "\\(", 8, string("null")},
    new token{9, "RPAREN", "string", 0, 0, "\\)", "\\)", 9, string("null")},
    new token{10, "ASTERISK", "string", 0, 0, "\\*", "\\*", 10, string("null")},
    new token{11, "NOT_EQUAL", "string", 0, 0, "!=", "!=", 11, string("null")},
    new token{12, "EQUAL", "string", 0, 0, "=", "=", 12, string("null")},
    new token{13, "COMMA", "string", 0, 0, "\\,", "\\,", 13, string("null")},
    new token{14, "DOT", "string", 0, 0, "\\.", "\\.", 14, string("null")},
    // new token{15, "CARROT", "string", 0, 0, "\\^", "\\^", 15, string("null")},
    // new token{16, "QUESTION_MARK", "string", 0, 0, "\\?", "\\?", 16, string("null")},
    // new token{17, "BACKSLASH", "string", 0, 0, "\\\\", "\\\\", 17, string("null")},
    // new token{18, "PLUS", "string", 0, 0, "\\+", "\\+", 18, string("null")},
    // new token{19, "MINUS", "string", 0, 0, "-", "-", 19, string("null")},
    // new token{23, "DOLLAR_SIGN", "string", 0, 0, "\\$", "$", 21, string("null")},
    // new token{25, "GREATER_THAN", "string", 0, 0, ">", ">", 19, string("null")},
    // new token{19, "LESS_THAN", "string", 0, 0, "<", "<", 19, string("null")},
    // new token{19, "GREATER_THAN_EQUAL", "string", 0, 0, ">=", ">=", 19, string("null")},
    // new token{19, "LESS_THAN_EQUAL", "string", 0, 0, "<=", "<=", 19, string("null")},
    // new token{19, "GREATER_THAN", "string", 0, 0, ">", ">", 19, string("null")},
    //
    // new token{19, "SINGLE_QUOTE", "string", 0, 0, "'", "'", 19, string("null")},
    // new token{19, "DOUBLE_QUOTE", "string", 0, 0, "\"", "\"", 19, string("null")},
    // new token{19, "SLASH", "string", 0, 0, "/", "/", 19, string("null")},
    // new token{19, "BACK_SLASH", "string", 0, 0, "\\", "\\", 19, string("null")},
    //
    // new token{19, "NUMERIC_LITERAL", "string", 0, 0, "[0-9]+", "12345", 19, string("null")},
    // new token{19, "ARRAY", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\])", "/", 19, string("null")},
    // new token{19, "ID", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/", 19, string("null")},
    // new token{20, "SYMBOL", "string", 0, 0, "\\$[a-zA-Z]+", "\\$abc", 20, string("null")},
    // //new token{19, "SYMBOL", "string", 0, 0, R"(\$[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/", 19, string("null")},
    // new token{19, "CONST_SYMBOL", "string", 0, 0, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", "/", 19, string("null")},
    // new token{19, "UNESCAPED_TEXT", "string", 0, 0, R"([^{]+)", "testing ...", 19, string("null")},
    // new token{21, "WHITESPACE", "string", 0, 0, "[ \\t]", "\\t", 22, string("null")},
    // new token{22, "ANYTHING", "string", 0, 0, ".", "~#", 23, string("null")}


};

// .[{()\*+?|^$
// [[.NUL.]] matches a NUL character.
//                           "(\\|)|(:)|(\\[)|(\\])|(\\{)|(\\})|(\\*)|(!=)|(=)|(\\,)|(\\.)|(\\$[a-zA-Z]+)|([ \\t]+)"
//const string expression = R"((\|)|(:)|(\[)|(\])|(\{)|(\})|(\*)|(!=)|(=)|(\,)|(\.)|(\$[a-zA-Z]+)|([ \t])|(.))";

// states
#define INITIAL_ 0
#define COMMENT_ 1
#define ESCAPED_  3
#define DOUBLE_QUOTED 4
#define SINGLE_QUOTED 5
#define INCLUDING 6
#define IF_BLOCK 7
#define IF_CONDITION 8

inline map<int, vector<token_def *> > state_tokens_tab = {
    {INITIAL_, {state_initial}}, {COMMENT_, {state_comment}}, {ESCAPED_, {state_escaped}}
};

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
#define SKIP_TOKEN           (-1)
#define ERROR               (-2)
#define SCAN_EOF             0
#define ANYTHING            (-3)

inline int Lexer::on_state(const state_t &s) {
    switch (s.id) {
        case INITIAL_:
            return INITIAL_;
    }
    return ERROR;
}

inline yy::parser::symbol_type Lexer::on_token_action(const state_t &s, const token_def &tok)
{
    switch (s.id)
    {
        case INITIAL_:
        {
            switch (tok.id)
            {
                case LBRACKET:
                    cout << "LBRACKET" << endl;
                    return yy::parser::make_LBRACE("{");
                    //return LBRACKET;
                case COMMENT:
                    //case WHITESPACE:
                case SKIP_TOKEN:
                    //return SKIP_TOKEN;
                case SCAN_EOF:
                    //parser::make_END();
                    return EOF;
                case ANYTHING:
                    cout << tok.value << endl;
                    //return ERROR;
                default:
                    return yy::parser::make_END();
            }
            return yy::parser::make_END();
        }
        case ESCAPED_:
        {
            switch (tok.id)
            {
                case DOUBLE_QUOTE:
                    cout << "DOUBLE_QUOTE" << endl;
                    break;
                case SINGLE_QUOTE:
                    cout << "SINGLE_QUOTE" << endl;
                    break;
                case SLASH:
                    cout << "SLASH" << endl;
                    break;
                case BACK_SLASH:
                    cout << "BACK_SLASH" << endl;
                    break;
                case AT:
                    cout << "AT" << endl;
                    break;
                    //case PLUS            : break;
                case MINUS:
                    cout << "MINUS" << endl;
                    break;
                case ASTERIK:
                    cout << "ASTERIK" << endl;
                    break;
                case EQUAL:
                    cout << "EQUAL" << endl;
                    break;
                case NOT_EQUAL:
                    cout << "NOT_EQUAL" << endl;
                    break;
                    //case DOT             : break;
                    //case INDIRECT_MEMBER_SELECT: break;
                case PERCENT:
                    cout << "PERCENT" << endl;
                    break;
                case AMPERSAND:
                    cout << "AMPERSAND" << endl;
                    break;
                case NOT:
                    cout << "NOT" << endl;
                    break;
                case AND:
                    cout << "AND" << endl;
                    break;
                case OR:
                    cout << "OR:" << endl;
                    break;
                case LESS_THAN:
                    cout << "LESS_THAN" << endl;
                    break;
                case LESS_THAN_EQUAL:
                    cout << "LESS_THAN_EQUAL" << endl;
                    break;
                case GREATER_THAN:
                    cout << "GREATER_THAN" << endl;
                    break;
                case GREATER_THAN_EQUAL:
                    cout << "GREATER_THAN_EQUAL" << endl;
                    break;
                case NUMERIC_LITERAL:
                    cout << "NUMERIC_LITERAL" << endl;
                    break;
                case REQUIRE:
                    cout << "REQUIRE" << endl;
                    break;
                case CONFIG_LOAD:
                    cout << "CONFIG_LOAD" << endl;
                    break;
                case INSERT:
                    cout << "INSERT" << endl;
                    break;
                case INCLUDE:
                    cout << "INCLUDE" << endl;
                    break;
                case FILE_ATTRIB:
                    cout << "FILE_ATTRIB" << endl;
                    break;
                case ASSIGN:
                    cout << "ASSIGN" << endl;
                    break;
                case VAR_ATTRIB:
                    cout << "VAR_ATTRIB" << endl;
                    break;
                case VALUE_ATTRIB:
                    cout << "VALUE_ATTRIB" << endl;
                    break;
                case FROM_ATTRIB:
                    cout << "FROM_ATTRIB" << endl;
                    break;
                case ITEM_ATTRIB:
                    cout << "ITEM_ATTRIB" << endl;
                    break;
                case KEY_ATTRIB:
                    cout << "KEY_ATTRIB" << endl;
                    break;
                case NAME_ATTRIB:
                    cout << "NAME_ATTRIB" << endl;
                    break;
            }
        }
    }
    return yy::parser::make_END();
}

//  enum yytokentype
//  {
//      YYEMPTY = -2,
//      YYEOF = 0,                     /* "end of file"  */
//      YYERROR = 256,                 /* error  */
//      YYUNDEF = 257,                 /* "invalid token"  */
//      INTEGER = 258,                 /* INTEGER  */
//      //token_ = 259,                   /* token  */
//      MY_SEMI_COLON = 260,              /* SEMI_COLON  */
//      NEWLINE = 261,                 /* NEWLINE  */
//      MY_PLUS = 262,                    /* PLUS  */
//      // MINUS = 263,                   /* MINUS  */
//      // MULT = 264,                    /* MULT  */
//      // DIV = 265                      /* DIV  */
// };
//typedef yytokentype yytoken_kind_t;

#endif
