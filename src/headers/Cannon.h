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

    void setAngleToMousePosition(Point mousePosition);

    void setLoadedBubble(Bubble* loadedBubble);

    void freeBubble();
private:
    Arrow *arrow;
    Bubble *loadedBubble;
    const float ANGLE_UPPER_BOUND = 170;
    const float ANGLE_LOWER_BOUND = 10;
};


#endif //BUBBLESHOOTER_CANNON_H
