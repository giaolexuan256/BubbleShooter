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
#include "BubbleColorConverter.h"
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
    std::shared_ptr<Cannon> cannon;
    SDL_Point mousePosition;
    std::shared_ptr<BubbleGridManager> bubbleGridManager;
    TTF_Font *gameTextFont;
    int turnCounter;
    std::shared_ptr<TextureAlpha> winMessage;
    std::shared_ptr<TextureAlpha> loseMessage;

    const int TURNS_TO_ADD_BUBBLES = 7;

    unsigned int playerScore;

    void initialize();

    bool initializeSDLPropertiesSuccessfully();

    static bool initializeSDLSubsystemsSuccessfully();

    bool initializeWindowSuccessfully();

    void initializeGameProperties();

    void initializeTTFFont();

    void initializeBubbleTextures();

    void initializeEndGameMessage();

    void initializeWinMessage();

    void initializeLoseMessage();

    void gameLoop(double delta);

    void processInput(double deltaTime);

    void checkToQuit(SDL_Event event);

    void checkToShootBubble(SDL_Event event, float deltaTime);

    void updateMousePosition(SDL_Event event);

    void shootCannonBubble(float deltaTime);

    void updateObjects();

    void checkGameOver();

    bool isGameOver();

    void updateTurnCounterAndCheckToAddBubbles();

    void resetTurnCounter();

    void snapBubble();

    void render();

    void clearScreen();

    void renderObjects();

    void renderPlayerScore();

    void drawBottomOfLevelLine();

    void quit();

};


#endif //BUBBLESHOOTER_GAME_H
