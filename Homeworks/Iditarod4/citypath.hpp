//citypath.hpp
//Chuluunbat Purev
//2020-4-11
//Vector connection between all the cities

#include "cities.hpp"

class CityPath {
public:
	CityPath(const int& size);
	void addNode(const CityNode& n);

private:
	std::vector<int> _path;
	int _size;
};