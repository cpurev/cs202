//colors.cpp
//2020-2-2
//Chuluunbat Purev
//Body of colors.hpp

#include "colors.hpp"

void addQueue(std::list<std::shared_ptr<Colors>>& list, const Colors& val) {
	list.push_back(std::make_shared<Colors>(val));
}

void popQueue(std::list<std::shared_ptr<Colors>>& list) {
	list.pop_front();
}

void pushStack(std::list<std::shared_ptr<Colors>>& list, const Colors& val) {
	addQueue(list, val);
}

void popStack(std::list<std::shared_ptr<Colors>>& list) {
	list.pop_back();
}

void insert(std::list<std::shared_ptr<Colors>>& list, const Colors& val, std::list<std::shared_ptr<Colors>>::iterator n) {
	list.insert(n, std::make_shared<Colors>(val));
}

bool find(const std::list<std::shared_ptr<Colors>>& list, const Colors& val) {
	for (auto x : list) {
		if (x->str == val.str)
			return true;
	}
	return false;
}

void print(std::list<std::shared_ptr<Colors>>& list) {
	for (auto x : list)
		std::cout << x << " ";
	std::cout << std::endl;
}