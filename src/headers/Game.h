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
#include "RandomBubbleColorGenerator.h"
#include "BubbleTextureHandler.h"
#include "BubbleGridManager.h"
#include <vector>
#include <algorithm>
#include <SDL_ttf.h>


class Game {
public:
    std::vector<std::shared_ptr<TextureAlpha>> bubbleTextures;
    void start();
private:
    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Cannon *cannon;
    SDL_Point mousePosition;
    std::shared_ptr<BubbleGridManager> bubbleGridManager;
    TTF_Font *font;
    std::shared_ptr<TextureAlpha> youWinMessage;
    int turnCounter;

    const int TURNS_TO_ADD_BUBBLES = 1;

    void initialize();

    void initializeBubbleTextures();

    void initializeYouWinMessage();

    void initializeTTFFont();

    void gameLoop(double delta);

    void processInput(double delta);

    void updateObjects();

    bool checkGameOver();

    bool isGameOver();

    void updateTurnCounterAndCheckToAddBubbles();

    void snapBubble();

    void render();

    void clearScreen();

    void quit();

};


#endif //BUBBLESHOOTER_GAME_H
