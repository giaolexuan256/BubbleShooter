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
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            Point bubbleCoordinate = getBubbleCoordinate(i, j);
            renderBubble(bubbleCoordinate.x, bubbleCoordinate.y, bubbleArray[i][j]);
        }
    }
}

void BubbleGridManager::renderBubble(float x, float y, int type) {

}
