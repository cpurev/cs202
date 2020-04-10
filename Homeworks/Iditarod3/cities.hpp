//cities.hpp
//Chuluunbat Purev
//2020-4-9
//Header for cities with location

#include <vector>

#ifndef CITIES_HPP
#define CITIES_HPP
class CityNode {
public:
	CityNode(int id, double lat, double lng, double x, double y) 
		: _id(id), _lat(lat), _lng(lng), _x(x), _y(y) {};
private:
	int _id;
	double _lat;
	double _lng;
	double _x, _y;
};

class CityList {
public:
	//Euclidean distance
	double distance(int first, int second) const;
	//Load TSPLIB file
	void load();
private:
	std::vector<CityNode> cityList;
};
#endif // !CITIES_HPP
