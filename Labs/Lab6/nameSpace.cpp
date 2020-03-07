//nameSpace.cpp
//2020-2-13
//Chuluunbat	Purev
//Namespace 

#include "names.hpp"
#include <iostream>

//#define C main
//#define CC int
//#define CCC return
//#define CCCC std::cout
//#define CCCCC <<
//#define CCCCCC "Hello\n"
//#define CCCCCCC namespace
//#define CCCCCCCC std::string
//#define CCCCCCCCC =
//#define CCCCCCCCCC str
//#define CCCCCCCCCCC "World\n"
//
//
//CCCCCCC{
//	CCCCCCCC CCCCCCCCCC CCCCCCCCC CCCCCCCCCCC;
//}
//
//CC C() {
//
//	CCCC CCCCC CCCCCC;
//	CCCC CCCCC CCCCCCCCCC;
//
//	CCC 1;
//
//}

void foo() {
	std::cout << "main foo()\n";
}

//namespace {
//	void foo() {
//		std::cout << "anonymous foo()\n";
//	}
//}

int main() {

	moo::foo();

	zoo::foo();

	foo();

	

	return 1;
}