#include "DogFW/Common/Time/Timer.h"
#include "DogFW/Platform/Windows/DogWindows.h"

namespace DogFW
{
	Timer::Timer()
	: secondsPerCount_(0.0),deltaTime_(-1.0),baseTime_(0),
		pausedTime_(0),prevTime_(0),currTime_(0),stopTime_(0),isStopped_(false)
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec_);
		secondsPerCount_ = 1.0 / (double)countsPerSec_;
	}

	float Timer::getTotalTime() const
	{
		if (isStopped_)
		{
			return (float)(((stopTime_ - baseTime_) - pausedTime_) * secondsPerCount_);
		}
		else
		{
			(float)(((currTime_ - baseTime_) - pausedTime_) * secondsPerCount_);
		}
	}

	float Timer::getDeltaTime() const
	{
		return (float)deltaTime_;
	}

	void Timer::reset()
	{
		int64 currtime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currtime);

		baseTime_ = currtime;
		prevTime_ = currtime;
		stopTime_ = 0;
		isStopped_ = false;
	}

	void Timer::start()
	{
		int64 starttime;
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
			int64 currtime;
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
		
		int64 currtime;
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
