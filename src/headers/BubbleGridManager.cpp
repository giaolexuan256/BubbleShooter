#include "BubbleGridManager.h"

Point BubbleGridManager::getBubbleCoordinate(int column, int row) {
    int x = column * tileWidth;
    if (row % 2 == 1) {
        x += tileWidth / 2;
    }
    int y = row * tileHeight;
    return Point((float) x, (float) y);
}

void BubbleGridManager::renderAllBubbles() {

}

void BubbleGridManager::renderBubble(float x, float y, int type) {

}
