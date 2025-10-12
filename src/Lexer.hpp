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
#include <regex>

using std::string;
using std::vector;
using std::map;
using std::pair;
using std::regex;

/**
  * @brief class Lexer
  */
class Lexer
{
public:
	Lexer();
	Lexer( const Lexer& src );
	virtual ~Lexer();

	/**
	 * @brief initialize state
	 */
	bool init(const string& file);

	/**
	 * @brief  load_config: load confiuration from file
	 * @param  const string &path
	 * @return void
	 */
	void load_config( const string &path );

	/**
	 * @brief dump current config
	 * @return void
	 */
	void dump_config( );

	/**
	 * @brief dump config
	 * @param const string& file : config to dump
	 * @return void
	 */
	void dump_config( const string& file );

	/**
	 * @brief start tokenizing file
	 * @param file
	 * @return void
	 */
	void start( string file );

	/**
	 * @brief
	 * @param iter
	 * @param id
	 * @return
	 */
	int get_token( unsigned int& token );


	/**
	 * @brief tokenize
	 * @param exp : regular expression
	 * @param text : search text
	 */
	void tokenize( const string &exp, const string &text );

private:
	map<string, string> map_config;
	// todo : revert to no configuration sections!
	map<string, map<string, string>> map_sections_config;
	map<string, string> map_vars;
	map<string, string> map_const;
	map<string, vector<string>> map_arrays;
	map<string, pair<string, vector<string>>> map_objects;

	// current position & state : i.e. --> get_token
	std::string _search_text;
	std::regex _rexp;
	std::sregex_iterator _begin;
	std::sregex_iterator _end;
	std::sregex_iterator* _p_iter;
	map<string, pair<string, pair<int, string>>> _tokens;
};

#endif
