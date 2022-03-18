#ifndef BUBBLESHOOTER_GAME_H
#define BUBBLESHOOTER_GAME_H

#include <SDL.h>
#include "Bubble.h"
#include "Arrow.h"
#include "TextureAlpha.h"
#include "Cannon.h"
#include "ScreenSizeCarrier.h"
#include <list>
#include <cmath>

class Game {
public:
    void start() {
        initialize();
        gameLoop();
    }


private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::list<Bubble *> listOfBubbles;
    Cannon *cannon;
    bool running;
    SDL_Point mousePosition;


    void gameLoop();

    void initialize();

    void processInput();

    void updateObjects();

    void render();

    void clearScreen();

    void quit();

};


#endif //BUBBLESHOOTER_GAME_H
