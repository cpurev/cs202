//simpleTokenizer.hpp
//Chuluunbat Purev
//2020-2-16
//Read from stream and tokenize it to vector

#include <fstream>
#include <vector>

#ifndef SIMPLE_TOKEN_HPP
#define SIMPLE_TOKEN_HPP

//Read from stream and put it in to tokens
//tokens and linecols correspond with each other with
//the same elemnt numbers
//ex: tokens[1] = n
//	  linecols[1] = (1, 2) this is n values position
bool readLine(std::istream& is, std::vector<std::string>& tokens,
					std::vector<std::pair<int, int>>& linecols);

//Read whole line to tokens
//Ignores whitespaces
bool lineToTokens(const std::string& line, std::vector<std::string>& tokens);

//Print tokens in
//Line x, Column y: "z" format
void printTokens(std::ostream& os, std::vector<std::string>& tokens,
					std::vector<std::pair<int, int>>& linecols);

#endif // !SIMPLE_TOKEN_HPP
