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

	//Randomly connect cities
	while (unchosen.size() != 0) {
		start = randomInt(0, unchosen.size()-1);

		chosen.addPath(unchosen.getPath(start));

		unchosen.deletePath(start);

	}

	//First and last city are the same
	chosen.addPath(chosen.getPath(0));

	//Calculate total distance of this path
	for (auto i = 0; i < chosen.size() - 1; i++) {

		bestD += l.distance(chosen.getPath(i), chosen.getPath(i+1));

		//std::cout << chosen.getPath(i) << " ";
	}

	//std::cout << std::endl;

	return bestD;
}

double TspSolver::solveGreedy(const CityList& l) {
	//Init distance
	double dist;

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

	for (auto i = 0; i < l.size() - 1; i++) {
		dist = 0;
		for (auto j = 0; j < unchosen.size(); j++) {
			if (dist < l.distance(chosen.getPath(i), unchosen.getPath(j))) {
				dist = l.distance(chosen.getPath(i), unchosen.getPath(j));
				chosen.addPath(j);
				unchosen.deletePath(j);
			}
		}
	}

	dist = 0;

	//Calculate total distance of this path
	for (auto i = 0; i < chosen.size() - 1; i++) {

		dist += l.distance(chosen.getPath(i), chosen.getPath(i + 1));

		//std::cout << chosen.getPath(i) << " ";
	}

	return dist;
}