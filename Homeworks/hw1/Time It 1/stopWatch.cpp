//stopWatch.cpp
//2020-1-26
//Chuluunbat Purev
//Source of stopwatch.hpp

#include "stopWatch.hpp"

StopWatch::StopWatch() {
	_start = std::chrono::system_clock::now();

}

void StopWatch::Start() {
	_start = std::chrono::system_clock::now();
}

void StopWatch::Stop() {
	_end = std::chrono::system_clock::now();
}

void StopWatch::eTimeSec(double& d) {
	std::chrono::duration<double> time = _end - _start;
	d = time.count();
}
