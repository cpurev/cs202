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

double TspSolver::solveRandomly(CityList& l) {
	//Best-found distance init
	double bestD = 0;

	//Init paths
	CityPath chosen;
	CityPath unchosen;

	//Init temp list
	CityList temp;

	//Unchosen list
	for (auto i = 0; i < l.size(); i++)
		unchosen.addPath(i);

	//Random starting city
	int start = randomInt(0, l.size() - 1);

	//Put randomly chosen city to list
	//And delete it from unchosen
	chosen.addPath(start);
	unchosen.deletePath(start);

	//Randomly connect cities
	while (unchosen.size() != 0) {
		//Random city which cannot repeat since
		//It gets deleted away from unchosen
		start = randomInt(0, unchosen.size() - 1);

		chosen.addPath(unchosen.getPath(start));
		unchosen.deletePath(start);

	}

	//First and last city are the same
	chosen.addPath(chosen.getPath(0));

	//Calculate total distance of this path
	for (auto i = 0; i < chosen.size() - 1; i++) {

		bestD += l.distance(chosen.getPath(i), chosen.getPath(i + 1));

		temp.addNode(l.node(chosen.getPath(i)));	

	}

	temp.addNode(l.node(chosen.getPath(chosen.size() - 1)));
	l = temp;

	return bestD;
}

double TspSolver::solveGreedy(CityList& l) {
	//Init distance
	double dist;

	//Init paths
	CityPath chosen;
	CityPath unchosen;

	//Init list
	CityList temp;

	//Unchosen list
	for (auto i = 0; i < l.size(); i++)
		unchosen.addPath(i);

	//Random starting city
	int start = randomInt(0, l.size() - 1);

	//Put randomly chosen city to list
	//And delete it from unchosen
	chosen.addPath(start);
	unchosen.deletePath(start);

	//Temp variables
	int small, erase;

	//Loop for N times or the total amount of nodes
	for (auto i = 0; i < l.size(); i++) {
		//We are finding the minimum so it can be whatever max number
		//That will not be reached
		dist = 1e12;

		//If only 1 city is left then break
		if (unchosen.size() == 1) {
			chosen.addPath(unchosen.getPath(0));
			unchosen.deletePath(0);
			break;
		}

		//i is the last city we chose
		//we repeated the amount of unchosen cities
		//to find its closest city
		for (auto j = 0; j < unchosen.size(); j++) {
			if (dist > l.distance(chosen.getPath(i), unchosen.getPath(j))) {
				dist = l.distance(chosen.getPath(i), unchosen.getPath(j));

				//This is the closest city 
				small = unchosen.getPath(j);

				//This is the index to delete the found city not the city
				erase = j;
			}
		}

		chosen.addPath(small);
		unchosen.deletePath(erase);
	}

	//First and last city are the same
	chosen.addPath(chosen.getPath(0));

	//Reset dist
	//Keeping variables minimum and effiecent
	dist = 0;

	//Calculate total distance of this path
	for (auto i = 0; i < chosen.size() - 1; i++) {

		dist += l.distance(chosen.getPath(i), chosen.getPath(i + 1));

		temp.addNode(l.node(chosen.getPath(i)));
		//std::cout << chosen.getPath(i) << " ";
	}

	temp.addNode(l.node(chosen.getPath(chosen.size() - 1)));
	l = temp;

	return dist;
}

double TspSolver::solveMyWay(CityList& l) {
	//Init distance
	double dist;

	//Init paths
	CityPath chosen;

	//Init list
	CityList temp;

	//Vector of x coordinates of the node
	std::vector<double> x;
	for (auto i = 0; i < l.size(); i++) {
		x.push_back(l.node(i)->y());
	}

	//Sort them
	std::sort(x.begin(), x.end());

	//This loop is to find what are the sorted x
	//values nodes are.
	//And then put them in chosen citypath
	for (auto i = 0; i < x.size(); i++) {
		for (auto j = 0; j < l.size(); j++) {
			if (x[i] == l.node(j)->y()) {
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

		temp.addNode(l.node(chosen.getPath(i)));

		//std::cout << chosen.getPath(i) << " ";
	}

	temp.addNode(l.node(chosen.getPath(chosen.size() - 1)));
	l = temp;

	return dist;
}
