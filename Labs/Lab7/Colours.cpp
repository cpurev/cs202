#include "Colours.hpp"

Colours::Colours() : _r(0), _g(0), _b(0), _a(0){}

std::ostream& operator<<(std::ostream& os, const Colours& colours) {
	os << "(" << colours.r() << ", " << colours.g() << ", " << colours.b() << ", " << colours.a() << ")";
	return os;
}