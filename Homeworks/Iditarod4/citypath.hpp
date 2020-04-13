//citypath.hpp
//Chuluunbat Purev
//2020-4-11
//Vector connection between all the cities

#include "cities.hpp"

class CityPath {
public:
	CityPath(const int& size);
	CityPath() : _size(0) {};
	void addPath(const int& n);
	void deletePath(const int& num);
	int getPath(const int& num) const;
	size_t size() const { return _path.size(); }

private:
	std::vector<int> _path;
	int _size;
};