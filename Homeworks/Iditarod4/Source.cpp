//Source.cpp
//Chuluunbat Purev
//2020-4-13
//Testing path solving algortihms

#include "tspsolver.hpp"

int main(void) {

	/*CityList vm;
	vm.load("vm1748.tsp");
	CityList d15;
	d15.load("d15112.tsp");
	CityList d18;
	d18.load("d18512.tsp");
	CityList rl;
	rl.load("rl5934.tsp");*/

	CityList us;
	us.load("usa.tsp");
	TspSolver ts;
	
	//std::cout << "Random solving USA distance: " << ts.solveRandomly(us) << std::endl;

	std::cout << "Greedy solving USA distance: " << ts.solveGreedy(us) << std::endl;


	return 0;
}