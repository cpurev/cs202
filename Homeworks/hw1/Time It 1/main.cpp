//main.cpp
//2020-1-26
//Chuluunbat Purev
//Testing stopWatch.hpp

#include "stopWatch.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

int main() {

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10);

	int n = 0;
	std::vector<int> v;

	StopWatch a;

	for (auto i = 0; i < 100; i++) {
		v.push_back(dis(gen));
	}

	std::binary_search(v.begin(), v.end(), 7);

	a.Stop();
	std::cout << "Binary search 100 items: " << a.eTimeSec(d);

	std::search(v.begin(), v.end(), 7);


	return 1;
}