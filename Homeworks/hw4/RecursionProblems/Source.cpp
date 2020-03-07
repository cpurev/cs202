//Source.cpp
//2020-3-7
//Chuluunbat Purev
//Fibonacci, Ackerman, Factorial problems

#include <iostream>

//Factorial with recursion
unsigned int factorial(int n) {
	return n <= 1 ? 1 : factorial(n - 1) * n;
}

//Factorial with loop
unsigned int factorial_l(int n) {
	int j = 1;
	for (auto i = 1; i <= n; i++) {
		j *= i;
	}
	return j;
}

int main(void) {

	std::cout << factorial_l(0);

	return 1;
}