#ifndef BUBBLESHOOTER_GAME_H
#define BUBBLESHOOTER_GAME_H

#include <SDL.h>
#include "TextureAlpha.h"
#include "Bubble.h"
#include "Arrow.h"
#include <cmath>

class Game {
public:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 640;

    void start() {
        initialize();
        gameLoop();
    }


private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Bubble bubble;
    Arrow *arrow;
    bool running;


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
        window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        bubble.loadTexture(R"(C:\Dev\Projects\BubbleShooter\assets\GreenBubble.png)", renderer);
        bubble.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT - bubble.getBubbleTexture().getHeight() / 2);
        arrow = new Arrow(Point(bubble.getX(), bubble.getY()), 50, 90);
    }

    void processInput() {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit();
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_a:
                        arrow->setAngle(arrow->getAngle() - 10);
                        break;
                    case SDLK_d:
                        arrow->setAngle(arrow->getAngle() + 10);
                        break;
                    case SDLK_SPACE:
                        bubble.setMoving(true);
                }
            }
        }
    }

    void updateObjects() {

    }

    void render() {
        clearScreen();
        bubble.getBubbleTexture().renderCenter(renderer, bubble.getX(), bubble.getY(), nullptr);
        if (bubble.isMoving()) {
            bubble.setX(bubble.getX() + cos(Utility::toRadians(arrow->getAngle())));
            bubble.setY(bubble.getY() - sin(Utility::toRadians(arrow->getAngle())));
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(renderer, arrow->getTailPoint().x, arrow->getTailPoint().y, arrow->getHeadPoint().x,
                               arrow->getHeadPoint().y);
        }
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
