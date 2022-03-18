#ifndef BUBBLESHOOTER_GAME_H
#define BUBBLESHOOTER_GAME_H

#include <SDL.h>
#include "Bubble.h"
#include "Arrow.h"
#include "TextureAlpha.h"
#include "Cannon.h"
#include "ScreenSizeCarrier.h"
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
    Cannon *cannon;
    bool running;
    SDL_Point mousePosition;
    float bubbleSpeedX, bubbleSpeedY;


    void gameLoop() {
        running = true;
        while (running) {
            processInput();
            updateObjects();
            render();
        }
    }


    void initialize() {
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow("Bubble Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        cannon = new Cannon(renderer);
    }

    void processInput() {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit();
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
                        cannon->getLoadedBubble()->setMoving(true);
                        bubbleSpeedX = 0.1f * std::cos(Utility::toRadians(cannon->getAngle()));
                        bubbleSpeedY = 0.1f * std::sin(Utility::toRadians(cannon->getAngle()));
                }
            }
            if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
                SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
            }
        }
    }

    void updateObjects() {
        Arrow *arrow = cannon->getArrow();
        Bubble *bubble = cannon->getLoadedBubble();
        float dx = (float) mousePosition.x - arrow->getTailPoint().x;
        float dy = (float) mousePosition.y - arrow->getTailPoint().y;
        float angle = std::atan(dy / dx);
        angle = Utility::toDegrees(angle);
        if (angle < 0) angle += 180;
        cannon->setAngle(Utility::clamp(angle, 10, 170));


        if (bubble->getX() < 20 ||
            bubble->getX() > (float) SCREEN_WIDTH - bubble->getWidth() / 2)
            bubbleSpeedX = -bubbleSpeedX;
        if (bubble->getY() < 20) {
            bubble->setMoving(false);
        }
        if (bubble->isMoving()) {
            bubble->setX(bubble->getX() - bubbleSpeedX);
            bubble->setY(bubble->getY() - bubbleSpeedY);
        }
    }

    void render() {
        clearScreen();
        cannon->getLoadedBubble()->getBubbleTexture().renderCenter(renderer, (int) cannon->getLoadedBubble()->getX(),
                                                                   (int) cannon->getLoadedBubble()->getY(), nullptr);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, (int) cannon->getArrow()->getTailPoint().x,
                           (int) cannon->getArrow()->getTailPoint().y,
                           (int) cannon->getArrow()->getHeadPoint().x,
                           (int) cannon->getArrow()->getHeadPoint().y);
        SDL_RenderPresent(renderer);
    }

    void clearScreen() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }

    void quit() {
        running = false;
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
        SDL_DestroyWindow(window);
        window = nullptr;
        SDL_Quit();
    }

};


#endif //BUBBLESHOOTER_GAME_H
