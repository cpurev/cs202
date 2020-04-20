//Source.cpp
//Chuluunbat Purev
//2020-4-13
//Testing path solving algortihms

#include "tspsolver.hpp"
#include <fstream>
#include <sstream>

int main(void) {

	/*CityList vm;
	vm.load("vm1748.tsp");
	CityList d15;
	d15.load("d15112.tsp");
	CityList d18;
	d18.load("d18512.tsp");
	CityList rl;
	rl.load("rl5934.tsp");*/

	//std::ofstream outf("graph.svg");

	std::ifstream inf("graph.svg");

	if (!inf) {
		std::cout << "File error";
		return 0;
	}

	std::istringstream iss;
	std::string str;

	while (std::getline(inf, str)) {
		std::cout << str << std::endl;
		if (str == "      <!-- FROM HERE THE DATA-->")
			std::cout << inf.tellg() << std::endl;
	}


	/*CityList us;
	us.load("usa13509.tsp");
	
	for (auto i = 0; i < us.size(); i++) {
		auto node = us.node(i);


	}*/


	return 0;
}