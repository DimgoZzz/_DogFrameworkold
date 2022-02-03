#pragma once
#include "DogFW/DogBasicTypes.h"

namespace DogFW
{
	class Timer
	{

	public:
		Timer();

		Float getTotalTime()const; // in seconds
		Float getDeltaTime()const; // in seconds

		void reset(); // Call before message loop.
		void start(); // Call when unpaused.
		void stop();  // Call when paused.
		void tick();  //tCall every frame.

	private:
		Double secondsPerCount_;
		Int64  countsPerSec_;
		Double deltaTime_;

		Int64 baseTime_;
		Int64 pausedTime_;
		Int64 stopTime_;
		Int64 prevTime_;
		Int64 currTime_;

		Bool isStopped_;
	};
}