//
// Created by giaol on 3/15/2022.
//


#ifndef BUBBLESHOOTER_GAME_H
#define BUBBLESHOOTER_GAME_H

#include <SDL.h>

class Game {
public:

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    Game() = default;

    void start() {
        initialize();
        gameLoop();
    }


private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    bool running{};

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
    }

    void processInput() {
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                quit();
            }
        }

    }

    void updateObjects() {

    }

    void render() {
        clearScreen();
        SDL_RenderPresent(renderer);
    }

    void clearScreen() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }

    void quit() {
        running = false;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        window = nullptr;
        SDL_Quit();
    }
};


#endif //BUBBLESHOOTER_GAME_H
