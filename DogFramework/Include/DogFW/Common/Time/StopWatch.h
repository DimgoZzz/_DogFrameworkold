#pragma once
#include "DogFW/Common/Math/DogInt.h"

namespace DogFW
{
	class SimpleStopWatch
	{
	public:
		SimpleStopWatch();

		void Start();
		void Stop();

		int64 GetStartTick()   const;
		int64 GetCurrentTick() const;
		int64 GetTickElapsed() const;
		float GetTimeElapsed() const;
	private:
		double mSecondsPerTick;

		int64 mStartTick;
		int64 mStopTick;
	};
}
