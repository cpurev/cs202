#include "Colours.hpp"

//Init white
Colours::Colours() : _r(255), _g(255), _b(255), _a(1){}

void Colours::rgba(const float& r_, const float& g_, const float& b_, const float& a_) {
	_r = r_; _g = g_; _b = b_; _a = a_;
}

Colours& Colours::operator=(const Colours& copy) {
	_r = copy._r; _g = copy._g; _b = copy._b; _a = copy._a;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Colours& colours) {
	os << "(" << colours.r() << ", " << colours.g() << ", " << colours.b() << ", " << colours.a() << ")";
	return os;
}