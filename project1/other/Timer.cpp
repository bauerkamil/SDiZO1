#include "../headers/other/Timer.h"
void Timer::start()
{
	this->startTime = std::chrono::high_resolution_clock::now();
}

void Timer::stop()
{
	this->endTime = std::chrono::high_resolution_clock::now();
}

long Timer::result()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(this->endTime - this->startTime).count();
}