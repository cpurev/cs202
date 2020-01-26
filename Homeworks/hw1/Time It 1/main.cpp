//main.cpp
//2020-1-26
//Chuluunbat Purev
//Testing stopWatch.hpp

#include "stopWatch.hpp"
#include <iostream>

int main() {

	double d = 0;
	int n = 0;

	StopWatch a;

	for (auto i = 0; i < 100000; i++) {
		n += i;
	}

	a.Stop();

	a.eTimeSec(d);

	std::cout << "The number is: " << n << "\nTime it took: " << d <<"sec";

	return 1;
}