//mainTokenizer.cpp
//Chuluunbat Purev
//2020-2-15
//Simple Tokenzier from text file

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {

	std::ifstream file("test.txt");

	if (!file) {
		std::cout << "File error!";
		return 0;
	}

	return 1;
}