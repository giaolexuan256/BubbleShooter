#include "../headers/Game.h"

void Game::start() {
    running = true;
    initialize();
    Uint32 currentTime = SDL_GetTicks();
    Uint32 lastTime = currentTime;
    Uint32 millisecondsPerFrame;
    while (running) {
        currentTime = SDL_GetTicks();
        millisecondsPerFrame = currentTime - lastTime;
        gameLoop(millisecondsPerFrame / 1.0E3);
        lastTime = currentTime;
    }
}

void Game::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("Error Init Video\n");
    } else {
        window = SDL_CreateWindow("Bubble Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if (window != nullptr) {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            cannon = new Cannon(renderer);
            initializeBubbleTextures();
            bubbleGridManager = std::make_shared<BubbleGridManager>();
        }
    }
}

void Game::initializeBubbleTextures() {
    for (int i = 0; i < BubbleColor::BUBBLE_COLOR_SIZE; i++) {
        bubbleTextures.push_back(std::make_shared<TextureAlpha>());
        bubbleTextures.back()->loadFromFile(renderer,
                                            BubbleTextureHandler::getBubbleTexturePath(static_cast<BubbleColor>(i)));
    }
}

void Game::gameLoop(double delta) {
    processInput(delta);
    updateObjects();
    render();
}

void Game::processInput(double delta) {
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
                        cannon->getLoadedBubble()->setSpeed(
                                -500 * delta * std::cos(Utility::degreesToRadians(cannon->getAngle())),
                                500 * delta * std::sin(Utility::degreesToRadians(cannon->getAngle())));
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
    std::shared_ptr<Bubble> cannonBubble = cannon->getLoadedBubble();
    if (cannonBubble->getX() < 0 ||
        cannonBubble->getX() > (float) SCREEN_WIDTH - cannonBubble->getWidth()) {
        cannonBubble->setSpeedX(-cannonBubble->getSpeedX());
    }
    if (cannonBubble->getY() < 0) {
        cannonBubble->setMoving(false);
        snapBubble();
        return;
    }
    if (cannonBubble->isMoving()) {
        cannonBubble->setX(cannonBubble->getX() - cannonBubble->getSpeedX());
        cannonBubble->setY(cannonBubble->getY() - cannonBubble->getSpeedY());
    }

    if (bubbleGridManager->isCannonBubbleCollideWithBubbleArray(cannonBubble)) {
        snapBubble();
    }
}

void Game::snapBubble() {
    SDL_Point gridPosition = bubbleGridManager->getGridPosition(cannon->getLoadedBubble());
    if (gridPosition.y >= BubbleGridManager::rows) {
        quit();
    }
    bubbleGridManager->bubbleArray[gridPosition.x][gridPosition.y] = cannon->getLoadedBubble()->getType();
    bubbleGridManager->findCluster(gridPosition.x, gridPosition.y, cannon->getLoadedBubble()->getType());
    if (bubbleGridManager->foundCluster.size() >= 3) {
        for (auto &i: bubbleGridManager->foundCluster) {
            bubbleGridManager->bubbleArray[i.x][i.y] = BLANK;
        }
    }
    if (isGameOver()) { quit(); }
    bubbleGridManager->findFloatingCluster();
    bubbleGridManager->resetSnappingBubbleContainers();
    cannon->loadBubble(renderer);
}

bool Game::isGameOver() {
    if (bubbleGridManager->isBubbleArrayCleared()) return true;
    else return false;
}


void Game::render() {
    clearScreen();
    cannon->render(renderer);
    bubbleGridManager->renderAllBubbles(renderer, bubbleTextures);
    SDL_RenderPresent(renderer);
}

void Game::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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


