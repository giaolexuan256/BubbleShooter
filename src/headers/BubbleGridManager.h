#ifndef BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
#define BUBBLESHOOTER_BUBBLEGRIDMANAGER_H

#include "BubbleColor.h"
#include "TextureAlpha.h"
#include "Point.h"
#include "RandomBubbleColorGenerator.h"
#include "Utility.h"
#include "Bubble.h"
#include <algorithm>
#include <cmath>
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
    const static int rows = 10;
    const float radius = 20.0f;
    BubbleColor bubbleArray[columns][rows];
    bool toProcess[columns][rows];
    std::vector<SDL_Point> foundCluster;
    SDL_Point neighborsOffsets[2][6] = {
            {{1, 0}, {0, 1}, {-1, 1}, {-1, -1}, {0, -1}, {-1, 0}},
            {{1, 0}, {1, 1}, {0,  1}, {-1, 0},  {0, -1}, {1,  -1}}
    };

    BubbleGridManager();

    void initialize();

    void initializeBubbleArray();

    void snapCannonBubble(const std::shared_ptr<Bubble>& cannonBubble);

    SDL_Point getGridPosition(const std::shared_ptr<Bubble> &bubble);

    void renderAllBubbles(SDL_Renderer *renderer, std::vector<std::shared_ptr<TextureAlpha>> bubbleTextures);

    Point getBubbleCoordinate(int column, int row);

    bool isCannonBubbleCollideWithBubbleArray(std::shared_ptr<Bubble> &cannonBubble);

    bool isBubbleArrayCleared();

    bool isBubblesReachBottom();

    void resetSnappingBubbleContainers();

    void clearToProcessArray();

    void destroyCluster(int xGrid, int yGrid, BubbleColor type);

    void findCluster(int xGrid, int yGrid, BubbleColor type);

    void findFloatingCluster();

    void recursivelyFindFloatingCluster(int xGrid, int yGrid);

    void addBubblesToFirstRow();

    BubbleColor getAnExistingColor();

    std::vector<BubbleColor> findExistingColors();


private:

    const int startingRows = 0;
    int rowOffSet;
    static void renderBubble(float x, float y, BubbleColor color, std::vector<std::shared_ptr<TextureAlpha>> &bubbleTextures,
                             SDL_Renderer *renderer);
};


#endif //BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
