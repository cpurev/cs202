//main.cpp
//2020-2-2
//Chuluunbat Purev
//Cave exploring

#include "cave.hpp"
#include <fstream>

int main() {

	Cave cav;

	//std::ofstream of("cave.txt", std::ofstream::out);



	std::ifstream file;
	file.open("cave.txt");

	if (!file.is_open()) {
		std::cout << "Error file";
		return 0;
	}

	cav.connect(1, 2);


	return 1;
}