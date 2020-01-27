//main.cpp
//2020-1-26
//Chuluunbat Purev
//Testing stopWatch.hpp

#include "stopWatch.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

void stopWatchTrials(StopWatch a, std::string filename) {

	std::ifstream file(filename);

	if (!file) {
		std::cout << "File error";
		return;
	}

	std::string str;

	a.Start();
	str.assign((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	a.Stop();
	std::cout << "Reading a txt file to string :" << a.eTimeMili() << "ms" << std::endl;

	std::vector<std::string> v;
	std::string line;

	a.Start();
	while (std::getline(file, line)) {
		if (line.size() > 0)
			v.push_back(line);
	}
	a.Stop();
	std::cout << "Reading a txt file to vector :" << a.eTimeMili() << "ms" << std::endl;

	std::pair<std::string, int> p; 
	int i = 0;

	a.Start();
	while (std::getline(file, line)) {
		if (line.size() > 0) {
			i++;
			p.first = line;
			p.second = i;
		}
	}
	a.Stop();
	std::cout << "Reading a txt file to pair :" << a.eTimeMili() << "ms" << std::endl;



}

int main() {

	StopWatch a;

	stopWatchTrials(a, "11659-8.txt");
	std::cout << std::endl;

	stopWatchTrials(a, "61230-0.txt");
	std::cout << std::endl;

	stopWatchTrials(a, "61231-0.txt");
	std::cout << std::endl;

	stopWatchTrials(a, "61234-0.txt");
	std::cout << std::endl;

	stopWatchTrials(a, "61236-0.txt");
	std::cout << std::endl;



	return 1;
}