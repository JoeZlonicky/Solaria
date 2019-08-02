#pragma once
#include <SDL_timer.h>

class Timer
{
public:
	Timer();

	void startTimer();
	void endTimer();
	unsigned int currentTime();

private:
	unsigned int start;
	unsigned int cTime;
};

