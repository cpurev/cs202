//main.cpp
//2020-2-2
//Chuluunbat Purev
//Linked List with Shared Pointer and catch2.hpp

#define CATCH_CONFIG_MAIN

#include "colors.hpp"
#include <catch2/catch.hpp>

Colors Col[] = { "GREEN", "RED", "BLUE", "YELLOW", "BLACK", "WHITE" };
std::list<std::shared_ptr<Colors>> list;


TEST_CASE("QUEUE: FIRST IN FIRST OUT", "[queue]") {
	REQUIRE(find(list, Col[2]) == true);
}


//int main() {
//
//
//	return 1;
//}