#include "BubbleGridManager.h"

BubbleGridManager::BubbleGridManager() {
    initialize();
}

void BubbleGridManager::initialize() {
    rowOffSet = 0;
    initializeBubbleArray();
    clearToProcessArray();
    numberOfBubblesDestroyedInATurn = 0;
}

void BubbleGridManager::initializeBubbleArray() {
    rowOffSet = 0;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            if (j >= startingRows) bubbleArray[i][j] = BLANK;
            else bubbleArray[i][j] = RandomBubbleColorGenerator::generateRandomBubbleColor();
        }
    }
}

void
BubbleGridManager::renderAllBubbles(SDL_Renderer *renderer, std::vector<std::shared_ptr<TextureAlpha>> bubbleTextures) {
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
            Point bubbleCoordinate = getBubbleCoordinate(i, j);
            renderBubble(bubbleCoordinate.x, bubbleCoordinate.y, bubbleArray[i][j],
                         bubbleTextures, renderer);
        }
    }
}

void BubbleGridManager::renderBubble(float x, float y, BubbleColor color,
                                     std::vector<std::shared_ptr<TextureAlpha>> &bubbleTextures,
                                     SDL_Renderer *renderer) {
    if (color == BLANK) return;
    bubbleTextures[color]->render(renderer, (int) x, (int) y);
}

bool BubbleGridManager::isCannonBubbleCollideWithBubbleArray(std::shared_ptr<CannonBubble> &cannonBubble) {
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

void BubbleGridManager::snapCannonBubble(const std::shared_ptr<CannonBubble> &cannonBubble) {
    numberOfBubblesDestroyedInATurn = 0;
    SDL_Point gridPosition = getGridPosition(cannonBubble);
    bubbleArray[gridPosition.x][gridPosition.y] = cannonBubble->getType();
    findAndDestroyBubbleCluster(gridPosition.x, gridPosition.y, cannonBubble->getType());
}

void BubbleGridManager::findAndDestroyBubbleCluster(int xGrid, int yGrid, BubbleColor type) {
    clearSnappingBubbleContainers();
    findBubbleCluster(xGrid, yGrid, type);
    if (foundCluster.size() >= 3) {
        destroyAllBubblesInCluster();
        findAndDestroyFloatingCluster();
    }
}

void BubbleGridManager::destroyAllBubblesInCluster() {
    for (auto &i: foundCluster) {
        bubbleArray[i.x][i.y] = BLANK;
    }
    numberOfBubblesDestroyedInATurn += foundCluster.size();
}

void BubbleGridManager::clearToProcessArray() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            toProcess[i][j] = true;
        }
    }
}

void BubbleGridManager::findAndDestroyFloatingCluster() {
    clearSnappingBubbleContainers();
    findFloatingClusterRecursivelyFromFirstRow();
    std::vector<std::vector<bool>> isFloating(columns, std::vector<bool>(rows, true));
    for (auto &i: foundCluster) {
        isFloating[i.x][i.y] = false;
    }
    destroyAllFloatingBubbles(isFloating);
}

void BubbleGridManager::clearSnappingBubbleContainers() {
    clearToProcessArray();
    foundCluster.clear();
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

SDL_Point BubbleGridManager::getGridPosition(const std::shared_ptr<CannonBubble> &bubble) {
    float x = bubble->position.x;
    float y = bubble->position.y;
    int yGrid = (int) std::round((y / tileHeight));
    int xOffset = 0;
    if ((yGrid + rowOffSet) % 2 == 1) {
        xOffset = tileWidth / 2;
    }
    int xGrid = (int) std::round((x - (float) xOffset) / tileWidth);

    return {xGrid, yGrid};
}

Point BubbleGridManager::getBubbleCoordinate(int column, int row) const {
    int x = column * tileWidth;
    if ((row + rowOffSet) % 2 == 1) {
        x += tileWidth / 2;
    }
    int y = row * tileHeight;
    return {(float) x, (float) y};
}

void BubbleGridManager::findBubbleCluster(int xGrid, int yGrid, BubbleColor type) {
    if (xGrid < 0 || xGrid >= columns || yGrid >= rows || yGrid < 0) return;
    BubbleColor targetBubble = bubbleArray[xGrid][yGrid];
    if (!toProcess[xGrid][yGrid] || targetBubble != type || targetBubble == BLANK) {
        return;
    } else {
        foundCluster.push_back({xGrid, yGrid});
        toProcess[xGrid][yGrid] = false;
        int tileRow = (yGrid + rowOffSet) % 2;
        for (int i = 0; i < 6; i++) {
            findBubbleCluster(xGrid + neighborsOffsets[tileRow][i].x, yGrid + neighborsOffsets[tileRow][i].y,
                              type);
        }
    }
}

void BubbleGridManager::findFloatingClusterRecursivelyFromFirstRow() {
    for (int i = 0; i < columns; i++) {
        findFloatingClusterRecursively(i, 0);
    }
}

void BubbleGridManager::findFloatingClusterRecursively(int xGrid, int yGrid) {
    if (xGrid < 0 || xGrid >= columns || yGrid >= rows || yGrid < 0) return;
    BubbleColor targetBubble = bubbleArray[xGrid][yGrid];

    if (!toProcess[xGrid][yGrid] || targetBubble == BLANK) {
        return;
    } else {
        foundCluster.push_back({xGrid, yGrid});
        toProcess[xGrid][yGrid] = false;
        int tileRow = (yGrid + rowOffSet) % 2;
        for (int i = 0; i < 6; i++) {
            findFloatingClusterRecursively(xGrid + neighborsOffsets[tileRow][i].x,
                                           yGrid + neighborsOffsets[tileRow][i].y);
        }
    }
}

void BubbleGridManager::destroyAllFloatingBubbles(std::vector<std::vector<bool>> &isFloating) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            if (bubbleArray[i][j] == BLANK) continue;
            else if (isFloating[i][j]) {
                bubbleArray[i][j] = BLANK;
                numberOfBubblesDestroyedInATurn++;
            }
        }
    }
}

void BubbleGridManager::addBubblesToFirstRow() {
    rowOffSet = (rowOffSet + 1) % 2;
    moveAllBubblesDownALine();
    generateBubblesOnFirstRow();
}

void BubbleGridManager::moveAllBubblesDownALine() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            bubbleArray[i][rows - 1 - j] = bubbleArray[i][rows - 1 - j - 1];
        }
    }
}

void BubbleGridManager::generateBubblesOnFirstRow() {
    for (int i = 0; i < columns; i++) {
        bubbleArray[i][0] = getAnExistingColor();
    }
}

BubbleColor BubbleGridManager::getAnExistingColor() {
    std::vector<BubbleColor> existingColors = findExistingColors();
    return existingColors[RandomNumberGenerator::generateRandomInteger(0, (int) existingColors.size() - 1)];
}

std::vector<BubbleColor> BubbleGridManager::findExistingColors() {
    std::vector<BubbleColor> existingColors;
    bool colorTable[TOTAL_COLORS] = {false};
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            if (bubbleArray[i][j] == BLANK) continue;
            int numberOfColor = BubbleColorConverter::toIntegerValue(bubbleArray[i][j]);
            if (colorTable[numberOfColor]) continue;
            colorTable[numberOfColor] = true;
            existingColors.push_back(bubbleArray[i][j]);
        }
    }
    return existingColors;
}
