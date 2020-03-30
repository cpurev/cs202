//Source.cpp
//Chuluunbat Purev
//2020-3-30
//Ackermans Analysis

#include <iostream>
#include "stopWatch.hpp"

//Ackerman's Function
unsigned int ackerman(unsigned int m, unsigned int n) {
	if (m == 0) return n + 1;
	if (m > 0 && n == 0) return ackerman(m - 1, 1);
	return ackerman(m - 1, ackerman(m, n - 1));

}

int main(void) {

	StopWatch sw;
	unsigned long long int m = 3, n = 8;

	sw.Start();
	int a = ackerman(m, n);
	sw.Stop();
	std::cout << "(" << m << ", " << n << "): " << a << "\nTime:" << sw.eTimeSec() << "seconds";

	return 1;	
}