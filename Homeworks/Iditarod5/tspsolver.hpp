//tscpsolver.hpp
//Chuluunbat Purev
//2020-4-13
//TSP path solving header

#include "cities.hpp"
#include "citypath.hpp"

class TspSolver {
public:
	double solveRandomly(CityList& l);
	double solveGreedy(CityList& l);
	double solveMyWay(CityList& l);
};