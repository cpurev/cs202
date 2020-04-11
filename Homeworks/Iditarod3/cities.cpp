//cities.cpp
//Chuluunbat Purev
//2020-4-9
//Cities header definition

#include "cities.hpp"
#include <fstream>
#include <iostream>
#include <string>

double CityList::distance(int first, int second) const {
	return 0;
}

void CityList::load(const std::string& str) {

	std::ifstream input(str);

	if (!input) {
		std::cout << "File error";
		return;
	}

	std::string a;
	while (std::getline(input, a)) {
		std::cout << a << std::endl;
	}
}