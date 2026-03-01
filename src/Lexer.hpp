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
#include <sstream>
#include "pparser.tab.hh"
#include <regex>
#include <boost/regex.hpp>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::pair;
using std::regex;
using std::stringstream;
using yy::parser;

/* LEX TYPES */
#define right_assoc 0x8
#define left_assoc  0x20
#define non_assoc   0x40
#define start       0x1;

#define INT 1
#define FLOAT 2

/*
 /// Symbol kinds.
struct symbol_kind
{
	enum symbol_kind_type
	{
	YYNTOKENS = 28, ///< Number of tokens.
	S_YYEMPTY = -2,
	S_YYEOF = 0,                             // "end of input"
	S_YYerror = 1,                           // error
	S_YYUNDEF = 2,                           // "invalid token"
	S_NUMBER = 3,                            // NUMBER
	S_DOLLAR_SIGN = 4,                       // DOLLAR_SIGN
	S_DOT = 5,                               // DOT
	S_INDIRECT_MEMBER = 6,                   // INDIRECT_MEMBER
	S_COMMA = 7,                             // COMMA
	S_EQUAL = 8,                             // EQUAL
	S_STRING_LITERAL = 9,                    // STRING_LITERAL
	S_NUMERIC_LITERAL = 10,                  // NUMERIC_LITERAL
	S_ID = 11,                               // ID
	S_CONST_ID = 12,                         // CONST_ID
	S_LBRACE = 13,                           // LBRACE
	S_RBRACE = 14,                           // RBRACE
	S_LBRACKET = 15,                         // LBRACKET
	S_RBRACKET = 16,                         // RBRACKET
	S_LPAREN = 17,                           // LPAREN
	S_RPAREN = 18,                           // RPAREN
	S_CONFIG_LOAD = 19,                      // CONFIG_LOAD
	S_INCLUDE = 20,                          // INCLUDE
	S_REQUIRE = 21,                          // REQUIRE
	S_INSERT = 22,                           // INSERT
	S_ASSIGN = 23,                           // ASSIGN
	S_VAR_ATTRIB = 24,                       // VAR_ATTRIB
	S_VALUE_ATTRIB = 25,                     // VALUE_ATTRIB
	S_FILE_ATTRIB = 26,                      // FILE_ATTRIB
	S_FILE_NAME = 27,                        // FILE_NAME
	S_YYACCEPT = 28,                         // $accept
	// S_complier = 29,                         // complier
	// S_files = 30,                            // files
	// S_file = 31,                             // file
	// S_blocks = 32,                           // blocks
	// S_block = 33,                            // block
	// S_qualafied_id = 34,                     // qualafied_id
	// S_sub_proc = 35,                         // sub_proc
	// S_array = 36,                            // array
	// S_params = 37,                           // params
	// S_symbol = 38,                           // symbol
	// S_built_in = 39,                         // built_in
	// S_attributes = 40,                       // attributes
	// S_attrib = 41                            // attrib
	};
};

// basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_attrib: // attrib
        value.copy< std::pair< std::string, std::string > > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DOLLAR_SIGN: // DOLLAR_SIGN
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_INDIRECT_MEMBER: // INDIRECT_MEMBER
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_NUMERIC_LITERAL: // NUMERIC_LITERAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_CONST_ID: // CONST_ID
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LPAREN: // LPAREN
      case symbol_kind::S_RPAREN: // RPAREN
      case symbol_kind::S_CONFIG_LOAD: // CONFIG_LOAD
      case symbol_kind::S_INCLUDE: // INCLUDE
      case symbol_kind::S_REQUIRE: // REQUIRE
      case symbol_kind::S_INSERT: // INSERT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_VAR_ATTRIB: // VAR_ATTRIB
      case symbol_kind::S_VALUE_ATTRIB: // VALUE_ATTRIB
      case symbol_kind::S_FILE_ATTRIB: // FILE_ATTRIB
      case symbol_kind::S_FILE_NAME: // FILE_NAME
      case symbol_kind::S_qualafied_id: // qualafied_id
      case symbol_kind::S_sub_proc: // sub_proc
      case symbol_kind::S_array: // array
      case symbol_kind::S_symbol: // symbol
      case symbol_kind::S_built_in: // built_in
      case symbol_kind::S_attributes: // attributes
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

struct symbol_type : basic_symbol<by_kind>
{
	// superclass
	typedef basic_symbol<by_kind> super_type;

	symbol_type () YY_NOEXCEPT {}

	// valueless symbols, and symbols from each type
	symbol_type (int tok) : super_type (token_kind_type (tok))
	{
	}

	symbol_type (int tok, const int& v)	: super_type (token_kind_type (tok), v)
	{
	}

	symbol_type (int tok, const std::string& v)	: super_type (token_kind_type (tok), v)
	{
	}
};

*/

// namespace bkp
// {
//vector<pair<string,int>> str_to_int { { "INT", 1}, {"FLOAT", 2} };
typedef struct token_t {
	unsigned long id;
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
	unsigned long id;
	string name;
	string stype;
	int itype;
	int lex_t;
	string rexp;
	string test_value;
	unsigned long index;
	string value;
	parser::symbol_type type;
	// operator yy::parser::symbol_type()
	// {
	// 	return new yy::parser::symbol_type;
	// }
} token_def;

typedef token_def token;

typedef struct token_match
{
	unsigned long id;
	int pos;
	int line;
	string value;
	token_def token;
} token_match;

typedef struct state_t
{
	unsigned long id;
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
	Lexer(const string& file, const string &config_file, yy::parser* pp );

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
	bool init( const string& file, const string &config_file, yy::parser* pp );

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
	yy::parser::symbol_type get_token();

	/**
	 * @brief reset to initial state
	 */
	void reset();

	/**
	 * @brief on_token, for each token ...
	 * @param state
	 * @param token
	 */
	parser::symbol_type on_token( const state_t& state, const token_def& token );
	/**
	 * @brief on_token_action, for each token ...
	 * @param state
	 * @param token
	 */
	parser::symbol_type on_token_action( const state_t& state, const token_def &token );
	/**
	 * @brief on_state, on_token, for each token ...
	 * @param state
	 */
	unsigned long on_state(const state_t &s);

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

	state_t* get_state() const;

	void set_state(const state_t& s) const;

protected:
	parser*                       _pparser;
	string                        _config_file;
	vector<token_def>             _tokens;
	vector<state_t*>              _states;
	map<int, token_def*>          _idx_tab;  // idx -> token_def
	map<int, token_def*>          _id_tab;   // id -> token_def
	map<string, token_def*>       _name_tab; // name -> token_def
	map<int, vector<token_def*>>  _state_tokens_tab;
	map<int, state_t*>            _state_tab;
	vector<token_def*>            _matches;
	std::string                   _scan_file;
	std::string                   _search_text;
	boost::regex                  _rexp;
	boost::sregex_iterator        _begin;
	boost::sregex_iterator        _end;
	boost::sregex_iterator*       _p_iter;
	state_t*                      _state;
	string                        _expr;
	stringstream                  _sout;
};

//}

#endif
