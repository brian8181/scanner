
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

/**
 * @name Lexer
 * @def Lexer::Lexer()
 * @brief default ctor
 */
Lexer::Lexer()
{
}

/**
 * @name load_config
 * @def void Lexer::load_config( const string &file )
 * @brief  load_config: load configuration from file
 * @param  const string& file
 * @return void
 */
void Lexer::load_config( const string& file )
{
    m_config_file = file;
    string section = "none";
    string s;
    read_str( m_config_file, s);
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
            m_tokens.push_back(*ptoken);
            m_id_tab[ptoken->id] = ptoken;
            m_name_tab[ptoken->name] = ptoken;
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
                token_def* ptoken = m_name_tab[str_token];
                tokens.push_back(*ptoken);
                //_state_tokens_tab[pstate->id] = tokens;
            }
        }
    }
}

/**
 * @name dump_config
 * @brief void Lexer::dump_config( const string& file ) const
 * @param const string& file
 * @return void
 */
void Lexer::dump_config( const string& file ) const
{
    dump_config( );
}

/**
 * @name dump_config
 * @def void Lexer::dump_config( ) const
 * @brief  dump current config
 * @return void
 */
void Lexer::dump_config( ) const
{
    cout << "config_file: " << m_config_file << endl;
    cout << "scan file: " << m_input_file << endl;
    cout << "search text: " << m_all_search_text << endl;
    cout << "regexp: " << m_expr << endl;
    cout << "state: " << p_state->name << endl;

    // todo: loop though globals

    stringstream ss;
    const size_t len = m_tokens.size();
    for(int i = 0; i < len; ++i)
    {
        const token_def* ptoken = &m_tokens[i];
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
 * @name init
 * @def void Lexer::init(const string &config_file, parser* pparser, const string& input_file, const string& output_file)
 * @brief  initialize state
 * @return bool
 */
void Lexer::init(const string &config_file, parser* pparser, const string& input_file, const string& output_file)
{
    m_config_file = config_file;
    m_input_file = input_file;
    m_output_file = output_file;
    m_pparser = pparser;

    p_state = gp_state;
    p_states = &g_states;
    p_state_tab = &g_state_tab;
    p_state_tokens_tab = &g_state_tokens_tab;

    //load_config( m_config_file );
    stringstream ss;
    read_sstream( m_input_file, ss );
    m_all_search_text = ss.str( );
    m_current_search_text = m_all_search_text;
    // set state
    set_state(p_state);
}

/**
* @name get_state
* @brief state_t *Lexer::get_state() const
* @return state_t
*/
state_t *Lexer::get_state() const
{
    return p_state;
}

/**
 * @name set_state
 * @brief void Lexer::set_state(state_t* pstate)
 * @param state_t* pstate
 * @return void
 */
void Lexer::set_state(state_t* pstate)
{
    m_tokens.clear();
    m_idx_tab.clear();
    m_idx_tab.clear();
    m_name_tab.clear();

    gp_state = pstate;
    p_state = gp_state;

    m_tokens.clear();
    vector<unsigned long>* TOKENS = &g_state_tokens_tab[gp_state->id];
    const unsigned long len_states = TOKENS->size();
    for (unsigned long i = 0; i < len_states; i++)
    {
        const unsigned long len_tokens = g_tokens_all.size();
        for (unsigned long j = 0; j < len_tokens; j++)
        {
            g_tokens_all[j].index = i + 1;
            if (g_tokens_all[j].id == (*TOKENS)[i])
            {
                m_tokens.push_back(g_tokens_all[j]);
                m_id_tab[g_tokens_all[j].id] = &g_tokens_all[j];
                m_idx_tab[g_tokens_all[j].index] = &g_tokens_all[j];
                m_name_tab[g_tokens_all[j].name] = &g_tokens_all[j];
            }
        }
    }

    build_expr();
    // reinit get_token iterators
    m_rexp = boost::regex( m_expr, boost::regex::extended /*|  boost::match_not_bol | boost::match_not_eol*/ );
    m_begin = boost::sregex_iterator( m_current_search_text.begin( ), m_current_search_text.end( ), m_rexp );
    m_piter = &m_begin;
    m_end = boost::sregex_iterator();
}

/**
 * @name tokenize
 * @def void Lexer::tokenize()
*/
void Lexer::tokenize()
{
    stringstream ss;
    read_sstream( m_input_file, ss );
    string search_text = ss.str( );

    // initialize expression ...
    const auto rexp = boost::regex( m_expr, boost::regex::extended );
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

                ptoken = m_idx_tab[i];        // look up by index
                ptoken->value = m[i].str();  // set match value

                cout << "matched index: " << i << endl;
                print_token(ptoken->id);
                if(ptoken->id == UL_SKIP_TOKEN)
                {
                    ++(*m_piter);
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
 * @name  get_token
 * @def parser::symbol_type Lexer::get_token()
 * @return int
 */
parser::symbol_type Lexer::get_token()
{
    if(*m_piter != m_end)
    {
        token* ptoken = nullptr;
        boost::smatch m = *(*m_piter);
        const size_t len = m.size();

        cout << endl
             << "   match:  '" << m.str()
             << "', prefix: '" << m.prefix()
             << "', suffix: '" << m.suffix()
             << "'" << endl << endl;

        m_prefix = m.prefix();
        m_suffix = m.suffix();
        // if (p_state->id == cESCAPED)
        // {
        //     if(!m_prefix.empty())
        //         m_sout << m_prefix;
        // }

        // find matched
        for(int i = 1; i < len; ++i)
        {
            if(m[i].matched)
            {
                // find match & lookup by sub_match index
                ptoken = m_idx_tab[i];        // lookup by sub_match index!
                ptoken->value = m[i].str();   // set match value
                m_current_search_text= m.suffix();
                m_matches.push_back(ptoken);

                ++(*m_piter); // increment iterator

                // get return "value / token" first, then check for skip,
                // call "get_token/on_token" recursively until it does not skip
                // then return token ... stack unrolls
                // auto ret = parser::symbol_type( on_token(ptoken) );
                if (ptoken->id == UL_WHITESPACE)
                    continue;

                return on_token( ptoken );
            }
        }
    }
    else
    {
        if(!m_suffix.empty())
            m_sout << m_current_search_text;
        m_current_search_text.clear();

        const char* s = m_sout.str().c_str();
        int len = strlen(s);

        write_buf(m_output_file, s, len);
        return parser::make_END(); // error or eof
    }
    return parser::make_END_OF_FILES(); // error or eof
}

/**
 * @name reset
 * @def void Lexer::reset()
 */
void Lexer::reset()
{
    init(m_config_file, m_pparser, m_input_file, m_output_file);
}

/**
 * @name get_expr
 * @def const string& Lexer::get_expr() const
 * @brief get regex expression
 * @return const string&
 */
const string& Lexer::get_expr() const
{
    return m_expr;
}

/**
 * @name build_expr
 * @def void Lexer::build_expr()
 */
void Lexer::build_expr()
{
    m_expr.clear();
    stringstream ss;
    const size_t len = m_tokens.size();
    for(int i = 0; i < len; ++i)
    {
        const token_def* ptoken = &m_tokens[i];
        // ss << "(?<" << ptoken->name << ">" << ptoken->rexp << ")|";
        ss << "(" << ptoken->rexp << ")|";
    }
    m_expr = ss.str();
    m_expr.pop_back(); // remove extra '|' i.e. "V-BAR"
    m_rexp = boost::regex( m_expr, boost::regex::extended );
}

/**
 * @name print_token
 * @def void Lexer::print_token(int id)
 * @brief print token to stdout
 */
void Lexer::print_token(int id)
{
    const token *ptoken = m_id_tab[id];
    cout << "token:\n{" << setw(5) << left << "\n\t id: " << setw(10) << right << ptoken->id << setw(5) << left
         << "\n\t name: " << setw(10) << right << ptoken->name << setw(5) << left << "\n\t stype: " << setw(10) << right
         << ptoken->stype << setw(5) << left << "\n\t index: " << setw(10) << right << ptoken->index << setw(5) << left
         << "\n\t value: " << setw(10) << right << ptoken->value << setw(5) << left << "\n\t rexp: " << setw(10) << right
         << ptoken->rexp << setw(5) << left << setw(10) << right
         << ptoken->type << setw(5) << left << setw(10) << right
         << "\n}" << endl;
}

/**
 * @name is_id
 * @def bool Lexer::is_id( const token_def& token, const int& id )
 * @param token
 * @param id
 * @return
 */
bool Lexer::is_id( const token_def& token, const int& id )
{
        return (token.id == id);
}