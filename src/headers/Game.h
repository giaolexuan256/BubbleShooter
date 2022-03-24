#ifndef BUBBLESHOOTER_GAME_H
#define BUBBLESHOOTER_GAME_H

#include <SDL.h>
#include <iostream>
#include "Bubble.h"
#include "Arrow.h"
#include "TextureAlpha.h"
#include "Cannon.h"
#include "ScreenSizeCarrier.h"
#include <list>
#include <cmath>
#include <memory>
#include "Timer.h"
#include "BubbleColor.h"
#include "BubbleGridManager.h"
#include "RandomBubbleColorGenerator.h"
#include "BubbleTextureHandler.h"
#include <vector>


class Game {
public:
    const static int tileWidth = 40;
    const static int tileHeight = 40;
    const static int columns = 15;
    const static int rows = 8;
    const float radius = 20.0f;
    BubbleColor bubbleArray[columns][rows];
    std::vector<std::shared_ptr<TextureAlpha>> bubbleTextures;


    void start();

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

    static SDL_Point getGridPosition(float x, float y);


private:
    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Cannon *cannon;
    SDL_Point mousePosition;
    std::shared_ptr<BubbleGridManager> bubbleGridManager;


    void initialize();

    void initializeBubbleTextures();

    void gameLoop(double delta);

    void processInput(double delta);

    void updateObjects(double delta);

    bool isGameOver();

    void snapBubble();

    void recursiveFindCluster(int xGrid, int yGrid, BubbleColor type);

    void resetProcess();

    void render();

    void clearScreen();

    void quit();

};


#endif //BUBBLESHOOTER_GAME_H
