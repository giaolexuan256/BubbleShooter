#include "BubbleGridManager.h"

BubbleGridManager::BubbleGridManager() {
    initializeBubbleArray();
    clearToProcessArray();
}

void BubbleGridManager::initializeBubbleArray() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            if (j >= startingRows) bubbleArray[i][j] = BLANK;
            else bubbleArray[i][j] = RandomBubbleColorGenerator::generateRandomBubbleColor();
        }
    }
}