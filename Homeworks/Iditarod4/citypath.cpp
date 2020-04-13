#include "citypath.hpp"

CityPath::CityPath(const int& size) : _size(size) {}

void CityPath::addPath(const int& n) {

	_path.push_back(n);

}

void CityPath::deletePath(const int& num) {
	if (_path.size() == 1) {
		_path.erase(_path.begin());
		return;
	}
	_path.erase(_path.begin() + num);
}
int CityPath::getPath(const int& num) const { return _path[num]; }