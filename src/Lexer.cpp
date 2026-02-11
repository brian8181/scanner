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
#include <boost/regex.hpp>
#include "fileio.hpp"
#include "Lexer.hpp"
#include "constants.hpp"
#include "tokens.hpp"

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
Lexer::Lexer( const Lexer& src ): _p_iter(nullptr)
{

}

/**
 * @brief virtual dtor
 */
Lexer::~Lexer()
{
    const int tlen = _tokens.size();
    for(int i = 0; i < tlen; ++i)
    {
        delete _tokens[i];
    }

    const int mlen = _matches.size();
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

    #define LEX_TEST
    #ifdef LEX_TEST
    // init tables from tokens.hpp
    for(int i = 0; i < tokens.size(); ++i)
    {
        _tokens.push_back(tokens[i]);
        _id_tab[tokens[i]->id] = tokens[i];
        _name_tab[tokens[i]->name] = tokens[i];
        _idx_tab[tokens[i]->index] = tokens[i];
    }
    // testing ... todo ... use auto created expression
    //_expr = expression;
    init_epxr();
    cout << _expr << endl;
    #endif

    // bkp todo 1-3 ...
    _state = new state{ 1, "INITIAL" };
    _states.push_back(_state);
    _state_tab[_state->id] = _state;
    vector<token*> tokens; // bkp todo tokens for state
    _state_tokens_tab[_state->id] = tokens;

    //load_config( config_file );
    _scan_file = file;
    stringstream ss;
    const int r = read_sstream( file, ss );
    _search_text = ss.str( );

    // initialize expression ...
    //init_expr();
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

            auto* ptoken = new token{ 0xFF + j*0x06, string(name), stype, 0, 0, string(expr), string(test_val), 0, string("null") };
            // copy to term to vector
            _tokens.push_back(ptoken);
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
                token* ptoken = _name_tab[str_token];
                tokens.push_back(ptoken);
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
    stringstream ss;
    const size_t len = _tokens.size();
    for(int i = 0; i < len; ++i)
    {
        const token* ptoken = _tokens[i];
        ss <<  "id: "         << left << setw(10) << ptoken->id         <<
              " name: "       << left << setw(10) << ptoken->name       <<
              " type: "       << left << setw(10) << ptoken->stype      <<
              " value: "      << left << setw(10) << ptoken->value      <<
              " rexp: "       << left << setw(10) << ptoken->rexp       <<
              " index: "      << left << setw(10) << ptoken->index      <<
              " test_value: " << left << setw(10) << ptoken->test_value << endl;
    }
    cout << ss.str();
}

/**
 * @brief tokenize
*/
void Lexer::tokenize()
{
    stringstream ss;
    const int r = read_sstream( _scan_file, ss );
    string search_text = ss.str( );

    // initialize expression ...
    // testing ... todo ... use auto created expression
    // _expr = "(!=)|(=)";
    // search_text = "! =!= =   !=";

    auto rexp = boost::regex( _expr, boost::regex::ECMAScript );
    auto begin = boost::sregex_iterator( search_text.begin( ), search_text.end( ), rexp, boost::match_not_bol | boost::match_not_eol );
    auto end = boost::sregex_iterator();

    for(auto iter = begin; iter != end; ++iter)
    {
        CONTINUE_ON_NO_ACTION:
        token* ptoken = nullptr;
        const boost::smatch& m = *(iter);
        const size_t len = m.size();
        // find matched
        cout << "find index " << endl;
        for(int i = 1; i < len; ++i)
        {
            if(m[i].matched)
            {   cout << "prefix: \"" << m.prefix() << "\" match: \"" << m[i].str() << "\"" << endl;
                if(string prefix = m.prefix(); prefix.empty())
                {
                    cout << "error: invalid characters in sequence (" << prefix << ")" << endl;
                }
                ptoken = _idx_tab[i];        // look up by index
                ptoken->value = m[i].str();
                cout << "matched index: " << i << endl;
                print_token(ptoken->id);
                if(on_token( *_state, *ptoken ) == NO_ACTION)
                    goto CONTINUE_ON_NO_ACTION;
                break;                    // found
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
int Lexer::get_token()
{
    #define LEX_TEST
    #ifdef LEX_TEST
    enum yytokentype
    {
        YYEMPTY = -2,
        YYEOF = 0,                     /* "end of file"  */
        YYerror = 256,                 /* error  */
        YYUNDEF = 257,                 /* "invalid token"  */
        INTEGER = 258,                 /* INTEGER  */
        //token_ = 259,                   /* token  */
        //SEMI_COLON = 260,              /* SEMI_COLON  */
        NEWLINE = 261,                 /* NEWLINE  */
        // PLUS = 262,                    /* PLUS  */
        // MINUS = 263,                   /* MINUS  */
        // MULT = 264,                    /* MULT  */
        // DIV = 265                      /* DIV  */
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
    default: ;
    }
    #else
    stringstream ss;
    token* ptok = 0;

    if(*_p_iter != _end)
    {
    CONTINUE_ON_NO_ACTION:
        cout << "get_token " << endl;
        // need to look up by sub_match index
        boost::smatch m = *(*_p_iter);
        size_t len = m.size();
        cout << "max: " << m.max_size() << endl;
        // find matched
        cout << "find index ";
        for(int i = 1; i < len; ++i)
        {
            cout << ".";
            if(m[i].matched)
            {
                cout << "prefix: \"" << m.prefix() << "\" match: \"" << m[i].str() << "\"" << endl;
                string prefix = m.prefix();
                if(prefix.size() != 0)
                {
                    cout << "error: invalid characters in sequence (" << prefix << ")" << endl;
                }
                ptok = _idx_tab[i]; // by index
                ptok->value = m[i].str(); // set match value
                _matches.push_back(ptok); // push matched
                cout << "debug - id: " << ptok->id << "name: " << ptok->name  << endl;
                print_token(ptok->id); // debug print
                if(on_token( *_state, *ptok ) == NO_ACTION)
                {
                    (*_p_iter)++;
                    goto CONTINUE_ON_NO_ACTION; // do actions
                }
                break; // found
            }
        }
        ++(*_p_iter); // increment iterrator
        cout << "return -> " << ptok->id << endl;
        return ptok->id; // return token id
    }
    #endif
    return 0; // error or eof

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
int Lexer::on_token( const state& s, token& tok )
{
   return on_token_action(s, tok);
}

/**
 * @brief override virtual, on_token, for each token ...
 * @param token
 */
void Lexer::on_token( const unsigned int& token_, const boost::smatch& m )
{
    // bkp todo!
    stringstream ss;
    unsigned int token = ID_UNDEFINED;

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

        // only if there are no submatches
        ptok->index = i;
        _idx_tab[ptok->index] = ptok;
        //ss << "(?<" << ptok->name << ">" << ptok->rexp << ")|";
        ss << "(" << ptok->rexp << ")|";
    }
    _expr = ss.str();
    _expr.pop_back();

    #define LEX_TEST
    #ifndef LEX_TEST
    auto index using test_value
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
                _idx_tab[ptok->index] = ptok;
                break;
            }
        }
    }
    #endif
}

/**
 * @brief print token to stdout
 */
void Lexer::print_token( int id )
{
    token* ptok = _id_tab[id];
    cout << "token:\n{"
            << setw(5) << left << "\n\tid: "         << setw(10) << right << ptok->id
            << setw(5) << left << "\n\tname: "       << setw(10) << right << ptok->name
            << setw(5) << left << "\n\tstype: "      << setw(10) << right << ptok->stype
            << setw(5) << left << "\n\tindex: "      << setw(10) << right << ptok->index
            << setw(5) << left << "\n\tvalue: "      << setw(10) << right << ptok->value
            << setw(5) << left << "\n\trexp: "       << setw(10) << right << ptok->rexp
            << setw(5) << left << "\n\ttest_value: " << setw(10) << right << ptok->test_value
        << "\n}"
    << endl;
}
