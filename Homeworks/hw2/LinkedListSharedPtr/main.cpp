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
	std::list<Value> list;

	Val.str = "GREEN";
	list.push_back(Val);
	Val.str = "RED";
	list.push_back(Val);
	Val.str = "BLUE";
	list.push_back(Val);

	for (auto x : list)
		std::cout << x.str << std::endl;

	return 1;
}