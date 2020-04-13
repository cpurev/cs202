#include "citypath.hpp"

CityPath::CityPath(const int& size) : _size(size) {}

void CityPath::addNode(const CityNode& n) {

	_path.push_back(n.id());

	if (_size == _path.size()) {
		_path.push_back(_path[0]);
		return;
	}
}