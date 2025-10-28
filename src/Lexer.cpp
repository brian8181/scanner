/**
 * @file    Lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 * @info    ...
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <map>
#include <regex>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include "fileio.hpp"
#include "Lexer.hpp"
#include "utility.hpp"
#include "constants.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::pair;

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

/**
 * @brief default ctor
 */
Lexer::Lexer( )
{
}

/**
 * @brief  ctor
 * @param  const string& file, scan file
 * @param  const string &config_file, config file
 */
Lexer::Lexer( const string& file, const string &config_file ) : _scan_file(file), _config_file(config_file)
{
    init( _scan_file, _config_file );
}

/**
 * @brief copy ctor
 * @param const Lexer& src
 */
Lexer::Lexer( const Lexer& src )
{
}

/**
 * @brief virtual dtor
 */
Lexer::~Lexer( )
{
}

/**
 * @brief  initialize state
 * @param  const string& file, scan file
 * @param  const string &config_file, config file
 * @return bool
 */
bool Lexer::init( const string& file, const string &config_file )
{
    load_config( config_file );
    _scan_file = file;
    stringstream sstrm;
    int r = read_sstream( file, sstrm );
    _search_text = sstrm.str( );
    _rexp = regex( EVERYTHING, regex::ECMAScript );
    _begin = sregex_iterator( _search_text.begin( ), _search_text.end( ), _rexp );
    _p_iter = &_begin;
    return r;
}

/**
 * @brief  load_config: load confiuration from file
 * @param  const string &path
 * @return void
 */
void Lexer::load_config( const string &path )
{
    _config_file = path;
    const unsigned int ID_NAME_VALUE_PAIR = 1;
    const unsigned int ID_NAME = 2;
    const unsigned int ID_VALUE = 5;
    const unsigned int ID_CONFIG_COMMENT = 6;
    const unsigned int ID_NUMERIC_LITERAL = 2;
    const unsigned int ID_STRING_LITERAL = 3;
    map_sections_config.clear();

    // get configuration file by lines
    vector<string> lines;
    if(! read_lines( _config_file, lines ) )
    {
        cerr << "error: read_lines ..." << endl;
    }
    // create one only section (global)
    string section_name = "global";
    map<string, string> section_map;
    pair<string, map<string, string>> sp( section_name, section_map );
    map_sections_config.insert( sp );

    int len = lines.size( );
    for(int i = 0; i < len; ++i)
    {
        string line = lines[i];
        regex rgx = regex( "(" + CONFIG_PAIR + ")|(" + CONFIG_COMMENT + ")"  );
        smatch match;
        regex_match( line, match, rgx );

        if(match[ID_NAME_VALUE_PAIR].matched)
        {
            string symbol_name = match[ID_NAME].str( ); // get name
            string value = (match[ID_VALUE].matched) ? match[ID_NUMERIC_LITERAL].str( ) : match[ID_STRING_LITERAL].str( ); // get value
            // create pair
            pair<string, string> p( symbol_name, value );
            map_sections_config[section_name].insert( p );
        }
    }
}

/**
 * @brief  dump config
 * @param  const string& file : config to dump
 * @return void
 */
void Lexer::dump_config( const string& file )
{
    load_config( file );
    dump_config( );
}

/**
 * @brief  dump current config
 * @return void
 */
void Lexer::dump_config( )
{
    stringstream ss;
    string section_name = "global";
    auto end = map_sections_config[section_name].end( );
    for(auto iter = map_sections_config[section_name].begin( ); iter != end; ++iter)
    {
        string key = (*iter).first;
        string value = (*iter).second;
        ss << "Section: " << left << setw(15) << section_name << left << " Key: " << left << setw(25) << key << "Value: " << "\"" << value << "\"" << endl;
    }
    cout << ss.str();
}

/**
 * @brief  get_token
 * @param  unsigned int& token, out param, a token
 * @return int
 */
int Lexer::get_token( /*out*/ unsigned int& token )
{
    stringstream ss;
    token = ID_UNDEFINED;
    if(*_p_iter != _end)
    {
        std::smatch m = *(*_p_iter);
        if( _token_map.contains( m.str( ) ) )
        {
            // token = _token_map[m.str( )].first;
            string name = _token_map[m.str( )].second;
            // ss << "{\n\ttoken: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( 0 ) << "\n}" << endl;
            // color_print( ss.str( ), fg( fmt::color::antique_white ) );
            // ss.clear( );
            // create token ...
            string match = m.str( );
            std::pair<int, std::string> id( token, name );
            std::pair<std::string, std::pair<int, std::string>> tok( match, id );
            _tokens[match] = tok;
        }
        ++(*_p_iter);
        on_token( token, m );
        return token;
    }
    return 0;
}

/**
 * @brief override virtual, on_token, for each token ...
 * @param token
 */
void Lexer::on_token( const unsigned int& token_, const std::smatch& m )
{
    //stringstream ss;
    //unsigned int token = ID_UNDEFINED;
    cout << "on_token( " << token_ << ", \"" << m.str() << "\" );" << endl;
}

/**
 * @brief  tokenize
 * @param  const string &exp, regular expression to match
 * @param  const string &text, text to tokenize
 * @return void
 */
void Lexer::tokenize( const string &exp, const string &text )
{
    stringstream ss;
    regex rexp = regex( exp, regex::ECMAScript );
    sregex_iterator begin = sregex_iterator( text.begin( ), text.end( ), rexp );
    //sregex_iterator end = sregex_iterator();
    sregex_iterator end;
    for (std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch m = *iter;
        if( _token_map.contains( m.str( ) ) )
        {
            int token = _token_map[m.str( )].first;
            string name = _token_map[m.str( )].second;
            ss << "{\n\ttoken: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( 0 ) << "\n}" << endl;
            color_print( ss.str( ), fg( fmt::color::antique_white ) );
            ss.clear( );
        }
        else
        {
            ss << "{\n\ttoken: null" << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( 0 ) << "\n};" << endl;
            color_print( ss.str( ), fg( fmt::color::red ) | fmt::emphasis::bold );
            ss.clear( );
        }
    }
}

/**
 * @brief print regex expression to stdout
 */
void Lexer::print_expr( )
{
    stringstream ss;
    string section_name = "global";
    auto end = map_sections_config[section_name].end( );
    for(auto iter = map_sections_config[section_name].begin( ); iter != end; ++iter)
    {
        string value = (*iter).second;
        ss << "(" + value + ")|";
    }
    string s = ss.str( );
    s.pop_back( );
    cout << s << endl;
}

/**
 * @brief print token to stdout
 */
void Lexer::print_token( )
{
    if(*_p_iter != _end)
    {
        stringstream ss;
        std::smatch m = *(*_p_iter);
        if( _token_map.contains( m.str( ) ) )
        {
            unsigned int token = _token_map[m.str( )].first;
            string name = _token_map[m.str( )].second;
            ss << "{\n\ttoken: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( 0 ) << "\n}" << endl;
            color_print( ss.str( ), fg( fmt::color::antique_white ) );
            ss.clear( );
        }
        else
        {
            ss << "{\n\ttoken: null" << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( 0 ) << "\n};" << endl;
            color_print( ss.str( ), fg( fmt::color::red ) | fmt::emphasis::bold );
            ss.clear( );
        }
    }
}
