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
    _rexp = boost::regex( EVERYTHING, boost::regex::ECMAScript );
    _begin = boost::sregex_iterator( _search_text.begin( ), _search_text.end( ), _rexp );
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
    const unsigned int ID_SECTION = 1;
    const unsigned int ID_NAME_VALUE_PAIR = 3;
    const unsigned int ID_TYPE = 4;
    const unsigned int ID_NAME = 5;
    const unsigned int ID_VALUE = 6;
    // const unsigned int ID_CONFIG_COMMENT = 7;
    // const unsigned int ID_NUMERIC_LITERAL = 3;
    // const unsigned int ID_STRING_LITERAL = 4;

    int j = 0;
    string section = "none";
    string s;
    int n = read_str( _config_file, s);
    boost::regex rgx = boost::regex( CONFIG_SECTIONS );
    boost::smatch section_match1;
    // begins section
    boost::regex_search( s, section_match1, rgx, boost::match_not_bol | boost::match_not_eol );
    cout << _config_file << "=" << endl << s;
    /*debug / testing*/
    for(int i = 0; i < section_match1.size(); ++i)
    {
        cout << "smatch[" << i << "] = \"" << section_match1[i] << "\" : matched=" << section_match1[i].matched <<  endl;
    }

    boost::smatch section_match2;
    // ends section match
    string suffix = section_match1.suffix();
    boost::regex_search(suffix, section_match2, rgx, boost::match_not_bol | boost::match_not_eol);
    /*debug / testing*/
    for(int i = 0; i < section_match2.size(); ++i)
    {
        cout << "smatch[" << i << "] = \"" << section_match2[i] << "\" : matched=" << section_match2[i].matched <<  endl;
    }
    // now get section
    string token_section = section_match2.prefix();
    // stream it line by line to parse tokens section
    std::istringstream input;
    input.str(token_section);
    for (std::string line; std::getline(input, line); j++)
    {
        boost::regex config_rgx = boost::regex( CONFIG );
        boost::smatch terminal_match;
        boost::regex_match( line, terminal_match, config_rgx );

        if(terminal_match[ID_NAME_VALUE_PAIR].matched && section == "tokens")
        {
            string name = terminal_match["name"].str(); // get name
            //string value = (terminal_match[ID_VALUE].matched) ? terminal_match[ID_NUMERIC_LITERAL].str( ) : terminal_match[ID_STRING_LITERAL].str( ); // get value
            string value = terminal_match["rexp"].str();
            string stype = terminal_match["type"].str();
            // copy to term to vector
            terminal term{ 0xFF + (j*0x06), stype, 0, 0, string(stype), string(value) };
            _terminals.push_back(term);

            _token_map[term.name] = std::pair<int, string>(term.id, term.rexp);
            cout << "Type: " << term.stype << " Id: " << left << setw(15) << term.id << left << " Name: " << left << setw(25) << term.name << "Value: " << "\"" << term.rexp << "\"" << endl;
        }

    }



    /* tesing */
    // CONFIG = string("(?<section>\\s*\\[(?<name>[a-zA-Z][a-zA-Z0-9]*)\\]\\s*)");
    // cout << "CONFIG = \"" << CONFIG << "\"" << endl;

    // get configuration file by lines
    // vector<string> lines;

    // if(! read_lines( _config_file, lines ) )
    // {
    //     cerr << "error: read_lines ..." << endl;
    // }
    //CONFIG_SECTIONS
    //string line = lines[i];

    // int len = lines.size( );
    // _terminals.resize(len);
    // int j = 0;
    // string section = "none";
    // for(int i = 0; i < len; ++i)
    // {
    //     string line = lines[i];
    //     boost::regex rgx = boost::regex( CONFIG  );
    //     boost::smatch match;
    //     boost::regex_match( line, match, rgx );

    //     for(int i = 0; i < match.size(); ++i)
    //     {
    //         cout << "line#="  << i << endl;
    //         cout << "smatch[" << i << "] = \"" << match[i] << "\" : matched=" << match[i].matched <<  endl;
    //     }

    //     //string bs = string(match["section"]);
    //     // if(match["section"].second != match["section"].end())
    //     // {
    //     //     int m = match["section"].matched;
    //     //     cout << "m=" << m << endl;
    //     // }

    //     cout << "empty=" << match.empty() << endl;

    //     if(match[ID_SECTION].matched)
    //     {
    //         cout << "m=" << match << endl;
    //         section = match["section"].str();
    //         cout << "section: " << section << endl;
    //         /* testing */
    //         //return;
    //         continue;
    //     }

    //     if(match[ID_NAME_VALUE_PAIR].matched && section == "tokens")
    //     {
    //         string symbol_name = match["name"].str(); // get name
    //         //string value = (match[ID_VALUE].matched) ? match[ID_NUMERIC_LITERAL].str( ) : match[ID_STRING_LITERAL].str( ); // get value
    //         string value = match["rexp"].str();
    //         string stype = match["type"].str();
    //         // vector
    //         terminal term;
    //         term.id = 0xFF + (j*0x06);
    //         term.stype = stype;
    //         term.name = symbol_name;
    //         term.rexp = value;
    //         _terminals[j] = term;
    //         j++;
    //         _token_map[term.name] = std::pair<int, string>(term.id, term.rexp);
    //         cout << "Type: " << term.stype << " Id: " << left << setw(15) << term.id << left << " Name: " << left << setw(25) << term.name << "Value: " << "\"" << term.rexp << "\"" << endl;
    //     }
    // }
    // _terminals.resize(j);
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
    int len = _terminals.size();
    for(int i = 0; i < len; ++i)
    {
        terminal term = _terminals[i];
        ss << "Id: " << left << setw(15) << term.id << left << " Key: " << left << setw(25) << term.name << "Value: " << "\"" << term.rexp << "\"" << endl;
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
        // need to look up by sub_match id
        boost::smatch what = *(*_p_iter);
        // for(int i = 0; i < what.size(); ++i)
        // {
        //     cout << "smatch[" << i << "].first" << what[i].first << endl;
        //     cout << "smatch[" << i << "].second" << what[i].second << endl;
        // }


        if( _token_map.contains( what.str( ) ) )
        {
            // tok = _token_map[what.str()].first;
            // string name = _token_map[what.str( )].second;
            // // ss << "{\n\ttoken__: " << token << "\n\tname: " << name << "\n\ttoken: '" << what.str( ) << "'\n\tpos: " << what.position( 0 ) << "\n}" << endl;
            // // color_print( ss.str( ), fg( fmt::color::antique_white ) );
            // // ss.clear( );
            // // create token ...
            // string match = what.str( );
            // std::pair<int, std::string> id( token, name );
            // std::pair<std::string, std::pair<int, std::string>> tok( match, id );
            // token t;
            // _tokens.push_back(t);
        }
        ++(*_p_iter);
        //on_token( token, what );
        return token;
    }
    return 0;
}

/**
 * @brief override virtual, on_token, for each token ...
 * @param token
 */
void Lexer::on_token( const unsigned int& token_, const boost::smatch& m )
{
    //stringstream ss;
    //unsigned int token = ID_UNDEFINED;
    cout << "on_token( " << token_ << ", \"" << m.str() << "\" );" << endl;
}

/**
 * @brief  tokenize (depracated)
 * @param  const string &exp, regular expression to match
 * @param  const string &text, text to tokenize
 * @return void
 */
void Lexer::tokenize( const string &exp, const string &text )
{
    stringstream ss;
    boost::regex rexp = boost::regex( exp, boost::regex::ECMAScript );
    boost::sregex_iterator begin = boost::sregex_iterator( text.begin( ), text.end( ), rexp );
    boost::sregex_iterator end;
    for (boost::sregex_iterator iter = begin; iter != end; ++iter)
    {
        // need to look up by sub_match id
        boost::smatch m = *iter;
        if( _token_map.contains( m.str( ) ) )
        {
            int token = _token_map[m.str( )].first;
            string name = _token_map[m.str( )].second;
            ss << "{\n\ttoken: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( (int)0 ) << "\n}" << endl;
            color_print( ss.str( ), fg( fmt::color::antique_white ) );
            ss.clear( );
        }
        else
        {
            ss << "{\n\ttoken: null" << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( (int)0 ) << "\n};" << endl;
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
    int len = _terminals.size();
    for(int i = 0; i < len; ++i)
    {
        terminal term = _terminals[i];
        ss << "(?<" << term.name << ">" + term.rexp + ")|";
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
        // need to look up by sub_match id
        stringstream ss;
        boost::smatch m = *(*_p_iter);
        if( _token_map.contains( m.str( ) ) )
        {
            unsigned int token = _token_map[m.str( )].first;
            string name = _token_map[m.str( )].second;
            ss << "{\n\ttoken: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( (int)0 ) << "\n}" << endl;
            color_print( ss.str( ), fg( fmt::color::antique_white ) );
            ss.clear( );
        }
        else
        {
            ss << "{\n\ttoken: null" << "\n\ttoken: '" << m.str( ) << "'\n\tpos: " << m.position( (int)0 ) << "\n};" << endl;
            color_print( ss.str( ), fg( fmt::color::red ) | fmt::emphasis::bold );
            ss.clear( );
        }
    }
}
