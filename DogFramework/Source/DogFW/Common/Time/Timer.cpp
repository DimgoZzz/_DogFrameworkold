#include "DogFW/Common/Time/Timer.h"
#include "DogFW/External/Windows/DogWindows.h"

namespace DogFW
{
	Timer::Timer()
	: secondsPerCount_(0.0),deltaTime_(-1.0),baseTime_(0),
		pausedTime_(0),prevTime_(0),currTime_(0),stopTime_(0),isStopped_(false)
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec_);
		secondsPerCount_ = 1.0 / (Double)countsPerSec_;
	}

	Float Timer::getTotalTime() const
	{
		if (isStopped_)
		{
			return (Float)(((stopTime_ - baseTime_) - pausedTime_) * secondsPerCount_);
		}
		else
		{
			(Float)(((currTime_ - baseTime_) - pausedTime_) * secondsPerCount_);
		}
	}

	Float Timer::getDeltaTime() const
	{
		return (Float)deltaTime_;
	}

	void Timer::reset()
	{
		Int64 currtime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currtime);

		baseTime_ = currtime;
		prevTime_ = currtime;
		stopTime_ = 0;
		isStopped_ = false;
	}

	void Timer::start()
	{
		Int64 starttime;
		QueryPerformanceCounter((LARGE_INTEGER*)&starttime);

		if (isStopped_)
		{
			pausedTime_ += (starttime - stopTime_);
			
			prevTime_ = starttime;
			stopTime_ = 0;
			isStopped_ = false;
		}
	}

	void Timer::stop()
	{
		if (isStopped_)
		{
			Int64 currtime;
			QueryPerformanceCounter((LARGE_INTEGER*)&currtime);

			stopTime_ = currtime;
			isStopped_ = true;
		}
	}

	void Timer::tick()
	{
		if (isStopped_)
		{
			deltaTime_ = 0.0;
		}
		
		Int64 currtime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currtime);
		currTime_ = currtime;

		deltaTime_ = (currTime_ - prevTime_) * secondsPerCount_;

		prevTime_ = currTime_;

		// Force nonnegative.  The DXSDK's CDXUTTimer mentions that if the 
		// processor goes into a power save mode or we get shuffled to another
		// processor, then mDeltaTime can be negative.
		if (deltaTime_ < 0.0)
		{
			deltaTime_ = 0.0;
		}
	}
}
