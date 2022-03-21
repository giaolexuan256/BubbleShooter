#ifndef BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
#define BUBBLESHOOTER_BUBBLEGRIDMANAGER_H


#include "Point.h"


class BubbleGridManager {
    const static int tileWidth = 40;
    const static int tileHeight = 40;
    const static int columns = 15;
    const static int rows = 5;
    int bubbleArray[columns][rows];

    Point getBubbleCoordinate(int column, int row);

    void renderAllBubbles();

    void renderBubble(float x, float y, int type);
};


#endif //BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
