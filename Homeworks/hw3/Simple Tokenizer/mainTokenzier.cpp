//mainTokenizer.cpp
//Chuluunbat Purev
//2020-2-15
//Simple Tokenzier from text file

#include <string>
#include <iostream>
#include "stopWatch.hpp"
#include "simpleTokenizer.hpp"

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