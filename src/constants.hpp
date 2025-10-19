#ifndef _CONSTANTS_HPP
#define _CONSTANTS_HPP

#include <string>
#include <utility>
#include <map>

//using std::string;

using namespace std;

/*
    The basic source character set consists of 96 characters:
    the space character, the control characters representing horizontal tab,
    vertical tab, form feed, and new-line, plus the following 91 graphical characters
        a b c d e f g h i j k l m n o p q r s t u v w x y z
        A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
        0 1 2 3 4 5 6 7 8 9
        _ { } [ ] # ( ) < > % : ; . ? * + - / ˆ & | ˜ ! = , \ " ’ \
*/

// utility
const string CAPTIAL_LETTER       = "[A-Z]";
const string LETTER               = "[a-z]";
const string DIGIT                = "[0-9]";
const string HEX_DIGIT            = "[A-F0-9]";
const string VALID_SYMBOL_CHARS   = "[A-Za-z0-9_]"; /** @note_to_self: ~~> \w == [A-Za-z0-9_] **/
const string VALID_CHARS          = "[ [:punct:][:alnum:]]"; // [:punct:] = !"#$%&'()*+,-./:;<=>?@[\]^_{|}~`
const string VALID_FILE_CHARS     = "[A-Za-z0-9_. ]";
const string CONFIG_PAIR          = "\\s*([A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*((" + VALID_CHARS + "*))\\s*";
const string CONFIG_PAIR_VAR      = "\\s*([A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*($[A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*";
const string CONFIG_COMMENT       = "^\\s*#.*$";
const string PREPROCESSOR         = "#[A-Za-z_]+";
const string COMMENT              = "(//.*$)|(\\/\\*[\\s\\S]*?\\*\\/)";
const string FILE_NAME            = "[0-9A-Za-z_\\.]+";
// literals
const string FLOAT_LITERAL        = "[0-9]*\\.[0-9]+";
const string INTEGER_LITERAL      = DIGIT + "+";
const string HEX_LITERAL          = "0x" + HEX_DIGIT+ "+";
const string STRING_LITERAL       = "\"" + VALID_CHARS + "*\"";
const string CHAR_LITERAL         = "'[a-zA-Z0-9_{}\\[\\]#()<>%:;.?*+-\\/^&|~!=,\"]'";
// declration
const string TYPES                = "(char)|(int)|(float)|(double)|(string)|(long)|(short)|(bool)|(void)";
const string TYPE_MODIFIERS       = "(signed)|(unsigned)|(static)|(const)|(volatile)";
const string SYMBOL               = "_?[A-Za-z][A-Za-z0-9_]*";
// keywords
const string KEYWORDS             = "(if)|(else)|(for)|(while)|(return)|(break)|(continue)|(switch)|(case)|(default)|(do)|(goto)|(sizeof)";
// punctuations
const string ASTERIK              = "\\*";
const string AMPERSAND            = "&";
const string SEMI_COLON           = ";";
const string COMMA                = ",";
const string DOT                  = "\\.";
const string OPEN_PAREN           = "\\(";
const string CLOSE_PAREN          = "\\)";
const string OPEN_BRACKET         = "\\[";
const string CLOSE_BRACKET        = "\\]";
const string OPEN_BRACE           = "\\{";
const string CLOSE_BRACE          = "\\}";
const string DOUBLE_QUOTE         = "\"";
const string SINGLE_QUOTE         = "'";
const string TICK_MARK            = "`";
const string FORWARD_SLASH        = "/";
const string BACKWARD_SLASH       = "\\\\";
const string EQUAL                = "=";
const string TILDE                = "~";
const string VBAR                 = "\\|";
const string CARROT               = "\\^";
const string PERCENT              = "%";
const string EXCLAMATION          = "!";
// operators
const string PLUS                 = "\\+";
const string MINUS                = "-";
// multi char operators
const string BIT_SHIFT_LEFT       = "<<";
const string BIT_SHIFT_RIGHT      = ">>";
const string AND                  = "&&";
const string OR                   = "\\|\\|";
const string EQUALS_EQUAL         = "==";
const string NOT_EQUAL            = "!=";
const string LESS_THAN            = "<";
const string GREATER_THAN         = ">";
const string LESS_THAN_EQUAL      = "<=";
const string GREATER_THAN_EQUAL   = ">=";
const string SCOPE_RESOLUTION     = "::";
const string INDIRECT_SELECTION   = "->";

// groups
const string OPERATORS            = "(" + BIT_SHIFT_LEFT        + ")|" +
                                    "(" + BIT_SHIFT_RIGHT       + ")|" +
                                    "(" + NOT_EQUAL             + ")|" +
                                    "(" + AND                   + ")|" +
                                    "(" + OR                    + ")|" +
                                    "(" + LESS_THAN             + ")|" +
                                    "(" + GREATER_THAN          + ")|" +
                                    "(" + LESS_THAN_EQUAL       + ")|" +
                                    "(" + GREATER_THAN_EQUAL    + ")|" +
                                    "(" + SCOPE_RESOLUTION      + ")|" +
                                    "(" + INDIRECT_SELECTION    + ")|" +
                                    "(" + EQUAL                 + ")|" +
                                    "(" + PLUS                  + ")|" +
                                    "(" + MINUS                 + ")|" +
                                    "(" + ASTERIK               + ")|" +
                                    "(" + FORWARD_SLASH         + ")|" +
                                    "(" + PERCENT               + ")";
const string PUNCTUATION          = "(" + SEMI_COLON            + ")|" +
                                    "(" + COMMA                 + ")|" +
                                    "(" + DOT                   + ")|" +
                                    "(" + OPEN_BRACE            + ")|" +
                                    "(" + CLOSE_BRACE           + ")|" +
                                    "(" + OPEN_PAREN            + ")|" +
                                    "(" + CLOSE_PAREN           + ")|" +
                                    "(" + OPEN_BRACKET          + ")|" +
                                    "(" + CLOSE_BRACKET         + ")|" +
                                    "(" + DOUBLE_QUOTE          + ")|" +
                                    "(" + SINGLE_QUOTE          + ")|" +
                                    "(" + TICK_MARK             + ")";
const string DECL                 = "(" + TYPES                 + ")|" +
                                    "(" + TYPE_MODIFIERS        + ")|" +
                                    "(" + SYMBOL                + ")";
const string LITERAL              = "(" + STRING_LITERAL        + ")|" +
                                    "(" + FLOAT_LITERAL         + ")|" +
                                    "(" + INTEGER_LITERAL       + ")|" +
                                    "(" + HEX_LITERAL           + ")|" +
                                    "(" + CHAR_LITERAL          + ")";
const string EVERYTHING           =       LITERAL               + "|"
                                        + OPERATORS             + "|"
                                        + PUNCTUATION           + "|"
                                        + DECL;
/**
 * @brief Enumeration of token IDs
 */
enum token_id : unsigned long
{
    ID_UNDEFINED                  = 0,
    ID_LETTER                     = 55,
    ID_CAPITAL_LETTER             = 60,
    ID_DIGIT                      = 72,
    ID_TILDE                      = 102,
    ID_TICK_MARK                  = 104,
    ID_EXCLAMATION                = 105,
    ID_LOGICAL_NOT                = 105,
    ID_AT_SIGN                    = 106,
    ID_POUND_SIGN                 = 108,
    ID_DOLLAR_SIGN                = 109,
    ID_PERCENT_SIGN               = 290,
    ID_CARROT_SIGN                = 500,
    ID_BITWISE_XOR                = 500,
    ID_AMPERSAND                  = 131,
    ID_BITWISE_AND                = 131,
    ID_ASTERIK                    = 130,
    ID_MULTIPLY_OP                = 130,
    ID_OPEN_PAREN                 = 270,
    ID_CLOSE_PAREN                = 280,
    ID_UNDERSCORE                 = 141,
    ID_MINUS                      = 250,
    ID_SUBTRACT_OP                = 250,
    ID_PLUS                       = 260,
    ID_ADD_OP                     = 260,
    ID_EQUAL                      = 170,
    ID_ASSIGN_OP                  = 170,
    ID_OPEN_BRACE                 = 70,
    ID_CLOSE_BRACE                = 80,
    ID_OPEN_BRACKET               = 110,
    ID_CLOSE_BRACKET              = 120,
    ID_VBAR                       = 190,
    ID_BITWISE_OR                 = 190,
    ID_BACKWARD_SLASH             = 140,
    ID_COLON                      = 200,
    ID_SEMI_COLON                 = 132,
    ID_SINGLE_QUOTE               = 60,
    ID_DOUBLE_QUOTE               = 50,
    ID_LESS_THAN                  = 230,
    ID_LT                         = 230,
    ID_COMMA                      = 165,
    ID_GREATER_THAN               = 240,
    ID_GT                         = 240,
    ID_DOT                        = 160,
    ID_FORWARD_SLASH              = 139,
    ID_DIVISION_OP                = 139,
    ID_QUESTION_MARK              = 480,

    ID_IF                         = 10,
    ID_ELSE                       = 20,
    ID_WHILE                      = 30,
    ID_DO                         = 35,
    ID_CONTINUE                   = 40,
    ID_BREAK                      = 44,
    ID_RETURN                     = 46,

    ID_LESS_THAN_EQUAL            = 235,
    ID_LE                         = 235,
    ID_GREATER_THAN_EQUAL         = 245,
    ID_GE                         = 245,

    ID_LOGICAL_EQUAL              = 340,
    ID_LOGICAL_OR                 = 322,
    ID_LOGICAL_AND                = 324,
    ID_BIT_SHIFT_LEFT             = 540,
    ID_BIT_SHIFT_RIGHT            = 550,
    ID_LITERAL                    = 100,
    ID_NUMERIC_LITERAL            = 600,
    ID_STRING_LITERAL             = 610,
    ID_SYMBOL_NAME                = 620,
    ID_SCOPE_RESOLUTION           = 630,
    ID_INDIRECT_SELECTION         = 640


};

// map<string, std::pair<unsigned int, string>> _token_map = {
//                                                                 {"a",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"b",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"c",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"d",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"e",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"f",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"g",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"h",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"i",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"j",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"k",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"l",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"m",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"n",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"o",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"p",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"q",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"r",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"s",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"t",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"u",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"v",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"w",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"x",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"y",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"z",        {ID_LETTER,           "ID_LETTER"         }},
//                                                                 {"A",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"B",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"C",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"D",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"E",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"F",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"G",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"H",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"I",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"J",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"K",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"L",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"M",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"N",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"O",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"P",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"Q",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"R",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"S",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"T",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"U",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"V",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"W",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"X",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"Y",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"Z",        {ID_CAPITAL_LETTER,   "ID_CAPITAL_LETTER" }},
//                                                                 {"0",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"1",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"2",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"3",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"4",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"5",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"6",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"7",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"8",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"9",        {ID_DIGIT,            "ID_DIGIT"          }},
//                                                                 {"~",        {ID_TILDE,            "ID_TILDE"          }},
//                                                                 {"`",        {ID_TICK_MARK,        "ID_TICK_MARK"      }},
//                                                                 {"@",        {ID_AT_SIGN,          "ID_AT_SYMBOL"      }},
//                                                                 {"#",        {ID_POUND_SIGN,       "ID_POUND_SIGN"     }},
//                                                                 {"$",        {ID_DOLLAR_SIGN,      "ID_DOLLAR_SIGN"    }},
//                                                                 {"%",        {ID_PERCENT_SIGN,     "ID_PERCENT_SIGN"   }},

//                                                                 {"^",        {ID_CARROT_SIGN,      "ID_CARROT_SIGN"    }},
//                                                                 {"&",        {ID_AMPERSAND,        "ID_AMPERSAND"      }},
//                                                                 {"*",        {ID_ASTERIK,          "ID_ASTERIK"        }},
//                                                                 {"(",        {ID_OPEN_PAREN,       "ID_OPEN_PAREN"     }},
//                                                                 {")",        {ID_CLOSE_PAREN,      "ID_CLOSE_PAREN"    }},
//                                                                 {"-",        {ID_MINUS,            "ID_MINUS"          }},
//                                                                 {"_",        {ID_UNDERSCORE,       "ID_UNDERSCORE"     }},
//                                                                 {"+",        {ID_PLUS,             "ID_PLUS"           }},
//                                                                 {"=",        {ID_EQUAL,            "ID_EQUAL"          }},
//                                                                 {"{",        {ID_OPEN_BRACE,       "ID_OPEN_BRACE"     }},
//                                                                 {"[",        {ID_OPEN_BRACKET,     "ID_OPEN_BRACKET"   }},
//                                                                 {"}",        {ID_CLOSE_BRACE,      "ID_CLOSE_BRACE"    }},
//                                                                 {"]",        {ID_CLOSE_BRACKET,    "ID_CLOSE_BRACKET"  }},
//                                                                 {"|",        {ID_VBAR,             "ID_VBAR"           }},
//                                                                 {"/",        {ID_BACKWARD_SLASH,   "ID_BACKWARD_SLASH" }},
//                                                                 {":",        {ID_COLON,            "ID_COLON"          }},
//                                                                 {";",        {ID_SEMI_COLON,       "ID_SEMI_COLON"     }},
//                                                                 {"\"",       {ID_DOUBLE_QUOTE,     "ID_DOUBLE_QUOTE"   }},
//                                                                 {"'",        {ID_SINGLE_QUOTE,     "ID_SINGLE_QUOTE"   }},
//                                                                 {"<",        {ID_LESS_THAN,        "ID_LESS_THAN"      }},
//                                                                 {",",        {ID_COMMA,            "ID_COMMA"          }},
//                                                                 {">",        {ID_GREATER_THAN,     "ID_GREATER_THAN"   }},
//                                                                 {".",        {ID_DOT,              "ID_DOT"            }},
//                                                                 {"?",        {ID_QUESTION_MARK,    "ID_QUESTION_MARK"  }},
//                                                                 {"/",        {ID_FORWARD_SLASH,    "ID_FORWARD_SLASH"  }},
//                                                                 {"==",       {ID_LOGICAL_EQUAL,    "ID_LOGICAL_EQUAL"  }},
//                                                                 {"&&",       {ID_LOGICAL_AND,      "ID_LOGICAL_AND"    }},
//                                                                 {"||",       {ID_LOGICAL_OR,       "ID_LOGICAL_OR"     }},
//                                                                 {"<<",       {ID_BIT_SHIFT_LEFT,   "ID_BIT_SHIFT_LEFT" }},
//                                                                 {">>",       {ID_BIT_SHIFT_RIGHT,  "ID_BIT_SHIFT_RIGHT"}},
//                                                                 {"!",        {ID_EXCLAMATION,      "ID_EXCLAMATION"    }},
//                                                                 {"if",       {ID_IF,               "ID_IF"             }},
//                                                                 {"if",       {ID_DO,               "ID_DO"             }},
//                                                                 {"while",    {ID_WHILE,            "ID_WHILE"          }},
//                                                                 {"else",     {ID_ELSE,             "ID_ELSE"           }},
//                                                                 {"continue", {ID_CONTINUE,         "ID_CONTINUE"       }},
//                                                                 {"break",    {ID_BREAK,            "ID_BREAK"          }},
//                                                                 {"return",   {ID_RETURN,           "ID_RETURN"         }}
//                                                             };

#endif // _CONSTANTS_HPP
