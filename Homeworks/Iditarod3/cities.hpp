//cities.hpp
//Chuluunbat Purev
//2020-4-9
//Header for cities with location

#include <vector>
#include <string>
#include <iostream>

#ifndef CITIES_HPP
#define CITIES_HPP
class CityNode {
public:
	CityNode(int id, double lat, double lng, double x, double y) 
		: _id(id), _lat(lat), _lng(lng), _x(x), _y(y) {};
	CityNode() : _id(0), _lat(0), _lng(0), _x(0), _y(0) {};

	void id(const int& num);
	void x(const double& num);
	void y(const double& num);

	int id();
	double x();
	double y();

	void print();
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
	void load(const std::string& str);
	void print();
private:
	std::vector<std::shared_ptr<CityNode>> cityList;
};
#endif // !CITIES_HPP
