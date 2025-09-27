#ifndef _CTERMINALS_HPP
#define _CTERMINALS_HPP

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
const string VALID_CHARS          = "[\\w\\s\\[\\]+-=|$><^/#@~&*.%!~`_:;',()]";
const string VALID_FILE_CHARS     = "[A-Za-z0-9_. ]";
const string CONFIG_PAIR          = "\\s*([A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*((" + VALID_SYMBOL_CHARS + "*)|(\"" + VALID_CHARS + "*\"))\\s*";
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
    ID_LETTER                     = 10,
    ID_CAPITAL_LETTER             = 15,
    ID_DIGIT                      = 20,
    ID_TILDE                      = 102,
    ID_TICK_MARK                  = 104,
    //ID_EXCLAMATION                = 105,
    ID_LOGICAL_NOT                = 220,
    ID_AT_SIGN                    = 106,
    ID_POUND_SIGN                 = 108,
    ID_DOLLAR_SIGN                = 109,
    ID_PERCENT_SIGN               = 290,
    ID_CARROT_SIGN                = 500,
    ID_AMPERSAND                  = 131,
    //ID_LOGICAL_AND                = 300,
    ID_ASTERIK                    = 130,
    ID_OPEN_PAREN                 = 270,
    ID_CLOSE_PAREN                = 280,
    ID_UNDERSCORE                 = 141,
    ID_MINUS                      = 250,
    ID_PLUS                       = 260,
    ID_EQUAL                      = 170,
    ID_OPEN_BRACE                 = 70,
    ID_CLOSE_BRACE                = 80,
    ID_OPEN_BRACKET               = 110,
    ID_CLOSE_BRACKET              = 120,
    //ID_LOGICAL_OR                 = 310,
    ID_VBAR                       = 190,
    ID_BACKWARD_SLASH             = 140,
    ID_COLON                      = 200,
    ID_SEMI_COLON                 = 132,
    ID_SINGLE_QUOTE               = 60,
    ID_DOUBLE_QUOTE               = 50,
    ID_LESS_THAN                  = 230,
    ID_COMMA                      = 165,
    ID_GREATER_THAN               = 240,
    ID_DOT                        = 160,
    ID_FORWARD_SLASH              = 139,
    ID_QUESTION_MARK              = 480,

    //
    ID_IF                         = 10,
    ID_ELSE                       = 20,
    ID_WHILE                      = 30,
    ID_DO                         = 35,
    ID_CONTINUE                   = 40,
    ID_BREAK                      = 44,
    ID_RETURN                     = 46,
    ID_LESS_THAN_EQUAL            = 235,
    ID_GREATER_THAN_EQUAL         = 245,



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

#endif // _CTERMINALS_HPP
