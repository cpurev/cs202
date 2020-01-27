//main.cpp
//2020-1-26
//Chuluunbat Purev
//Testing stopWatch.hpp

#include "stopWatch.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

void stopWatchTrials(std::vector<double>& v, int size, StopWatch a) {

	v.clear();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10);

	a.Start();
	for (auto i = 0; i < size - v.size(); i++) {
		v.push_back(dis(gen));
	}
	a.Stop();
	std::cout << "Pushing " << size << " items in to vector: " << a.eTimeSec() << std::endl;

	int arr[] = { 7 };

	a.Start();
	std::binary_search(v.begin(), v.end(), 7);
	a.Stop();
	std::cout << "Binary search 7 in " << size << " items: " << a.eTimeSec() << std::endl;

	a.Start();
	std::search(v.begin(), v.end(), arr, arr + 1);
	a.Stop();
	std::cout << "Search 7 in "<< size << " items: " << a.eTimeSec() << std::endl;

	a.Start();
	std::find(v.begin(), v.end(), 7);
	a.Stop();
	std::cout << "Find 7 in " << size << " items: " << a.eTimeSec() << std::endl;


}

int main() {

	int n = 0;
	std::vector<double> v;
	StopWatch a;

	stopWatchTrials(v, 10000, a);

	std::cout << std::endl;

	stopWatchTrials(v, 100000,a );

	std::cout << std::endl;

	stopWatchTrials(v, 1000000,a );

	std::cout << std::endl;

	stopWatchTrials(v, 10000000, a);

	std::cout << std::endl;

	stopWatchTrials(v, 100000000, a);

	return 1;
}