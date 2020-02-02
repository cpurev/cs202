//main.cpp
//2020-2-2
//Chuluunbat Purev
//Linked List with Shared Pointer and catch2.hpp

#include "colors.hpp"
#include <catch2/catch.hpp>

TEST_CASE("QUEUE: FIRST IN FIRST OUT", "[queue]") {
//	Value Val[] = { "GREEN", "RED", "BLUE", "YELLOW", "BLACK", "WHITE" };

	REQUIRE();
}

int main() {


	std::list<std::shared_ptr<Value>> list;

	for (auto i : Val)
		addQueue(list, i);

	for (auto x : list)
		std::cout << x->str << std::endl;

	if (find(list, Val[3]))
		std::cout << Val[3].str << std::endl;


	return 1;
}