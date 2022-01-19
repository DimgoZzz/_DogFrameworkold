#include "DogFW/Common/Time/StopWatch.h"
#include "DogFW/Platform/Windows/DogWindows.h"

using namespace DogFW;

SimpleStopWatch::SimpleStopWatch() :
	mStartTick(0),
	mStopTick(0)
{
	int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	mSecondsPerTick = 1.0 / (double)countsPerSec;
}

void DogFW::SimpleStopWatch::Start()
{
	int64 temp;
	QueryPerformanceCounter((LARGE_INTEGER*)&temp);
	mStartTick = temp;
}

void DogFW::SimpleStopWatch::Stop()
{
	int64 temp;
	QueryPerformanceCounter((LARGE_INTEGER*)&temp);
	mStopTick = temp;

}

int64 DogFW::SimpleStopWatch::GetStartTick() const
{
	return mStartTick;
}

int64 SimpleStopWatch::GetCurrentTick() const
{
	int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	return currTime;
}

int64 DogFW::SimpleStopWatch::GetTickElapsed() const
{
	return mStopTick-mStartTick;
}

float DogFW::SimpleStopWatch::GetTimeElapsed() const
{
	return ((double)GetTickElapsed())*mSecondsPerTick;
}
