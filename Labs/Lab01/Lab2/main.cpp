//main.cpp
//2020-1-23
//Chuluunbat Purev
//

#include "cats.hpp"
#include <iostream>
#include <vector>

int main() {

	std::string str = "Mittes";
	char c[] = { 'M', 'o', 'd', '\0' };

	std::vector<CAT> v{ CAT(&str[0]), CAT(c), CAT("qasd")}; 

	for (auto x : v)
		std::cout << x.getCats() << std::endl;

	return 1;
}