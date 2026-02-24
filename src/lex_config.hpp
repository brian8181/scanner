
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
token{20, "SLASH", "string", 0, 0, "/", "/", 19, string("null")},
token{21, "BACK_SLASH", "string", 0, 0, "\\", "\\", 19, string("null")},

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

/**
 * built-ins
 */
token{30, "REQUIRE", "string", 0, 0, "require", "require", 23, string("null")},
token{31, "INCLUDE", "string", 0, 0, "include", "include", 23, string("null")},
token{32, "CONFIG_LOAD", "string", 0, 0, "config_load", "config_load", 23, string("null")}

};


#endif
