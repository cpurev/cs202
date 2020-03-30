//Source.cpp
//Chuluunbat Purev
//2020-3-30
//Fibonnaci and Factorial

#include <iostream>

//Recursive fibonacci
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

int main(void) {

	std::cout << "Fibonacci Recursion of 10: " << fibonacci(10) << "\n";
	std::cout << "Fibonacci Loop of 10: " << fibonacci_l(10) << "\n";
	std::cout << "Factorial Recursion of 10: " << factorial(10) << "\n";
	std::cout << "Factorial Loop of 10: " << factorial_l(10) << "\n";

	return 1;
}