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
    initializeTTFFont();
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    playerScore = 0;
    gameTextureHandler = std::make_unique<GameTextureHandler>(renderer, gameTextFont);
    backgroundMusic = Mix_LoadMUS("assets/backgroundMusic.flac");
    Mix_PlayMusic(backgroundMusic, -1);
    bubbleShootingSound = Mix_LoadWAV("assets/bubbleShootingSound.wav");
    bubblePopSound = Mix_LoadWAV("assets/bubblePop.wav");
    inputHandler = std::make_unique<InputHandler>();
    timeCounter = 0;
}

void Game::initializeTTFFont() {
    if (TTF_Init() == -1) {
        printf("SDL_ttf couldn't initialize: TTF_GetError: %s\n", TTF_GetError());
    } else {
        gameTextFont = TTF_OpenFont("assets/VeraMoBd.ttf", 28);
        if (gameTextFont == nullptr) {
            printf("Failed to load gameTextFont! SDL_ttf Error: %s\n", TTF_GetError());
        }
    }
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
        displayWinMessage();
        return true;
    } else if (bubbleGridManager->isBubblesReachBottom()) {
        displayLoseMessage();
        return true;
    }
    return false;
}

void Game::displayLoseMessage() {
    SDL_Delay(300);
    clearScreen();
    gameTextureHandler->renderTotalScore(renderer, gameTextFont, playerScore);
    gameTextureHandler->loseMessage->render(renderer, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
}

void Game::displayWinMessage() {
    clearScreen();
    gameTextureHandler->winMessage->render(renderer, SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
}

void Game::render() {
    clearScreen();
    gameTextureHandler->background->render(renderer, 0, 0);
    renderObjects();
    SDL_RenderPresent(renderer);
}

void Game::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Game::renderObjects() {
    cannon->render(renderer);
    bubbleGridManager->renderAllBubbles(renderer, bubbleTextures);
    renderBottomLevelLine();
    renderPlayerScore();
}

void Game::renderPlayerScore() {
    std::unique_ptr<TextureAlpha> playerScoreTexture = std::make_unique<TextureAlpha>();
    playerScoreTexture->loadFromRenderedText(renderer, gameTextFont, "Score: " + std::to_string(playerScore),
                                             SDL_Color{255, 255, 0, 255});
    playerScoreTexture->render(renderer, SCREEN_WIDTH / 8 * 5, SCREEN_HEIGHT / 8 * 7);
}

void Game::renderBottomLevelLine() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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
    TTF_CloseFont(gameTextFont);
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}


