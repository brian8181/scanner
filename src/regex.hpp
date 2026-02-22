/**
 * @file    regex.hpp
 * @version 0.0.1
 * @date    Fri, 26 Sep 2025 17:05:10 +0000
 */
#ifndef _regex_HPP_
#define _regex_HPP_

const string VALID_SYMBOL_CHARS   = "[A-Za-z0-9_]"; /** @note_to_self: ~~> \w == [A-Za-z0-9_] **/
const string VALID_CHARS          = "[ [:punct:][:alnum:]]"; // [:punct:] = !"#$%&'()*+,-./:;<=>?@[\]^_{|}~`
const string VALID_FILE_CHARS     = "[A-Za-z0-9_. ]";
const string TOKEN_TYPE           = "[A-Za-z][A-Za-z_]*((::)[A-Za-z_]*)?";
const string TOKEN_TYPE_           = "[A-Za-z][A-Za-z_]*";
//*deprecated* const string CONFIG_PAIR          = "\\s*(?<type>" + TOKEN_TYPE_ + ")\\s+(?<name>[A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*(?<rexp>" + VALID_CHARS + "*)\\s*";
const string CONFIG_PAIR          = "\\s*(?<type>" + TOKEN_TYPE_ + ")\\s+(?<name>[A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*(?<rexp>" + VALID_CHARS + R"(*)\s*(?<test>".*")\s*)";
const string CONFIG_STATES        = R"((?<states>^\s*(?<state>[A-Za-z][A-Za-z0-9_]*)\s*=\s*\s*\{(?<tokens>[A-Za-z][A-Za-z0-9_]*(, [A-Za-z][A-Za-z0-9_]*)*)\}\s*\s*$))";
//const string CONFIG_PAIR          = "\\s*(" + TOKEN_TYPE_ + ")\\s+([A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*(" + VALID_CHARS + "*)\\s*";
const string CONFIG_PAIR_VAR      = "\\s*\\s*([A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*=\\s*($[A-Za-z]" + VALID_SYMBOL_CHARS + "*)\\s*";
const string CONFIG_SECTION       = R"(\s*\[(?<section>[a-zA-Z][a-zA-Z0-9]*)\]\s*)";
const string CONFIG_SECTIONS      = R"(^\s*\[\s*(?<tokens>tokens)|(?<groups>groups)|(?<states>states)\s*\]\s*$)";
const string CONFIG_COMMENT       = "^\\s*#.*$";
const string CONFIG               = "(?<pairs>" + CONFIG_PAIR + ")|(?<comments>" + CONFIG_COMMENT + ")";

#endif
