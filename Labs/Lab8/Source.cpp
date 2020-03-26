//Source.cpp
//Chuluunbat Purev
//2020-3-26
//Complex numbers testing

#include "complex.hpp"

int main() {

	std::cout << Complex() << std::endl;
	std::cout << Complex(55.55) << std::endl;
	std::cout << Complex(23.4, 1.65) << std::endl;

	std::cout << Complex(1, 1) + Complex(1, 2) << std::endl;
	std::cout << 3 + Complex(1, 2) << std::endl;
	std::cout << Complex(7, 2) + 3<< std::endl;


	return 1;
}