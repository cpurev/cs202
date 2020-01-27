//main.cpp
//2020-1-26
//Chuluunbat Purev
//Testing stopWatch.hpp

#include "stopWatch.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

void stopWatchTrials(std::vector<int>& v, int size) {

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10);

	for (auto i = 0; i < size; i++) {
		v.push_back(dis(gen));
	}



}

int main() {

	int n = 0;
	std::vector<int> v;
	int arr[] = { 7 };

	StopWatch a;


	std::binary_search(v.begin(), v.end(), 7);
	a.Stop();
	std::cout << "Binary search 7 in  100 items: " << a.eTimeSec() << std::endl;

	a.Start();
	std::search(v.begin(), v.end(), arr, arr+1);
	a.Stop();
	std::cout << "Search 7 in 100 items: " << a.eTimeSec() << std::endl;

	a.Start();
	std::find(v.begin(), v.end(), 7);
	a.Stop();
	std::cout << "Find 7 in 100 items: " << a.eTimeSec() << std::endl;

	a.Start();
	std::count(v.begin(), v.end(), 7);
	a.Stop();
	std::cout << "Count 7 in 100 items: " << a.eTimeSec() << std::endl;


	return 1;
}