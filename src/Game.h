#ifndef BUBBLESHOOTER_GAME_H
#define BUBBLESHOOTER_GAME_H

#include <SDL.h>
#include <iostream>
#include "CannonBubble.h"
#include "Arrow.h"
#include "TextureAlpha.h"
#include "Cannon.h"
#include "ScreenSizeCarrier.h"
#include <list>
#include <cmath>
#include <memory>
#include "BubbleColor.h"
#include "RandomBubbleColorGenerator.h"
#include "BubbleColorConverter.h"
#include "BubbleGridManager.h"
#include <vector>
#include <algorithm>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "TimeHandler.h"
#include "GameTextureHandler.h"
#include "InputHandler.h"


class Game {
public:
    std::vector<std::shared_ptr<TextureAlpha>> bubbleTextures;

    void start();

private:
    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::unique_ptr<TimeHandler> timeHandler;
    std::shared_ptr<Cannon> cannon;
    SDL_Point mousePosition;
    std::shared_ptr<BubbleGridManager> bubbleGridManager;
    TTF_Font *gameTextFont;
    Mix_Music *backgroundMusic;
    Mix_Chunk* bubbleShootingSound;
    std::unique_ptr<GameTextureHandler> gameTextureHandler;
    unsigned int playerScore;
    std::unique_ptr<InputHandler> inputHandler;
    float timeCounter;
    const float amountOfTimeToAddABubbleRow = 10;

    void initialize();

    bool initializeSDLPropertiesSuccessfully();

    static bool initializeSDLSubsystemsSuccessfully();

    bool initializeWindowSuccessfully();

    void initializeGameProperties();

    void initializeTTFFont();

    void initializeBubbleTextures();

    void gameLoop(float deltaTime);

    void processInput(float deltaTime);

    void shootCannonBubble(float deltaTime);

    void updateObjects(float deltaTime);

    void clampCannonBubblePosition(const std::shared_ptr<CannonBubble> &cannonBubble);

    void checkGameOver();

    bool isGameOver();

    void displayLoseMessage();

    void displayWinMessage();

    void updateTurnCounterAndCheckToAddBubbles();

    void snapBubble();

    void render();

    void clearScreen();

    void renderObjects();

    void renderPlayerScore();

    void renderBottomLevelLine();

    void quit();

};


#endif //BUBBLESHOOTER_GAME_H
