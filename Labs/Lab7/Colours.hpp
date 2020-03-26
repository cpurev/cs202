#ifndef COLOURS_HPP
#define COLOURS_HPP

#include <iostream>

class Colours {
public:
	Colours();

	const float& r() const { return _r; }
	const float& g() const { return _g; }
	const float& b() const { return _b; }
	const float& a() const { return _a; }
private:
	float _r, _g, _b, _a;
};

std::ostream& operator<<(std::ostream& os, const Colours& colours);

#endif // !COLOURS_HPP
