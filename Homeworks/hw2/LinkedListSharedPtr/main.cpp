//main.cpp
//2020-2-2
//Chuluunbat Purev
//Linked List with Shared Pointer and catch2.hpp

#include <iostream>
#include <catch2/catch.hpp>
#include <list>

struct Value {
	std::string str;
};

void addQueue(std::list<std::shared_ptr<Value>>& list, const Value& val) {
	list.push_back(std::make_shared<Value>(val));
}

int main() {

	Value Val[] = {"GREEN", "RED", "BLUE", "YELLOW", "BLACK", "WHITE"};

	std::list<std::shared_ptr<Value>> list;

	for (auto i : Val)
		addQueue(list, i);

	for (auto x : list)
		std::cout << x->str << std::endl;

	return 1;
}