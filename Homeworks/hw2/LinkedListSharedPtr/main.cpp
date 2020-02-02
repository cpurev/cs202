//main.cpp
//2020-2-2
//Chuluunbat Purev
//Linked List with Shared Pointer and catch2.hpp

#define CATCH_CONFIG_MAIN

#include "colors.hpp"
#include <catch2/catch.hpp>

//Testing variables
Colors Col[] = { "GREEN", "RED", "BLUE", "YELLOW", "BLACK", "WHITE" };
std::list<std::shared_ptr<Colors>> list;
Colors c = { "ORANGE" };
Colors d = { "DARK" };
Colors e = { "EWO" };


TEST_CASE("TESTING COLORS.HPP", "[colors]") {

	//Dont know why but this has to go here 
	//Shows expected declaration error outside of block
	for(auto x : Col)
		addQueue(list, x);

	//Testing queue functions
	//Know what the results have to be so we just compare it
	SECTION("QUEUE: FIRST IN FIRST OUT") {
		addQueue(list, c);
		REQUIRE(list.back()->str == c.str);

		popQueue(list);
		REQUIRE(list.front()->str != Col[0].str);

	}
	
	//Testing stack
	SECTION("STACK: LAST IN FIRST OUT") {

		pushStack(list, c);
		REQUIRE(list.back()->str == c.str);

		popStack(list);
		REQUIRE(list.front()->str != Col[0].str);

	}

	//Testing insert
	//and find
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