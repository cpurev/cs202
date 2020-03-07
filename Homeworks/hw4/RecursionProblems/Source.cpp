//Source.cpp
//2020-3-7
//Chuluunbat Purev
//Fibonacci, Ackerman, Factorial problems

#include <iostream>
#include "stopWatch.hpp"

//Fibonacci with recursion
unsigned int fibonacci(int n) {
	return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

//Fibonacci with loops
unsigned int fibonacci_l(int n) {
	int num1 = 0, num2 = 1, num3 = 0;
	for (auto i = 1; i <= n; i++) {
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;
	}
	return num1;
}

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

//Ackerman's Function
unsigned int ackerman(int m, int n) {
	if (m == 0) return n + 1;
	if (n == 0) return ackerman(m - 1, 1);
	return ackerman(m - 1, ackerman(m, n - 1));
}

int main(void) {

	StopWatch sw;
	
	sw.Start();
	std::cout << fibonacci(100);
	sw.Stop();
	std::cout << "Fibonacci Re"

	return 1;
}