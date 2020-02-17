//mainTokenizer.cpp
//Chuluunbat Purev
//2020-2-15
//Simple Tokenzier from text file

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

//Lines to tokens
//Wont use this function so i left it
bool lineToTokens(const std::string& line, std::vector<std::string>& tokens) {

	//if (line == "") {
	//	tokens.push_back("blank line");
	//	return true;
	//}



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

	return false;
}

//Print tokens in the given format with their corresponding column and rows
void printTokens(std::ostream& os, std::vector<std::string>& tokens, std::vector<std::pair<int, int>>& linecols) {

	for (auto i = 0; i < tokens.size(); i++) {
		std::cout << "Line " << linecols[i].first << ", Column " << linecols[i].second << ": \"" << tokens[i] << "\"\n";
	}

}

int main(int argc, char *argv[]) {

	/*std::ifstream file("test.txt");

	if (!file) {
		std::cout << "File error!";
		return 0;
	}
	std::vector<std::string> tokens; 
	std::vector<std::pair<int, int>> linecols;


	readLine(file, tokens, linecols);

	printTokens(std::cout, tokens, linecols);*/

	for (auto i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}

	return 1;
}