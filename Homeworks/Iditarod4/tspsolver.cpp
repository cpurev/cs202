//tspsolver.cpp
//Chuluunbat Purev
//2020-4-13
//definition of tspsolver.hpp

#include "tspsolver.hpp"
#include <random>

int randomInt(const int& min, const int& max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}

double TspSolver::solveRandomly(const CityList& l) {
	//Best-found distance init
	double bestD = 0;

	//Init paths
	CityPath chosen;
	CityPath unchosen;

	//Unchosen list
	for (auto i = 0; i < l.size(); i++)
		unchosen.addPath(i);

	//Random starting city
	int start = randomInt(0, l.size() - 1);
	chosen.addPath(start);

	unchosen.deletePath(start);

	while (unchosen.size() != 0) {
		start = randomInt(0, unchosen.size()-1);

		chosen.addPath(unchosen.getPath(start));

		unchosen.deletePath(start);

	}

	chosen.addPath(chosen.getPath(0));

	for (auto i = 0; i < chosen.size() - 1; i++) {

		bestD += l.distance(chosen.getPath(i), chosen.getPath(i+1));

		std::cout << chosen.getPath(i) << " ";
	}

	std::cout << std::endl;

	return bestD;
}