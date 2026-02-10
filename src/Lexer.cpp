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
    int tlen = _tokens.size();
    for(int i = 0; i < tlen; ++i)
    {
        delete _tokens[i];
    }

    int mlen = _matches.size();
    for(int i = 0; i < mlen; ++i)
    {
        delete _matches[i];
    }
}

/**
 * @brief  initialize state
 * @param  file
 * @param  config_file
 * @return bool
 */
bool Lexer::init( const string& file, const string &config_file )
{
    // bkp todo!
    // _scan_file = "";
    // _search_text = "";
    // _rexp = "";
    // _begin;
    // _end;
    // _p_iter;
    // delete _state;
    // _state = new state{ 1, "INITIAL" };
    // _expr;

    _tokens.clear();
	_idx_tab.clear();
	_id_tab.clear();
	_name_tab.clear();
	_state_tokens_tab.clear();
	_state_tab.clear();
	_matches.clear();

    load_config( config_file );
    _state = new state{ 1, "INITIAL" };
    _scan_file = file;
    stringstream ss;
    const int r = read_sstream( file, ss );
    _search_text = ss.str( );
    // initialize expression ...
    //init_epxr();
    //_rexp = boost::regex( EVERYTHING, boost::regex::ECMAScript );
    _rexp = boost::regex( _expr, boost::regex::ECMAScript );
    _begin = boost::sregex_iterator( _search_text.begin( ), _search_text.end( ), _rexp );
    _p_iter = &_begin;
    _end = boost::sregex_iterator();
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
    _config_file = path;
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
    int j = 0;
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
            string str_state = states_match["state"].str();  // new state to create
            string str_tokens = states_match["tokens"].str(); // csv tokens for that state
            int i = 0;
            int state_id = 0xFF | (++i*6); // generate id for new state
            auto* pstate = new state{ state_id , str_state }; // create new state
            _states.push_back(pstate);
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
        ss <<  "id: "         << left << setw(10) << ptok->id         <<
              " name: "       << left << setw(15) << ptok->name       <<
              " type: "       << left << setw(15) << ptok->stype      <<
              " value: "      << left << setw(15) << ptok->value      <<
              " rexp: "       << left << setw(15) << ptok->rexp       <<
              " index: "      << left << setw(15) << ptok->index      <<
              " test_value: " << left << setw(15) << ptok->test_value << endl;
    }
    cout << ss.str();
}

/**
 * @brief tokenize
 * @param exp
 * @param text
*/
void Lexer::tokenize()
{
    stringstream ss;
    const int r = read_sstream( _scan_file, ss );
    string search_text = ss.str( );
    // initialize expression ...

    // testing ...
    string expr = "(\\*)|(\\,)|(\\.)";
    auto rexp = boost::regex( expr, boost::regex::ECMAScript );
    auto begin = boost::sregex_iterator( search_text.begin( ), search_text.end( ), rexp, boost::match_not_bol | boost::match_not_eol );
    auto end = boost::sregex_iterator();

    for(auto iter = begin; iter != end; ++iter)
    {
        token* ptok = 0;
        boost::smatch m = *(iter);
        size_t len = m.size();
        // find matched
        cout << "find index " << endl;
        for(int i = 1; i < len; ++i)
        {
            if(m[i].matched)
            {
                // ptok = _idx_tab[i];        // look up by index
                // ptok->value = m[i].str();
                cout << "matched index: " << i << endl;
                //print_token(ptok->id);
                break;                    // found
            }
        }
        if(ptok == 0)
            cout << "error: no submatch (" << m.str() << ") ..." << endl;
    }
}

/**
 * @brief  get_token
 * @return int
 */
int Lexer::get_token()
{
    enum yytokentype
    {
        YYEMPTY = -2,
        YYEOF = 0,                     /* "end of file"  */
        YYerror = 256,                 /* error  */
        YYUNDEF = 257,                 /* "invalid token"  */
        INTEGER = 258,                 /* INTEGER  */
        token_ = 259,                   /* token  */
        SEMI_COLON = 260,              /* SEMI_COLON  */
        NEWLINE = 261,                 /* NEWLINE  */
        PLUS = 262,                    /* PLUS  */
        MINUS = 263,                   /* MINUS  */
        MULT = 264,                    /* MULT  */
        DIV = 265                      /* DIV  */
    };
    typedef enum yytokentype yytoken_kind_t;

    static int i = 0;
    switch(++i)
    {
    case 1:
        //yylval.num = atoi(TOKS[i++]);
        return INTEGER;
    case 2:
        //yylval.str = TOKS[i++];
        return PLUS;
    case 3:
        //yylval.num = atoi(TOKS[i++]);
        return INTEGER;
    case 4:
        //yylval.str = TOKS[i++];
        return SEMI_COLON;
     case 5:
        //yylval.str = TOKS[i++];
        return NEWLINE;
     case 6:
        //yylval.str = TOKS[i++];
        return 0;
    }
    return 0;
    // stringstream ss;
    // token* ptok = 0;
    // if(*_p_iter != _end)
    // {
    //     cout << "get_token " << endl;
    //     // need to look up by sub_match index
    //     boost::smatch m = *(*_p_iter);
    //     size_t len = m.size();
    //     cout << "max: " << m.max_size() << endl;
    //     // find matched
    //     cout << "find index ";
    //     for(int i = 1; i < len; ++i)
    //     {
    //         cout << ".";
    //         if(m[i].matched)
    //         {
    //             ptok = _idx_tab[i];        // look up by index
    //             ptok->value = m[i].str();
    //             _matches.push_back(ptok);  // push matched token
    //             cout << "matched " << ptok->name << endl;
    //             break;                    // found
    //         }
    //     }
    //     ++(*_p_iter);              // increment iterrator
    //     cout << "return -> " << ptok->id << endl;
    //     return ptok->id;           // return token id
    // }
    // return 0; // error or eof
}

/**
 * @brief reset
 */
void Lexer::reset()
{

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
const string& Lexer::get_expr() const
{
    return _expr;
}

/**
 * @brief init_expr
 */
void Lexer::init_epxr()
{
    // generate expression from sub expressions (1?)|(2?)|(3?)|...|(n?)
    stringstream ss;
    const size_t len = _tokens.size();
    for(int i = 0; i < len; ++i)
    {
        token* ptok = _tokens[i];
        ss << "(?<" << ptok->name << ">" + ptok->rexp + ")|";
    }
    _expr = ss.str();
    _expr.pop_back();

    // auto index using test_value
    const auto rgx = boost::regex( _expr );
    boost::smatch m;
    for(int i = 0; i < len; ++i)
    {
        cout << "checking indexes ..." << endl;
        token* ptok = _tokens[i];
        boost::regex_search( ptok->test_value, m, rgx );
        const size_t sz = m.size();
        for(int j = 1; j < sz; ++j)
        {
            cout << j << ", ";
            if(m[j].matched)
            {
                cout << endl;
                cout << "found idx = " << j << endl;
                ptok->index = j;
                break;
            }
        }
    }
}

/**
 * @brief print token to stdout
 */
void Lexer::print_token( int id )
{
    token* ptok = _id_tab[id];
    cout << "{\n\ttoken: " << ptok->id << "\n\tname: " << ptok->name << "\n\ttoken: '" << ptok->value << "\n}" << endl;
}
