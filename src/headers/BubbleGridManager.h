#ifndef BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
#define BUBBLESHOOTER_BUBBLEGRIDMANAGER_H

#include "BubbleColor.h"
#include "TextureAlpha.h"
#include "Point.h"
#include <vector>
#include <memory>
#include <cmath>

class BubbleGridManager {
public:
    const static int tileWidth = 40;
    const static int tileHeight = 40;
    const static int columns = 15;
    const static int rows = 8;
    const float radius = 20.0f;
    BubbleColor bubbleArray[columns][rows];
    std::vector<std::shared_ptr<TextureAlpha>> bubbleTextures;
    SDL_Renderer *renderer;

    const int PROCESSED = 1;
    const int NOT_PROCESSED = 0;
    std::vector<std::vector<int>> toProcess = std::vector<std::vector<int>>(columns,
                                                                            std::vector<int>(rows, NOT_PROCESSED));
    std::vector<SDL_Point> foundCluster;
    SDL_Point neighborsOffsets[2][6] = {
            {{1, 0}, {0, 1}, {-1, 1}, {-1, -1}, {0, -1}, {-1, 0}},
            {{1, 0}, {1, 1}, {0,  1}, {-1, 0},  {0, -1}, {1,  -1}}
    };

    BubbleGridManager(SDL_Renderer *renderer);

    Point getBubbleCoordinate(int column, int row) {
        int x = column * tileWidth;
        if (row % 2 == 1) {
            x += tileWidth / 2;
        }
        int y = row * tileHeight;
        return {(float) x, (float) y};
    }

    void renderAllBubbles() {
        for (int j = 0; j < rows; j++) {
            for (int i = 0; i < columns; i++) {
                Point bubbleCoordinate = getBubbleCoordinate(i, j);
                renderBubble(bubbleCoordinate.x, bubbleCoordinate.y, bubbleArray[i][j]);
            }
        }
    }

    void renderBubble(float x, float y, BubbleColor color) {
        if (color == BLANK) return;
        bubbleTextures[color]->render(renderer, (int) x, (int) y);
    }

    static SDL_Point getGridPosition(float x, float y) {
        int yGrid = round((y / tileHeight));
        int xOffset = 0;
        if (yGrid % 2 == 1) {
            xOffset = tileWidth / 2;
        }
        int xGrid = round((x - (float) xOffset) / tileWidth);

        return {xGrid, yGrid};
    }

    void recursiveFindCluster(int xGrid, int yGrid, BubbleColor type) {
        if (xGrid < 0 || xGrid >= columns || yGrid >= rows || yGrid < 0) return;
        BubbleColor targetBubble = bubbleArray[xGrid][yGrid];
        if (toProcess[xGrid][yGrid] == PROCESSED || targetBubble != type || targetBubble == BLANK) {
            return;
        } else {
            foundCluster.push_back({xGrid, yGrid});
            toProcess[xGrid][yGrid] = PROCESSED;
            int tileRow = yGrid % 2;
            for (int i = 0; i < 6; i++) {
                recursiveFindCluster(xGrid + neighborsOffsets[tileRow][i].x, yGrid + neighborsOffsets[tileRow][i].y,
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
        printf("%d\n", foundCluster.size());
        for (int i = 0; i < columns; i++) {
            for (int j = 0; j < rows; j++) {
                if (bubbleArray[i][j] == BLANK) continue;
                else if (isFloating[i][j]) bubbleArray[i][j] = BLANK;
            }
        }
    }

    void recursivelyFindFloatingCluster(int xGrid, int yGrid) {
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
        printf("%d\n", foundCluster.size());
        for (int i = 0; i < columns; i++) {
            for (int j = 0; j < rows; j++) {
                if (bubbleArray[i][j] == BLANK) continue;
                else if (isFloating[i][j]) bubbleArray[i][j] = BLANK;
            }
        }
    }

    void resetProcess() {
        for (int i = 0; i < toProcess.size(); i++) {
            for (int j = 0; j < toProcess[0].size(); j++) {
                toProcess[i][j] = NOT_PROCESSED;
            }
        }
        foundCluster.clear();
    }
};


#endif //BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
