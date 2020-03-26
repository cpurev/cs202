#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
public:
	Complex();
	Complex(const double& real);
	Complex(const double& real, const double& imaginary);

	Complex operator+(const Complex& complex);
	Complex& operator+=(const Complex& complex) {
		*this = *this + complex;
		return *this;
	}

	double real() const { return _real; }
	double imag() const { return _imag; }
private:
	double _real, _imag;
};

Complex operator+(const double& real, const Complex complex);

std::ostream& operator<<(std::ostream& os, const Complex& complex);

#endif // !COMPLEX_HPP
