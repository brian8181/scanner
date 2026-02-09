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
// bkp todo!
//using namespace bkp;

/**
 * @brief default ctor
 */
Lexer::Lexer(): _p_iter(nullptr) {}

/**
 * @brief  ctor
 * @param file
 * @param config_file
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
Lexer::Lexer( const Lexer& src ): _p_iter(nullptr) {}

/**
 * @brief virtual dtor
 */
Lexer::~Lexer()
{
    // bkp todo!
}

/**
 * @brief  initialize state
 * @param  file
 * @param  config_file
 * @return bool
 */
bool Lexer::init( const string& file, const string &config_file )
{
    load_config( config_file );
    _state = new state{ 1, "INITIAL" };
    _scan_file = file;
    stringstream ss;
    const int r = read_sstream( file, ss );
    _search_text = ss.str( );
    // build expression ...
    string exp;
    get_expr(exp);
    _expr = exp;
    // bkp todo!
    //_rexp = boost::regex( EVERYTHING, boost::regex::ECMAScript );
    _rexp = boost::regex( exp, boost::regex::ECMAScript );
    _begin = boost::sregex_iterator( _search_text.begin( ), _search_text.end( ), _rexp );
    _p_iter = &_begin;
    return r;
}

/**
 * @brief  load_config: load configuration from file
 * @param  path to config file
 * @param  const string &path
 * @return void
 */
void Lexer::load_config( const string &path )
{
    // bkp todo!
    //need to delete each token before clearing!! _tokens.clear();
    _id_tab.clear();
    _idx_tab.clear();
    _name_tab.clear();
    //need to delete each state before clearing!! _state_tab.clear();
    _state_tokens_tab.clear();


    _config_file = path;
    string section = "none";
    string s;
    read_str( _config_file, s);
    auto rgx = boost::regex( CONFIG_SECTIONS );
    boost::smatch terminal_match;
    // begins terminal section
    boost::regex_search( s, terminal_match, rgx, boost::match_not_bol | boost::match_not_eol );
    // cout << "terminal_match[\"tokens\"].matched = " << (terminal_match["tokens"].matched ? "TRUE" : "FALSE") << endl;
    boost::smatch groups_match;
    // ends terminal section, begin group section
    string terminal_suffix = terminal_match.suffix();
    boost::regex_search(terminal_suffix, groups_match, rgx, boost::match_not_bol | boost::match_not_eol);
    // now get section
    string token_section = groups_match.prefix();

    // stream & parse tokens section
    std::istringstream input1;
    input1.str(token_section);
    int j = 0;
    for (std::string line; std::getline(input1, line); j++)
    {
        auto config_rgx = boost::regex( CONFIG );
        boost::smatch token_match;
        boost::regex_match( line, token_match, config_rgx );
        // error!
        // cout << "token_match[\"pairs\"].matched = " << (token_match["pairs"].matched ? "TRUE" : "FALSE") << endl;
        if(constexpr unsigned int ID_PAIR = 1; token_match[ID_PAIR].matched)
        {
            // cout << "token_match[\"name\"].matched = " << (token_match["name"].matched ? "TRUE" : "FALSE") << endl;
            string name = token_match["name"].str();
            string expr = token_match["rexp"].str();
            string stype = token_match["type"].str();
            string test_val = token_match["test"].str();

            token* ptok = new token{ 0xFF + j*0x06, string(name), stype, 0, 0, string(expr), string("null"), string(test_val), 0 };
            // copy to term to vector
            _tokens.push_back(ptok);
            _id_tab[ptok->id] = ptok;
            _idx_tab[ptok->index] = ptok;
            _name_tab[ptok->name] = ptok;
        }
    }

    // ends group section, begin states section
    string groups_suffix = groups_match.suffix();
    boost::smatch states_match;
    boost::regex_search(groups_suffix, states_match, rgx, boost::match_not_bol | boost::match_not_eol);
    string groups_section = states_match.prefix();
    string states_section = states_match.suffix();

    // stream & parse tokens section
    std::istringstream input2;
    input2.str(states_section);
    for (std::string line; std::getline(input2, line);)
    {
        auto config_states_rgx = boost::regex( CONFIG_STATES );
        boost::regex_match( line, states_match, config_states_rgx );
        if(states_match["states"].matched)
        {
            // cout << "states_match[\"state\"].matched = " << (states_match["state"].matched ? "TRUE" : "FALSE") << endl;
            // cout << "states_match[\"tokens\"].matched = " << (states_match["tokens"].matched ? "TRUE" : "FALSE") << endl;

            string str_state = states_match["state"].str();  // new state to create
            string str_tokens = states_match["tokens"].str(); // csv tokens for that state
            int i = 0;
            int state_id = 0xFF | (++i*6); // generate id for new state
            auto* pstate = new state{ state_id , str_state }; // create new state
            _state_tab[pstate->id] = pstate; // insert new state into table

            // copy to term to vector
            vector<token*> tokens; // token vector for this state
            std::stringstream ss(str_tokens); // csv of states
            std::string str_token; // item in csv states

            // use get line to split on commas
            while (std::getline(ss, str_token, ','))
            {

                token* ptok = _name_tab[str_token];
                tokens.push_back(ptok);
                _state_tokens_tab[pstate->id] = tokens;

            }
        }
    }
}

/**
 * @brief  dump config
 * @param file
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
void Lexer::dump_config( ) const
{
    stringstream ss;
    const size_t len = _tokens.size();
    for(int i = 0; i < len; ++i)
    {
        token* ptok = _tokens[i];
        ss << "Id: "        << left << setw(10) << ptok->id         <<
            " name: "       << left << setw(15) << ptok->name       <<
            " type: "       << left << setw(15) << ptok->stype      <<
            " value: "      << left << setw(15) << ptok->value      <<
            " rexp: "       << left << setw(15) << ptok->rexp       <<
            " test_value: " << left << setw(15) << ptok->test_value << endl;
    }
    cout << ss.str();
}

/**
 * @brief  get_token
 * @param  unsigned int& token, out param, a token
 * @return int
 */
int Lexer::get_token()
{
    // bkp todo!
    return 0;

    stringstream ss;
    token* ptok = 0;
    if(*_p_iter != _end)
    {
        // need to look up by sub_match index
        boost::smatch sm = *(*_p_iter);
        size_t len = sm.size();
        // find matched
        for(int i = 0; i < len; ++i)
        {
            if(sm[i].matched)
            {
                ptok = _idx_tab[i];        // look up by index
                _matches.push_back(ptok);  // push matched token
                break;                     // found
            }
        }
        ++(*_p_iter);              // increment iterrator
        return ptok->id;           // return token id
    }
    return -1; // error or eof
}

/**
 * @brief reset
 */
void Lexer::reset()
{
    // bkp todo!
    _scan_file = "";
    _search_text = "";
    _rexp = "";
    _begin;
    _end;
    _p_iter;
    delete _state;
    _state = new state{ 1, "INITIAL" };
    _expr;
}


/**
 * @brief override virtual, on_token, for each token ...
 * @param token
 */
void Lexer::on_token( const unsigned int& token_, const boost::smatch& m )
{
    // bkp todo!
    //stringstream ss;
    //unsigned int token = ID_UNDEFINED;
    cout << "on_token( " << token_ << ", \"" << m.str() << "\" );" << endl;
}

/**
 * @brief get regex expression
 */
void Lexer::get_expr( /*out*/ string& s ) const
{
    stringstream ss;
    const size_t len = _tokens.size();
    for(int i = 0; i < len; ++i)
    {
        token* ptok = _tokens[i];
        ss << "(?<" << ptok->name << ">" + ptok->rexp + ")|";
        //ss << "(" << tok.rexp << ")|";
    }
    s = ss.str();
    s.pop_back();

    // bkp todo!
    // auto index using test_value
    // const auto rgx = boost::regex( s );
    // boost::smatch m;
    // for(int i = 0; i < len; ++i)
    // {
    //     boost::regex_match( tok[i]->test_value, m, rgx );
    //     const size_t sz = m.size();
    //     for(int j = 0; j < sz; ++j)
    //     {
    //         if(m[j].matched)
    //         {
    //             tok[i]->index = j;
    //             break;
    //         }
    //     }
    // }
}

/**
 * @brief set_expr
 */
void Lexer::set_expr(const string& s)
{

}

/**
 * @brief print regex expression to stdout
 */
void Lexer::print_expr( ) const
{
    string s;
    get_expr(s);
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
