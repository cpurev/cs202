//names.cpp
//Chuluunbat Purev
//2020-2-13
//Souce of names.hpp

#include "names.hpp"
#include <iostream>

//namespace {
//	void foo() {
//		std::cout << "anonymous foo()\n";
//	}
//}
void zoo::foo() {
	std::cout << "namespace foo()\n";
	//::foo();
}
void moo::foo() {
	std::cout << "class foo()\n";
	//foo();
}
