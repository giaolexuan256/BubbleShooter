#ifndef BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
#define BUBBLESHOOTER_BUBBLEGRIDMANAGER_H


#include
#include "Point.h"


class BubbleGridManager {
    const static int tileWidth = 40;
    const static int tileHeight = 40;
    const static int columns = 15;
    const static int rows = 5;
    int bubbleArray[columns][rows];

    Point getBubbleCoordinate(int column, int row);
};


#endif //BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
