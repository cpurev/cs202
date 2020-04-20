//Source.cpp
//Chuluunbat Purev
//2020-4-13
//Testing path solving algortihms

#include "tspsolver.hpp"
#include <fstream>

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
	us.load("usa13509.tsp");

	std::ifstream inf("graph.svg");
	if (!inf) {
		std::cout << "File error";
		return 0;
	}

	std::string str = "", line;
	while (std::getline(inf, line)) {
		str += line;
		str += "\n";
	}
	inf.close();


	std::ofstream outf("graph.svg");

	outf.write(str.c_str(), str.size());

	outf.close();

	return 0;
}