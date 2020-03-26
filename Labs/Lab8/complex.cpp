#include "complex.hpp"

Complex::Complex() : _real(0), _imag(0){}
Complex::Complex(const double& real) : _real(real), _imag(0) {}
Complex::Complex(const double& real, const double& imaginary) : _real(real), _imag(imaginary) {}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
	os << complex.real() << " + " << complex.imag() << "i";
	return os;
}

Complex Complex::operator+(const Complex& complex) {
	return Complex(_real + complex._real, _imag + complex._imag);
}

Complex operator+(const double& real, const Complex complex) {
	return Complex(real + complex.real(), complex.imag());
}