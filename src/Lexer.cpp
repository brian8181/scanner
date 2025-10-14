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
#include "constants.hpp"
#include "fileio.hpp"
#include "Lexer.hpp"
#include "utility.hpp"

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
 * @brief ctor
 * @param config
 */
Lexer::Lexer(const string& config) : _config(config)
{

}

/**
 * @brief copy ctor
 * @param src
 */
Lexer::Lexer( const Lexer& src )
{

}

/**
 * @brief
 */
Lexer::~Lexer( )
{

}

/**
 * @brief  initialize state
 * @return bool
 */
bool Lexer::init( const string& file )
{
    stringstream sstrm;
    int r = read_sstream( file, sstrm );
    _search_text = sstrm.str( );
    _rexp = regex( EVERYTHING, regex::ECMAScript );
    _begin = sregex_iterator( _search_text.begin(), _search_text.end(), _rexp );
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
    const unsigned int ID_NAME_VALUE_PAIR = 1;
    const unsigned int ID_NAME = 2;
    const unsigned int ID_VALUE = 5;
    const unsigned int ID_CONFIG_COMMENT = 6;
    const unsigned int ID_NUMERIC_LITERAL = 2;
    const unsigned int ID_STRING_LITERAL = 3;
    map_sections_config.clear();

    // get configuration file by lines
    vector<string> lines;
    if(! read_lines( path, lines ) )
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
            // get name
            string symbol_name = match[ID_NAME].str( );
            // get value
            string value = (match[ID_VALUE].matched) ? match[ID_NUMERIC_LITERAL].str( ) : match[ID_STRING_LITERAL].str( );
            // create pair
            pair<string, string> p( symbol_name, value );
            map_sections_config[section_name].insert( p );
        }
    }
    cout << "config loaded ..." << endl;
}

/**
 * @brief  dump current config
 * @return void
 */
void Lexer::dump_config( )
{
    stringstream ss;
    cout << "config dump ..." << endl;
    string section_name = "global";
    auto end = map_sections_config[section_name].end( );
    for(auto iter = map_sections_config[section_name].begin( ); iter != end; ++iter)
    {
        string key = (*iter).first;
        string value = (*iter).second;
        ss << "Section: " << left << setw(15) << section_name << left << " Key: " << left << setw(25) << key << "Value: " << setw(25) << value << endl;

        //color_print(ss.str(), fg(fmt::color::blue) | fmt::emphasis::bold);
    }
    cout << ss.str();
}

/**
 * @brief  dump config
 * @param  const string& file : config to dump
 * @return void
 */
void Lexer::dump_config( const string& file )
{
    //load_config( file );
    dump_config( );
}

/**
 * @brief  start tokenizing file
 * @param  file
 * @return void
 */
void Lexer::start( string file )
{
    cout << "Starting lexical analysis on file: " << file << endl;
    stringstream sstrm;
    ifstream strm( file, ios::in );
    if( strm.is_open( ) )
    {
        cout << file << "-> opened ..." << endl;
        char c;
        while( strm.get( c ) )
        {
            sstrm << c;
        }
    }
    else
    {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    stringstream ss;
    string section_name = "global";
    auto end = map_sections_config[section_name].end( );
    for(auto iter = map_sections_config[section_name].begin( ); iter != end; ++iter)
    {
        string key = (*iter).first;
        string value = (*iter).second;
        ss << "(" << value << ")|";
    }
    string ALL_CONFIG_EXPRS = ss.str();
    ALL_CONFIG_EXPRS.pop_back();
    cout << ALL_CONFIG_EXPRS << endl;

    // unsigned int token = ID_UNDEFINED;
    // _search_text = sstrm.str( );
    // _rexp = regex( EVERYTHING, regex::ECMAScript );
    // _begin = sregex_iterator( _search_text.begin( ), _search_text.end( ), _rexp );
    // _p_iter = &_begin;
    // while( get_token( token ) );
}

/**
 * @brief  get_token
 * @param  iter
 * @param  id
 * @return int
 */
int Lexer::get_token( unsigned int& token )
{
    stringstream ss;
    static int count = 0;
    if(*_p_iter != _end)
    {
        ++(*_p_iter);
        std::smatch m = *(*_p_iter);
        if( _token_map.contains( m.str( ) ) )
        {
            int token = _token_map[m.str( )].first;
            string name = _token_map[m.str( )].second;
            ss << "{\n\ttoken: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( 0 ) << "\n\tcount: " << ++count << "\n};" << endl;
            color_print(ss.str(), fg(fmt::color::blue) | fmt::emphasis::bold);
            ss.clear();
            // create token ...
            string match = m.str( );
            std::pair<int, std::string> id( token, name );
            std::pair<std::string, std::pair<int, std::string>> tok( match, id );
            _tokens[match] = tok;
        }
        else
        {
            ss << "{\n\ttoken: null" << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( 0 ) << "\n\tcount: " << ++count << "\n};" << endl;
            color_print(ss.str(), fg(fmt::color::red) | fmt::emphasis::bold);
            ss.clear();
        }
        return 1;
    }
    return 0;
}

/**
 * @brief  tokenize
 * @param  exp The regular expression to match
 * @param  text The text to search for matches
 * @return void
 */
void Lexer::tokenize( const string &exp, const string &text )
{
    int count = 0;
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
            cout << "{\n\ttoken: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str() << "'\n\tpos: " << m.position( 0 ) << "\n\tcount: " << ++count << "\n};" << endl;
        }
        else
        {
            cout << "{\n\ttoken: null" << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( 0 ) << "\n\tcount: " << ++count << "\n};" << endl;
        }
    }
}
