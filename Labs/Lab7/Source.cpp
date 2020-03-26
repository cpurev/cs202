//Source.cpp
//Chuluunbat Purev
//2020-3-26
//Testing custom Colour class

#include "Colours.hpp"

int main() {

	const Colours cl;
	std::cout << cl << std::endl;

	Colours cl1;
	cl1.rgba(128, 128, 128, 1);
	std::cout << cl1 << std::endl;

	cl1 = cl;
	std::cout << cl1 << std::endl;

	return 1;
}