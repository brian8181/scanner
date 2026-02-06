/**
 * @file    Lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 * @info    ...
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

	// const string VALID_SYMBOL_CHARS   = "[A-Za-z0-9_]"; /** @note_to_self: ~~> \w == [A-Za-z0-9_] **/
	// const string VALID_CHARS          = "[ [:punct:][:alnum:]]"; // [:punct:] = !"#$%&'()*+,-./:;<=>?@[\]^_{|}~`
	// const string VALID_FILE_CHARS     = "[A-Za-z0-9_. ]";
	// const string TOKEN_TYPE           = "[A-Za-z][A-Za-z_]*((::)[A-Za-z_]*)?";
	// const string TOKEN_TYPE_           = "[A-Za-z][A-Za-z_]*";
	// const string CONFIG_PAIR          = "\\s*(?<type>" + TOKEN_TYPE_ + ")\\s+(?<name>[A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*(?<rexp>" + VALID_CHARS + "*)\\s*";
	// const string CONFIG_STATES        = "(?<states>^\\s*(?<state>[A-Za-z][A-Za-z0-9_]*)\\s*=\\s*\\s*\\{(?<tokens>[A-Za-z][A-Za-z0-9_]*(, [A-Za-z][A-Za-z0-9_]*)*)\\}\\s*\\s*$)";
	// //const string CONFIG_PAIR          = "\\s*(" + TOKEN_TYPE_ + ")\\s+([A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*(" + VALID_CHARS + "*)\\s*";
	// const string CONFIG_PAIR_VAR      = "\\s*\\s*([A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*($[A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*";
	// const string CONFIG_SECTION       = "\\s*\\[(?<section>[a-zA-Z][a-zA-Z0-9]*)\\]\\s*";
	// const string CONFIG_SECTIONS      = "^\\s*\\[\\s*(?<tokens>tokens)|(?<groups>groups)|(?<states>states)\\s*\\]\\s*$";
	// const string CONFIG_COMMENT       = "^\\s*#.*$";
	// const string CONFIG               = "(?<pairs>" + CONFIG_PAIR + ")|(?<comments>" + CONFIG_COMMENT + ")";

#define INT 1
#define FLOAT 2


vector<pair<string,int>> str_to_int { { "INT", 1}, {"FLOAT", 2} };

typedef struct terminal
{
	int id;
	string stype;
	int itype;
	int lex_t;
	string name;
	string rexp;
} terminal;

typedef struct token
{
	int id;
	string value;
	string stype;
	int itype;
	int lex_t;
	string name;
} token;

typedef struct lex_state
{
	int id;
	string name;
} lex_state;


/**
  * @brief class Lexer
  */
class Lexer
{
public:
	/**
	 * @brief default ctor
	 */
	Lexer();

	/**
	 * @brief ctor
	 * @param const string& file, scan file
	 * @param const string &config_file, config file
	 */
	Lexer(const string& file, const string &config_file);

	/**
	 * @brief copy ctor
	 * @param const Lexer& src
	 */
	Lexer( const Lexer& src );

	/**
	 * @brief virtual dtor
	 */
	virtual ~Lexer();

	/**
	 * @brief  initialize state
	 * @param  const string& file, scan file
	 * @param  const string &config_file, config file
	 * @return bool
	 */
	bool init( const string& file, const string &config_file );

	/**
	 * @brief  load_config: load confiuration from file
	 * @param  const string &path
	 * @return void
	 */
	void load_config( const string &path );

	/**
	 * @brief  dump current config
	 * @return void
	 */
	void dump_config( );

	/**
	 * @brief  dump config
	 * @param  const string& file : config to dump
	 * @return void
	 */
	void dump_config( const string& file );

	/**
	 * @brief  get_token
	 * @param  unsigned int& token, out param, a token
	 * @return int
	 */
	int get_token( unsigned int& token );

	/**
	 * @brief virtual, virtual for each token ...
	 * @param const unsigned int& token_
	 * @param const std::smatch& m
	 */
	virtual void on_token( const unsigned int& token_, const boost::smatch& m );


	/**
	 * @brief tokenize
	 * @param const string &exp, regular expression
	 * @param const string &text, search text
	 */
	void tokenize( const string &exp, const string &text );

	/**
 	* @brief build experssion
 	*/
	void build_expr( /*out*/ string& s );

	/**
     * @brief print regex expression to stdout
 	 */
	void print_expr();

	/**
     * @brief print token to stdout
 	 */
	void print_token( );


protected:
	string _config_file;
	// vector testing
	vector<terminal> _terminals;
	map<string, pair<int, string>> _token_map;
	map<string, pair<lex_state, vector<terminal>>> _terminal_map;

	vector<token> _tokens;
	// BKP ??
	//     id        name   match
	//map<int, pair<string, string>> _tokens;
	//map<string, pair<string, pair<int, string>>> _tokens;

	// current position & state : i.e. --> get_token
	std::string _scan_file;
	std::string _search_text;

	boost::regex           _rexp;
	boost::sregex_iterator _begin;
	boost::sregex_iterator _end;
	boost::sregex_iterator* _p_iter;
};

#endif
