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
            for (int i = 0; i < columns; i++) {
                for (int j = 0; j < rows; j++) {
                    bubbleArray[i][j] = RED;
                }
            }
            initializeBubbleTextures(renderer);
        }
    }
}

void Game::initializeBubbleTextures(SDL_Renderer *renderer) {
    for (int i = 0; i < BubbleColor::BUBBLE_COLOR_SIZE; i++) {
        bubbleTextures.push_back(std::make_shared<TextureAlpha>());
        bubbleTextures.back()->loadFromFile(renderer, getBubbleTexturePath(static_cast<BubbleColor>(i)));
    }
}

std::string Game::getBubbleTexturePath(BubbleColor color) {
    return R"(C:\Dev\Projects\BubbleShooter\assets\)" + BubbleNameConverter::toString(color) + "Bubble.jpg";
}

void Game::gameLoop(double delta) {
    processInput(delta);
    updateObjects(delta);
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
                                -400 * delta * std::cos(Utility::degreesToRadians(cannon->getAngle())),
                                400 * delta * std::sin(Utility::degreesToRadians(cannon->getAngle())));
                    }
            }
        }
        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
        }
    }
}

void Game::updateObjects(double delta) {
    cannon->setAngleToMousePosition(Point((float) mousePosition.x, (float) mousePosition.y));
    std::shared_ptr<Bubble> cannonBubble = cannon->getLoadedBubble();
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
    renderAllBubbles();
    SDL_RenderPresent(renderer);
}

void Game::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Game::sleep(double sleepTime) {

}

void Game::quit() {
    running = false;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}


