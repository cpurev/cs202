//mainTokenizer.cpp
//Chuluunbat Purev
//2020-2-15
//Simple Tokenzier from text file

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "stopWatch.hpp"

//Lines to tokens
bool lineToTokens(const std::string& line, std::vector<std::string>& tokens) {

	//Save newline as blank line
	if (line == "") {
		tokens.push_back("blank line");
		return true;
	}

	//Ignoring whitespaces
	//Puting all the values in line to tokens
	std::istringstream is(line);
	std::string str;

	do {
		is >> str;
		tokens.push_back(str);
	} while (is);

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
			linecols.push_back(std::make_pair(rows, cols ));
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
					linecols.push_back(std::make_pair(rows, cols- str.length()));
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
void printTokens(std::ostream& os, std::vector<std::string>& tokens, std::vector<std::pair<int, int>>& linecols) {

	for (auto i = 0; i < tokens.size(); i++) {
		std::cout << std::setw(5) << "Line " << linecols[i].first << ", Column " << 
					linecols[i].second << ": \"" << tokens[i] << "\"\n";
	}

}

int main(int argc, char* argv[]) {

	StopWatch sw;

	//If there is no arguments end;
	if (argc == 1)
		return 0;

	std::ifstream file(argv[1]);

	//Check file existance
	if (!file) {
		std::cout << "File error!";
		return 0;
	}

	std::vector<std::string> tokens;
	std::vector<std::pair<int, int>> linecols;

	//Line number counter
	int n = 0;

	//Line saver which is also used for the command argument
	//container so we can check in the if statement
	//If there is no 2nd argument we go to notLineOnly
	std::string line;
	if (argv[2] != NULL)
		line = argv[2];
	else
		goto notLineOnly;

	//If the second argument is invalid we end the program
	if (line == "--lineonly") {
		line = "";
		sw.Start();
		while (std::getline(file, line)) {
			lineToTokens(line, tokens);
			++n;
		}
		sw.Stop();
		std::cout << "Time it took to read " << n << " lines to tokens: " << sw.eTimeSec() << "s";
		return 1;
	}
	else
		return 0;

	//Time saver
	double d;

	//I put it in block so i can call goto on this
notLineOnly:{
	sw.Start();
	readLine(file, tokens, linecols);
	sw.Stop();
	d = sw.eTimeSec();
	sw.Start();
	printTokens(std::cout, tokens, linecols);
	sw.Stop();

	std::cout << std::endl << "Time it took to read and tokenize: " << d << "s\n" << "Time it took to print: " << sw.eTimeSec() << "s\n";
}
	return 1;
}