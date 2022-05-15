#ifndef BUBBLESHOOTER_TIMEHANDLER_H
#define BUBBLESHOOTER_TIMEHANDLER_H

#include <SDL.h>


class TimeHandler {
public:
    void startTimer();

    void calculateDeltaTime();

    float getDeltaTime() const;

private:
    float deltaTime;
    Uint32 currentTime;
    Uint32 lastTime;
};


#endif //BUBBLESHOOTER_TIMEHANDLER_H
