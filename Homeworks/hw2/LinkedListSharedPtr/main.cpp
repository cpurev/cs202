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


int main() {

	Value Val;

	std::list<std::shared_ptr<Value>> list;

	Val.str = "RED";
	list.push_back(std::make_shared<Value>(Val));

	Val.str = "GREEN";
	list.push_back(std::make_shared<Value>(Val));

	Val.str = "BLUE";
	list.push_back(std::make_shared<Value>(Val));

	Val.str = "YELLOW";
	list.push_back(std::make_shared<Value>(Val));

	Val.str = "BLACK";
	list.push_back(std::make_shared<Value>(Val));

	Val.str = "WHITE";
	list.push_back(std::make_shared<Value>(Val));

	for (auto x : list)
		std::cout << x->str << std::endl;

	return 1;
}