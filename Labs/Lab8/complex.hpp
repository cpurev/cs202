#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
public:
	Complex();
	Complex(const double& real);
	Complex(const double& real, const double& imaginary);

	double real() const { return _real; }
	double imag() const { return _imag; }
private:
	double _real, _imag;
};

std::ostream& operator<<(std::ostream& os, const Complex& complex);

#endif // !COMPLEX_HPP
