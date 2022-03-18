//
// Created by giaol on 3/17/2022.
//

#ifndef BUBBLESHOOTER_CANNON_H
#define BUBBLESHOOTER_CANNON_H


#include "Arrow.h"
#include "Bubble.h"
#include "ScreenSizeCarrier.h"

class Cannon {
public:
    Cannon(SDL_Renderer *renderer);

    Arrow *getArrow();

    Bubble *getLoadedBubble();

    void setAngle(float angleDegree);

    float getAngle();

    void loadBubble(SDL_Renderer *renderer);

    void render(SDL_Renderer *renderer);

private:

    Arrow *arrow;
    Bubble *loadedBubble;
};


#endif //BUBBLESHOOTER_CANNON_H
