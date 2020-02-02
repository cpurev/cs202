//colors.cpp
//2020-2-2
//Chuluunbat Purev
//Body of colors.hpp

#include "colors.hpp"

#include <catch2/catch.hpp>

TEST_CASE("QUEUE: FIRST IN FIRST OUT", "[queue]") {
	REQUIRE();
}


void addQueue(std::list<std::shared_ptr<Value>>& list, const Value& val) {
	list.push_back(std::make_shared<Value>(val));
}

void popQueue(std::list<std::shared_ptr<Value>>& list) {
	list.pop_front();
}

void pushStack(std::list<std::shared_ptr<Value>>& list, const Value& val) {
	addQueue(list, val);
}

void popStack(std::list<std::shared_ptr<Value>>& list) {
	list.pop_back();
}

void insert(std::list<std::shared_ptr<Value>>& list, const Value& val, std::list<std::shared_ptr<Value>>::iterator n) {
	list.insert(n, std::make_shared<Value>(val));
}

bool find(const std::list<std::shared_ptr<Value>>& list, const Value& val) {
	for (auto x : list) {
		if (x->str == val.str)
			return true;
	}
	return false;
}
