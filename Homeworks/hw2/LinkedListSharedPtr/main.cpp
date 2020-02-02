//main.cpp
//2020-2-2
//Chuluunbat Purev
//Linked List with Shared Pointer and catch2.hpp

#define CATCH_CONFIG_MAIN

#include "colors.hpp"
#include <catch2/catch.hpp>

Colors Col[] = { "GREEN", "RED", "BLUE", "YELLOW", "BLACK", "WHITE" };
std::list<std::shared_ptr<Colors>> list;
Colors c = { "ORANGE" };
Colors d = { "DARK" };
Colors e = { "EWO" };

TEST_CASE("TESTING COLORS.HPP", "[colors]") {
	for(auto x : Col)
		addQueue(list, x);

	SECTION("QUEUE: FIRST IN FIRST OUT") {
		addQueue(list, c);
		REQUIRE(list.back()->str == c.str);

		popQueue(list);
		REQUIRE(list.front()->str != Col[0].str);

	}

	SECTION("STACK: LAST IN FIRST OUT") {
		pushStack(list, c);
		REQUIRE(list.back()->str == c.str);

		popStack(list);
		REQUIRE(list.front()->str != Col[0].str);

	}

	SECTION("Insert and Find") {
		insert(list, e, list.begin());
		REQUIRE(list.front()->str == e.str);

		REQUIRE(find(list, d) != true);
	}
}


//int main() {
//
//
//	return 1;
//}