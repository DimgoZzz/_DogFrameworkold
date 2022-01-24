#pragma once
#include "DogFW/Common/Math/DogInt.h"

namespace DogFW
{
	class Timer
	{

	public:
		Timer();

		float getTotalTime()const; // in seconds
		float getDeltaTime()const; // in seconds

		void reset(); // Call before message loop.
		void start(); // Call when unpaused.
		void stop();  // Call when paused.
		void tick();  //tCall every frame.

	private:
		double secondsPerCount_;
		int64  countsPerSec_;
		double deltaTime_;

		int64 baseTime_;
		int64 pausedTime_;
		int64 stopTime_;
		int64 prevTime_;
		int64 currTime_;

		bool isStopped_;
	};
}