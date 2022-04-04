#include "BubbleGridManager.h"

BubbleGridManager::BubbleGridManager() {
    rowOffSet = 0;
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

void BubbleGridManager::renderAllBubbles(SDL_Renderer *renderer, std::vector<std::shared_ptr<TextureAlpha>> bubbleTextures) {
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            Point bubbleCoordinate = getBubbleCoordinate(i, j);
            renderBubble(bubbleCoordinate.x, bubbleCoordinate.y, bubbleArray[i][j],
                         bubbleTextures, renderer);
        }
    }
}

void BubbleGridManager::renderBubble(float x, float y, BubbleColor color, std::vector<std::shared_ptr<TextureAlpha>> &bubbleTextures,
                                     SDL_Renderer *renderer) {
    if (color == BLANK) return;
    bubbleTextures[color]->render(renderer, (int) x, (int) y);
}

bool BubbleGridManager::isCannonBubbleCollideWithBubbleArray(std::shared_ptr<Bubble> &cannonBubble) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            if (bubbleArray[i][j] == BLANK) continue;
            Point bubbleCoordinate = getBubbleCoordinate(i, j);
            if (Utility::circleIntersection(
                    {bubbleCoordinate.x + tileWidth / 2.0f, bubbleCoordinate.y + tileHeight / 2.0f},
                    radius, cannonBubble->getCenterPosition(), radius)) {
                cannonBubble->setMoving(false);
                return true;
            }
        }
    }
    return false;
}

bool BubbleGridManager::isBubbleArrayCleared() {
    for (int i = 0; i < columns; i++) {
        if (bubbleArray[i][0] != BLANK) return false;
    }
    return true;
}

bool BubbleGridManager::isBubblesReachBottom() {
    for (int i = 0; i < columns; i++) {
        if (bubbleArray[i][rows - 1] != BLANK) return true;
    }
    return false;
}

void BubbleGridManager::resetSnappingBubbleContainers() {
    clearToProcessArray();
    foundCluster.clear();
}

void BubbleGridManager::clearToProcessArray() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            toProcess[i][j] = true;
        }
    }
}

SDL_Point BubbleGridManager::getGridPosition(const std::shared_ptr<Bubble> &bubble) {
    float x = bubble->getX();
    float y = bubble->getY();
    int yGrid = (int) std::round((y / tileHeight));
    int xOffset = 0;
    if ((yGrid + rowOffSet) % 2 == 1) {
        xOffset = tileWidth / 2;
    }
    int xGrid = (int) std::round((x - (float) xOffset) / tileWidth);

    return {xGrid, yGrid};
}

Point BubbleGridManager::getBubbleCoordinate(int column, int row) {
    int x = column * tileWidth;
    if ((row + rowOffSet) % 2 == 1) {
        x += tileWidth / 2;
    }
    int y = row * tileHeight;
    return {(float) x, (float) y};
}

void BubbleGridManager::findCluster(int xGrid, int yGrid, BubbleColor type) {
    if (xGrid < 0 || xGrid >= columns || yGrid >= rows || yGrid < 0) return;
    BubbleColor targetBubble = bubbleArray[xGrid][yGrid];
    if (!toProcess[xGrid][yGrid] || targetBubble != type || targetBubble == BLANK) {
        return;
    } else {
        foundCluster.push_back({xGrid, yGrid});
        toProcess[xGrid][yGrid] = false;
        int tileRow = (yGrid + rowOffSet) % 2;
        for (int i = 0; i < 6; i++) {
            findCluster(xGrid + neighborsOffsets[tileRow][i].x, yGrid + neighborsOffsets[tileRow][i].y,
                        type);
        }
    }
}

void BubbleGridManager::findFloatingCluster() {
    resetSnappingBubbleContainers();
    for (int i = 0; i < columns; i++) {
        recursivelyFindFloatingCluster(i, 0);
    }
    bool isFloating[columns][rows];
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            isFloating[i][j] = true;
        }
    }
    for (auto &i: foundCluster) {
        isFloating[i.x][i.y] = false;
    }
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            if (bubbleArray[i][j] == BLANK) continue;
            else if (isFloating[i][j]) bubbleArray[i][j] = BLANK;
        }
    }
}

void BubbleGridManager::recursivelyFindFloatingCluster(int xGrid, int yGrid) {
    if (xGrid < 0 || xGrid >= columns || yGrid >= rows || yGrid < 0) return;
    BubbleColor targetBubble = bubbleArray[xGrid][yGrid];

    if (!toProcess[xGrid][yGrid] || targetBubble == BLANK) {
        return;
    } else {
        foundCluster.push_back({xGrid, yGrid});
        toProcess[xGrid][yGrid] = false;
        int tileRow = (yGrid + rowOffSet) % 2;
        for (int i = 0; i < 6; i++) {
            recursivelyFindFloatingCluster(xGrid + neighborsOffsets[tileRow][i].x,
                                           yGrid + neighborsOffsets[tileRow][i].y);
        }
    }
}

void BubbleGridManager::addBubbles() {
    rowOffSet = (rowOffSet + 1) % 2;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            bubbleArray[i][rows - 1 - j] = bubbleArray[i][rows - 1 - j - 1];
        }
    }

    for (int i = 0; i < columns; i++) {
        bubbleArray[i][0] = RandomBubbleColorGenerator::generateRandomBubbleColor();
    }
}

BubbleColor BubbleGridManager::getExistingColors() {
    BubbleColor color;
    std::vector<BubbleColor> existingColors = findExistingColors();
    //color = existingColor.at(Math.random(existingColor.length());
    return color;
}

std::vector<BubbleColor> BubbleGridManager::findExistingColors() {

}
