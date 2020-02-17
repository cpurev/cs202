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

	if (line == "") {
		tokens.push_back("blank line");
		return true;
	}

	std::istringstream is(line);
	std::string str;

	do {
		is >> str;
		tokens.push_back(str);
	} while (is);

	return true;
}

bool readLine(std::istream& is, std::vector<std::string>& tokens, std::vector<std::pair<int, int>>& linecols) {

	std::string line;
	int cols, rows = 1;
	std::string str;

	while (std::getline(is, line)) {
		cols = 1;

		if (line == "" || line == "\n") {
			tokens.push_back("blank line");
			linecols.push_back(std::make_pair(rows, cols ));
		}
		for (auto l : line) {

			if (l != ' ') {
				str += l;

			}
			else {
				if (str.length() != 0) {
					tokens.push_back(str);
					linecols.push_back(std::make_pair(rows, cols- str.length()));
				}
				str = "";
			}
			++cols;

		}

		if (str.length() != 0) {
			tokens.push_back(str);
			linecols.push_back(std::make_pair(rows, cols - str.length()));
		}
		str = "";

		rows++;

	}

	return true;
}

//Print tokens in the given format with their corresponding column and rows
void printTokens(std::ostream& os, std::vector<std::string>& tokens, std::vector<std::pair<int, int>>& linecols) {

	for (auto i = 0; i < tokens.size(); i++) {
		std::cout << std::setw(5) << "Line " << linecols[i].first << ", Column " << linecols[i].second << ": \"" << tokens[i] << "\"\n";
	}

}

int main(int argc, char *argv[]) {

	StopWatch sw;

	if (argc == 1)
		return 0;

	std::ifstream file(argv[1]);

	if (!file) {
		std::cout << "File error!";
		return 0;
	}

	std::vector<std::string> tokens;
	std::vector<std::pair<int, int>> linecols;

	int n = 0;
	std::string line;
	if (argv[2] != NULL)
		line = argv[2];
	if (line == "--lineonly") {
		line = "";
		sw.Start();
		while (std::getline(file, line)) {
			lineToTokens(line, tokens);
			++n;
		}
		sw.Stop();
		std::cout << "Time it took to read" << n << " lines to tokens: " << sw.eTimeSec() << "s";
		return 1;
	}

	double d;

	sw.Start();
	readLine(file, tokens, linecols);
	sw.Stop();
	d = sw.eTimeSec();
	sw.Start();
	printTokens(std::cout, tokens, linecols);
	sw.Stop();

	std::cout << std::endl << "Time it took to read and tokenize: " << d << "s\n" << "Time it took to print: " << sw.eTimeSec() << "s\n";

	return 1;
}