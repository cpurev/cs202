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

	int id () const;
	double x() const;
	double y() const;

	void print() const;
private:
	int _id;
	double _lat;
	double _lng;
	double _x, _y;
};

class CityList {
public:
	CityList() : minX(DBL_MAX), minY(DBL_MAX), maxX(0), maxY(0) {};
	//Euclidean distance
	double distance(int first, int second) const;
	//Load TSPLIB file
	bool load(const std::string& str);
	void print() const;
	size_t size() const { return cityList.size(); }
	std::shared_ptr<CityNode> node(const int& n) const { return cityList[n]; }
	void addNode(const std::shared_ptr<CityNode>& n) { cityList.push_back(n); }

	double getMaxX() const{ return maxX; }
	double getMaxY() const { return maxY; }
	double getMinX() const { return minX; }
	double getMinY() const { return minY; }
private:
	std::vector<std::shared_ptr<CityNode>> cityList;
	double minX, minY, maxX, maxY;
};
#endif // !CITIES_HPP
