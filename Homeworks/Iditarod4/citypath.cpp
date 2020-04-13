#include "citypath.hpp"

CityPath::CityPath(const int& size) : _size(size) {}

void CityPath::addNode(const std::shared_ptr<CityNode> n) {

	_path.push_back(n->id());

	if (_size == _path.size()) {
		_path.push_back(_path[0]);
		return;
	}
}

void CityPath::deleteNode(const int& num) {
	if (_path.size() == 1) {
		_path.erase(_path.begin());
		return;
	}
	_path.erase(_path.begin() + num);
}
int CityPath::getPath(const int& num) const { return _path[num]; }