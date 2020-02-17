//main.cpp
//2020-2-4
//Chuluunbat Purev
//File reading and writing

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

int main() {

	std::ifstream inf("text.txt");

	if (!inf) {
		std::cout << "Ifstream file error";
		return 0;
	}

	int n = 0;
	std::string str = "";

	while (inf >> str) {
		std::cout << str << std::endl;
	}

	inf.close();

	std::ofstream of("text.txt", std::ios::app);

	std::cout << "The string: "; std::cin >> str;
	std::cout << "n times: "; std::cin >> n;

	while (n > 0) {
		of << str << "\n";
		--n;
	}

	of.close();

	inf.open("text.txt");

	std::cout << "After:\n";

	while (inf >> str) {
		std::cout << str << std::endl;
	}

	return 0;
}