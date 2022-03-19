#ifndef BUBBLESHOOTER_GAME_H
#define BUBBLESHOOTER_GAME_H

#include <SDL.h>
#include "Bubble.h"
#include "Arrow.h"
#include "TextureAlpha.h"
#include "Cannon.h"
#include "ScreenSizeCarrier.h"
#include "BubbleManager.h"
#include <list>
#include <cmath>
#include <memory>

class Game {
public:

    void start();

    const static int tileWidth = 40;
    const static int tileHeight = 40;
    const static int columns = 10;
    const static int rows = 5;
    int bubbleArray[columns][rows];

    Point getBubbleCoordinate(int column, int row) {
        int xCoordinate = column * tileWidth;
        if (row % 2 == 1) {
            xCoordinate += tileWidth / 2;
        }
        int yCoordinate = row * tileHeight;
        return Point((float) xCoordinate, (float) yCoordinate);
    }

    void renderBubbles() {
        for (int j = 0; j < rows; j++) {
            for (int i = 0; i < columns; i++) {
                int bubbleType = bubbleArray[i][j];
                Point bubbleCoordinate = getBubbleCoordinate(i, j);
                drawBubble(bubbleCoordinate.x, bubbleCoordinate.y, bubbleType);
            }
        }
    }

    void drawBubble(float x, float y, int type) {

    }


private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Cannon *cannon;
    bool running;
    SDL_Point mousePosition;


    void initialize();

    void gameLoop();

    void processInput();

    void updateObjects();

    void render();

    void clearScreen();

    void quit();

};


#endif //BUBBLESHOOTER_GAME_H
