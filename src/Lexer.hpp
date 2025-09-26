/**
 * @file    Lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 * @info    ...
 */

#ifndef _Lexer_HPP_
#define _Lexer_HPP_
#include <iostream>

/**
  * @brief class Lexer
  */
class Lexer
{
public:
	Lexer();
	Lexer( const Lexer& src );
	virtual ~Lexer();
	bool operator<( const Lexer& that );

	/**
	  * @brief
	  * @brief c++ comment ...
	  * @brief place future addtions here ...
	  *
	*/

	/**
 * @brief  load_config: load confiuration from file
 * @param  const string &path
 * @return void
 */
void Lexer::load_config( const string &path );

/**
 * @brief start tokenizing file
 * @param file
 * @return void
 */
void Lexer::start(string file);


/**
 * @brief tokenize
 * @param exp The regular expression to match
 * @param text The text to search for matches
 */
void tokenize(const string &exp, const string &text);

private:

};

#endif
