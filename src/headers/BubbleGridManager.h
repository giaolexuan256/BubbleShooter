#ifndef BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
#define BUBBLESHOOTER_BUBBLEGRIDMANAGER_H

#include "BubbleColor.h"
#include "TextureAlpha.h"
#include "Point.h"
#include "RandomBubbleColorGenerator.h"
#include "Utility.h"
#include "Bubble.h"
#include <cstdio>
#include <vector>
#include <memory>
#include <cmath>
#include <iostream>

class BubbleGridManager {
public:
    const static int tileWidth = 40;
    const static int tileHeight = 40;
    const static int columns = 15;
    const static int rows = 8;
    const float radius = 20.0f;
    BubbleColor bubbleArray[columns][rows];
    bool toProcess[columns][rows];
    std::vector<SDL_Point> foundCluster;
    SDL_Point neighborsOffsets[2][6] = {
            {{1, 0}, {0, 1}, {-1, 1}, {-1, -1}, {0, -1}, {-1, 0}},
            {{1, 0}, {1, 1}, {0,  1}, {-1, 0},  {0, -1}, {1,  -1}}
    };

    explicit BubbleGridManager();

    void initializeBubbleArray();

    static Point getBubbleCoordinate(int column, int row) {
        int x = column * tileWidth;
        if (row % 2 == 1) {
            x += tileWidth / 2;
        }
        int y = row * tileHeight;
        return {(float) x, (float) y};
    }

    void renderAllBubbles(SDL_Renderer *renderer, std::vector<std::shared_ptr<TextureAlpha>> bubbleTextures) {
        for (int j = 0; j < rows; j++) {
            for (int i = 0; i < columns; i++) {
                Point bubbleCoordinate = getBubbleCoordinate(i, j);
                renderBubble(bubbleCoordinate.x, bubbleCoordinate.y, bubbleArray[i][j],
                             bubbleTextures, renderer);
            }
        }
    }

    bool isCannonBubbleCollideWithBubbleArray(std::shared_ptr<Bubble> &cannonBubble) {
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

    bool isBubbleArrayCleared() {
        for (auto &i: bubbleArray) {
            if (i[0] != BLANK) return false;
        }
        return true;
    }

    void resetProcess() {
        clearToProcessArray();
        foundCluster.clear();
    }

    void clearToProcessArray() {
        for (int i = 0; i < columns; i++) {
            for (int j = 0; j < rows; j++) {
                toProcess[i][j] = true;
            }
        }
    }


    static SDL_Point getGridPosition(const std::shared_ptr<Bubble> &bubble) {
        float x = bubble->getX();
        float y = bubble->getY();
        int yGrid = round((y / tileHeight));
        int xOffset = 0;
        if (yGrid % 2 == 1) {
            xOffset = tileWidth / 2;
        }
        int xGrid = round((x - (float) xOffset) / tileWidth);

        return {xGrid, yGrid};
    }

    void findCluster(int xGrid, int yGrid, BubbleColor type) {
        if (xGrid < 0 || xGrid >= columns || yGrid >= rows || yGrid < 0) return;
        BubbleColor targetBubble = bubbleArray[xGrid][yGrid];
        if (!toProcess[xGrid][yGrid] || targetBubble != type || targetBubble == BLANK) {
            return;
        } else {
            foundCluster.push_back({xGrid, yGrid});
            toProcess[xGrid][yGrid] = false;
            int tileRow = yGrid % 2;
            for (int i = 0; i < 6; i++) {
                findCluster(xGrid + neighborsOffsets[tileRow][i].x, yGrid + neighborsOffsets[tileRow][i].y,
                            type);
            }
        }
    }

    void findFloatingCluster() {
        resetProcess();
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

    void recursivelyFindFloatingCluster(int xGrid, int yGrid) {
        if (xGrid < 0 || xGrid >= columns || yGrid >= rows || yGrid < 0) return;
        BubbleColor targetBubble = bubbleArray[xGrid][yGrid];

        if (!toProcess[xGrid][yGrid] || targetBubble == BLANK) {
            return;
        } else {
            foundCluster.push_back({xGrid, yGrid});
            toProcess[xGrid][yGrid] = false;
            int tileRow = yGrid % 2;
            for (int i = 0; i < 6; i++) {
                recursivelyFindFloatingCluster(xGrid + neighborsOffsets[tileRow][i].x,
                                               yGrid + neighborsOffsets[tileRow][i].y);
            }
        }
    }


private:

    const int startingRows = 4;

    static void
    renderBubble(float x, float y, BubbleColor color, std::vector<std::shared_ptr<TextureAlpha>> &bubbleTextures,
                 SDL_Renderer *renderer) {
        if (color == BLANK) return;
        bubbleTextures[color]->render(renderer, (int) x, (int) y);
    }
};


#endif //BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
