//mainPretty.cpp
//2020-2-16
//Chuluunbat Purev
//Pretty Format books

#include "simpleTokenizer.hpp"
#include <iostream>
#include <string>
#include <algorithm>

//Code from stackoverflow
//Lambda function checking if all the characters in string is digit
//If it is then its a number
bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int main(int argc, char* argv[]) {


	//Exit if no arguments
	if (argc == 1)
		return 0;

	//Init
	int wrap = 0;
	int size = 0;
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

	//Never given what to do without second argument
	if(argv[2] != NULL)
		arg = argv[2];
	else {
		std::cout << "TO DO WHAT?";
		return 0;
	}

	//Loop for each line
	while (std::getline(file, line)) {
		if (line == "")
			paragraphs.push_back("\n");
		lineToTokens(line, paragraphs);
	}

	//goto matched blocks
	if (line == "--html")
		goto html;
	if (is_number(arg))
		goto wrapping;
	return 1;

	//Wrap texts into given value
wrapping: {
	wrap = std::stoi(arg);

	//Loop for every word in paragraphs
	for (auto v : paragraphs) {

		//If the current temp and the new word adds more
		//than the warpping we print and reset
		if (temp.length() + v.length() >= wrap) {
			std::cout << temp << std::endl;
			
			//Save the current word to temp
			temp = v + " ";
			continue;
		}

		//If wrapping limit not reached 
		//Keep adding to temp
		temp += v;
		
		//For occasions when its exactly at the wrapped value
		//So new line will go in instead of whitespace
		if (temp.size() != wrap)
			temp += " ";


	}

	//when the loop is done and the wrapping not reached
	//the last value is lost
	//so we do this to print it/ save it
	std::cout << temp;
	return 1;
}
html: {
	
}
	return 1;
}