//cities.cpp
//Chuluunbat Purev
//2020-4-9
//Cities header definition

#include "cities.hpp"
#include <fstream>
#include <sstream>
#include <math.h>

void CityNode::id(const int& num){
	_id = num;
};
void CityNode::x(const double& num) {
	_x = num;
};
void CityNode::y(const double& num) {
	_y = num;
};
void CityNode::print() const {
	std::cout << _id << "\t" << _x << "\t" << _y << "\n";
}

int CityNode::id() const {return _id;}
double CityNode::x() const { return _x; }
double CityNode::y() const { return _y; }

void CityList::load (const std::string& str){

	std::ifstream input(str);

	if (!input) {
		std::cout << "File error";
		return;
	}

	std::string a;
	while (std::getline(input, a)) {
		if (a == "NODE_COORD_SECTION")
			break;
	}

	int num;
	double d;
	while (std::getline(input, a)) {
		if (a == "EOF")
			break;
		CityNode cn;
		std::istringstream iss(a);
		iss >> num;
		cn.id(num);
		iss >> d;
		cn.x(d);
		iss >> d;
		cn.y(d);

		cityList.push_back(std::make_shared<CityNode>(cn));
			
	}

}
void CityList::print() const {
	for (auto x : cityList) 
		x->print();
}

double CityList::distance(int first, int second) const {
	if (first == second) return 0;
	if (cityList.size() <= first || cityList.size() <= second) return 0;
	return std::sqrt(std::pow(cityList[second]->x() - cityList[first]->x(), 2) + std::pow(cityList[second]->y() - cityList[first]->y(), 2));
}