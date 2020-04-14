//tscpsolver.hpp
//Chuluunbat Purev
//2020-4-13
//TSP path solving header

#include "cities.hpp"
#include "citypath.hpp"

class TspSolver {
public:
	double solveRandomly(const CityList& l);
	double solveGreedy(const CityList& l);
	double solveMyWay(const CityList& l);
	double eucD(double x1, double x2, double y1, double y2);
};