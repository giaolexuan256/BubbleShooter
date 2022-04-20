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
    const static int rows = 14;
    const float radius = 20.0f;
    BubbleColor bubbleArray[columns][rows];
    bool toProcess[columns][rows];
    std::vector<SDL_Point> foundCluster;
    SDL_Point neighborsOffsets[2][6] = {
            {{1, 0}, {0, 1}, {-1, 1}, {-1, -1}, {0, -1}, {-1, 0}},
            {{1, 0}, {1, 1}, {0,  1}, {-1, 0},  {0, -1}, {1,  -1}}
    };

    unsigned int numberOfBubblesDestroyedInATurn;

    BubbleGridManager();

    void initialize();

    void initializeBubbleArray();

    void snapCannonBubble(const std::shared_ptr<Bubble>& cannonBubble);

    SDL_Point getGridPosition(const std::shared_ptr<Bubble> &bubble);

    void renderAllBubbles(SDL_Renderer *renderer, std::vector<std::shared_ptr<TextureAlpha>> bubbleTextures);

    Point getBubbleCoordinate(int column, int row) const;

    bool isCannonBubbleCollideWithBubbleArray(std::shared_ptr<Bubble> &cannonBubble);

    bool isBubbleArrayCleared();

    bool isBubblesReachBottom();

    void clearSnappingBubbleContainers();

    void clearToProcessArray();

    void findAndDestroyBubbleCluster(int xGrid, int yGrid, BubbleColor type);

    void findBubbleCluster(int xGrid, int yGrid, BubbleColor type);

    void destroyAllBubblesInCluster();

    void findAndDestroyFloatingCluster();

    void findFloatingClusterRecursivelyFromFirstRow();

    void findFloatingClusterRecursively(int xGrid, int yGrid);

    void destroyAllFloatingBubbles(std::vector<std::vector<bool>> &isFloating);

    void addBubblesToFirstRow();

    BubbleColor getAnExistingColor();

    std::vector<BubbleColor> findExistingColors();


private:

    const int startingRows = 6;
    int rowOffSet;
    static void renderBubble(float x, float y, BubbleColor color, std::vector<std::shared_ptr<TextureAlpha>> &bubbleTextures,
                             SDL_Renderer *renderer);
};


#endif //BUBBLESHOOTER_BUBBLEGRIDMANAGER_H
