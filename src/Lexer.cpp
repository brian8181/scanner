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
#include <boost/regex.hpp>
#include "fileio.hpp"
#include "Lexer.h"
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
    // build expression ...
    string exp;
    build_expr(exp);
    cout << "exp=" << exp << endl;
    //_rexp = regex( exp, regex::ECMAScript );
    // testing
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
    _map_sections_config.clear();

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
    _map_sections_config.insert( sp );

    int len = lines.size( );
    _name_vals.resize(len);
    int j = 0;
    for(int i = 0; i < len; ++i)
    {
        string line = lines[i];
        regex rgx = regex( "(" + CONFIG_PAIR + ")|(" + CONFIG_COMMENT + ")"  );
        smatch match;
        regex_match( line, match, rgx );
        // bkp todo...
        // NUMBER              = {0x200, [0-9]+}
        // PLUS                = {0x201, \+}
        if(match[ID_NAME_VALUE_PAIR].matched)
        {
            string symbol_name = match[ID_NAME].str( ); // get name
            string value = (match[ID_VALUE].matched) ? match[ID_NUMERIC_LITERAL].str( ) : match[ID_STRING_LITERAL].str( ); // get value
            // create pair
            pair<string, string> p( symbol_name, value );
            _map_sections_config[section_name].insert( p );
            // vector
            NameValue nv;
            _name_vals[j] = nv;
            _name_vals[j].id = 0x200 | (1 << j);
            _name_vals[j].name = symbol_name;
            _name_vals[j].value = value;
            j++;
        }
    }
    _name_vals.resize(j);
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
    auto end = _map_sections_config[section_name].end( );
    for(auto iter = _map_sections_config[section_name].begin( ); iter != end; ++iter)
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
            token = _token_map[m.str( )].first;
            string name = _token_map[m.str( )].second;
            // ss << "{\n\ttoken__: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( 0 ) << "\n}" << endl;
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
void Lexer::build_expr( /*out*/ string& s )
{
    stringstream ss;

    //string section_name = "global";
    //auto end = _map_sections_config[section_name].end( );
    // for(auto iter = _map_sections_config[section_name].begin( ); iter != end; ++iter)
    // {
    //     string value = (*iter).second;
    //     ss << "(" + value + ")|";
    // }

    int len = _name_vals.size();
    for(int i = 0; i < len; ++i)
    {
        NameValue nv = _name_vals[i];
        ss << "(?<" << nv.name << ">" + nv.value + ")|";
    }
    s = ss.str( );
    s.pop_back( );
}

/**
 * @brief print regex expression to stdout
 */
void Lexer::print_expr( )
{
    string s;
    build_expr(s);
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
