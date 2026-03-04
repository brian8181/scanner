
/**
 * @file    Lexer.cpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 * @info    ...
 */

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
#include <boost/regex.hpp>
#include "fileio.hpp"
#include "Lexer.hpp"
//#include "constants.hpp"
#include "tokens.hpp"

#include "scanner.h"
//#include "pars.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::pair;
using std::setw;
using std::left;
using std::right;
using yy::parser;

//using namespace std;

/**
 * @brief default ctor
 */
Lexer::Lexer() : _p_iter(nullptr) {}

/**
 * @brief  ctor
 * @param file
 * @param config_file
 * @param pp
 * @param  file
 */
Lexer::Lexer( const string& file, const string &config_file, yy::parser* pparser ) : _p_iter(nullptr), _scan_file(file), _config_file(config_file), _pparser(pparser)
{
    init( _scan_file, _config_file, _pparser );
}

/**
 * @brief copy ctor
 * @param src
 */
Lexer::Lexer( const Lexer& src ) : _p_iter(nullptr)
{
}

/**
 * @brief virtual dtor
 */
Lexer::~Lexer()
{
}

/**
 * @brief  initialize state
 * @param  file
 * @param  config_file
 * @return bool
 */
bool Lexer::init( const string& file, const string &config_file, yy::parser* pp )
{
    _tokens.clear();
    _idx_tab.clear();
    _id_tab.clear();
    _name_tab.clear();
    _matches.clear();


    // globals ...
    // g_state_tab
    // g_state_tokens_tab
    // g_state

    p_state = gp_state;
    p_states = &g_states;
    p_state_tab = &g_state_tab;
    p_state_tokens_tab = &g_state_tokens_tab;

    // init from global
    const int len_states = g_tokens_all.size();
    for (int i = 0; i < len_states; i++)
    {
        g_tokens_all[i].index = i + 1;
        _tokens.push_back(g_tokens_all[i]);
        _id_tab[g_tokens_all[i].id] = &g_tokens_all[i];
        _idx_tab[g_tokens_all[i].index] = &g_tokens_all[i];
        _name_tab[g_tokens_all[i].name] = &g_tokens_all[i];
    }

    //load_config( config_file );
    _scan_file = file;
    stringstream ss;
    const int r = read_sstream( file, ss );
    _search_text = ss.str( );

    // set state
    set_state(p_state);
    // initialize expression ...
    // init_expr();

    // DEBUGGING OVERRIDE _expr
    cout << _expr << endl;
    // _expr = R"((?<DOLLAR_SIGN>\$)|(?<IDENTIFIER>[A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)|(?<LBRACE>\{)|(?<WHITESPACE>[ \t]))";
    // _expr = R"((\$)|([A-Za-z*@_.~+-][A-Za-z0-9*@_.~+-]*)|(\{)|([ \t]))";
    _rexp = boost::regex( _expr, boost::regex::extended );
    _begin = boost::sregex_iterator( _search_text.begin( ), _search_text.end( ), _rexp );
    _p_iter = &_begin;
    _end = boost::sregex_iterator();
    return r;
}

/**
 * @brief  load_config: load configuration from file
 * @param  file
 * @return void
 */
void Lexer::load_config( const string &file )
{
    _config_file = file;
    string section = "none";
    string s;
    read_str( _config_file, s);
    auto rgx = boost::regex( CONFIG_SECTIONS );
    boost::smatch terminal_match;
    // begins terminal section
    boost::regex_search( s, terminal_match, rgx, boost::match_not_bol | boost::match_not_eol );
    boost::smatch groups_match;
    // ends terminal section, begin group section
    string terminal_suffix = terminal_match.suffix();
    boost::regex_search(terminal_suffix, groups_match, rgx, boost::match_not_bol | boost::match_not_eol);
    // now get section
    string token_section = groups_match.prefix();

    // stream & parse tokens section
    std::istringstream input1;
    input1.str(token_section);
    unsigned long j = 0;
    for (std::string line; std::getline(input1, line); j++)
    {
        auto config_rgx = boost::regex( CONFIG );
        boost::smatch token_match;
        boost::regex_match( line, token_match, config_rgx );
        if(constexpr unsigned int ID_PAIR = 1; token_match[ID_PAIR].matched)
        {
            string name = token_match["name"].str();
            string expr = token_match["rexp"].str();
            string stype = token_match["type"].str();
            string test_val = token_match["test"].str();

            auto* ptoken = new token_def{ 0xFFul + j*0x06ul, string(name), stype, 0, string(expr), 0, string("null"), nullptr };

            // copy to term to vector
            _tokens.push_back(*ptoken);
            _id_tab[ptoken->id] = ptoken;
            _name_tab[ptoken->name] = ptoken;
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
            string str_state = states_match["state"].str();  // new state to create
            string str_tokens = states_match["tokens"].str(); // csv tokens for that state
            unsigned long i = 0ul;
            unsigned long state_id = 0xFFul | (++i*6ul); // generate id for new state
            auto* pstate = new state_t{ state_id , str_state }; // create new state
            p_states->push_back(pstate);
            (*p_state_tab)[pstate->id] = pstate; // insert new state into table

            // copy to term to vector
            vector<token_def> tokens; // token vector for this state
            std::stringstream ss(str_tokens); // csv of states
            std::string str_token; // item in csv states

            // use get line to split on commas
            while (std::getline(ss, str_token, ','))
            {
                token_def* ptoken = _name_tab[str_token];
                tokens.push_back(*ptoken);
                //_state_tokens_tab[pstate->id] = tokens;
            }
        }
    }
}

/**
 * @brief  dump config
 * @param file
 * @return void
 */
void Lexer::dump_config( const string& file ) const
{
    dump_config( );
}

/**
 * @brief  dump current config
 * @return void
 */
void Lexer::dump_config( ) const
{
    cout << "config_file: " << _config_file << endl;
    cout << "scan file: " << _scan_file << endl;
    cout << "search text: " << _search_text << endl;
    cout << "regexp: " << _expr << endl;
    cout << "state: " << p_state->name << endl;

    // todo: loop though globals

    stringstream ss;
    const size_t len = _tokens.size();
    for(int i = 0; i < len; ++i)
    {
        const token_def* ptoken = &_tokens[i];
        ss <<  "id: "         << left << setw(10) << ptoken->id         <<
              " name: "       << left << setw(10) << ptoken->name       <<
              " type: "       << left << setw(10) << ptoken->stype      <<
              " value: "      << left << setw(10) << ptoken->value      <<
              " rexp: "       << left << setw(10) << ptoken->rexp       <<
              " index: "      << left << setw(10) << ptoken->index      << endl;
    }
    cout << ss.str();
}

/**
 * @brief tokenize
*/
void Lexer::tokenize()
{
    stringstream ss;
    read_sstream( _scan_file, ss );
    string search_text = ss.str( );

    // initialize expression ...
    const auto rexp = boost::regex( _expr, boost::regex::extended );
    const auto begin = boost::sregex_iterator( search_text.begin( ), search_text.end( ), rexp, boost::match_not_bol | boost::match_not_eol );
    const auto end = boost::sregex_iterator();

    for(auto iter = begin; iter != end; ++iter)
    {
        token_def* ptoken = nullptr;
        const boost::smatch& m = *iter;
        const size_t len = m.size();
        // find matched
        cout << "find index " << endl;
        for(int i = 1; i < len; ++i)
        {
            if(m[i].matched)
            {   cout << "prefix: \"" << m.prefix() << "\" match: \"" << m[i].str() << "\"" << endl;
                if(string prefix = m.prefix(); !prefix.empty())
                {
                    cout << "error: invalid characters in sequence (" << prefix << ")" << endl;
                }

                ptoken = _idx_tab[i];        // look up by index
                ptoken->value = m[i].str();  // set match value

                cout << "matched index: " << i << endl;
                print_token(ptoken->id);
                if(ptoken->id == UL_SKIP_TOKEN)
                {
                    ++(*_p_iter);
                    continue; // skip back to top of for
                }
                break; // found : break for
            }
        }
        if(ptoken == nullptr)
            cout << "error: no submatch (" << m.str() << ") ..." << endl;
    }
}

/**
 * @brief  get_token
 * @return int
 */
parser::symbol_type Lexer::get_token()
{
    stringstream ss;
    if(*_p_iter != _end)
    {
        token* ptoken = nullptr;
        // find match & lookup by sub_match index
        boost::smatch m = *(*_p_iter);
        const size_t len = m.size();
        // find matched
        for(int i = 1; i < len; ++i)
        {
            if(m[i].matched)
            {
                ++(*_p_iter); // increment iterator

                string prefix = m.prefix();
                if(!prefix.empty())
                    _sout << prefix;

                ptoken = _idx_tab[i];        // lookup by sub_match index!
                ptoken->value = m[i].str();  // set match value
                //ptoken->type = parser::symbol_type( parser::token::SKIP_TOKEN );

                //_pos = m.position(i);
                //_len = m.length(i);
                auto ret = parser::symbol_type( on_token(ptoken) );
                if ( ptoken->type->kind_ == parser::symbol_kind_type::S_SKIP_TOKEN )
                {
                    cout << ptoken->name << endl;
                    return get_token(); // recursive skipping logic
                }
                cout << endl;
                _matches.push_back(ptoken);
                return ret;
            }
        }
    }
    return parser::make_END(); // error or eof
}

/**
 * @brief reset
 */
void Lexer::reset()
{
    init(_scan_file, _config_file, _pparser);
}

/**
 * @brief get regex expression
 * @return const string&
 */
const string& Lexer::get_expr() const
{
    return _expr;
}

/**
 * @brief init_expr
 */
void Lexer::build_expr()
{
    _expr.clear();
    stringstream ss;
    const size_t len = _tokens.size();
    for(int i = 0; i < len; ++i)
    {
        const token_def* ptoken = &_tokens[i];
        // ss << "(?<" << ptoken->name << ">" << ptoken->rexp << ")|";
        ss << "(" << ptoken->rexp << ")|";
    }
    _expr = ss.str();
    _expr.pop_back(); // remove extra '|' i.e. "V-BAR"
    _rexp = boost::regex( _expr, boost::regex::extended );
}

/**
 * @brief print token to stdout
 */
void Lexer::print_token(int id)
{
    const token *ptoken = _id_tab[id];
    cout << "token:\n{" << setw(5) << left << "\n\t id: " << setw(10) << right << ptoken->id << setw(5) << left
         << "\n\t name: " << setw(10) << right << ptoken->name << setw(5) << left << "\n\t stype: " << setw(10) << right
         << ptoken->stype << setw(5) << left << "\n\t index: " << setw(10) << right << ptoken->index << setw(5) << left
         << "\n\t value: " << setw(10) << right << ptoken->value << setw(5) << left << "\n\t rexp: " << setw(10)
         << right << ptoken->rexp << setw(5) << left << "\n\t test_value: " << setw(10) << right
         << "\n}" << endl;
}


/**
* @brief get_state
* @return state_t
*/
state_t *Lexer::get_state() const
{
    return p_state;
}

/**
 * @brief set_state
 * @param pstate
 * @return void
 */
void Lexer::set_state(state_t* pstate)
{
    // _tokens.clear();
    // _idx_tab.clear();
    // _idx_tab.clear();
    // _name_tab.clear();

    gp_state = pstate;
    p_state = gp_state;
    build_expr();

    // vector<unsigned long> *TOKENS = &g_state_tokens_tab[g_state->id];
    // const int len_states = TOKENS->size();
    // for (int i = 0; i < len_states; i++)
    // {
    //     const int len_tokens = g_tokens_all.size();
    //     for (int j = 0; j < len_tokens; j++)
    //     {
    //         g_tokens_all[j].index = i + 1;
    //         if (g_tokens_all[j].id == (*TOKENS)[i])
    //         {
    //             _tokens.push_back(g_tokens_all[j]);
    //             _id_tab[g_tokens_all[j].id] = &g_tokens_all[j];
    //             _idx_tab[g_tokens_all[j].index] = &g_tokens_all[j];
    //             _name_tab[g_tokens_all[j].name] = &g_tokens_all[j];
    //         }
    //     }
    // }

    //vector<unsigned long> *g_tokens_all = &g_state_tokens_tab[g_state->id];
    // const int len_states = g_tokens_all.size();
    // for (int i = 0; i < len_states; i++)
    // {
    //     const int len_tokens = g_tokens_all.size();
    //     for (int j = 0; j < len_tokens; j++)
    //     {
    //         g_tokens_all[j].index = i + 1;
    //         _tokens.push_back(g_tokens_all[j]);
    //         _id_tab[g_tokens_all[j].id] = &g_tokens_all[j];
    //         _idx_tab[g_tokens_all[j].index] = &g_tokens_all[j];
    //         _name_tab[g_tokens_all[j].name] = &g_tokens_all[j];
    //     }
    // }
    // //
    // cout << _expr << endl;
    //
    //
    // // // todo just begin !!
    // // _matches[_matches.size()-1];
    // // _search_text = _search_text.substr(_pos, _len);
    // _begin = boost::sregex_iterator( _search_text.begin( ), _search_text.end( ), _rexp );
    // _p_iter = &_begin;
    //_end = boost::sregex_iterator();
}


bool Lexer::is_id( const token_def& token, const int& id )
{
        return (token.id == id);
}