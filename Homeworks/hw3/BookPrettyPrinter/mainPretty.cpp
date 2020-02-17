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

	int wrap = 0;
	int size = 0;

	//Exit if no arguments
	if (argc == 1)
		return 0;

	std::vector<std::string> paragraphs;
	std::string line;
	std::string arg;
	std::string temp;

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

	std::string str;

	while (std::getline(file, line)) {
		if (line == "")
			paragraphs.push_back("\n");
		lineToTokens(line, paragraphs);
	}

	if (line == "--html")
		goto html;
	if (is_number(arg))
		goto wrapping;
	return 1;

wrapping: {
	wrap = std::stoi(arg);
	for (auto v : paragraphs) {
		if (temp.length() + v.length() >= wrap) {
			std::cout << temp << std::endl;
			temp = v + " ";
			continue;
		}

		temp += v;
		
		if (temp.size() != wrap)
			temp += " ";


	}
	std::cout << temp;
	return 1;
}
html: {
	
}
	return 1;
}