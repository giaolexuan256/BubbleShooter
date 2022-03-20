#include "Timer.h"

Timer::Timer() {


}


void Timer::start() {
    started = true;
    paused = false;
    startTime = SDL_GetTicks();
    pausedTime = 0;
}

void Timer::stop() {
    startTime = 0;
    pausedTime = 0;
    started = false;
    paused = false;
}

void Timer::pause() {
    if (started && !paused) {
        paused = true;
        pausedTime = getTime();

    }
}

void Timer::unpause() {
    if (started && paused) {
        paused = false;
        startTime = SDL_GetTicks() - pausedTime;
        pausedTime = 0;
    }
}

Uint32 Timer::getTime() {
    Uint32 time;
    if (isStarted()) {
        if (isPaused()) {
            time = pausedTime;
        } else {
            time = SDL_GetTicks() - startTime;
        }
    } else {
        time = 0;
    }
    return time;
}

bool Timer::isPaused() {
    return paused;
}

bool Timer::isStarted() {
    return started;
}
