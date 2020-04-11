//Source.cpp
//2020-4-3
//Chuluunbat Purev
//main for cities header

#include "cities.hpp"
#include <exception>

int main(void) {

	CityList vm;
	vm.load("vm1748.tsp");
	CityList d15;
	d15.load("d15112.tsp");
	CityList d18;
	d18.load("d18512.tsp");
	CityList rl;
	rl.load("rl5934.tsp");
	CityList us;
	us.load("usa13509.tsp");


	vm.print();

	std::cout << "Distance from node 1 to 2" << std::endl;
	std::cout << vm.distance(1, 2);

	return 0;
}