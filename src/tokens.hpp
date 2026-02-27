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

inline vector tokens_ = {
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

inline static int g_index = 0;
/**
 * @brief g_tokens
 */
inline vector g_tokens =
{
    /**
    * All
    */
    new token{++g_index, "DOLLAR_SIGN", "string", 0, 0, R"(\$)", "$",                                     g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "CARROT", "string", 0, 0, R"(\^)", "\\^",                                        g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "AMPERSAND", "string", 0, 0, R"(\*)", "\\*",                                     g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "ASTERISK", "string", 0, 0, R"(\*)", "\\*",                                      g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "LPAREN", "string", 0, 0, R"(\()", "\\(",                                        g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "RPAREN", "string", 0, 0, R"(\))", "\\)",                                        g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "MINUS", "string", 0, 0, "-", "-",                                               g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "PLUS", "string", 0, 0, R"(\+)", "\\+",                                          g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "EQUAL", "string", 0, 0, "=", "=",                                               g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "LBRACE", "string", 0, 0, R"(\{)", "\\{",                                        g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "RBRACE", "string", 0, 0, R"(\})", "\\}",                                        g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "LBRACKET", "string", 0, 0, R"(\[)", "\\[",                                      g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "RBRACKET", "string", 0, 0, R"(\])", "\\]",                                      g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "VBAR", "string", 0, 0, R"(\|)", "\\|",                                          g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "BACKSLASH", "string", 0, 0, R"(\\)", "\\\\",                                    g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "COLON", "string", 0, 0, ":", ":",                                               g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "SEMI_COLON", "string", 0, 0, ";", ";",                                          g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "DOUBLE_QUOTE", "string", 0, 0, "\"", "\"",                                     g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "SINGLE_QUOTE", "string", 0, 0, "'", "'",                                       g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "LESS_THAN", "string", 0, 0, "<", "<",                                          g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "GREATER_THAN", "string", 0, 0, ">", ">",                                       g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "QUESTION_MARK", "string", 0, 0, R"(\?)", "\\?",                                 g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "COMMA", "string", 0, 0, R"(\,)", "\\,",                                         g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "DOT_", "string", 0, 0, R"(\.)", "\\.",                                          g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "SLASH", "string", 0, 0, "/", "/",                                               g_index, string("null"), yy::parser::make_YYUNDEF()},
    /**
     * @brief operators
     */
    new token{++g_index, "NOT_EQUAL", "string", 0, 0, "!=", "!=",                                         g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "GREATER_THAN_EQUAL", "string", 0, 0, ">=", ">=",                               g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "LESS_THAN_EQUAL", "string", 0, 0, "<=", "<=",                                  g_index, string("null"), yy::parser::make_YYUNDEF()},
    /**
     * @brief types
     */
    new token{++g_index,  "NUMERIC_LITERAL", "string", 0, 0, "[0-9]+", "12345",                           g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "ARRAY", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*\[[^\]]\])", "/", g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "ID", "string", 0, 0, R"([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)", "/",             g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index, "SYMBOL", "string", 0, 0, R"(\$[a-zA-Z]+)", "\\$abc",                            g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "CONST_SYMBOL", "string", 0, 0, R"(#[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*#)", "/", g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "WHITESPACE", "string", 0, 0, R"([ \t])", "\\t",                                g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "UNESCAPED_TEXT", "string", 0, 0, R"([^{]+)", "testing ...",                    g_index, string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "ANYTHING", "string", 0, 0, ".", "~#",                                          g_index, string("null"), yy::parser::make_YYUNDEF()},
    /**
     * @brief keywords
     */
    new token{++g_index,  "IF", "string", 0, 0, "if", "if", g_index,                                               string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "ELSE", "string", 0, 0, "else", "else", g_index,                                         string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "ELSEIF", "string", 0, 0, "elseif", "elseif", g_index,                                   string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "FOREACH", "string", 0, 0, "foreach", "forech", g_index,                                 string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "WHILE", "string", 0, 0, "while", "while", g_index,                                      string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "DO", "string", 0, 0, "do", "do", g_index,                                               string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "BREAK", "string", 0, 0, "break", "break", g_index,                                      string("null"), yy::parser::make_YYUNDEF()},
    /**
     * @brief pre proces
     */
    new token{++g_index,  "ASSIGN", "string", 0, 0, "assign", "assign", g_index,                                   string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "REQUIRE", "string",     0, 0, "require",     "require",     g_index,                    string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "INCLUDE", "string",     0, 0, "include",     "include",     g_index,                    string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "CONFIG_LOAD", "string", 0, 0, "config_load", "config_load", g_index,                    string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "INSERT", "string",      0, 0, "insert",      "insert",      g_index,                    string("null"), yy::parser::make_YYUNDEF()},
    /**
     * @brief attributes
     */
    new token{++g_index,  "VAR_ATTRIB", "string", 0, 0, "var_attrib", "var_attrib", g_index,                       string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "VALUE_ATTRIB", "string", 0, 0, "value_attrib", "value_attrib", g_index,                 string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "FROM_ATTRIB", "string", 0, 0, "from_attrib", "from_attrib", g_index,                    string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "ITEM_ATTRIB", "string", 0, 0, "item_attrib", "item_attrib", g_index,                    string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "KEY_ATTRIB", "string", 0, 0, "key_attrib", "key_attrib", g_index,                       string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "NAME_ATTRIB", "string", 0, 0, "name_attrib", "name_attrib", g_index,                    string("null"), yy::parser::make_YYUNDEF()},
    /**
     * @brief built-ins
     */
    new token{++g_index,  "CAPITALIZE", "string", 0, 0, "capitalize", "capitalize", g_index,                       string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "CAT", "string", 0, 0, "cat", "cat", g_index,                                            string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "COUNT_CHARACTERS", "string", 0, 0, "count_characters", "count_characters", g_index,     string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "COUNT_PARAGRAPHS", "string", 0, 0, "count_paragraphs", "count_paragraphs", g_index,     string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "COUNT_SENTENCES", "string", 0, 0, "count_sentences", "count_sentences", g_index,        string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "COUNT_WORDS", "string", 0, 0, "count_words", "count_words", g_index,                    string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "DATE_FORMAT", "string", 0, 0, "date_format", "date_format", g_index,                    string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "DEFAULT", "string", 0, 0, "default", "default", g_index,                                string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "ESCAPE", "string", 0, 0, "escape", "escape", g_index,                                   string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "INDENT", "string", 0, 0, "indent", "indent", g_index,                                   string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "LOWER", "string", 0, 0, "lower", "lower", g_index,                                      string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "UPPER", "string", 0, 0, "upper", "upper", g_index,                                      string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "STRIP", "string", 0, 0, "strip", "strip", g_index,                                      string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "NL2BR", "string", 0, 0, "nl2br", "nl2br", g_index,                                      string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "REGX_REPLACE", "string", 0, 0, "regx_replace", "regx_replace", g_index,                 string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "REPLACE", "string", 0, 0, "replace", "replace", g_index,                                string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "SPACIFY", "string", 0, 0, "spacify", "spacify", g_index,                                string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "STRING_FORMAT", "string", 0, 0, "string_format", "string_format", g_index,              string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "STRIP_TAGS", "string", 0, 0, "strip_tags", "strip_tags", g_index,                       string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "TRUNCATE", "string", 0, 0, "truncate", "truncate", g_index,                             string("null"), yy::parser::make_YYUNDEF()},
    new token{++g_index,  "WORDWRAP", "string", 0, 0, "wordwrap", "wordwrap", g_index,                             string("null"), yy::parser::make_YYUNDEF()}
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
//new token{27, "UNESCAPED_TEXT", "string", 0, 0, R"([^{]+)", "testing ...", 19, string("null")},
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

inline map<int, vector<token_def *> > state_tokens_tab = {
    {INITIAL_, {state_comment}}, {COMMENT_, {state_comment}}, {ESCAPED_, {state_escaped}}
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
        default: ;
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
                    return yy::parser::make_DOUBLE_QUOTE(tok.value);
                case SINGLE_QUOTE:
                    cout << "SINGLE_QUOTE" << endl;
                    return yy::parser::make_SINGLE_QUOTE(tok.value);
                case SLASH:
                    cout << "SLASH" << endl;
                    return yy::parser::make_SLASH();
                case BACK_SLASH:
                    cout << "BACK_SLASH" << endl;
                    return yy::parser::make_BACK_SLASH(tok.value);
                case AT:
                    cout << "AT" << endl;
                    return yy::parser::make_AT(tok.value);
                    //case PLUS            : break;
                case MINUS:
                    cout << "MINUS" << endl;
                    return yy::parser::make_MINUS();
                case ASTERIK:
                    cout << "ASTERISK" << endl;
                    return yy::parser::make_ASTERISK();
                case EQUAL:
                    cout << "EQUAL" << endl;
                    return yy::parser::make_EQUAL();
                case NOT_EQUAL:
                    cout << "NOT_EQUAL" << endl;
                    return yy::parser::make_NOT_EQUAL();
                    //case DOT             : break;
                    //case INDIRECT_MEMBER_SELECT: break;
                case PERCENT:
                    cout << "PERCENT" << endl;
                    return yy::parser::make_PERCENT();
                case AMPERSAND:
                    cout << "AMPERSAND" << endl;
                    return yy::parser::make_AMPERSAND(tok.value);
                case NOT:
                    cout << "NOT" << endl;
                    return yy::parser::make_NOT(tok.value);
                case AND:
                    cout << "AND" << endl;
                    return yy::parser::make_AND(tok.value);
                case OR:
                    cout << "OR:" << endl;
                    return yy::parser::make_OR(tok.value);
                case LESS_THAN:
                    cout << "LESS_THAN" << endl;
                    return yy::parser::make_LESS_THAN();
                case LESS_THAN_EQUAL:
                    cout << "LESS_THAN_EQUAL" << endl;
                    return yy::parser::make_LESS_THAN_EQUAL();
                case GREATER_THAN:
                    cout << "GREATER_THAN" << endl;
                    return yy::parser::make_GREATER_THAN();
                case GREATER_THAN_EQUAL:
                    cout << "GREATER_THAN_EQUAL" << endl;
                    return yy::parser::make_GREATER_THAN_EQUAL();
                case NUMERIC_LITERAL:
                    cout << "NUMERIC_LITERAL" << endl;
                    return yy::parser::make_NUMERIC_LITERAL(tok.value);
                case REQUIRE:
                    cout << "REQUIRE" << endl;
                    return yy::parser::make_REQUIRE(tok.value);
                case CONFIG_LOAD:
                    cout << "CONFIG_LOAD" << endl;
                    return yy::parser::make_CONFIG_LOAD(tok.value);
                case INSERT:
                    cout << "INSERT" << endl;
                    return yy::parser::make_INSERT(tok.value);
                case INCLUDE:
                    cout << "INCLUDE" << endl;
                    return yy::parser::make_INCLUDE(tok.value);
                case FILE_ATTRIB:
                    cout << "FILE_ATTRIB" << endl;
                    return yy::parser::make_FILE_ATTRIB(tok.value);
                case ASSIGN:
                    cout << "ASSIGN" << endl;
                    return yy::parser::make_ASSIGN(tok.value);
                case VAR_ATTRIB:
                    cout << "VAR_ATTRIB" << endl;
                    return yy::parser::make_VAR_ATTRIB(tok.value);
                case VALUE_ATTRIB:
                    cout << "VALUE_ATTRIB" << endl;
                    return yy::parser::make_VALUE_ATTRIB(tok.value);
                case FROM_ATTRIB:
                    cout << "FROM_ATTRIB" << endl;
                    //return yy::parser::make_FROM_ATTRIB(tok.value);
                case ITEM_ATTRIB:
                    cout << "ITEM_ATTRIB" << endl;
                    break;
                case KEY_ATTRIB:
                    cout << "KEY_ATTRIB" << endl;
                    //return yy::parser::make_KEY_ATTRIB(tok.value);
                case NAME_ATTRIB:
                    cout << "NAME_ATTRIB" << endl;
                    ///return yy::parser::make_NAME_ATTRIB(tok.value);
            }
        }
        default: ;
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
