#include <iostream>
#include "../headers/Game.h"

void Game::gameLoop() {
    running = true;
    while (running) {
        processInput();
        updateObjects();
        render();
    }
}

void Game::initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Bubble Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    cannon = new Cannon(renderer);
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
                    cannon->getLoadedBubble()->setMoving(true);
                    cannon->getLoadedBubble()->setSpeed(0.1f * std::cos(Utility::toRadians(cannon->getAngle())),
                                                        0.1f * std::sin(Utility::toRadians(cannon->getAngle())));
            }
        }
        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
        }
    }
}

void Game::updateObjects() {
    Arrow *arrow = cannon->getArrow();
    Bubble *bubble = cannon->getLoadedBubble();
    float dx = (float) mousePosition.x - arrow->getTailPoint().x;
    float dy = arrow->getTailPoint().y - (float) mousePosition.y;
    float angle = std::atan2(dy, dx);
    angle = Utility::toDegrees(angle);
    if (angle < 0) angle += 360;
    if(angle > 90 && angle < 270) {
        if(angle > angleUpperBound) angle = angleUpperBound;
    } else {
        if(angle < angleLowerBound || angle >= 270) angle = angleLowerBound;
    }
    cannon->setAngle(Utility::clamp(angle, 10, 170));
    std::cout << angle << std::endl;


    if (bubble->getX() < bubble->getWidth() / 2 ||
        bubble->getX() > (float) SCREEN_WIDTH - bubble->getWidth() / 2) {
        bubble->setSpeedX(-bubble->getSpeedX());
    }
    if (bubble->getY() < bubble->getHeight() / 2) {
        bubble->setMoving(false);
        listOfBubbles.push_back(bubble);
        cannon->loadBubble(renderer);
    }
    if (bubble->isMoving()) {
        bubble->setX(bubble->getX() - bubble->getSpeedX());
        bubble->setY(bubble->getY() - bubble->getSpeedY());
    }
}

void Game::render() {
    clearScreen();
    cannon->render(renderer);
    for(auto bubble : listOfBubbles) {
        bubble->render(renderer, (int) bubble->getX(), (int) bubble->getY(), nullptr);
    }
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


