#include "Game.h"

void Game::start() {
    initialize();
    timeHandler->startTimer();
    while (running) {
        timeHandler->calculateDeltaTime();
        gameLoop(timeHandler->getDeltaTime());
    }
}

void Game::initialize() {
    running = true;
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
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) < 0) {
        printf("Error Init Subsystems: %s", SDL_GetError());
        return false;
    } else { return true; }
}

bool Game::initializeWindowSuccessfully() {
    window = SDL_CreateWindow("CannonBubble Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Error Init Window: %s", SDL_GetError());
        return false;
    } else { return true; }
}

void Game::initializeGameProperties() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    timeHandler = std::make_unique<TimeHandler>();
    cannon = std::make_shared<Cannon>(renderer);
    initializeBubbleTextures();
    bubbleGridManager = std::make_shared<BubbleGridManager>();
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    playerScore = 0;
    gameTextureHandler = std::make_unique<GameTextureHandler>(renderer);
    backgroundMusic = Mix_LoadMUS("assets/backgroundMusic.flac");
    Mix_PlayMusic(backgroundMusic, -1);
    bubbleShootingSound = Mix_LoadWAV("assets/bubbleShootingSound.wav");
    bubblePopSound = Mix_LoadWAV("assets/bubblePop.wav");
    inputHandler = std::make_unique<InputHandler>();
    std::make_unique<ScreenClearer>();
    timeCounter = 0;
}

void Game::initializeBubbleTextures() {
    for (int i = 0; i < BubbleColor::TOTAL_COLORS; i++) {
        bubbleTextures.push_back(std::make_shared<TextureAlpha>());
        bubbleTextures.back()->loadFromFile(renderer,
                                            BubbleColorConverter::getBubbleTexturePath(static_cast<BubbleColor>(i)));
    }
}

void Game::gameLoop(float deltaTime) {
    processInput(deltaTime);
    updateObjects(deltaTime);
    render();
}

void Game::processInput(float deltaTime) {
    inputHandler->poll();
    if (inputHandler->unhandledEvent.type == SDL_QUIT) {
        quit();
    }
    if (inputHandler->keyDownOnce(SDLK_SPACE)) {
        shootCannonBubble(deltaTime);
    }
    mousePosition = inputHandler->getMousePosition();
}

void Game::shootCannonBubble(float deltaTime) {
    Mix_PlayChannel(-1, bubbleShootingSound, 0);
    if (!cannon->getLoadedBubble()->isMoving()) {
        cannon->getLoadedBubble()->setMoving(true);
        cannon->getLoadedBubble()->setSpeed(
                -CannonBubble::BUBBLE_SPEED * deltaTime * std::cos(Utility::degreesToRadians(cannon->getAngle())),
                CannonBubble::BUBBLE_SPEED * deltaTime * std::sin(Utility::degreesToRadians(cannon->getAngle())));
    }
}

void Game::updateObjects(float deltaTime) {
    timeCounter += deltaTime;
    if (timeCounter >= amountOfTimeToAddABubbleRow) {
        bubbleGridManager->addBubblesToFirstRow();
        timeCounter = 0;
    }
    cannon->setAngleToMousePosition(Point((float) mousePosition.x, (float) mousePosition.y));
    std::shared_ptr<CannonBubble> cannonBubble = cannon->getLoadedBubble();
    clampCannonBubblePosition(cannonBubble);
    if (bubbleGridManager->isCannonBubbleCollideWithBubbleArray(cannonBubble)) {
        processSnappedBubble();
    }
    checkGameOver();
}

void Game::clampCannonBubblePosition(const std::shared_ptr<CannonBubble> &cannonBubble) {
    if (cannonBubble->position.x<0 ||
                                 cannonBubble->position.x>(float)
        SCREEN_WIDTH - cannonBubble->getWidth()) {
        cannonBubble->setSpeedX(-cannonBubble->getSpeedX());
    }
    if (cannonBubble->position.y < 0) {
        cannonBubble->setMoving(false);
        processSnappedBubble();
        return;
    }
    if (cannonBubble->isMoving()) {
        cannonBubble->setX(cannonBubble->position.x - cannonBubble->getSpeedX());
        cannonBubble->setY(cannonBubble->position.y - cannonBubble->getSpeedY());
    }
}

void Game::processSnappedBubble() {
    bubbleGridManager->snapCannonBubble(cannon->getLoadedBubble());
    playerScore += bubbleGridManager->bubblesToDestroy.size();
    cannon->loadBubble(renderer, bubbleGridManager->getAnExistingColor());
    for (SDL_Point &bubblePosition: bubbleGridManager->bubblesToDestroy) {
        bubbleGridManager->bubbleArray[bubblePosition.x][bubblePosition.y] = BLANK;
        render();
        Mix_PlayChannel(-1, bubblePopSound, 0);
        SDL_Delay(100);
    }
    bubbleGridManager->bubblesToDestroy.clear();
}

void Game::checkGameOver() {
    if (isGameOver()) {
        quit();
    }
}

bool Game::isGameOver() {
    if (bubbleGridManager->isBubbleArrayCleared()) {
        gameTextureHandler->displayWinMessage();
        return true;
    } else if (bubbleGridManager->isBubblesReachBottom()) {
        gameTextureHandler->displayLoseMessage();
        return true;
    }
    return false;
}

void Game::render() {
    ScreenClearer::clearScreen(renderer, COLOR_BLACK);
    renderObjects();
    SDL_RenderPresent(renderer);
}

void Game::renderObjects() {
    cannon->render(renderer);
    bubbleGridManager->renderAllBubbles(renderer, bubbleTextures);
    renderBottomLevelLine();
    gameTextureHandler->displayPlayerScore(playerScore);
}

void Game::renderBottomLevelLine() {
    SDL_SetRenderDrawColor(renderer, COLOR_WHITE.r, COLOR_WHITE.g, COLOR_WHITE.b, COLOR_WHITE.a);
    int bottomOfTheLevelPosition = (bubbleGridManager->rows - 1) * bubbleGridManager->tileWidth;
    SDL_RenderDrawLine(renderer, 0, bottomOfTheLevelPosition, SCREEN_WIDTH, bottomOfTheLevelPosition);
}

void Game::quit() {
    running = false;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    Mix_FreeChunk(bubbleShootingSound);
    Mix_FreeMusic(backgroundMusic);
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}


