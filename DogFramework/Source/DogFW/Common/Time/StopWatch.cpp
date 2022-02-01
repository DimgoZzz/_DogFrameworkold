#include "DogFW/Common/Time/StopWatch.h"
#include "DogFW/External/Windows/DogWindows.h"

using namespace DogFW;

SimpleStopWatch::SimpleStopWatch() :
	startTick_(0),
	stopTick_(0)
{
	Int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	mSecondsPerTick_ = 1.0 / (Double)countsPerSec;
}

void DogFW::SimpleStopWatch::start()
{
	Int64 temp;
	QueryPerformanceCounter((LARGE_INTEGER*)&temp);
	startTick_ = temp;
}

void DogFW::SimpleStopWatch::stop()
{
	Int64 temp;
	QueryPerformanceCounter((LARGE_INTEGER*)&temp);
	stopTick_ = temp;

}

Int64 DogFW::SimpleStopWatch::getStartTick() const
{
	return startTick_;
}

Int64 SimpleStopWatch::getCurrentTick() const
{
	Int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	return currTime;
}

Int64 DogFW::SimpleStopWatch::getTickElapsed() const
{
	return stopTick_ - startTick_;
}

Float DogFW::SimpleStopWatch::getTimeElapsed() const
{
	return static_cast<Float>(((Double)getTickElapsed())*mSecondsPerTick_);
}
