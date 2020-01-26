

#ifndef STPWTCH_HPP
#define STPWTCH_HPP

#include <chrono>
#include <ctime>

class StopWatch {
public:
	//Start the watch
	StopWatch();

	//Reset the watch
	void Start();

	//Stop the watch
	void Stop();

	//Retrieve time
	void eTimeSec(double& d);
	void eTimeMili(double& d);
private:
	std::chrono::system_clock::time_point _start;
	std::chrono::system_clock::time_point _end;

};
#endif // !STPWTCH_HPP
