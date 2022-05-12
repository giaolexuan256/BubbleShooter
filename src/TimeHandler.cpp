#include "TimeHandler.h"

void TimeHandler::startTimer() {
    currentTime = 0;
    lastTime = SDL_GetTicks();

}

void TimeHandler::calculateDeltaTime() {
    currentTime = SDL_GetTicks();
    Uint32 milisecondsPerFrame = currentTime - lastTime;
    deltaTime = (float) milisecondsPerFrame / 1.0E3;
    lastTime = currentTime;
}

float TimeHandler::getDeltaTime() const {
    return deltaTime;
}
