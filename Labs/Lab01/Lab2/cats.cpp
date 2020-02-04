//cats.cpp
//2020-1-23
//Chuluunbat Purev
//Body of cats.hpp

#include "cats.hpp"

CAT::CAT() {
	_c = nullptr;
}

CAT::CAT(const CAT& c) {
	_c = c._c;
}

CAT::CAT(const char* c) {
	_c = c;
}

CAT::~CAT() {

}

const char* CAT::getCats() {
	return _c;
}