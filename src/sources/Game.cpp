#include <iostream>
#include "../headers/Game.h"


void Game::start() {
    initialize();
    gameLoop();
}

void Game::gameLoop() {
    running = true;
    while (running) {
        processInput();
        updateObjects();
        render();
    }
}

void Game::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error Init Video\n");
    } else {
        window = SDL_CreateWindow("Bubble Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if (window != nullptr) {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            cannon = new Cannon(renderer);
        }
    }
}

void Game::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            quit();
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    if (!cannon->getLoadedBubble()->isMoving()) {
                        cannon->getLoadedBubble()->setMoving(true);
                        cannon->getLoadedBubble()->setSpeed(-0.1f * std::cos(Utility::toRadians(cannon->getAngle())),
                                                            0.1f * std::sin(Utility::toRadians(cannon->getAngle())));
                    }
            }
        }
        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
        }
    }
}

void Game::updateObjects() {
    cannon->setAngleToMousePosition(Point((float) mousePosition.x, (float) mousePosition.y));
    Bubble *cannonBubble = cannon->getLoadedBubble();
    if (cannonBubble->getX() < 0 ||
        cannonBubble->getX() > (float) SCREEN_WIDTH - cannonBubble->getWidth()) {
        cannonBubble->setSpeedX(-cannonBubble->getSpeedX());
    }
    if (cannonBubble->getY() < 0) {
        cannonBubble->setMoving(false);
        cannon->loadBubble(renderer);
    }
    if (cannonBubble->isMoving()) {
        cannonBubble->setX(cannonBubble->getX() - cannonBubble->getSpeedX());
        cannonBubble->setY(cannonBubble->getY() - cannonBubble->getSpeedY());
    }
}

void Game::render() {
    clearScreen();
    cannon->render(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Game::quit() {
    running = false;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}


