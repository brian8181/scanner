#ifndef _CTERMINALS_HPP
#define _CTERMINALS_HPP

#include <string>
using std::string;

const string PREPROCESSOR       = "#[A-Za-z_]+";
const string COMMENT            = "(//.*$)|(\\/\\*[\\s\\S]*?\\*\\/)";
/// terminals
const string TYPES              = "(char)|(int)|(float)|(double)|(string)|(long)|(short)|(bool)|(void)";
const string TYPE_MODIFIERS     = "(signed)|(unsigned)|(static)|(const)|(volatile)";
const string KEYWORDS           = "(if)|(else)|(for)|(while)|(return)|(break)|(continue)|(switch)|(case)|(default)|(do)|(goto)|(sizeof)";
const string VALID_SYMBOL_CHARS = "[A-Za-z0-9_]";
const string VALID_CHARS        = "[\\w\\s\\[\\]+-=|$><^/#@~&*.%!~`_:;',()]";
const string VALID_FILE_CHARS   = "[A-Za-z0-9_. ]";
const string SYMBOL             = "_?[A-Za-z][A-Za-z0-9_]*";
// punctuations
const string ASTERIK            = "\\*";
const string AMPERSAND          = "&";
const string SEMI_COLON         = ";";
const string COMMA              = ",";
const string DOT                = "\\.";
const string OPEN_PAREN         = "\\(";
const string CLOSE_PAREN        = "\\)";
const string OPEN_BRACKET       = "\\[";
const string CLOSE_BRACKET      = "\\]";
const string OPEN_BRACE         = "\\{";
const string CLOSE_BRACE        = "\\}";
const string DOUBLE_QUOTE       = "\"";
const string SINGLE_QUOTE       = "'";
const string TICK_MARK          = "`";
const string FORWARD_SLASH      = "/";
const string BACKWARD_SLASH     = "\\\\";
const string EQUAL              = "=";
const string TILDE              = "~";
const string VBAR               = "\\|";
const string CARROT             = "\\^";
const string PERCENT            = "%";
const string EXCLAMATION        = "!";
// operators
const string PLUS               = "\\+";
const string MINUS              = "-";
const string BIT_SHIFT_LEFT     = "<<";
const string BIT_SHIFT_RIGHT    = ">>";
const string AND                = "&&";
const string OR                 = "\\|\\|";
const string EQUALS_EQUAL       = "==";
const string NOT_EQUAL          = "!=";
const string LESS_THAN          = "<";
const string GREATER_THAN       = ">";
const string LESS_THAN_EQUAL    = "<=";
const string GREATER_THAN_EQUAL = ">=";
const string SCOPE_RESOLUTION   = "::";
const string INDIRECT_SELECTION = "->";

//
const string LOGICAL_OPERATORS    = "(" + EQUAL              + ")|" +
                                    "(" + EXCLAMATION        + ")|" +
                                    "(" + NOT_EQUAL          + ")|" +
                                    "(" + AND                + ")|" +
                                    "(" + OR                 + ")|" +
                                    "(" + LESS_THAN          + ")|" +
                                    "(" + GREATER_THAN       + ")|" +
                                    "(" + LESS_THAN_EQUAL    + ")|" +
                                    "(" + GREATER_THAN_EQUAL + ")";
//
const string PUNCTUATION          = "(" + SEMI_COLON          + ")|" +
                                    "(" + COMMA               + ")|" +
                                    "(" + DOT                 + ")|" +
                                    "(" + SCOPE_RESOLUTION    + ")|" +
                                    "(" + OPEN_BRACE          + ")|" +
                                    "(" + CLOSE_BRACE         + ")|" +
                                    "(" + OPEN_PAREN          + ")|" +
                                    "(" + CLOSE_PAREN         + ")|" +
                                    "(" + OPEN_BRACKET        + ")|" +
                                    "(" + CLOSE_BRACKET       + ")|" +
                                    "(" + DOUBLE_QUOTE        + ")|" +
                                    "(" + SINGLE_QUOTE        + ")|" +
                                    "(" + TICK_MARK           + ")";

const string ARITHMETIC_OPERATORS = "(" + PLUS               + ")|" +
                                    "(" + MINUS              + ")|" +
                                    "(" + ASTERIK            + ")|" +
                                    "(" + FORWARD_SLASH      + ")|" +
                                    "(" + PERCENT            + ")";

const string DECL                 = "(" + TYPES               + ")|" +
                                    "(" + TYPE_MODIFIERS      + ")|" +
                                    "(" + SYMBOL              + ")";

//
const string OPERATORS            = "([,/'\"$*#=+-:!%<>|.(){}\\]\\[])";
const string FILE_NAME            = "[0-9A-Za-z_\\.]+";
const string FLOAT_LITERAL        = "([0-9]*\\.[0-9]+)";
const string INTEGER_LITERAL      = "([0-9]+)";
const string HEX_LITERAL          = "(0x[0-9A-Fa-f]+)";
const string SYMBOL_NAME          = "\\$?_*[A-Za-z]" + VALID_SYMBOL_CHARS + "*";
const string STRING_LITERAL       = "\"" + VALID_CHARS + "*\"";
const string LITERAL              = "(" + STRING_LITERAL      + ")|" +
                                    "(" + INTEGER_LITERAL     + ")|" +
                                    "(" + FLOAT_LITERAL       + ")";

/**
 * @brief Enumeration of token IDs.
 */
enum token_id : unsigned long
{
    ID_UNDEFINED               = 0,
    ID_IF                      = 10,
    ID_ELSE                    = 20,
    ID_ELSEIF                  = 30,
    ID_DOUBLE_QUOTE            = 50,
    ID_SINGLE_QUOTE            = 60,
    ID_OPEN_BRACE              = 70,
    ID_CLOSE_BRACE             = 80,
    ID_LITERAL                 = 100,
    ID_OPEN_BRACKET            = 110,
    ID_CLOSE_BRACKET           = 120,
    ID_ASTERIK                 = 130,
    ID_FORWARD_SLASH           = 132,
    ID_BACKWARD_SLASH          = 134,
    ID_POUND_SIGN              = 140,
    ID_DOLLAR_SIGN             = 150,
    ID_DOT                     = 160,
    ID_EQUAL                   = 170,
    ID_BUILTIN_FUNCTION        = 180,
    ID_VBAR                    = 190,
    ID_COLON                   = 200,
    ID_SEMI_COLON              = 210,
    ID_LOGICAL_NOT             = 220,
    ID_LESS_THAN               = 230,
    ID_GREATER_THAN            = 240,
    ID_MINUS                   = 250,
    ID_PLUS                    = 260,
    ID_OPEN_PAREN              = 270,
    ID_CLOSE_PAREN             = 280,
    ID_PERCENT                 = 290,
    ID_LOGICAL_AND             = 300,
    ID_LOGICAL_OR              = 310,

    ID_LOGICAL_EQUAL           = 340,
    ID_MODIFIER_CAPATIALIZE    = 350,
    ID_MODIFIER_INDENT         = 360,
    ID_MODIFIER_LOWER          = 370,
    ID_MODIFIER_UPPER          = 380,
    ID_MODIFIER_TRUNCATE       = 390,
    ID_MODIFIER_SPACIFY        = 400,
    ID_MODIFIER_STRINGF_FORMAT = 410,
    ID_MODIFIER_DATE_FORMAT    = 420,
    ID_MODIFIER_ESCAPE         = 440,
    ID_UNESCAPED_TEXT          = 450,
    ID_INCLUDE_FILE            = 460,
    ID_COMMA                   = 470,
    ID_QUESTION_MARK           = 480,
    ID_TILDE                   = 490,
    ID_CARROT                  = 500,
    ID_AMPERSAND               = 515,
    ID_BIT_SHIFT_LEFT          = 540,
    ID_BIT_SHIFT_RIGHT         = 550,
    ID_NUMERIC_LITERAL         = 600,
    ID_STRING_LITERAL          = 610,
    ID_SYMBOL_NAME             = 620
};
#endif // _CTERMINALS_HPP
