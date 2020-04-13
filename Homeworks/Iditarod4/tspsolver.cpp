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
	CityPath chosen(l.size());
	CityPath unchosen(l.size());

	//Unchosen list
	for (auto i = 0; i < l.size(); i++)
		unchosen.addNode(l.node(i));

	//Random starting city
	int start = randomInt(0, l.size() - 1);
	chosen.addNode(l.node(start));
	
	unchosen.deleteNode(start);

	while (unchosen.size() != 0) {
		start = randomInt(0, unchosen.size() - 1);

		chosen.addNode(l.node(start));

		unchosen.deleteNode(start);

	}

	std::cout << std::endl;
	
	for (auto i = 0; i < chosen.size() - 1; i++) {

		bestD += l.distance(i, i++);

		//std::cout << l.distance(i, i++) << " ";
	}

	std::cout << std::endl;
	return bestD;
}