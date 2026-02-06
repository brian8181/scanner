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
    //cout << "exp=" << exp << endl;
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
    const unsigned int ID_NAME_VALUE_PAIR = 1;
    const unsigned int ID_TYPE = 2;
    const unsigned int ID_NAME = 3;
    const unsigned int ID_VALUE = 4;
    // const unsigned int ID_CONFIG_COMMENT = 7;
    // const unsigned int ID_NUMERIC_LITERAL = 3;
    // const unsigned int ID_STRING_LITERAL = 4;

    int j = 0;
    string section = "none";
    string s;
    int n = read_str( _config_file, s);
    boost::regex rgx = boost::regex( CONFIG_SECTIONS );
    boost::smatch terminal_match;
    // begins terminal section
    boost::regex_search( s, terminal_match, rgx, boost::match_not_bol | boost::match_not_eol );
    //cout << _config_file << "=" << endl << s;
    // /*debug / testing*/
    // for(int i = 0; i < terminal_match.size(); ++i)
    // {
    //     cout << "smatch[" << i << "] = \"" << terminal_match[i] << "\" : matched=" << terminal_match[i].matched <<  endl;
    // }

    boost::smatch groups_match;
    // ends terminal section, begin group section
    string terminal_suffix = terminal_match.suffix();
    boost::regex_search(terminal_suffix, groups_match, rgx, boost::match_not_bol | boost::match_not_eol);
    // /*debug / testing*/
    // for(int i = 0; i < groups_match.size(); ++i)
    // {
    //     cout << "smatch[" << i << "] = \"" << groups_match[i] << "\" : matched=" << groups_match[i].matched <<  endl;
    // }

    // now get section
    string token_section = groups_match.prefix();
    // stream it line by line to parse tokens section
    std::istringstream input;
    input.str(token_section);
    for (std::string line; std::getline(input, line); j++)
    {
        boost::regex config_rgx = boost::regex( CONFIG );
        boost::smatch token_match;
        boost::regex_match( line, token_match, config_rgx );

        if(token_match[ID_NAME_VALUE_PAIR].matched)
        {
            string name = token_match["name"].str();
            string value = token_match["rexp"].str();
            string stype = token_match["type"].str();
            // copy to term to vector
            terminal term{ 0xFF + (j*0x06), stype, 0, 0, string(stype), string(value) };
            _terminals.push_back(term);
            _token_map[term.name] = std::pair<int, string>(term.id, term.rexp);
            //cout << "Type: " << term.stype << " Id: " << left << setw(15) << term.id << left << " Name: " << left << setw(25) << term.name << "Value: " << "\"" << term.rexp << "\"" << endl;
        }
    }

    boost::smatch states_match;
    // ends group section, begin states section
    string groups_suffix = groups_match.suffix();
    boost::regex_search(groups_suffix, states_match, rgx, boost::match_not_bol | boost::match_not_eol);
    // /*debug / testing*/
    // for(int i = 0; i < states_match.size(); ++i)
    // {
    //     cout << "smatch[" << i << "] = \"" << states_match[i] << "\" : matched=" << states_match[i].matched <<  endl;
    // }

     string groups_section = states_match.prefix();
     string states_section = states_match.suffix();

    // stream it line by line to parse tokens section
    std::istringstream input2;
    input2.str(states_section);
    for (std::string line; std::getline(input2, line);)
    {
        boost::regex config_states_rgx = boost::regex( CONFIG_STATES );
        boost::smatch states_match;
        boost::regex_match( line, states_match, config_states_rgx );

        if(states_match[1].matched)
        {
            string state = states_match["state"].str();
            string tokens = states_match["tokens"].str();
            // copy to term to vector
            vector<string> terminals;
            std::stringstream ss(tokens);
            std::string token;
            // Use getline to split stream on comma
            while (std::getline(ss, token, ','))
            {
                terminals.push_back(trim(token));
            }
            std::pair<string, vector<string>> state_map(state, terminals);

            // // debug Print the tokens
            // for (const std::string& tok : terminals)
            // {
            //     std::cout << tok << std::endl;
            // }
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
