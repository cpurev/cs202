#ifndef COLOURS_HPP
#define COLOURS_HPP

#include <iostream>

class Colours {
public:
	Colours();

	Colours& operator=(const Colours& copy);

	//Red, Green, Blue, Alpha
	const float& r() const { return _r; }
	const float& g() const { return _g; }
	const float& b() const { return _b; }
	const float& a() const { return _a; }

	//Red, Green, Blue, Alpha
	void rgba(const float& r_, const float& g_, const float& b_, const float& a_);
private:
	float _r, _g, _b, _a;
};

std::ostream& operator<<(std::ostream& os, const Colours& colours);


#endif // !COLOURS_HPP
