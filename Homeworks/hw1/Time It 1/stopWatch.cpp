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
	_end = 
}
