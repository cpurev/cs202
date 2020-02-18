//simpleTokenizer.cpp
//2020-2-16
//Chuluunbat Purev
//Body of simpleTokenizer.hpp

#include "simpleTokenizer.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>

//Lines to tokens
bool lineToTokens(const std::string& line, std::vector<std::string>& tokens) {

	//Save newline as blank line
	//if (line == "") {
	//	tokens.push_back("blank line");
	//	return true;
	//}

	//Ignoring whitespaces
	//Puting all the values in line to tokens
	std::string str;

	for (auto l : line) {
		if (l == ' ') {
			tokens.push_back(str);
			str = "";
		}
		else 
			str += l;
	}

	if(str.length() != 0)
		tokens.push_back(str);
	return true;
}

//Reads line while also saving its position
bool readLine(std::istream& is, std::vector<std::string>& tokens,
				std::vector<std::pair<int, int>>& linecols) {

	//Init values
	std::string line;
	int cols, rows = 1;
	std::string str;

	//Loop for each line
	while (std::getline(is, line)) {

		//Reset column number
		cols = 1;

		//If its new line put blank space and continue;
		if (line == "" || line == "\n") {
			tokens.push_back("blank line");
			linecols.push_back(std::make_pair(rows, cols));
			++rows;
			continue;
		}

		//Iterate throught whole line character by character
		for (auto l : line) {

			//If its not white space add characters creating words which were together
			if (l != ' ') {
				str += l;

			}
			//If its white space
			else {
				//If there is a word before white space
				//Push it to tokens and save the cols and rows
				if (str.length() != 0) {
					tokens.push_back(str);
					//We minus lenght because we want to have words start position not end
					linecols.push_back(std::make_pair(rows, cols - str.length()));
				}
				//Reset the string
				str = "";
			}
			//Increase columns
			++cols;

		}

		//This is for the time when we need to save the word before the newline
		//New line skips the code above so we call this again
		if (str.length() != 0) {
			tokens.push_back(str);
			linecols.push_back(std::make_pair(rows, cols - str.length()));
		}
		//Reset string
		str = "";

		//Increase rows
		rows++;

	}

	return true;
}

//Print tokens in the given format with their corresponding column and rows
void printTokens(std::ostream& os, std::vector<std::string>& tokens, 
					std::vector<std::pair<int, int>>& linecols) {

	for (auto i = 0; i < tokens.size(); i++) {
		std::cout << std::setw(5) << "Line " << linecols[i].first << ", Column " <<
			linecols[i].second << ": \"" << tokens[i] << "\"\n";
	}

}