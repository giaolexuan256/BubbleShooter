#ifndef BUBBLESHOOTER_TIMER_H
#define BUBBLESHOOTER_TIMER_H


#include <SDL.h>

class Timer {
public:
    Timer();
    void start();
    void stop();
    void pause();
    void unpause();
    Uint32 getTime();
    bool isPaused();
    bool isStarted();

private:
    Uint32 startTime;
    Uint32 pausedTime;
    bool paused;
    bool started;
};


#endif //BUBBLESHOOTER_TIMER_H
