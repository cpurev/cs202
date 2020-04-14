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

		std::cout << chosen.getPath(i) << " ";
	}

	std::cout << std::endl;

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

	int small, erase;

	for (auto i = 0; i < l.size(); i++) {
		dist = 1e12;
		if (unchosen.size() == 1) {
			chosen.addPath(unchosen.getPath(0));
			unchosen.deletePath(0);
			break;
		}
		for (auto j = 0; j < unchosen.size(); j++) {
			if (dist > l.distance(chosen.getPath(i), unchosen.getPath(j))) {
				dist = l.distance(chosen.getPath(i), unchosen.getPath(j));
				small = unchosen.getPath(j);
				erase = j;
			}
		}

		chosen.addPath(small);
		unchosen.deletePath(erase);
	}

	//First and last city are the same
	chosen.addPath(chosen.getPath(0));

	dist = 0;

	//Calculate total distance of this path
	for (auto i = 0; i < chosen.size() - 1; i++) {

		dist += l.distance(chosen.getPath(i), chosen.getPath(i + 1));

		std::cout << chosen.getPath(i) << " ";
	}
	std::cout << chosen.getPath(chosen.size() - 1) << std::endl;

	return dist;
}

double TspSolver::solveMyWay(const CityList& l) {
	//Init distance
	double dist;

	//Init paths
	CityPath chosen;

	std::vector<double> x;
	for (auto i = 0; i < l.size(); i++) {
		x.push_back(l.node(i)->x());
	}

	std::sort(x.begin(), x.end());

	for (auto i = 0; i < x.size(); i++) {
		for (auto j = 0; j < l.size(); j++) {
			if (x[i] == l.node(j)->x()) {
				chosen.addPath(j);
				break;
			}
		}
	}

	//First and last city are the same
	chosen.addPath(chosen.getPath(0));

	dist = 0;

	//Calculate total distance of this path
	for (auto i = 0; i < chosen.size() - 1; i++) {

		dist += l.distance(chosen.getPath(i), chosen.getPath(i + 1));

		std::cout << chosen.getPath(i) << " ";
	}
	std::cout << std::endl;

	return dist;
}
