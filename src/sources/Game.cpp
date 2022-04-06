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
    if (initializeSDLSubsystemsSuccessfully()) {
        if (initializeWindowSuccessfully()) {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            cannon = new Cannon(renderer);
            initializeBubbleTextures();
            bubbleGridManager = std::make_shared<BubbleGridManager>();
            initializeTTFFont();
            initializeWinMessage();
            turnCounter = 0;
        }
    }
}

bool Game::initializeSDLSubsystemsSuccessfully() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("Error Init Subsystems: %s", SDL_GetError());
        return false;
    } else { return true; }
}

bool Game::initializeWindowSuccessfully() {
    window = SDL_CreateWindow("Bubble Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Error Init Window: %s", SDL_GetError());
        return false;
    } else { return true; }
}

void Game::initializeTTFFont() {
    if (TTF_Init() == -1) {
        printf("SDL_ttf couldn't initialize: TTF_GetError: %s\n", TTF_GetError());
    } else {
        gameTextFont = TTF_OpenFont(R"(C:\Dev\Projects\BubbleShooter\assets\VeraMoBd.ttf)", 28);
        if (gameTextFont == nullptr) {
            printf("Failed to load lazy gameTextFont! SDL_ttf Error: %s\n", TTF_GetError());
        }
    }
}

void Game::initializeWinMessage() {
    winMessage = std::make_shared<TextureAlpha>();
    SDL_Color textColor{255, 255, 0, 255};
    std::string message = "Winner Winner Chicken Dinner!!!";
    winMessage->loadFromRenderedText(renderer, gameTextFont, message, textColor);

    loseMessage = std::make_shared<TextureAlpha>();
    message = "You Lost =)";
    loseMessage->loadFromRenderedText(renderer, gameTextFont, message, textColor);
}


void Game::initializeBubbleTextures() {
    for (int i = 0; i < BubbleColor::TOTAL_COLORS; i++) {
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
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit();
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    if (!cannon->getLoadedBubble()->isMoving()) {
                        cannon->getLoadedBubble()->setMoving(true);
                        cannon->getLoadedBubble()->setSpeed(
                                -Bubble::BUBBLE_SPEED * delta * std::cos(Utility::degreesToRadians(cannon->getAngle())),
                                Bubble::BUBBLE_SPEED * delta * std::sin(Utility::degreesToRadians(cannon->getAngle())));
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
    bubbleGridManager->snapCannonBubble(cannon->getLoadedBubble());
    checkGameOver();
    cannon->loadBubble(renderer, bubbleGridManager->getAnExistingColor());
    updateTurnCounterAndCheckToAddBubbles();
}

void Game::checkGameOver() {
    if (isGameOver()) {
        quit();
    }
}

bool Game::isGameOver() {
    if (bubbleGridManager->isBubbleArrayCleared() || bubbleGridManager->isBubblesReachBottom()) {
        return true;
    } else return false;
}

void Game::updateTurnCounterAndCheckToAddBubbles() {
    turnCounter++;
    if (turnCounter >= TURNS_TO_ADD_BUBBLES) {
        bubbleGridManager->addBubblesToFirstRow();
        turnCounter = 0;
    }
}

void Game::render() {
    clearScreen();
    cannon->render(renderer);
    bubbleGridManager->renderAllBubbles(renderer, bubbleTextures);
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
    TTF_CloseFont(gameTextFont);
    TTF_Quit();
}


