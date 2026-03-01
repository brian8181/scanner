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

constexpr unsigned long UL_TILDE         = 0x100;
constexpr unsigned long UL_TIC_MARK      = 0x200;
constexpr unsigned long UL_EXCLAMATION   = 0x400;
constexpr unsigned long UL_AT_SYMBOL     = 0x800;
constexpr unsigned long UL_HASH_MARK     = 0x1000;
constexpr unsigned long UL_DOLLAR_SIGN   = 0x2000;
constexpr unsigned long UL_PERCENT_SIGN  = 0x4000;
constexpr unsigned long UL_CARROT_SYMB   = 0x8000;
constexpr unsigned long UL_AMPERSAND     = 0x10000;
constexpr unsigned long UL_ASTERISK      = 0x10001;
constexpr unsigned long UL_OPEN_PAREN    = 0x20000;
constexpr unsigned long UL_CLOSE_PAREN   = 0x40000;
constexpr unsigned long UL_DASH          = 0x80000;
constexpr unsigned long UL_UNDERSCORE    = 0x100000;
constexpr unsigned long UL_PLUS_SIGN     = 0x200000;
constexpr unsigned long UL_EQUAL_SIGN    = 0x400000;
constexpr unsigned long UL_OPEN_BRACE    = 0x800000;
constexpr unsigned long UL_OPEN_BRACKET  = 0x1000000;
constexpr unsigned long UL_CLOSE_BRACE   = 0x2000000;
constexpr unsigned long UL_CLOSE_BRACKET = 0x4000000;
constexpr unsigned long UL_VBAR          = 0x8000000;
constexpr unsigned long UL_BACKSLASH     = 0x10000000;
constexpr unsigned long UL_COLON         = 0x20000000;
constexpr unsigned long UL_SEMI_COLON    = 0x40000000;
constexpr unsigned long UL_DOUBLE_QUOTE  = 0x80000000;
constexpr unsigned long UL_SINGLE_QUOTE  = 0x100000000;
constexpr unsigned long UL_LESS_THAN     = 0x200000000;
constexpr unsigned long UL_COMMA         = 0x400000000;
constexpr unsigned long UL_GREATER_THAN  = 0x800000000;
constexpr unsigned long UL_PERIOD        = 0x1000000000;
constexpr unsigned long UL_QUESTION_MARK = 0x2000000000;
constexpr unsigned long UL_SLASH         = 0x4000000000;
constexpr unsigned long UL_NOT_EQUAL = 10;
constexpr unsigned long UL_GREATER_THAN_EQUAL = 30;
constexpr unsigned long UL_LESS_THAN_EQUAL = 31;
constexpr unsigned long UL_NUMERIC_LITERAL   = 32;
constexpr unsigned long UL_REQUIRE           = 33;
constexpr unsigned long UL_CONFIG_LOAD       = 34;
constexpr unsigned long UL_INSERT            = 35;
constexpr unsigned long UL_INCLUDE           = 36;
constexpr unsigned long UL_FILE_ATTRIB       = 37;
constexpr unsigned long UL_ASSIGN            = 38;
constexpr unsigned long UL_VAR_ATTRIB        = 39;
constexpr unsigned long UL_VALUE_ATTRIB      = 40;
constexpr unsigned long UL_FROM_ATTRIB       = 41;
constexpr unsigned long UL_ITEM_ATTRIB       = 42;
constexpr unsigned long UL_KEY_ATTRIB        = 43;
constexpr unsigned long UL_NAME_ATTRIB       = 44;
constexpr unsigned long UL_CAPITALIZE        = 45;
constexpr unsigned long UL_CAT               = 46;
constexpr unsigned long UL_COUNT_CHARACTERS  = 47;
constexpr unsigned long UL_COUNT_PARAGRAPHS  = 48;
constexpr unsigned long UL_COUNT_SENTENCES   = 49;
constexpr unsigned long UL_COUNT_WORDS       = 50;
constexpr unsigned long UL_DATE_FORMAT       = 51;
constexpr unsigned long UL_DEFAULT           = 52;
constexpr unsigned long UL_ESCAPE            = 53;
constexpr unsigned long UL_INDENT            = 54;
constexpr unsigned long UL_LOWER             = 55;
constexpr unsigned long UL_UPPER             = 56;
constexpr unsigned long UL_STRIP             = 57;
constexpr unsigned long UL_NL2BR             = 58;
constexpr unsigned long UL_REGX_REPLACE      = 59;
constexpr unsigned long UL_REPLACE           = 60;
constexpr unsigned long UL_SPACIFY           = 61;
constexpr unsigned long UL_STRING_FORMAT     = 62;
constexpr unsigned long UL_STRIP_TAGS        = 63;
constexpr unsigned long UL_TRUNCATE          = 64;
constexpr unsigned long UL_WORDWRAP          = 65;
constexpr unsigned long UL_VALID_CHARS       = 66;
constexpr unsigned long UL_FIRST_CHAR        = 67;
constexpr unsigned long UL_ID                = 68;
constexpr unsigned long UL_SYMBOL            = 69;
constexpr unsigned long UL_CONST_SYMBOL      = 70;
constexpr unsigned long UL_ARRAY             = 71;
constexpr unsigned long UL_COMMENT           = 72;
constexpr unsigned long UL_WHITESPACE        = 74;
constexpr unsigned long UL_FILE_NAME         = 73;
constexpr unsigned long UL_SKIP_TOKEN        = (-1);
constexpr unsigned long UL_UNESCAPED_TEXT        = (-5);
constexpr unsigned long UL_ERROR             = (-2);
constexpr unsigned long UL_SCAN_EOF          =   0;
constexpr unsigned long UL_ANYTHING          = (-3);


static int index_ = 0;
static int id = 0;
inline static long g_index = 30;

inline vector g_tokens =
{
    token {UL_DOLLAR_SIGN, "DOLLAR_SIGN", "string", 0, 0, R"(\$)", "$",                                0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_ID,  "ID", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/",             0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_OPEN_BRACE, "LBRACE", "string", 0, 0, R"(\{)", "\\{",                                    0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_WHITESPACE,  "WHITESPACE", "string", 0, 0, R"([ \t])", "\\t",                                0, string("null"), yy::parser::make_YYUNDEF()},
};

/**
 * @brief g_tokens
 */
inline vector g_tokens_ =
{
    token {UL_DOLLAR_SIGN, "DOLLAR_SIGN", "string", 0, 0, R"(\$)", "$",                                0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_CARROT_SYMB, "CARROT", "string", 0, 0, R"(\^)", "\\^",                                   0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_AMPERSAND, "AMPERSAND", "string", 0, 0, R"(\*)", "\\*",                                  0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_ASTERISK, "ASTERISK", "string", 0, 0, R"(\*)", "\\*",                                    0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_OPEN_PAREN, "LPAREN", "string", 0, 0, R"(\()", "\\(",                                    0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_CLOSE_PAREN, "RPAREN", "string", 0, 0, R"(\))", "\\)",                                   0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_DASH, "MINUS", "string", 0, 0, "-", "-",                                                 0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_PLUS_SIGN, "PLUS", "string", 0, 0, R"(\+)", "\\+",                                       0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_EQUAL_SIGN, "EQUAL", "string", 0, 0, "=", "=",                                           0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_OPEN_BRACE, "LBRACE", "string", 0, 0, R"(\{)", "\\{",                                    0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_CLOSE_BRACE, "RBRACE", "string", 0, 0, R"(\})", "\\}",                                   0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_OPEN_BRACKET, "LBRACKET", "string", 0, 0, R"(\[)", "\\[",                                0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_CLOSE_BRACKET, "RBRACKET", "string", 0, 0, R"(\])", "\\]",                               0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_VBAR, "VBAR", "string", 0, 0, R"(\|)", "\\|",                                            0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_BACKSLASH, "BACKSLASH", "string", 0, 0, R"(\\)", "\\\\",                                 0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_COLON, "COLON", "string", 0, 0, ":", ":",                                                0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_SEMI_COLON, "SEMI_COLON", "string", 0, 0, ";", ";",                                      0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_SINGLE_QUOTE,  "SINGLE_QUOTE", "string", 0, 0, "'", "'",                                 0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_GREATER_THAN,  "GREATER_THAN", "string", 0, 0, ">", ">",                                 0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_QUESTION_MARK, "QUESTION_MARK", "string", 0, 0, R"(\?)", "\\?",                          0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_COMMA, "COMMA", "string", 0, 0, R"(\,)", "\\,",                                          0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_PERIOD, "DOT_", "string", 0, 0, R"(\.)", "\\.",                                          0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_SLASH, "SLASH", "string", 0, 0, "/", "/",                                                0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_NOT_EQUAL, "NOT_EQUAL", "string", 0, 0, "!=", "!=",                                         0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_GREATER_THAN_EQUAL,  "GREATER_THAN_EQUAL", "string", 0, 0, ">=", ">=",                               0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_LESS_THAN_EQUAL,  "LESS_THAN_EQUAL", "string", 0, 0, "<=", "<=",                                  0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_NUMERIC_LITERAL,  "NUMERIC_LITERAL", "string", 0, 0, "[0-9]+", "12345",                           0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_ARRAY,  "ARRAY", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\])", "/", 0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_ID,  "ID", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/",             0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_SYMBOL, "SYMBOL", "string", 0, 0, R"(\$[a-zA-Z]+)", "\\$abc",                            0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_COMMENT, "COMMENT", "string", 0, 0, R"(\{[ ]*\*[^*}]*\*[ ]*\})",  R"(\* test *\)",        0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_CONST_SYMBOL,  "CONST_SYMBOL", "string", 0, 0, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", "/", 0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_WHITESPACE,  "WHITESPACE", "string", 0, 0, R"([ \t])", "\\t",                                0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_UNESCAPED_TEXT,  "UNESCAPED_TEXT", "string", 0, 0, R"([^{]+)", "testing ...",                    0, string("null"), yy::parser::make_YYUNDEF()},
    token {UL_ANYTHING,  "ANYTHING", "string", 0, 0, ".", "~#",                                          0, string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "IF", "string", 0, 0, "if", "if",                                               0,  string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "ELSEIF", "string", 0, 0, "elseif", "elseif",                                   0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "FOREACH", "string", 0, 0, "foreach", "forech",                                 0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "WHILE", "string", 0, 0, "while", "while",                                      0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "DO", "string", 0, 0, "do", "do",                                               0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {UL_ASSIGN,  "ASSIGN", "string", 0, 0, "assign", "assign",                                   0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "BREAK", "string", 0, 0, "break", "break",                                      0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {UL_REQUIRE,  "REQUIRE", "string",     0, 0, "require",     "require",                        0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {UL_INCLUDE,  "INCLUDE", "string",     0, 0, "include",     "include",                        0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {UL_CONFIG_LOAD,  "CONFIG_LOAD", "string", 0, 0, "config_load", "config_load",                    0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {UL_INSERT,  "INSERT", "string",      0, 0, "insert",      "insert",                         0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "VAR_ATTRIB", "string", 0, 0, "var_attrib", "var_attrib",                       0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "VALUE_ATTRIB", "string", 0, 0, "value_attrib", "value_attrib",                 0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "FROM_ATTRIB", "string", 0, 0, "from_attrib", "from_attrib",                    0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "ITEM_ATTRIB", "string", 0, 0, "item_attrib", "item_attrib",                    0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "KEY_ATTRIB", "string", 0, 0, "key_attrib", "key_attrib",                       0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {0,  "NAME_ATTRIB", "string", 0, 0, "name_attrib", "name_attrib",                    0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {UL_CAPITALIZE,  "CAPITALIZE", "string", 0, 0, "capitalize", "capitalize",                       0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {UL_CAT,  "CAT", "string", 0, 0, "cat", "cat",                                            0,                                            string("null"), yy::parser::make_YYUNDEF()},
    token {UL_COUNT_CHARACTERS,  "COUNT_CHARACTERS", "string", 0, 0, "count_characters", "count_characters",     0,     string("null"), yy::parser::make_YYUNDEF()},
    token {UL_COUNT_PARAGRAPHS,  "COUNT_PARAGRAPHS", "string", 0, 0, "count_paragraphs", "count_paragraphs",     0,     string("null"), yy::parser::make_YYUNDEF()},
    token {UL_COUNT_SENTENCES,  "COUNT_SENTENCES", "string", 0, 0, "count_sentences", "count_sentences",        0,        string("null"), yy::parser::make_YYUNDEF()},
    token {UL_COUNT_WORDS,  "COUNT_WORDS", "string", 0, 0, "count_words", "count_words",                    0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {UL_DATE_FORMAT,  "DATE_FORMAT", "string", 0, 0, "date_format", "date_format",                    0,                    string("null"), yy::parser::make_YYUNDEF()},
    token {UL_DEFAULT,  "DEFAULT", "string", 0, 0, "default", "default",                                0,                                string("null"), yy::parser::make_YYUNDEF()},
    token {UL_ESCAPE,  "ESCAPE", "string", 0, 0, "escape", "escape",                                   0,                                   string("null"), yy::parser::make_YYUNDEF()},
    token {UL_INDENT,  "INDENT", "string", 0, 0, "indent", "indent",                                   0,                                   string("null"), yy::parser::make_YYUNDEF()},
    token {UL_LOWER,  "LOWER", "string", 0, 0, "lower", "lower",                                      0,                                      string("null"), yy::parser::make_YYUNDEF()},
    token {UL_UPPER,  "UPPER", "string", 0, 0, "upper", "upper",                                      0,                                      string("null"), yy::parser::make_YYUNDEF()},
    token {UL_STRIP,  "STRIP", "string", 0, 0, "strip", "strip",                                      0,                                      string("null"), yy::parser::make_YYUNDEF()},
    token {UL_NL2BR,  "NL2BR", "string", 0, 0, "nl2br", "nl2br",                                      0,                                      string("null"), yy::parser::make_YYUNDEF()},
    token {UL_REGX_REPLACE,  "REGX_REPLACE", "string", 0, 0, "regx_replace", "regx_replace",                 0,                 string("null"), yy::parser::make_YYUNDEF()},
    token {UL_REPLACE,  "REPLACE", "string", 0, 0, "replace", "replace",                                0,                                string("null"), yy::parser::make_YYUNDEF()},
    token {UL_SPACIFY,  "SPACIFY", "string", 0, 0, "spacify", "spacify",                                0,                                string("null"), yy::parser::make_YYUNDEF()},
    token {UL_STRING_FORMAT,  "STRING_FORMAT", "string", 0, 0, "string_format", "string_format",              0,              string("null"), yy::parser::make_YYUNDEF()},
    token {UL_STRIP_TAGS,  "STRIP_TAGS", "string", 0, 0, "strip_tags", "strip_tags",                       0,                       string("null"), yy::parser::make_YYUNDEF()},
    token {UL_TRUNCATE,  "TRUNCATE", "string", 0, 0, "truncate", "truncate",                             0,                             string("null"), yy::parser::make_YYUNDEF()},
    token {UL_WORDWRAP,  "WORDWRAP", "string", 0, 0, "wordwrap", "wordwrap",                             0,                             string("null"), yy::parser::make_YYUNDEF()}
};

inline string e1 = R"((\|)|(:)|(\*)|(/)|(\)|(\,)|(\.)|(\^)|(\?)|(\\)|(\+)|(-)|(\$[a-zA-Z]+)|(\$)|(\[)|(\])|(\{)|(\})|(\()|(\))|(!=)|(=)|(>)|(<)|(>=)|(<=)|(>)|(')|(")|([0-9]+))";
inline string e2 = R"(|([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\])|([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)|(\$[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)|(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)|([^{]+))";
inline string e3 = R"(|([ \t])|(.)|(if)|(else)|(elseif)|(foreach)|(while)|(do)|(break)|(require)|(include)|(config_load)|(insert)|(assign)|(var_attrib)|(value_attrib)|(from_attrib)|(item_attrib)|(key_attrib)|(name_attrib))";
inline string e4 = R"(|(capitalize)|(cat)|(count_characters)|(count_paragraphs)|(count_sentences)|(count_words)|(date_format)|(default)|(escape)|(indent)|(lower)|(upper)|(strip)|(nl2br)|(regx_replace)|(replace)|(spacify))";
inline string e5 = R"(|(string_format)|(strip_tags)|(truncate)|(wordwrap)|((\|)|(:)|(\*)|(/)|(\)|(\,)|(\.)|(\^)|(\?)|(\\)|(\+)|(-)|(\$[a-zA-Z]+)|(\$)|(\[)|(\])|(\{)|(\})|(\()|(\))|(!=)|(=)|(>)|(<)|(>=)|(<=)|(>)|(')|(")|([0-9]+))";
inline string e6 = R"(|([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\])|([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)|(\$[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)|(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)|([^{]+)|([ \t])|(.))";
inline string e7 = R"(|(if)|(else)|(elseif)|(foreach)|(while)|(do)|(break)|(require)|(include)|(config_load)|(insert)|(assign)|(var_attrib)|(value_attrib)|(from_attrib)|(item_attrib)|(key_attrib)|(name_attrib))";
inline string e8 = R"(|(capitalize)|(cat)|(count_characters)|(count_paragraphs)|(count_sentences)|(count_words)|(date_format)|(default)|(escape)|(indent)|(lower)|(upper)|(strip)|(nl2br)|(regx_replace)|(replace)|(spacify)|(string_format)|(strip_tags)|(truncate)|(wordwrap))";
inline string expression = e1 + e2 + e3 + e4 + e5 + e6 + e8;

/**
 * @brief lex states
**/
inline vector state_initial = {
    token{UL_OPEN_BRACE, "LBRACE", "string", 0, 0, R"(\{)", "\\{",                                        0, string("null"), yy::parser::make_YYUNDEF()},
    token{UL_COMMENT, "COMMENT", "string", 0, 0, R"(\{[ ]*\*[^*}]*\*[ ]*\})",  R"(\* test *\)",        0, string("null"), yy::parser::make_YYUNDEF()},
    token{0,  "UNESCAPED_TEXT", "string", 0, 0, R"([^{]+)", "testing ...",                    0, string("null"), yy::parser::make_YYUNDEF()},
};
//
// inline vector state_comment = {
//     new token{UL_ANYTHING,  "ANYTHING", "string", 0, 0, ".", "~#",                                          0, string("null"), yy::parser::make_YYUNDEF()}
// };
//
// inline vector state_escaped = {
//     new token{UL_ANYTHING,  "ANYTHING", "string", 0, 0, ".", "~#",                                          0, string("null"), yy::parser::make_YYUNDEF()}
// };

// .[{()\*+?|^$
// [[.NUL.]] matches a NUL character.
// "(\\|)|(:)|(\\[)|(\\])|(\\{)|(\\})|(\\*)|(!=)|(=)|(\\,)|(\\.)|(\\$[a-zA-Z]+)|([ \\t]+)"

// states
#define INITIAL_ 0
#define COMMENT_ 1
#define ESCAPED_  3
#define DOUBLE_QUOTED 4
#define SINGLE_QUOTED 5
#define INCLUDING 6
#define IF_BLOCK 7
#define IF_CONDITION 8

// inline map<unsigned long, vector<token_def *> > state_tokens_tab = {
//     {INITIAL_, {state_comment}}, {COMMENT_, {state_comment}}, {ESCAPED_, {state_escaped}}
// };

inline vector<unsigned long> INITIAL_STATE = { UL_DOLLAR_SIGN, UL_ID, UL_OPEN_BRACE, UL_WHITESPACE };
inline vector<unsigned long> COMMENT_STATE = { UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING };

inline state_t sINITIAL = { INITIAL_, "INITIAL" };
inline state_t sESCAPED = { ESCAPED_, "ESCAPED" };
inline state_t sDOUBLE_QUOTED = { DOUBLE_QUOTED, "DOUBLE_QUOTED" };
inline state_t sSINGLE_QUOTED = { SINGLE_QUOTED, "SINGLE_QUOTED" };
inline state_t sINCLUDING = { INCLUDING, "INCLUDING" };
inline state_t sIF_BLOCK = { IF_BLOCK, "IF_BLOCK" };
inline state_t sIF_CONDITION = { IF_CONDITION, "IF_CONDITION" };

inline map<int, state_t*>  g_state_tab = { { INITIAL_, &sINITIAL }, { ESCAPED_, &sESCAPED } };

inline unsigned long Lexer::on_state(const state_t &s)
{
    switch (s.id) {
        case INITIAL_:
            return INITIAL_;
        default: ;
    }
    return -1;
}

using yy::parser;

inline yy::parser::symbol_type Lexer::on_token_action(const state_t &s, const token_def &tok)
{
    cout << "state = " << s.id << endl;
    print_token(tok.id);
    switch (s.id)
    {
        case INITIAL_:
        {
            switch (tok.id)
            {
                case UL_DOLLAR_SIGN:
                    return parser::make_DOLLAR_SIGN(tok.value);
                case UL_ID:
                    return parser::make_ID(tok.value);
                case UL_OPEN_BRACE:
                       set_state(sESCAPED);
                    // todo stream the prefix
                    return yy::parser::make_LBRACE("{");
                case UL_COMMENT:
                    return yy::parser::make_YYUNDEF();
                case UL_WHITESPACE:
                case UL_SKIP_TOKEN:
                    return yy::parser::make_YYUNDEF();
                case UL_SCAN_EOF:
                    return EOF;
                case UL_ANYTHING:
                    return yy::parser::make_YYUNDEF();
                default:
                    return yy::parser::make_YYUNDEF();
            }
            //return yy::parser::make_END();
        }
        case ESCAPED_:
        {
            switch (tok.id)
            {
                case UL_CLOSE_BRACE:
                    set_state(sINITIAL);
                    // todo stream the prefix
                    return yy::parser::make_RBRACE("}");
                case UL_DOLLAR_SIGN:
                    return parser::make_DOLLAR_SIGN(tok.value);
                case UL_ID:
                    return parser::make_ID(tok.value);
                case UL_DOUBLE_QUOTE:
                    return yy::parser::make_DOUBLE_QUOTE(tok.value);
                case UL_SINGLE_QUOTE:
                    return yy::parser::make_SINGLE_QUOTE(tok.value);
                case UL_SLASH:
                    return yy::parser::make_SLASH();
                case UL_BACKSLASH:
                    return yy::parser::make_BACK_SLASH(tok.value);
                case UL_AT_SYMBOL:
                    return yy::parser::make_AT(tok.value);
                case UL_DASH:
                    return yy::parser::make_MINUS();
                case UL_ASTERISK:
                    return yy::parser::make_ASTERISK();
                case UL_EQUAL_SIGN:
                    return yy::parser::make_EQUAL();
                case UL_NOT_EQUAL:
                    return yy::parser::make_NOT_EQUAL();
                case UL_PERIOD:
                    return yy::parser::make_DOT(tok.value);
                    //case INDIRECT_MEMBER_SELECT: break;
                case UL_PERCENT_SIGN:
                    return yy::parser::make_PERCENT();
                case UL_AMPERSAND:
                    return yy::parser::make_AMPERSAND(tok.value);
                //case UL_NOT:
                   // return yy::parser::make_NOT(tok.value);
                //case OR:
                   // return yy::parser::make_OR(tok.value);
                //case AND:
                   // return yy::parser::make_AND(tok.value);
                case UL_LESS_THAN:
                    return yy::parser::make_LESS_THAN();
                case UL_LESS_THAN_EQUAL:
                    return yy::parser::make_LESS_THAN_EQUAL();
                case UL_GREATER_THAN:
                    return yy::parser::make_GREATER_THAN();
                case UL_GREATER_THAN_EQUAL:
                    return yy::parser::make_GREATER_THAN_EQUAL();
                case UL_NUMERIC_LITERAL:
                    return yy::parser::make_NUMERIC_LITERAL(tok.value);
                case UL_REQUIRE:
                    return yy::parser::make_REQUIRE(tok.value);
                case UL_CONFIG_LOAD:
                    return yy::parser::make_CONFIG_LOAD(tok.value);
                case UL_INSERT:
                    return yy::parser::make_INSERT(tok.value);
                case UL_INCLUDE:
                    return yy::parser::make_INCLUDE(tok.value);
                case UL_FILE_ATTRIB:
                      return yy::parser::make_FILE_ATTRIB(tok.value);
                case UL_ASSIGN:
                    return yy::parser::make_ASSIGN(tok.value);
                case UL_VAR_ATTRIB:
                    return yy::parser::make_VAR_ATTRIB(tok.value);
                case UL_VALUE_ATTRIB:
                    return yy::parser::make_VALUE_ATTRIB(tok.value);
                case UL_FROM_ATTRIB:
                    return yy::parser::make_FROM_ATTRIB(tok.value);
                case UL_ITEM_ATTRIB:
                    return yy::parser::make_ITEM_ATTRIB(tok.value);
                case UL_KEY_ATTRIB:
                    return yy::parser::make_KEY_ATTRIB(tok.value);
                case UL_NAME_ATTRIB:
                    return yy::parser::make_NAME_ATTRIB(tok.value);
                default: ;
            }
        }
        default: ;
    }

    return yy::parser::make_END();
}
#endif
