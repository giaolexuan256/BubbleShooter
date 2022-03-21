#ifndef BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
#define BUBBLESHOOTER_BUBBLEGRIDMANAGER_H


#include "Point.h"
#include "BubbleColor.h"


class BubbleGridManager {
public:
    Point getBubbleCoordinate(int column, int row);

    void renderAllBubbles();

    void renderBubble(float x, float y, int type);


private:
    const static int tileWidth = 40;
    const static int tileHeight = 40;
    const static int columns = 15;
    const static int rows = 5;
};


#endif //BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
