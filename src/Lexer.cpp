
/**
 * @file    Lexer.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 * @info    ...
 */
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <regex>
#include "constants.hpp"
#include "fileio.hpp"
#include "Lexer.hpp"

// using std::string;
// using std::vector;
// using std::map;
// using std::pair;

using namespace std;

Lexer::Lexer()
{

}

Lexer::Lexer( const Lexer& src )
{

}

Lexer::~Lexer()
{

}

/**
 * @brief  load_config: load confiuration from file
 * @param  const string &path
 * @return void
 */
void Lexer::load_config( const string &path )
{
    const unsigned int ID_NAME_VALUE_PAIR = 0;
    const unsigned int ID_NAME = 1;
    const unsigned int ID_VALUE = 2;
    const unsigned int ID_NUMERIC_LITERAL = 2;
    const unsigned int ID_STRING_LITERAL = 3;

    // get configuration file by lines
    vector<string> lines;
    lines = read_lines(path, lines);
    // create one only section (global)
    string section_name = "global";
    map<string, string> section_map;
    pair<string, map<string, string>> sp(section_name, section_map);
    map_sections_config.insert(sp);

    int len = lines.size();
    for (int i = 0; i < len; ++i)
    {
        string line = lines[i];
        regex rgx = regex(CONFIG_PAIR);
        smatch match;
        regex_match(line, match, rgx);

        if (match[ID_NAME_VALUE_PAIR].matched)
        {
            // get name
            string symbol_name = match[ID_NAME].str();
            // get value
            string value = (match[ID_VALUE].matched) ? match[ID_NUMERIC_LITERAL].str() : match[ID_STRING_LITERAL].str();
            // create pair
            pair<string, string> p(symbol_name, value);
            map_sections_config[section_name].insert(p);
        }
    }
}

/**
 * @brief start tokenizing file
 * @param file
 * @return void
 */
void Lexer::start(string file)
{
    cout << "Starting lexical analysis on file: " << file << endl;
    stringstream sstrm;
    ifstream strm(file, ios::in);
    if (strm.is_open())
    {
        cout << file << "-> opened ..." << endl;
        char c;
        while (strm.get(c))
        {
            sstrm << c;
        }
    }
    else
    {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    _search_text = sstrm.str();
    unsigned int token = ID_UNDEFINED;
    _rexp = regex(EVERYTHING, regex::ECMAScript);
    _begin = sregex_iterator(_search_text.begin(), _search_text.end(), _rexp);
    _p_iter = &_begin;

    while(get_token(token));
}

/**
 * @brief
 * @param iter
 * @param id
 * @return
 */
int Lexer::get_token(unsigned int& token)
{
    static int count = 0;
    if(*_p_iter != _end)
    {
        ++(*_p_iter);
        std::smatch m = *(*_p_iter);
        if( _token_map.contains(m.str()) )
        {
            int token = _token_map[m.str()].first;
            string name = _token_map[m.str()].second;
            cout << "{\n\ttoken: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str() << "'\n\tpos: " << m.position(0) << "\n\tcount: " << ++count << "\n};" << endl;
        }
        else
        {
            cout << "{\n\ttoken: null" << "\n\ttoken: '" << m.str() << "'\n\tpos: " << m.position(0) << "\n\tcount: " << ++count << "\n};" << endl;
        }
        return 1;
    }
    return 0;
}

/**
 * @brief tokenize
 * @param exp The regular expression to match
 * @param text The text to search for matches
 */
void Lexer::tokenize(const string &exp, const string &text)
{
    int count = 0;
    regex rexp = regex(exp, regex::ECMAScript);
    sregex_iterator begin = sregex_iterator(text.begin(), text.end(), rexp);
    //sregex_iterator end = sregex_iterator();
    sregex_iterator end;
    for (std::sregex_iterator iter = begin; iter != end; ++iter)
    {
        std::smatch m = *iter;
        if( _token_map.contains(m.str()) )
        {
            int token = _token_map[m.str()].first;
            string name = _token_map[m.str()].second;
            cout << "{\n\ttoken: " << token << "\n\tname: " << name << "\n\ttoken: '" << m.str() << "'\n\tpos: " << m.position(0) << "\n\tcount: " << ++count << "\n};" << endl;
        }
        else
        {
            cout << "{\n\ttoken: null" << "\n\ttoken: '" << m.str() << "'\n\tpos: " << m.position(0) << "\n\tcount: " << ++count << "\n};" << endl;
        }
    }
}
