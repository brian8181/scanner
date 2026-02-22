/**
 * @file    Lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 */
#ifndef Lexer_HPP_
#define Lexer_HPP_

#include <iostream>
#include <string>
#include <utility>
#include <iterator>
#include <vector>
#include <map>
#include <list>
#include "pparser.tab.hh"
#include <regex>
#include <boost/regex.hpp>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::pair;
using std::regex;

/* LEX TYPES */
#define right_assoc 0x8
#define left_assoc  0x20
#define non_assoc   0x40
#define start       0x1;

#define INT 1
#define FLOAT 2

// namespace bkp
// {
//vector<pair<string,int>> str_to_int { { "INT", 1}, {"FLOAT", 2} };
typedef struct token_t {
	int id;
	string name;
	string type;
	string rexpr;
} token_t;

typedef struct token_match_t
{
	int line;
	int col;
	string value;
	token_t token;
} token_match_t;

typedef struct token_def
{
	int id;
	string name;
	string stype;
	int itype;
	int lex_t;
	string rexp;
	string test_value;
	int index;
	string value;
} token_def;

typedef token_def token;

typedef struct token_match
{
	int id;
	int pos;
	int line;
	string value;
	token_def token;
} token_match;

typedef struct state_t
{
	int id;
	string name;
} state_t;

typedef struct context_t
{
	std::string&               scan_file;
	std::string&               search_text;
	boost::regex&              rexp;
	boost::sregex_iterator&    begin;
	boost::sregex_iterator&    end;
	boost::sregex_iterator*    p_iter;
	state_t*                   state;
	string&                    expr;
	vector<token_def*>*        matches;
} context_t;

const string TOKEN_TYPE           = "[A-Za-z][A-Za-z_]*((::)[A-Za-z_]*)?";
const string TOKEN_TYPE_           = "[A-Za-z][A-Za-z_]*";
const string VALID_SYMBOL_CHARS   = "[A-Za-z0-9_]"; /** @note_to_self: ~~> \w == [A-Za-z0-9_] **/
const string VALID_CHARS          = "[[:punct:][:alnum:]]"; // [:punct:] = !"#$%&'()*+,-./:;<=>?@[\]^_{|}~`
const string CONFIG_STATES        = R"((?<states>^\s*(?<state>[A-Za-z][A-Za-z0-9_]*)\s*=\s*\s*\{(?<tokens>[A-Za-z][A-Za-z0-9_]*(, [A-Za-z][A-Za-z0-9_]*)*)\}\s*\s*$))";
const string CONFIG_SECTIONS      = R"(^\s*\[\s*(?<tokens>tokens)|(?<groups>groups)|(?<states>states)\s*\]\s*$)";
const string CONFIG_PAIR          = "\\s*(?<type>" + TOKEN_TYPE_ + ")\\s+(?<name>[A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*(?<rexp>" + VALID_CHARS + "*)\\s*\"(?<test>.*)\"\\s*";
const string CONFIG_COMMENT       = "^\\s*#.*$";
const string CONFIG               = "(?<pairs>" + CONFIG_PAIR + ")|(?<comments>" + CONFIG_COMMENT + ")";

/**
  * @brief class Lexer
  */
class Lexer final
{
public:
	/**
	 * @brief default ctor
	 */
	Lexer();

	/**
	 * @brief ctor
	 * @param file
	 * @param config_file
	 */
	Lexer(const string& file, const string &config_file);

	/**
	 * @brief copy ctor
	 * @param src
	 */
	Lexer( const Lexer& src );

	/**
	 * @brief virtual dtor
	 */
	virtual ~Lexer();

	/**
	 * @brief  initialize state
	 * @param file
	 * @param config_file
	 * @return bool
	 */
	bool init( const string& file, const string &config_file );

	/**
	 * @brief  load_config: load configuration from file
	 * @param  file
	 * @return void
	 */
	void load_config( const string &file );

	/**
	 * @brief  dump current config
	 * @return void
	 */
	void dump_config( ) const;

	/**
	 * @brief  dump config
	 * @param  file
	 * @return void
	 */
	void dump_config( const string &file ) const;

	/**
	 * @brief  get_token
	 * @return int
	 */
	static int get_token();

	/**
	 * @brief reset to initial state
	 */
	void reset();

	/**
	 * @brief override virtual, on_token, for each token ...
	 * @param state
	 * @param token
	 */
	static int on_token( const state_t& state, const token_def& token );

	/**
	 * @brief tokenize
	*/
	void tokenize();

	/**
 	* @brief get expression
 	*/
	const string& get_expr() const;

	/**
	 * @brief init_expr
	 */
	void init_expr();

	/**
     * @brief print token to stdout
	 * @param id
 	 */
	void print_token( int id );

protected:
	string                        _config_file;
	vector<token_def*>            _tokens;
	vector<state_t*>              _states;
	map<int, token_def*>          _idx_tab;  // idx -> token_def
	map<int, token_def*>          _id_tab;   // id -> token_def
	map<string, token*>           _name_tab; // name -> token_def
	map<int, vector<token_def*>>  _state_tokens_tab;
	map<int, state_t*>            _state_tab;
	vector<token_def*>            _matches;
	std::string                   _scan_file;
	std::string                   _search_text;
	boost::regex                  _rexp;
	boost::sregex_iterator        _begin;
	boost::sregex_iterator        _end;
	boost::sregex_iterator*      _p_iter;
	state_t*                     _state;
	string                       _expr;
};

//}

#endif
