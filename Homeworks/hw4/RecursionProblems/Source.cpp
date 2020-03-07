//Source.cpp
//2020-3-7
//Chuluunbat Purev
//Fibonacci, Ackerman, Factorial problems

#include <iostream>
#include "stopWatch.hpp"
#include <iomanip>

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
	unsigned int a;

	sw.Start();
	a = fibonacci(10);
	sw.Stop();
	std::cout << std::setw(11) << "Fibonacci Recursion of 10: " << a << ", " << sw.eTimeMili() << "ms\n";

	sw.Start();
	a = fibonacci_l(10);
	sw.Stop();
	std::cout << "Fibonacci Loop of 10: " << std::setw(7) << a << ", " << sw.eTimeMili() << "ms\n";

	sw.Start();
	a = factorial(10);
	sw.Stop();
	std::cout << std::setw(11) << "Factorial Recursion of 10: " << a << ", " << sw.eTimeMili() << "ms\n";

	sw.Start();
	a = factorial_l(10);
	sw.Stop();
	std::cout << std::setw(11) << "Factorial Recursion of 10: " << a << ", " << sw.eTimeMili() << "ms\n";

	sw.Start();
	a = ackerman(3, 3);
	sw.Stop();	
	std::cout << std::setw(11) << "Ackerman's Recursion of (3,3): " << a << ", " << sw.eTimeMili() << "ms\n";

	return 1;
}