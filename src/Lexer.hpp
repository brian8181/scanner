/**
 * @file    Lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 */
#ifndef _Lexer_HPP_
#define _Lexer_HPP_

#include <iostream>
#include <string>
#include <utility>
#include <iterator>
#include <vector>
#include <map>
#include <list>
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

typedef struct state
{
	int id;
	string name;
} state;

typedef struct context
{
	std::string&               scan_file;
	std::string&               search_text;
	boost::regex&              rexp;
	boost::sregex_iterator&    begin;
	boost::sregex_iterator&    end;
	boost::sregex_iterator*    p_iter;
	state*                     state;
	string&                    expr;
	vector<token*>*            matches;
} context;

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
	 * @param const string& file, scan file
	 * @param const string &config_file, config file
	 */
	Lexer(const string& file, const string &config_file);

	/**
	 * @brief copy ctor
	 * @param src
	 * @param const Lexer& src
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
	 * @param  file : config to dump
	 * @return void
	 */
	void dump_config( const string &file );

	/**
	 * @brief  get_token
	 * @param token
	 * @return int
	 */
	int get_token();

	/**
	 * reset to intial state
	 */
	void reset();

	/**
	 * @brief override virtual, on_token, for each token ...
	 * @param token
	 */
	int on_token( token& );


	/**
	 * @brief virtual, virtual for each token ...
	 * @param token_
	 * @param m
	 */
	virtual void on_token( const unsigned int& token_, const boost::smatch& m );

	/**
	 * @brief tokenize
	 * @param exp
	 * @param text
	*/
	void tokenize();

	/**
 	* @brief get expression
 	*/
	const string& get_expr() const;

	/**
	 * @brief init_expr
	 */
	void init_epxr();

	/**
     * @brief print token to stdout
 	 */
	void print_token( int id );

protected:
	string                    _config_file;
	vector<token*>            _tokens;
	vector<state*>            _states;
	map<int, token*>          _idx_tab;
	map<int, token*>          _id_tab;
	map<string, token*>       _name_tab;
	map<int, vector<token*>>  _state_tokens_tab;
	map<int, state*>          _state_tab;
	vector<token*>            _matches;
	std::string               _scan_file;
	std::string               _search_text;
	boost::regex              _rexp;
	boost::sregex_iterator    _begin;
	boost::sregex_iterator    _end;
	boost::sregex_iterator*   _p_iter;
	state*                    _state;
	string                    _expr;
};

//}

#endif
