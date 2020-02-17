//mainPretty.cpp
//2020-2-16
//Chuluunbat Purev
//Pretty Format books

#include "simpleTokenizer.hpp"
#include <iostream>
#include <string>
#include <algorithm>

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int main(int argc, char* argv[]) {

	//Exit if no arguments
	if (argc == 1)
		return 0;

	std::vector<std::string> paragraphs;
	std::string line;
	std::string arg;

	//Init file
	std::ifstream file("test.txt");
	if (!file) {
		std::cout << "File error!";
		return 0;
	}

	if(argv[2] != NULL)
		arg = argv[2];
	else {
		std::cout << "TO DO WHAT?";
		return 0;
	}

	while (std::getline(file, line)) {
		lineToTokens(line, paragraphs);
	}

	if (line == "--html")
		goto html;
	if (is_number(arg))
			goto wrapping;

	int wrap;
wrapping: {
	wrap = std::stoi(arg);
	for (auto i = 0; i < paragraphs.size(); i++) {
		wrap = paragraphs[i].length() + 1;
		if (wrap >= 40) {
			i--;
			continue;
		}
		std::cout << paragraphs[i] << " ";
	}
}
html: {
	
}
	return 1;
}