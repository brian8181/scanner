
/**
 * @file    tokens.hpp
 * @version 0.0.1
 * @date    Wed Feb 11 17:23:05 CST 2026
 */
#ifndef LEX_CONF_HPP_
#define LEX_CONF_HPP_

#include <iostream>
#include "Lexer.hpp"
#include "pparser.tab.hh"
int n = (int)yy::parser::token::END;


inline vector tokens =
{

/**
 * punct
 */
token{1, "VBAR", "string", 0, 0, "\\|", "\\|", 1, string("null")},
token{2, "COLON", "string", 0, 0, ":", ":", 2, string("null")},
token{10, "ASTERISK", "string", 0, 0, "\\*", "\\*", 10, string("null")},
token{20, "SLASH", "string", 0, 0, "/", "/", 19, string("null")},
token{21, "BACK_SLASH", "string", 0, 0, "\\", "\\", 19, string("null")},
token{13, "COMMA", "string", 0, 0, "\\,", "\\,", 13, string("null")},
token{14, "DOT_", "string", 0, 0, "\\.", "\\.", 14, string("null")},
token{15, "CARROT", "string", 0, 0, "\\^", "\\^", 15, string("null")},
token{16, "QUESTION_MARK", "string", 0, 0, "\\?", "\\?", 16, string("null")},
token{17, "BACKSLASH", "string", 0, 0, "\\\\", "\\\\", 17, string("null")},
token{18, "PLUS", "string", 0, 0, "\\+", "\\+", 18, string("null")},
token{19, "MINUS", "string", 0, 0, "-", "-", 19, string("null")},
token{20, "SYMBOL", "string", 0, 0, "\\$[a-zA-Z]+", "\\$abc", 20, string("null")},
token{23, "DOLLAR_SIGN", "string", 0, 0, "\\$", "$", 21, string("null")},
/**
 * punct 2
 * braces & parens
 */
token{4, "LBRACKET", "string", 0, 0, "\\[", "\\[", 4, string("null")},
token{5, "RBRACKET", "string", 0, 0, "\\]", "\\]", 5, string("null")},
token{6, "LBRACE", "string", 0, 0, "\\{", "\\{", 6, string("null")},
token{7, "RBRACE", "string", 0, 0, "\\}", "\\}", 7, string("null")},
token{8, "LPAREN", "string", 0, 0, "\\(", "\\(", 8, string("null")},
token{9, "RPAREN", "string", 0, 0, "\\)", "\\)", 9, string("null")},
/**
 * punct 3
 */
token{11, "NOT_EQUAL", "string", 0, 0, "!=", "!=", 11, string("null")},
token{12, "EQUAL", "string", 0, 0, "=", "=", 12, string("null")},
token{13, "GREATER_THAN", "string", 0, 0, ">", ">", 19, string("null")},
token{14, "LESS_THAN", "string", 0, 0, "<", "<", 19, string("null")},
token{15, "GREATER_THAN_EQUAL", "string", 0, 0, ">=", ">=", 19, string("null")},
token{16, "LESS_THAN_EQUAL", "string", 0, 0, "<=", "<=", 19, string("null")},
token{17, "GREATER_THAN", "string", 0, 0, ">", ">", 19, string("null")},
token{18, "SINGLE_QUOTE", "string", 0, 0, "'", "'", 19, string("null")},
token{19, "DOUBLE_QUOTE", "string", 0, 0, "\"", "\"", 19, string("null")},
/**
 * symbols types literals
 */
token{22, "NUMERIC_LITERAL", "string", 0, 0, "[0-9]+", "12345", 19, string("null")},
token{23, "ARRAY", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\])", "/", 19, string("null")},
token{24, "ID", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/", 19, string("null")},
token{25, "SYMBOL", "string", 0, 0, R"(\$[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/", 19, string("null")},
token{26, "CONST_SYMBOL", "string", 0, 0, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", "/", 19, string("null")},
token{27, "UNESCAPED_TEXT", "string", 0, 0, R"([^{]+)", "testing ...", 19, string("null")},
token{28, "WHITESPACE", "string", 0, 0, "[ \\t]", "\\t", 22, string("null")},
token{29, "ANYTHING", "string", 0, 0, ".", "~#", 23, string("null")},
/**
 * keywords
 */
token{29, "IF", "string", 0, 0, "if", "if", 23, string("null")},
token{29, "ELSE", "string", 0, 0, "else", "else", 23, string("null")},
token{29, "ELSEIF", "string", 0, 0, "elseif", "elseif", 23, string("null")},
token{29, "FOREACH", "string", 0, 0, "foreach", "forech", 23, string("null")},
token{29, "WHILE", "string", 0, 0, "while", "while", 23, string("null")},
token{29, "DO", "string", 0, 0, "do", "do", 23, string("null")},
token{29, "BREAK", "string", 0, 0, "break", "break", 23, string("null")},
/**
 * built-ins
 */
token{30, "REQUIRE", "string",     0, 0, "require",     "require",     23, string("null")},
token{31, "INCLUDE", "string",     0, 0, "include",     "include",     23, string("null")},
token{32, "CONFIG_LOAD", "string", 0, 0, "config_load", "config_load", 23, string("null")},
token{32, "INSERT", "string",      0, 0, "insert",      "insert",      23, string("null")},


/**
* All
*/
token{15,  "VBAR", "string", 0, 0, "\\|", "\\|", 1, string("null")},
token{19,  "COLON", "string", 0, 0, ":", ":", 2, string("null")},
token{23,  "ASTERISK", "string", 0, 0, "\\*", "\\*", 10, string("null")},
token{27,  "SLASH", "string", 0, 0, "/", "/", 19, string("null")},
token{31,  "BACK_SLASH", "string", 0, 0, "\\", "\\", 19, string("null")},
token{35,  "COMMA", "string", 0, 0, "\\,", "\\,", 13, string("null")},
token{39,  "DOT_", "string", 0, 0, "\\.", "\\.", 14, string("null")},
token{43,  "CARROT", "string", 0, 0, "\\^", "\\^", 15, string("null")},
token{47,  "QUESTION_MARK", "string", 0, 0, "\\?", "\\?", 16, string("null")},
token{51,  "BACKSLASH", "string", 0, 0, "\\\\", "\\\\", 17, string("null")},
token{55,  "PLUS", "string", 0, 0, "\\+", "\\+", 18, string("null")},
token{59,  "MINUS", "string", 0, 0, "-", "-", 19, string("null")},
token{63,  "SYMBOL", "string", 0, 0, "\\$[a-zA-Z]+", "\\$abc", 20, string("null")},
token{67,  "DOLLAR_SIGN", "string", 0, 0, "\\$", "$", 21, string("null")},
token{71,  "LBRACKET", "string", 0, 0, "\\[", "\\[", 4, string("null")},
token{75,  "RBRACKET", "string", 0, 0, "\\]", "\\]", 5, string("null")},
token{79,  "LBRACE", "string", 0, 0, "\\{", "\\{", 6, string("null")},
token{83,  "RBRACE", "string", 0, 0, "\\}", "\\}", 7, string("null")},
token{87,  "LPAREN", "string", 0, 0, "\\(", "\\(", 8, string("null")},
token{91,  "RPAREN", "string", 0, 0, "\\)", "\\)", 9, string("null")},
token{95,  "NOT_EQUAL", "string", 0, 0, "!=", "!=", 11, string("null")},
token{99,  "EQUAL", "string", 0, 0, "=", "=", 12, string("null")},
token{103,  "GREATER_THAN", "string", 0, 0, ">", ">", 19, string("null")},
token{107,  "LESS_THAN", "string", 0, 0, "<", "<", 19, string("null")},
token{111,  "GREATER_THAN_EQUAL", "string", 0, 0, ">=", ">=", 19, string("null")},
token{115,  "LESS_THAN_EQUAL", "string", 0, 0, "<=", "<=", 19, string("null")},
token{119,  "GREATER_THAN", "string", 0, 0, ">", ">", 19, string("null")},
token{123,  "SINGLE_QUOTE", "string", 0, 0, "'", "'", 19, string("null")},
token{127,  "DOUBLE_QUOTE", "string", 0, 0, "\"", "\"", 19, string("null")},
token{131,  "NUMERIC_LITERAL", "string", 0, 0, "[0-9]+", "12345", 19, string("null")},
token{135,  "ARRAY", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\])", "/", 19, string("null")},
token{139,  "ID", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/", 19, string("null")},
token{143,  "SYMBOL", "string", 0, 0, R"(\$[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/", 19, string("null")},
token{147,  "CONST_SYMBOL", "string", 0, 0, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", "/", 19, string("null")},
token{151,  "UNESCAPED_TEXT", "string", 0, 0, R"([^{]+)", "testing ...", 19, string("null")},
token{155,  "WHITESPACE", "string", 0, 0, "[ \\t]", "\\t", 22, string("null")},
token{159,  "ANYTHING", "string", 0, 0, ".", "~#", 23, string("null")},
/**
 * keywords
 */
token{163,  "IF", "string", 0, 0, "if", "if", 23, string("null")},
token{167,  "ELSE", "string", 0, 0, "else", "else", 23, string("null")},
token{171,  "ELSEIF", "string", 0, 0, "elseif", "elseif", 23, string("null")},
token{175,  "FOREACH", "string", 0, 0, "foreach", "forech", 23, string("null")},
token{179,  "WHILE", "string", 0, 0, "while", "while", 23, string("null")},
token{183,  "DO", "string", 0, 0, "do", "do", 23, string("null")},
token{187,  "BREAK", "string", 0, 0, "break", "break", 23, string("null")},
/**
 * built-ins
 */
token{191,  "REQUIRE", "string",     0, 0, "require",     "require",     23, string("null")},
token{195,  "INCLUDE", "string",     0, 0, "include",     "include",     23, string("null")},
token{199,  "CONFIG_LOAD", "string", 0, 0, "config_load", "config_load", 23, string("null")},
token{203,  "INSERT", "string",      0, 0, "insert",      "insert",      23, string("null")}
token{207,  "ASSIGN", string, 0, 0, "assign", "assign", 31, string(null)}
token{211,  "VAR_ATTRIB", string, 0, 0, "var_attrib", "var_attrib", 31, string("null")}
token{215,  "VALUE_ATTRIB", string, 0, 0, "value_attrib", "value_attrib", 31, string("null")}
token{219,  "FROM_ATTRIB", string, 0, 0, "from_attrib", "from_attrib", 31, string("null")}
token{223,  "ITEM_ATTRIB", string, 0, 0, "item_attrib", "item_attrib", 31, string("null")}
token{227,  "KEY_ATTRIB", string, 0, 0, "key_attrib", "key_attrib", 31, string("null")}
token{231,  "NAME_ATTRIB", string, 0, 0, "name_attrib", "name_attrib", 31, string("null")}
token{235,  "CAPITALIZE", string, 0, 0, "capitalize", "capitalize", 31, string("null")}
token{239,  "CAT", string, 0, 0, "cat", "cat", 31, string("null")}
token{243,  "COUNT_CHARACTERS", string, 0, 0, "count_characters", "count_characters", 31, string("null")}
token{247,  "COUNT_PARAGRAPHS", string, 0, 0, "count_paragraphs", "count_paragraphs", 31, string("null")}
token{251,  "COUNT_SENTENCES", string, 0, 0, "count_sentences", "count_sentences", 31, string("null")}
token{255,  "COUNT_WORDS", string, 0, 0, "count_words", "count_words", 31, string("null")}
token{259,  "DATE_FORMAT", string, 0, 0, "date_format", "date_format", 31, string("null")}
token{263,  "DEFAULT", string, 0, 0, "default", "default", 31, string("null")}
token{267,  "ESCAPE", string, 0, 0, "escape", "escape", 31, string("null")}
token{271,  "INDENT", string, 0, 0, "indent", "indent", 31, string("null")}
token{275,  "LOWER", string, 0, 0, "lower", "lower", 31, string("null")}
token{279,  "UPPER", string, 0, 0, "upper", "upper", 31, string("null")}
token{283,  "STRIP", string, 0, 0, "strip", "strip", 31, string("null")}
token{287,  "NL2BR", string, 0, 0, "nl2br", "nl2br", 31, string("null")}
token{291,  "REGX_REPLACE", string, 0, 0, "regx_replace", regx_replace, 31, string("null")}
token{295,  "REPLACE", string, 0, 0, "replace", "replace", 31, string("null")}
token{299,  "SPACIFY", string, 0, 0, "spacify", "spacify", 31, string("null")}
token{303,  "STRING_FORMAT", string, 0, 0, "string_format", "string_format", 31, string("null")}
token{307,  "STRIP_TAGS", string, 0, 0, "strip_tags", "strip_tags", 31, string("null")}
token{311,  "TRUNCATE", string, 0, 0, "truncate", "truncate", 31, string("null")}
token{315,  "WORDWRAP", string, 0, 0, "wordwrap", "wordwrap", 31, string("null")}
};
#endif
