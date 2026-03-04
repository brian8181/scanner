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

// .[{()\*+?|^$
// [[.NUL.]] matches a NUL character.
// "(\\|)|(:)|(\\[)|(\\])|(\\{)|(\\})|(\\*)|(!=)|(=)|(\\,)|(\\.)|(\\$[a-zA-Z]+)|([ \\t]+)"


using std::cerr;
using std::cout;
using std::endl;
using yy::parser;

// int INDEX = 100;
// /**
//  * @brief tokens / punctuation
//  */
// unsigned long UL_TILDE         = INDEX++;
// unsigned long UL_TIC_MARK      = INDEX++;
// unsigned long UL_EXCLAMATION   = INDEX++;
// unsigned long UL_AT_SYMBOL     = INDEX++;
// unsigned long UL_HASH_MARK     = INDEX++;
// unsigned long UL_DOLLAR_SIGN   = INDEX++;
// unsigned long UL_PERCENT_SIGN  = INDEX++;
// unsigned long UL_CARROT_SYMB   = INDEX++;
// unsigned long UL_AMPERSAND     = INDEX++;
// unsigned long UL_ASTERISK      = INDEX++;
// unsigned long UL_OPEN_PAREN    = INDEX++;
// unsigned long UL_CLOSE_PAREN   = INDEX++;
// unsigned long UL_DASH          = INDEX++;
// unsigned long UL_UNDERSCORE    = INDEX++;
// unsigned long UL_PLUS_SIGN     = INDEX++;
// unsigned long UL_EQUAL_SIGN    = INDEX++;
// unsigned long UL_OPEN_BRACE    = INDEX++;
// unsigned long UL_OPEN_BRACKET  = INDEX++;
// unsigned long UL_CLOSE_BRACE   = INDEX++;
// unsigned long UL_CLOSE_BRACKET = INDEX++;
// unsigned long UL_VBAR          = INDEX++;
// unsigned long UL_BACKSLASH     = INDEX++;
// unsigned long UL_COLON         = INDEX++;
// unsigned long UL_SEMI_COLON    = INDEX++;
// unsigned long UL_DOUBLE_QUOTE  = INDEX++;
// unsigned long UL_SINGLE_QUOTE  = INDEX++;
// unsigned long UL_LESS_THAN     = INDEX++;
// unsigned long UL_COMMA         = INDEX++;
// unsigned long UL_GREATER_THAN  = INDEX++;
// unsigned long UL_PERIOD        = INDEX++;
// unsigned long UL_QUESTION_MARK = INDEX++;
// unsigned long UL_SLASH         = INDEX++;
// /**
//  * @brief tokens / programming / logical
//  */
// unsigned long UL_NOT                   = INDEX++;
// unsigned long UL_AND                   = INDEX++;
// unsigned long UL_OR                    = INDEX++;
// unsigned long UL_XOR                   = INDEX++;
// unsigned long UL_LEFT_SHIFT            = INDEX++;
// unsigned long UL_RIGHT_SHIFT           = INDEX++;
// unsigned long UL_LOGICAL_AND           = INDEX++;
// unsigned long UL_LOGICAL_OR            = INDEX++;
// unsigned long UL_LOGICAL_NOT           = INDEX++;
// unsigned long UL_LOGICAL_EQUAL         = INDEX++;
// unsigned long UL_GREATER_THAN_EQUAL    = INDEX++;
// unsigned long UL_LESS_THAN_EQUAL       = INDEX++;
// unsigned long UL_NUMERIC_LITERAL       = INDEX++;
// unsigned long UL_STRING_LITERAL        = INDEX++;
// unsigned long UL_DECIMAL_LITERAL       = INDEX++;
// unsigned long UL_HEXADECIMAL_LITERAL   = INDEX++;
// unsigned long UL_OCTAL_DECIMAL_LITERAL = INDEX++;

// /**
//  * @brief tokens / keywords
//  */
// unsigned long UL_IF       = INDEX++;
// unsigned long UL_ELSE     = INDEX++;
// unsigned long UL_ELSEIF   = INDEX++;
// unsigned long UL_FOREACH  = INDEX++;
// unsigned long UL_DO       = INDEX++;
// unsigned long UL_WHILE    = INDEX++;
// unsigned long UL_SWITCH   = INDEX++;
// unsigned long UL_CASE     = INDEX++;
// unsigned long UL_DEFAULT  = INDEX++;
// unsigned long UL_BREAK    = INDEX++;
// unsigned long UL_CONTINUE = INDEX++;
// unsigned long UL_TRY      = INDEX++;
// unsigned long UL_CATCH    = INDEX++;

// /**
//  * @brief built-ins - streamy functions
//  */
// unsigned long UL_REQUIRE           = INDEX++;
// unsigned long UL_CONFIG_LOAD       = INDEX++;
// unsigned long UL_INSERT            = INDEX++;
// unsigned long UL_INCLUDE           = INDEX++;
// unsigned long UL_FILE_ATTRIB       = INDEX++;
// unsigned long UL_ASSIGN            = INDEX++;
// unsigned long UL_VAR_ATTRIB        = INDEX++;
// unsigned long UL_VALUE_ATTRIB      = INDEX++;
// unsigned long UL_FROM_ATTRIB       = INDEX++;
// unsigned long UL_ITEM_ATTRIB       = INDEX++;
// unsigned long UL_KEY_ATTRIB        = INDEX++;
// unsigned long UL_NAME_ATTRIB       = INDEX++;
// unsigned long UL_CAPITALIZE        = INDEX++;
// unsigned long UL_CAT               = INDEX++;
// unsigned long UL_COUNT_CHARACTERS  = INDEX++;
// unsigned long UL_COUNT_PARAGRAPHS  = INDEX++;
// unsigned long UL_COUNT_SENTENCES   = INDEX++;
// unsigned long UL_COUNT_WORDS       = INDEX++;
// unsigned long UL_DATE_FORMAT       = INDEX++;
// unsigned long UL_ESCAPE            = INDEX++;
// unsigned long UL_INDENT            = INDEX++;
// unsigned long UL_LOWER             = INDEX++;
// unsigned long UL_UPPER             = INDEX++;
// unsigned long UL_STRIP             = INDEX++;
// unsigned long UL_NL2BR             = INDEX++;
// unsigned long UL_REGX_REPLACE      = INDEX++;
// unsigned long UL_REPLACE           = INDEX++;
// unsigned long UL_SPACIFY           = INDEX++;
// unsigned long UL_STRING_FORMAT     = INDEX++;
// unsigned long UL_STRIP_TAGS        = INDEX++;
// unsigned long UL_TRUNCATE          = INDEX++;
// unsigned long UL_WORDWRAP          = INDEX++;

// /**
//  * @brief tokens / types
//  */
// unsigned long UL_VALID_CHARS       = INDEX++;
// unsigned long UL_FIRST_CHAR        = INDEX++;
// unsigned long UL_ID                = INDEX++;
// unsigned long UL_IDENTIFIER        = INDEX++;
// unsigned long UL_SYMBOL            = INDEX++;
// unsigned long UL_CONST_SYMBOL      = INDEX++;
// unsigned long UL_ARRAY             = INDEX++;
// unsigned long UL_COMMENT           = INDEX++;
// unsigned long UL_WHITESPACE        = INDEX++;
// unsigned long UL_FILE_NAME         = INDEX++;
// unsigned long UL_SKIP_TOKEN        = (-1);
// unsigned long UL_UNESCAPED_TEXT    = (-5);
// unsigned long UL_ERROR             = (-2);
// unsigned long UL_SCAN_EOF          =   0;
// unsigned long UL_ANYTHING          = (-3);
// unsigned long UL_MATCH             = INDEX++;

#define UL_TILDE                   4ul
#define UL_TIC_MARK                5ul
#define UL_EXCLAMATION             6ul
#define UL_AT_SYMBOL               7ul
#define UL_HASH_MARK               8ul
#define UL_DOLLAR_SIGN             9ul
#define UL_PERCENT_SIGN            10ul
#define UL_CARROT_SYMB             11ul
#define UL_AMPERSAND               12ul
#define UL_ASTERISK                13ul
#define UL_OPEN_PAREN              14ul
#define UL_CLOSE_PAREN             15ul
#define UL_DASH                    16ul
#define UL_UNDERSCORE              17ul
#define UL_PLUS_SIGN               18ul
#define UL_EQUAL_SIGN              19ul
#define UL_OPEN_BRACE              20ul
#define UL_OPEN_BRACKET            21ul
#define UL_CLOSE_BRACE             22ul
#define UL_CLOSE_BRACKET           23ul
#define UL_VBAR                    24ul
#define UL_BACKSLASH               25ul
#define UL_COLON                   26ul
#define UL_SEMI_COLON              27ul
#define UL_DOUBLE_QUOTE            28ul
#define UL_SINGLE_QUOTE            29ul
#define UL_LESS_THAN               30ul
#define UL_COMMA                   31ul
#define UL_GREATER_THAN            32ul
#define UL_PERIOD                  33ul
#define UL_QUESTION_MARK           34ul
#define UL_SLASH                   35ul
#define UL_NOT                     39ul
#define UL_AND                     40ul
#define UL_OR                      41ul
#define UL_XOR                     42ul
#define UL_LEFT_SHIFT              43ul
#define UL_RIGHT_SHIFT             44ul
#define UL_LOGICAL_AND             45ul
#define UL_LOGICAL_OR              46ul
#define UL_LOGICAL_NOT             47ul
#define UL_LOGICAL_EQUAL           48ul
#define UL_GREATER_THAN_EQUAL      49ul
#define UL_LESS_THAN_EQUAL         50ul
#define UL_NUMERIC_LITERAL         51ul
#define UL_STRING_LITERAL          52ul
#define UL_DECIMAL_LITERAL         53ul
#define UL_HEXADECIMAL_LITERAL     54ul
#define UL_OCTAL_DECIMAL_LITERAL   55ul
#define UL_IF                      60ul
#define UL_ELSE                    61ul
#define UL_ELSEIF                  62ul
#define UL_FOREACH                 63ul
#define UL_DO                      64ul
#define UL_WHILE                   65ul
#define UL_SWITCH                  66ul
#define UL_CASE                    67ul
#define UL_DEFAULT                 68ul
#define UL_BREAK                   69ul
#define UL_CONTINUE                70ul
#define UL_TRY                     71ul
#define UL_CATCH                   72ul
#define UL_REQUIRE                 77ul
#define UL_CONFIG_LOAD             78ul
#define UL_INSERT                  79ul
#define UL_INCLUDE                 80ul
#define UL_FILE_ATTRIB             81ul
#define UL_ASSIGN                  82ul
#define UL_VAR_ATTRIB              83ul
#define UL_VALUE_ATTRIB            84ul
#define UL_FROM_ATTRIB             85ul
#define UL_ITEM_ATTRIB             86ul
#define UL_KEY_ATTRIB              87ul
#define UL_NAME_ATTRIB             88ul
#define UL_CAPITALIZE              89ul
#define UL_CAT                     90ul
#define UL_COUNT_CHARACTERS        91ul
#define UL_COUNT_PARAGRAPHS        92ul
#define UL_COUNT_SENTENCES         93ul
#define UL_COUNT_WORDS             94ul
#define UL_DATE_FORMAT             95ul
#define UL_ESCAPE                  96ul
#define UL_INDENT                  97ul
#define UL_LOWER                   98ul
#define UL_UPPER                   99ul
#define UL_STRIP                   100ul
#define UL_NL2BR                   101ul
#define UL_REGX_REPLACE            102ul
#define UL_REPLACE                 103ul
#define UL_SPACIFY                 104ul
#define UL_STRING_FORMAT           105ul
#define UL_STRIP_TAGS              106ul
#define UL_TRUNCATE                107ul
#define UL_WORDWRAP                108ul
#define UL_VALID_CHARS             113ul
#define UL_FIRST_CHAR              114ul
#define UL_ID                      115ul
#define UL_IDENTIFIER              116ul
#define UL_SYMBOL                  117ul
#define UL_CONST_SYMBOL            118ul
#define UL_ARRAY                   119ul
#define UL_COMMENT                 120ul
#define UL_WHITESPACE              121ul
#define UL_FILE_NAME               122ul
#define UL_SKIP_TOKEN              0xFF0000ul
#define UL_UNESCAPED_TEXT          0x00FF00ul
#define UL_ERROR                   0x0000FFul
#define UL_SCAN_EOF                0x0ul
#define UL_ANYTHING                0xFFFFFFul
#define UL_MATCH                   128ul


inline static long g_index = 30;
/**
 * @brief g_tokens
 */
inline vector g_tokens_all = {
    token{UL_MATCH, "MATCH", "string", 0,  "match", 42, string("null"), nullptr},
    token{UL_WHITESPACE, "WHITESPACE", "string", 0,  R"([ \t\n]*)", 42, string("null"), nullptr},
    token{UL_DOLLAR_SIGN, "DOLLAR_SIGN", "string", 0,  R"(\$)", 42, string("null"), nullptr},
    token{UL_CARROT_SYMB, "CARROT", "string", 0,  R"(\^)", 42, string("null"), nullptr},
    token{UL_AMPERSAND, "AMPERSAND", "string", 0,  R"(\*)", 42, string("null"), nullptr},
    token{UL_ASTERISK, "ASTERISK", "string", 0,  R"(\*)", 42, string("null"), nullptr},
    token{UL_OPEN_PAREN, "LPAREN", "string", 0,  R"(\()", 42, string("null"), nullptr},
    token{UL_CLOSE_PAREN, "RPAREN", "string", 0,  R"(\))", 42, string("null"), nullptr},
    token{UL_DASH, "MINUS", "string", 0,  "-", 42, string("null"), nullptr},
    token{UL_PLUS_SIGN, "PLUS", "string", 0,  R"(\+)", 42, string("null"), nullptr},
    token{UL_EQUAL_SIGN, "EQUAL", "string", 0,  "=", 42, string("null"), nullptr},
    token{UL_CLOSE_BRACKET, "RBRACKET", "string",  0, R"(\])", 42, string("null"), nullptr},
    token{UL_OPEN_BRACE, "LBRACE", "string", 0,  R"(\{)", 42, string("null"), nullptr},
    token{UL_CLOSE_BRACE, "RBRACE", "string", 0,  R"(\})", 42, string("null"), nullptr},
    token{UL_OPEN_BRACKET, "LBRACKET", "string",  0, R"(\[)", 42, string("null"), nullptr},
    token{UL_VBAR, "VBAR", "string", 0,  R"(\|)", 42, string("null"), nullptr},
    token{UL_BACKSLASH, "BACKSLASH", "string", 0,  R"(\\)", 42, string("null"), nullptr},
    token{UL_COLON, "COLON", "string", 0,  ":", 42, string("null"), nullptr},
    token{UL_SEMI_COLON, "SEMI_COLON", "string", 0,  ";", 42, string("null"), nullptr},
    token{UL_SINGLE_QUOTE, "SINGLE_QUOTE", "string", 0,  "'", 42, string("null"), nullptr},
    token{UL_GREATER_THAN, "GREATER_THAN", "string", 0,  ">", 42, string("null"), nullptr},
    token{UL_QUESTION_MARK, "QUESTION_MARK", "string", 0,  R"(\?)", 42, string("null"), nullptr},
    token{UL_COMMA, "COMMA", "string", 0,  R"(\,)", 42, string("null"), nullptr},
    token{UL_PERIOD, "DOT", "string", 0,  R"(\.)", 42, string("null"), nullptr},
    token{UL_SLASH, "SLASH", "string", 0,  "/", 42, string("null"), nullptr},
    token{UL_GREATER_THAN_EQUAL, "GREATER_THAN_EQUAL", "string", 0,  ">=", 42, string("null"), nullptr},
    token{UL_LESS_THAN_EQUAL, "LESS_THAN_EQUAL", "string", 0,  "<=", 42, string("null"), nullptr},
    token{UL_NUMERIC_LITERAL, "NUMERIC_LITERAL", "string", 0,  "[0-9]+", 42, string("null"), nullptr},
    token{UL_ARRAY, "ARRAY", "string", 0,  R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\])", 42, string("null"), nullptr},
    token{UL_IDENTIFIER, "IDENTIFIER", "string", 0,  R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", 42, string("null"), nullptr},
    //token{UL_SYMBOL, "SYMBOL", "string", 0,  R"(\$[a-zA-Z]+)", 42, string("null"), nullptr},
    token{UL_COMMENT, "COMMENT", "string", 0,  R"(\{[ ]*\*[^*}]*\*[ ]*\})", 42, string("null"), nullptr},
    token{UL_CONST_SYMBOL, "CONST_SYMBOL", "string", 0,  R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", 42, string("null"), nullptr},
    token{UL_UNESCAPED_TEXT, "UNESCAPED_TEXT", "string", 0,  R"([^{]+)", 42, string("null"), nullptr},
    token{UL_ANYTHING, "ANYTHING", "string", 0,  ".", 42, string("null"), nullptr},
    token{UL_IF, "IF", "string", 0,  "if", 42, string("null"), nullptr},
    token{UL_ELSEIF, "ELSEIF", "string", 0,  "elseif", 42, string("null"), nullptr},
    token{UL_WHILE, "WHILE", "string", 0,  "while", 42, string("null"), nullptr},
    token{UL_ASSIGN, "ASSIGN", "string", 0,  "assign", 42, string("null"), nullptr},
    token{UL_BREAK, "BREAK", "string", 0,  "break", 42, string("null"), nullptr},
    token{UL_REQUIRE, "REQUIRE", "string", 0,  "require", 42, string("null"), nullptr},
    token{UL_INCLUDE, "INCLUDE", "string", 0,  "include", 42, string("null"), nullptr},
    token{UL_CONFIG_LOAD, "CONFIG_LOAD", "string", 0,  "config_load", 42, string("null"), nullptr},
    token{UL_INSERT, "INSERT", "string", 0,  "insert", 42, string("null"), nullptr},
    token{UL_VAR_ATTRIB, "VAR_ATTRIB", "string", 0,  "var_attrib", 42, string("null"),  nullptr},
    token{UL_VALUE_ATTRIB, "VALUE_ATTRIB", "string", 0,  "value_attrib", 42, string("null"), nullptr},
    token{UL_FROM_ATTRIB, "FROM_ATTRIB", "string", 0,  "from_attrib", 42, string("null"),  nullptr},
    token{UL_ITEM_ATTRIB, "ITEM_ATTRIB", "string", 0,  "item_attrib", 42, string("null"),  nullptr},
    token{UL_KEY_ATTRIB, "KEY_ATTRIB", "string", 0,  "key_attrib", 42, string("null"), nullptr},
    token{UL_NAME_ATTRIB, "NAME_ATTRIB", "string", 0,  "name_attrib", 42, string("null"), nullptr},
    token{UL_CAPITALIZE, "CAPITALIZE", "string", 0,  "capitalize", 42, string("null"), nullptr},
    token{UL_CAT, "CAT", "string", 0,  "cat", 42,  string("null"), nullptr},
    token{UL_COUNT_PARAGRAPHS, "COUNT_PARAGRAPHS", "string", 0,  "count_paragraphs", 42, string("null"), nullptr},
    token{UL_COUNT_SENTENCES, "COUNT_SENTENCES", "string", 0,  "count_sentences", 42, string("null"), nullptr},
    token{UL_COUNT_WORDS, "COUNT_WORDS", "string", 0,  "count_words", 42, string("null"),   nullptr},
    token{UL_DATE_FORMAT, "DATE_FORMAT", "string", 0,  "date_format", 42, string("null"),  nullptr},
    token{UL_DEFAULT, "DEFAULT", "string", 0,  "default", 42, string("null"), nullptr},
    token{UL_ESCAPE, "ESCAPE", "string", 0,  "escape", 42, string("null"), nullptr},
    token{UL_INDENT, "INDENT", "string", 0,  "indent", 42, string("null"), nullptr},
    token{UL_LOWER, "LOWER", "string", 0,  "lower", 42, string("null"), nullptr},
    token{UL_UPPER, "UPPER", "string", 0,  "upper", 42, string("null"), nullptr},
    token{UL_STRIP, "STRIP", "string", 0,  "strip", 42, string("null"), nullptr},
    token{UL_NL2BR, "NL2BR", "string", 0,  "nl2br", 42, string("null"), nullptr},
    token{UL_REGX_REPLACE, "REGX_REPLACE", "string", 0,  "regx_replace", 42, string("null"),  nullptr},
    token{UL_REPLACE, "REPLACE", "string", 0,  "replace", 42, string("null"), nullptr},
    token{UL_SPACIFY, "SPACIFY", "string", 0,  "spacify", 42, string("null"), nullptr},
    token{UL_STRING_FORMAT, "STRING_FORMAT", "string", 0,  "string_format", 42, string("null"),  nullptr},
    token{UL_STRIP_TAGS, "STRIP_TAGS", "string", 0,  "strip_tags", 42, string("null"), nullptr},
    token{UL_TRUNCATE, "TRUNCATE", "string", 0,  "truncate", 42, string("null"),   nullptr},
    token{UL_WORDWRAP, "WORDWRAP", "string", 0,  "wordwrap", 42, string("null"),  nullptr}
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

// states
constexpr unsigned long  cINITIAL = 0;
constexpr unsigned long  cCOMMENT = 1;
constexpr unsigned long  cESCAPED  = 3;
constexpr unsigned long  cDOUBLE_QUOTED = 4;
constexpr unsigned long  cSINGLE_QUOTED = 5;
constexpr unsigned long  cINCLUDING = 6;
constexpr unsigned long  cIF_BLOCK = 7;
constexpr unsigned long  cIF_CONDITION = 8;

inline vector<unsigned long> INITIAL_STATE_TOKENS = { UL_OPEN_BRACE };
inline vector<unsigned long> COMMENT_STATE_TOKENS = { UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING };
inline vector<unsigned long> ESCAPED_STATE_TOKENS = { UL_DOLLAR_SIGN, UL_IDENTIFIER, UL_CLOSE_BRACE  };
inline vector<unsigned long> DOUBLE_QUOTED_STATE_TOKENS = { UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING };
inline vector<unsigned long> SINGLE_QUOTED_STATE_TOKENS = { UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING };
inline vector<unsigned long> INCLUDING_STATE_TOKENS = { UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING };
inline vector<unsigned long> IF_BLOCK_STATE_TOKENS = { UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING };
inline vector<unsigned long> IF_CONDITION_STATE_TOKENS = { UL_OPEN_BRACE, UL_COMMENT, UL_ANYTHING };

inline state_t sINITIAL = { cINITIAL, "INITIAL" };
inline state_t sCOMMENT = { cCOMMENT, "COMMENT" };
inline state_t sESCAPED = { cESCAPED, "ESCAPED" };
inline state_t sDOUBLE_QUOTED = { cDOUBLE_QUOTED, "DOUBLE_QUOTED" };
inline state_t sSINGLE_QUOTED = { cSINGLE_QUOTED, "SINGLE_QUOTED" };
inline state_t sINCLUDING = { cINCLUDING, "INCLUDING" };
inline state_t sIF_BLOCK = { cIF_BLOCK, "IF_BLOCK" };
inline state_t sIF_CONDITION = { cIF_CONDITION, "IF_CONDITION" };

inline map<int, state_t*>  g_state_tab =
{
    { cINITIAL, &sINITIAL },
    { cESCAPED, &sESCAPED },
    { cCOMMENT, &sCOMMENT },
    { cSINGLE_QUOTED, &sSINGLE_QUOTED },
    { cDOUBLE_QUOTED, &sDOUBLE_QUOTED },
    { cINCLUDING, &sINCLUDING },
    { cIF_BLOCK, &sIF_BLOCK },
    { cIF_CONDITION, &sIF_CONDITION }

};

inline map<int, vector<unsigned long>> g_state_tokens_tab
{
    {cINITIAL, INITIAL_STATE_TOKENS},
    {cESCAPED, ESCAPED_STATE_TOKENS},
    {cCOMMENT, COMMENT_STATE_TOKENS},
    {cSINGLE_QUOTED, SINGLE_QUOTED_STATE_TOKENS},
    {cDOUBLE_QUOTED, DOUBLE_QUOTED_STATE_TOKENS},
    {cINCLUDING, INCLUDING_STATE_TOKENS},
    {cIF_BLOCK, IF_BLOCK_STATE_TOKENS},
    {cIF_CONDITION, IF_CONDITION_STATE_TOKENS},
};

inline state_t* g_state = &sINITIAL;

inline unsigned long Lexer::on_state(state_t* pstate)
{
    switch (pstate->id) {
        case cINITIAL:
            return cINITIAL;
        default: ;
    }
    return -1;
}


/**
 * @brief override virtual, on_token, for each token ...
 * @param token
 */
inline parser::symbol_type Lexer::on_token( token_def* token )
{
    cout << "state = " << g_state->id << endl;

    switch (g_state->id)
    {
        case cINITIAL:
        {
            switch (token->id)
            {


               case UL_OPEN_BRACE:
                    print_token(token->id);
                    set_state(&sESCAPED);
                    cout << "state = " << _state->name << "(" << _state->id << ")" << endl;
                    // todo stream the prefix
                    return parser::make_LBRACE("{");
                case UL_WHITESPACE:
                    cout << "WHITESPACE" << endl;
                case UL_UNESCAPED_TEXT:
                    cout << "UNESCAPED_TEXT" << endl;
                    cout << "ascii: " << token->value  << endl;
                case UL_SKIP_TOKEN:
                default:
                    cout << "default: SKIP_TOKEN" << endl;
                    print_token(token->id);
                    token->type = new parser::symbol_type(parser::token::SKIP_TOKEN);
                    return *token->type;
            }
            break;
        }
        break;
        case cESCAPED:
        {
            switch ((*token).id)
            {
                case UL_CLOSE_BRACE:
                    set_state(&sINITIAL);
                    print_token(token->id);
                    cout << "state = " << _state->name << "(" << _state->id << ")" << endl;
                    // todo stream the prefix
                    return parser::make_RBRACE( token->value);
                case UL_DOLLAR_SIGN:
                    print_token(token->id);
                    return parser::make_DOLLAR_SIGN(token->value);
                case UL_IDENTIFIER:
                    print_token(token->id);
                    return parser::make_IDENTIFIER(token->value);
                case UL_PLUS_SIGN:
                    return parser::make_PLUS();
                case UL_NUMERIC_LITERAL:
                    return parser::make_NUMERIC_LITERAL(token->value);
                case UL_DOUBLE_QUOTE:
                    return parser::make_DOUBLE_QUOTE(token->value);
                case UL_SINGLE_QUOTE:
                    return parser::make_SINGLE_QUOTE(token->value);
                case UL_SLASH:
                    return parser::make_SLASH();
                case UL_BACKSLASH:
                    return parser::make_BACK_SLASH(token->value);
                case UL_AT_SYMBOL:
                    return parser::make_AT(token->value);
                case UL_DASH:
                    return parser::make_MINUS();
                case UL_ASTERISK:
                    return parser::make_ASTERISK();
                case UL_EQUAL_SIGN:
                    return parser::make_EQUAL();
                case 0:
                    return parser::make_NOT_EQUAL();
                case UL_PERIOD:
                    return parser::make_DOT(token->value);
                //case INDIRECT_MEMBER_SELECT: break;
                case UL_PERCENT_SIGN:
                    return parser::make_PERCENT();
                case UL_AMPERSAND:
                    return parser::make_AMPERSAND(token->value);
                //case UL_NOT:
                   // return parser::make_NOT(token->value);
                //case OR:
                   // return parser::make_OR(token->value);
                //case AND:
                   // return parser::make_AND(token->value);
                case UL_LESS_THAN:
                    return parser::make_LESS_THAN();
                case UL_LESS_THAN_EQUAL:
                    return parser::make_LESS_THAN_EQUAL();
                case UL_GREATER_THAN:
                    return parser::make_GREATER_THAN();
                case UL_GREATER_THAN_EQUAL:
                    return parser::make_GREATER_THAN_EQUAL();
                case UL_REQUIRE:
                    return parser::make_REQUIRE(token->value);
                case UL_CONFIG_LOAD:
                    return parser::make_CONFIG_LOAD(token->value);
                case UL_INSERT:
                    return parser::make_INSERT(token->value);
                case UL_INCLUDE:
                    return parser::make_INCLUDE(token->value);
                case UL_FILE_ATTRIB:
                      return parser::make_FILE_ATTRIB(token->value);
                case UL_ASSIGN:
                    return parser::make_ASSIGN(token->value);
                case UL_VAR_ATTRIB:
                    return parser::make_VAR_ATTRIB(token->value);
                case UL_VALUE_ATTRIB:
                    return parser::make_VALUE_ATTRIB(token->value);
                case UL_FROM_ATTRIB:
                    return parser::make_FROM_ATTRIB(token->value);
                case UL_ITEM_ATTRIB:
                    return parser::make_ITEM_ATTRIB(token->value);
                case UL_KEY_ATTRIB:
                    return parser::make_KEY_ATTRIB(token->value);
                case UL_NAME_ATTRIB:
                    return parser::make_NAME_ATTRIB(token->value);
                case UL_WHITESPACE:
                    cout << "WHITESPACE" << endl;
                case UL_SKIP_TOKEN:
                    return parser::make_SKIP_TOKEN();
                default:
                    cout << "Error: " << token->id << endl;

            }
            break;
        }
        default:
            cout << "ERROR:" << token->id << endl;
            break;
    }

    return parser::make_END();
}
#endif
