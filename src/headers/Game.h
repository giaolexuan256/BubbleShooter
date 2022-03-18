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
    void start() {
        initialize();
        gameLoop();
    }


private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Cannon *cannon;
    bool running;
    SDL_Point mousePosition;
    std::unique_ptr<BubbleManager> bubbleManager;



    void gameLoop();

    void initialize();

    void processInput();

    void updateObjects();

    void render();

    void clearScreen();

    void quit();

};


#endif //BUBBLESHOOTER_GAME_H
