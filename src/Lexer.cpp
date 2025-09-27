
/**
 * @file    Lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 * @info    ...
 */
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <regex>
#include "constants.hpp"
#include "fileio.hpp"
#include "Lexer.hpp"

// using std::string;
// using std::vector;
// using std::map;
// using std::pair;

using namespace std;

map<string, std::pair<unsigned int, string>> _token_map = {
                                                                {"a",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"b",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"c",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"d",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"e",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"f",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"g",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"h",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"i",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"j",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"k",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"l",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"m",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"n",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"o",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"p",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"q",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"r",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"s",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"t",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"u",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"v",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"w",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"x",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"y",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"z",        {ID_LETTER,           "ID_LETTER"         }},
                                                                {"A",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"B",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"C",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"D",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"E",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"F",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"G",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"H",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"I",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"J",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"K",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"L",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"M",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"N",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"O",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"P",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"Q",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"R",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"S",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"T",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"U",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"V",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"W",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"X",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"Y",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"Z",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
                                                                {"0",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"1",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"2",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"3",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"4",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"5",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"6",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"7",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"8",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"9",        {ID_DIGIT,            "ID_DIGIT"          }},
                                                                {"~",        {ID_TILDE,            "ID_TILDE"          }},
                                                                {"`",        {ID_TICK_MARK,        "ID_TICK_MARK"      }},
                                                                {"@",        {ID_AT_SIGN,          "ID_AT_SYMBOL"      }},
                                                                {"#",        {ID_POUND_SIGN,       "ID_POUND_SIGN"     }},
                                                                {"$",        {ID_DOLLAR_SIGN,      "ID_DOLLAR_SIGN"    }},
                                                                {"%",        {ID_PERCENT_SIGN,     "ID_PERCENT_SIGN"   }},
                                                                {"^",        {ID_CARROT_SIGN,      "ID_CARROT_SIGN"    }},
                                                                {"&",        {ID_AMPERSAND,        "ID_AMPERSAND"      }},
                                                                {"*",        {ID_ASTERIK,          "ID_ASTERIK"        }},
                                                                {"(",        {ID_OPEN_PAREN,       "ID_OPEN_PAREN"     }},
                                                                {")",        {ID_CLOSE_PAREN,      "ID_CLOSE_PAREN"    }},
                                                                {"-",        {ID_MINUS,            "ID_MINUS"          }},
                                                                {"_",        {ID_UNDERSCORE,       "ID_UNDERSCORE"     }},
                                                                {"+",        {ID_PLUS,             "ID_PLUS"           }},
                                                                {"=",        {ID_EQUAL,            "ID_EQUAL"          }},
                                                                {"{",        {ID_OPEN_BRACE,       "ID_OPEN_BRACE"     }},
                                                                {"[",        {ID_OPEN_BRACKET,     "ID_OPEN_BRACKET"   }},
                                                                {"}",        {ID_CLOSE_BRACE,      "ID_CLOSE_BRACE"    }},
                                                                {"]",        {ID_CLOSE_BRACKET,    "ID_CLOSE_BRACKET"  }},
                                                                {"|",        {ID_VBAR,             "ID_VBAR"           }},
                                                                {"/",        {ID_BACKWARD_SLASH,   "ID_BACKWARD_SLASH" }},
                                                                {":",        {ID_COLON,            "ID_COLON"          }},
                                                                {";",        {ID_SEMI_COLON,       "ID_SEMI_COLON"     }},
                                                                {"\"",       {ID_DOUBLE_QUOTE,     "ID_DOUBLE_QUOTE"   }},
                                                                {"'",        {ID_SINGLE_QUOTE,     "ID_SINGLE_QUOTE"   }},
                                                                {"<",        {ID_LESS_THAN,        "ID_LESS_THAN"      }},
                                                                {",",        {ID_COMMA,            "ID_COMMA"          }},
                                                                {">",        {ID_GREATER_THAN,     "ID_GREATER_THAN"   }},
                                                                {".",        {ID_DOT,              "ID_DOT"            }},
                                                                {"?",        {ID_QUESTION_MARK,    "ID_QUESTION_MARK"  }},
                                                                {"/",        {ID_FORWARD_SLASH,    "ID_FORWARD_SLASH"  }},
                                                                {"==",       {ID_LOGICAL_EQUAL,    "ID_LOGICAL_EQUAL"  }},
                                                                {"&&",       {ID_LOGICAL_AND,      "ID_LOGICAL_AND"    }},
                                                                {"||",       {ID_LOGICAL_OR,       "ID_LOGICAL_OR"     }},
                                                                {"<<",       {ID_BIT_SHIFT_LEFT,   "ID_BIT_SHIFT_LEFT" }},
                                                                {">>",       {ID_BIT_SHIFT_RIGHT,  "ID_BIT_SHIFT_RIGHT"}},
                                                                {"!",        {ID_EXCLAMATION,      "ID_EXCLAMATION"    }},
                                                                {"if",       {ID_IF,               "ID_IF"             }},
                                                                {"if",       {ID_DO,               "ID_DO"             }},
                                                                {"while",    {ID_WHILE,            "ID_WHILE"          }},
                                                                {"else",     {ID_ELSE,             "ID_ELSE"           }},
                                                                {"continue", {ID_CONTINUE,         "ID_CONTINUE"       }},
                                                                {"break",    {ID_BREAK,            "ID_BREAK"          }},
                                                                {"return",   {ID_RETURN,           "ID_RETURN"         }}
                                                            };

Lexer::Lexer()
{

}

Lexer::Lexer( const Lexer& src )
{

}

Lexer::~Lexer()
{

}

/**
 * @brief  load_config: load confiuration from file
 * @param  const string &path
 * @return void
 */
void Lexer::load_config( const string &path )
{
    const unsigned int ID_NAME_VALUE_PAIR = 0;
    const unsigned int ID_NAME = 1;
    const unsigned int ID_VALUE = 2;
    const unsigned int ID_NUMERIC_LITERAL = 2;
    const unsigned int ID_STRING_LITERAL = 3;

    // get configuration file by lines
    vector<string> lines;
    lines = read_lines(path, lines);
    // create one only section (global)
    string section_name = "global";
    map<string, string> section_map;
    pair<string, map<string, string>> sp(section_name, section_map);
    map_sections_config.insert(sp);

    int len = lines.size();
    for (int i = 0; i < len; ++i)
    {
        string line = lines[i];
        regex rgx = regex(CONFIG_PAIR);
        smatch match;
        regex_match(line, match, rgx);

        if (match[ID_NAME_VALUE_PAIR].matched)
        {
            // get name
            string symbol_name = match[ID_NAME].str();
            // get value
            string value = (match[ID_VALUE].matched) ? match[ID_NUMERIC_LITERAL].str() : match[ID_STRING_LITERAL].str();
            // create pair
            pair<string, string> p(symbol_name, value);
            map_sections_config[section_name].insert(p);
        }
    }
}

/**
 * @brief start tokenizing file
 * @param file
 * @return void
 */
void Lexer::start(string file)
{
    cout << "Starting lexical analysis on file: " << file << endl;
    stringstream sstrm;
    ifstream strm(file, ios::in);
    if (strm.is_open())
    {
        cout << file << "-> opened ..." << endl;
        char c;
        while (strm.get(c))
        {
            sstrm << c;
        }
    }
    else
    {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    string str = sstrm.str();
    tokenize(EVERYTHING, str);
}

/**
 * @brief
 * @param iter
 * @param id
 * @return
 */
int Lexer::get_token(std::sregex_iterator& iter, unsigned int& token)
{
    iter++;
    std::smatch m = *iter;
    token = _token_map[m.str()].first;
   return 0;
}

/**
 * @brief tokenize
 * @param exp The regular expression to match
 * @param text The text to search for matches
 */
void Lexer::tokenize(const string &exp, const string &text)
{
    regex rexp = regex(exp, regex::ECMAScript);
    sregex_iterator begin = sregex_iterator(text.begin(), text.end(), rexp);
    sregex_iterator end;
    for (std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch m = *iter;
        if( _token_map.contains(m.str()) )
        {
            int id = _token_map[m.str()].first;
            string name = _token_map[m.str()].second;
            cout << "{\n\tid: " << id << "\n\tname: " << name << "\n\ttoken: '" << m.str() << "'\n\tpos: " << m.position(0) << "\n};" << endl;
        }
        else
        {
            cout << "{\n\tid: null" << "\n\ttoken: '" << m.str() << "'\n\tpos: " << m.position(0) << "\n};" << endl;
        }
    }
}
