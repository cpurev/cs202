//Source.cpp
//2020-4-3
//Chuluunbat Purev
//main for cities header

#include "cities.hpp"

int main(void) {

	CityList cl;
	cl.load("d18512.tsp");

	cl.print();

	return 0;
}