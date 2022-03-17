//
// Created by giaol on 3/17/2022.
//

#ifndef BUBBLESHOOTER_CANNON_H
#define BUBBLESHOOTER_CANNON_H


#include "Arrow.h"
#include "Bubble.h"
#include "ConstantCarrier.h"
class Cannon {
public:
    Cannon() : arrow(Point(SCREEN_WIDTH / 2,SCREEN_HEIGHT - 40), 200, 90) {

    }

    Arrow arrow;
    Bubble loadedBubble;
};


#endif //BUBBLESHOOTER_CANNON_H
