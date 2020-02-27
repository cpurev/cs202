// TextWrapper.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include "TextWrapper.hpp"


//Code from stackoverflow
//Lambda function checking if all the characters in string is digit
//If it is then its a number
bool is_number(const std::string & s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

//Lines to tokens
bool lineToTokens(const std::string& line, std::vector<std::string>& tokens) {

	std::string str;

	for (auto l : line) {
		if (l == ' ') {
			tokens.push_back(str);
			str = "";
		}
		else
			str += l;
	}

	if (str.length() != 0)
		tokens.push_back(str);
	return true;
}

void wrap(const std::string& fileN, const int& wrapLenght) {

	//Init
	int size = 0;
	std::vector<std::string> paragraphs;
	std::string line;
	std::string temp;

	//Init file
	std::ifstream file(fileN);
	if (!file) {
		std::cout << "File error!";
		return;
	}

	//Loop for each line
	while (std::getline(file, line)) {
		if (line == "")
			paragraphs.push_back("\n");
		lineToTokens(line, paragraphs);
	}


	//Loop for every word in paragraphs
	for (auto v : paragraphs) {

		//When the next value adds exactly to wrapping value
		if (temp.length() + v.length() == wrapLenght) {
			std::cout << temp << v << std::endl;
			temp = "";
			continue;
		}

		//If the current temp and the new word adds more
		//than the warpping we print and reset
		if (temp.length() + v.length() > wrapLenght) {
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
		if (temp.size() != wrapLenght)
			temp += " ";


	}

	//when the loop is done and the wrapping not reached
	//the last value is lost
	//so we do this to print it/save it
	std::cout << temp;
}