//Source.cpp
//2020-4-3
//Chuluunbat Purev
//main for cities header

#include "cities.hpp"
#include <exception>

int main(void) {

	CityList cl;
	cl.load("vm1748.tsp");
	cl.print();


	std::cout << "Distance from node 1 to 2" << std::endl;
	std::cout << cl.distance(1, 2);

	return 0;
}