#pragma once
#include <windows.h>
class Timer
{
public:
	Timer();

	float TotalTime()const; // in seconds
	float DeltaTime()const; // in seconds

	void Reset(); // Call before message loop.
	void Start(); // Call when unpaused.
	void Stop();  // Call when paused.
	void Tick();  // Call every frame.

private:
	double mSecondsPerCount{ 0 };
	double mDeltaTime{ 0 };

	__int64 mBaseTime {0};
	__int64 mPausedTime{ 0 };
	__int64 mStopTime{ 0 };
	__int64 mPrevTime{ 0 };
	__int64 mCurrTime{ 0 };

	bool mStopped;
};