#ifndef BUBBLESHOOTER_CANNON_H
#define BUBBLESHOOTER_CANNON_H

#include "Arrow.h"
#include "Bubble.h"
#include "Game.h"


class Cannon {
public:
    Cannon()  : arrow(Point()){

    }
private:
    Arrow arrow;
    Bubble loadedBubble;
};


#endif //BUBBLESHOOTER_CANNON_H
