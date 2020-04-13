//citypath.hpp
//Chuluunbat Purev
//2020-4-11
//Vector connection between all the cities

#include "cities.hpp"

class CityPath {
public:
	CityPath(const int& size);
	void addNode(const std::shared_ptr<CityNode> n);
	void deleteNode(const int& num);
	int getPath(const int& num) const;
	size_t size() const { return _path.size(); }

private:
	std::vector<int> _path;
	int _size;
};