#include "Game.h"

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
    if (initializeSDLPropertiesSuccessfully()) {
        initializeGameProperties();
    }
}

bool Game::initializeSDLPropertiesSuccessfully() {
    if (initializeSDLSubsystemsSuccessfully()) {
        if (initializeWindowSuccessfully()) {
            return true;
        }
    }
    return false;
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

void Game::initializeGameProperties() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    cannon = std::make_shared<Cannon>(renderer);
    initializeBubbleTextures();
    bubbleGridManager = std::make_shared<BubbleGridManager>();
    initializeTTFFont();
    initializeEndGameMessage();
    background = std::make_unique<TextureAlpha>();
    background->loadFromFile(renderer, R"(C:\Dev\Projects\CLion\BubbleShooter\assets\background.jpg)");
    turnCounter = 0;
    playerScore = 0;
}

void Game::initializeTTFFont() {
    if (TTF_Init() == -1) {
        printf("SDL_ttf couldn't initialize: TTF_GetError: %s\n", TTF_GetError());
    } else {
        gameTextFont = TTF_OpenFont(R"(C:\Dev\Projects\CLion\BubbleShooter\assets\VeraMoBd.ttf)", 28);
        if (gameTextFont == nullptr) {
            printf("Failed to load gameTextFont! SDL_ttf Error: %s\n", TTF_GetError());
        }
    }
}

void Game::initializeEndGameMessage() {
    initializeWinMessage();
    initializeLoseMessage();
}

void Game::initializeWinMessage() {
    winMessage = std::make_shared<TextureAlpha>();
    winMessage->loadFromRenderedText(renderer, gameTextFont, "Winner Winner Chicken Dinner!!!", SDL_Color{255, 255, 0, 255});
}

void Game::initializeLoseMessage() {
    loseMessage = std::make_shared<TextureAlpha>();
    loseMessage->loadFromRenderedText(renderer, gameTextFont, "You Lost =(", SDL_Color{255, 255, 0, 255});
}


void Game::initializeBubbleTextures() {
    for (int i = 0; i < BubbleColor::TOTAL_COLORS; i++) {
        bubbleTextures.push_back(std::make_shared<TextureAlpha>());
        bubbleTextures.back()->loadFromFile(renderer,
                                            BubbleColorConverter::getBubbleTexturePath(static_cast<BubbleColor>(i)));
    }
}

void Game::gameLoop(double delta) {
    processInput(delta);
    updateObjects();
    render();
}

void Game::processInput(double deltaTime) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        checkToQuit(event);
        checkToShootBubble(event, (float) deltaTime);
        updateMousePosition(event);
    }
}

void Game::checkToQuit(SDL_Event event) {
    if (event.type == SDL_QUIT) {
        quit();
    }
}

void Game::checkToShootBubble(SDL_Event event, float deltaTime) {
    if (event.key.keysym.sym == SDLK_SPACE) {
        shootCannonBubble((float) deltaTime);
    }
}

void Game::updateMousePosition(SDL_Event event) {
    if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
        SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    }
}

void Game::shootCannonBubble(float deltaTime) {
    if (!cannon->getLoadedBubble()->isMoving()) {
        cannon->getLoadedBubble()->setMoving(true);
        cannon->getLoadedBubble()->setSpeed(
                -Bubble::BUBBLE_SPEED * deltaTime * std::cos(Utility::degreesToRadians(cannon->getAngle())),
                Bubble::BUBBLE_SPEED * deltaTime * std::sin(Utility::degreesToRadians(cannon->getAngle())));
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
    playerScore += bubbleGridManager->numberOfBubblesDestroyedInATurn;
    checkGameOver();
    if (running) {
        cannon->loadBubble(renderer, bubbleGridManager->getAnExistingColor());
        updateTurnCounterAndCheckToAddBubbles();
    }
}

void Game::checkGameOver() {
    if (isGameOver()) {
        quit();
    }
}

bool Game::isGameOver() {
    if (bubbleGridManager->isBubbleArrayCleared()) {
        clearScreen();
        winMessage->render(renderer, SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2);
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
        return true;
    } else if (bubbleGridManager->isBubblesReachBottom()) {
        SDL_Delay(300);
        clearScreen();
        loseMessage->render(renderer, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2);
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
        return true;
    } else return false;
}

void Game::updateTurnCounterAndCheckToAddBubbles() {
    turnCounter++;
    if (turnCounter >= TURNS_TO_ADD_BUBBLES) {
        bubbleGridManager->addBubblesToFirstRow();
        resetTurnCounter();
    }
}

void Game::resetTurnCounter() {
    turnCounter = 0;
}

void Game::render() {
    clearScreen();
    renderObjects();
    SDL_RenderPresent(renderer);
}

void Game::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    background->render(renderer, 0, 0);
}

void Game::renderObjects() {
    cannon->render(renderer);
    bubbleGridManager->renderAllBubbles(renderer, bubbleTextures);
    drawBottomOfLevelLine();
    renderPlayerScore();
}

void Game::renderPlayerScore() {
    std::unique_ptr<TextureAlpha> playerScoreTexture = std::make_unique<TextureAlpha>();
    playerScoreTexture->loadFromRenderedText(renderer, gameTextFont, "Score: " + std::to_string(playerScore), SDL_Color{255, 255, 0, 255});
    playerScoreTexture->render(renderer, SCREEN_WIDTH / 8 * 5, SCREEN_HEIGHT / 8 * 7);
}

void Game::drawBottomOfLevelLine() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    int bottomOfTheLevelPosition = (bubbleGridManager->rows - 1) * bubbleGridManager->tileWidth;
    SDL_RenderDrawLine(renderer, 0, bottomOfTheLevelPosition, SCREEN_WIDTH, bottomOfTheLevelPosition);
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


