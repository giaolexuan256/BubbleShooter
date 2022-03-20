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


    const static int tileWidth = 40;
    const static int tileHeight = 40;
    const static int columns = 15;
    const static int rows = 5;
    int bubbleArray[columns][rows];

    void start();

    Point getBubbleCoordinate(int column, int row) {
        int x = column * tileWidth;
        if (row % 2 == 1) {
            x += tileWidth / 2;
        }
        int y = row * tileHeight;
        return Point((float) x, (float) y);
    }

    void renderAllBubbles() {
        for (int j = 0; j < rows; j++) {
            for (int i = 0; i < columns; i++) {
                Point bubbleCoordinate = getBubbleCoordinate(i, j);
                renderBubble(bubbleCoordinate.x, bubbleCoordinate.y, bubbleArray[i][j]);
            }
        }
    }

    void renderBubble(float x, float y, int type) {
        TextureAlpha bubbleTexture;

        bubbleTexture.loadFromFile(renderer, R"(C:\Dev\Projects\BubbleShooter\assets\BlueBubble.jpg)");
        bubbleTexture.render(renderer, (int) x, (int) y);

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
