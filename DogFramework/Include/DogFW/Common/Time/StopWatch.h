#pragma once
#include "DogFW/DogBasicTypes.h"

namespace DogFW
{
	class SimpleStopWatch
	{
	public:
		SimpleStopWatch();

		void start();
		void stop();

		Int64 getStartTick()   const;
		Int64 getCurrentTick() const;
		Int64 getTickElapsed() const;
		Float getTimeElapsed() const;
	private:
		Double mSecondsPerTick_;

		Int64 startTick_;
		Int64 stopTick_;
	};
}
