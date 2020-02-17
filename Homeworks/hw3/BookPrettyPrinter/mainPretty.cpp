//mainPretty.cpp
//2020-2-16
//Chuluunbat Purev
//Pretty Format books

#include "simpleTokenizer.hpp"
#include <iostream>

int main(int argc, char* argv[]) {

	std::vector<std::string> paragraphs;
	std::string line;

	std::ifstream file("test.txt");

	if (!file) {
		std::cout << "File error!";
		return 0;
	}

	lineToTokens(line, paragraphs);

	return 1;
}