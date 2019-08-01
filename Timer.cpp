#include "Timer.h"
#include <stdio.h>

Timer::Timer(){}

void Timer::startTimer(){
	start = SDL_GetTicks();
}

void Timer::endTimer(){
	start = 0;
}

unsigned int Timer::currentTime(){
	cTime = (SDL_GetTicks() - start);
	return cTime;
}
