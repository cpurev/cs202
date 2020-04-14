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

	int small;

	for (auto i = 0; i < l.size() - 1; i++) {
		dist = 1e12;
		for (auto j = 0; j < unchosen.size(); j++) {
			if (dist > l.distance(chosen.getPath(i), unchosen.getPath(j))) {
				dist = l.distance(chosen.getPath(i), unchosen.getPath(j));
				small = j;
			}
		}
		chosen.addPath(small);
		unchosen.deletePath(small);
	}

	//First and last city are the same
	chosen.addPath(chosen.getPath(0));

	dist = 0;

	//Calculate total distance of this path
	for (auto i = 0; i < chosen.size() - 1; i++) {

		dist += l.distance(chosen.getPath(i), chosen.getPath(i + 1));

		//std::cout << chosen.getPath(i) << " ";
	}

	return dist;
}

double TspSolver::solveMyWay(const CityList& l) {
	//Init distance
	double dist;

	std::vector<double> x, y;
	for (auto i = 0; i < l.size(); i++) {
		x.push_back(l.node(i)->x());
		y.push_back(l.node(i)->y());
	}

	std::sort(x.begin(), x.end());
	std::sort(y.begin(), y.end());

	//First and last city are the same
	x.push_back(x[0]);
	y.push_back(y[0]);

	dist = 0;

	//Calculate total distance of this path
	for (auto i = 0; i < l.size() - 1; i++) {

		dist += eucD(x[i + 1], x[i], y[i + 1], y[i]);

		//std::cout << chosen.getPath(i) << " ";
	}

	return dist;
}

double TspSolver::eucD(double x1, double x2, double y1, double y2) {
	return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}