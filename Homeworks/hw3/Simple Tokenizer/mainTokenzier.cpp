//mainTokenizer.cpp
//Chuluunbat Purev
//2020-2-15
//Simple Tokenzier from text file

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

bool lineToTokens(const std::string& line, std::vector<std::string>& tokens) {

	if (line == "") {
		tokens.push_back("blank line");
		return true;
	}

	std::istringstream iss(line);

	do {
		std::string str;
		iss >> str;
		tokens.push_back(str);
	} while (iss);

	return true;
}

bool readLine(std::istream& is, std::vector<std::string>& tokens, std::vector<std::pair<int, int>>& linecols) {

	std::string line;
	int cols= 0, rows = 0;

	while (std::getline(is, line)) {
		cols = tokens.size();

		lineToTokens(line, tokens);

		cols = tokens.size() - cols;

		++rows;

		linecols.push_back(std::make_pair(rows, cols));
	}

	return false;
}

void printTokens(std::ostream& os, std::vector<std::string>& tokens, std::vector<std::pair<int, int>>& linecols) {

	for (auto v : linecols) {
		for (auto i = 1; i <= v.second; i++) {
			std::cout << "Line " << v.first << ", Column " << i << ": \"" << tokens[v.first * i] << "\"\n";
		}
	}
}

int main(int argc, char *argv[]) {

	std::ifstream file("test.txt");

	if (!file) {
		std::cout << "File error!";
		return 0;
	}
	std::vector<std::string> tokens; 
	std::vector<std::pair<int, int>> linecols;

	//tokens.push_back("asd");

	//std::cout << tokens.size();

	readLine(file, tokens, linecols);

	printTokens(std::cout, tokens, linecols);

	return 1;
}