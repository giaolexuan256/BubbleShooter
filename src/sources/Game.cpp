#include "../headers/Game.h"

const int PROCESSED = 1;
const int NOT_PROCESSED = 0;
std::vector<std::vector<int>> toProcess(Game::columns, std::vector<int>(Game::rows, NOT_PROCESSED));
std::vector<SDL_Point> foundCluster;
SDL_Point neighborsOffsets[2][6] = {
        {{1, 0}, {0, 1}, {-1, 1}, {-1, -1}, {0, -1}, {-1, 0}},
        {{1, 0}, {1, 1}, {0,  1}, {-1, 0},  {0, -1}, {1,  -1}}
};

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
                    if (j >= 4) bubbleArray[i][j] = BLANK;
                    else bubbleArray[i][j] = RandomBubbleColorGenerator::generateRandomBubbleColor();
                }
            }
            initializeBubbleTextures();
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

void Game::updateObjects(double delta) {
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

    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            if (bubbleArray[i][j] == BLANK) continue;
            Point bubbleCoordinate = getBubbleCoordinate(i, j);
            if (Utility::circleIntersection(
                    {bubbleCoordinate.x + tileWidth / 2.0f, bubbleCoordinate.y + tileHeight / 2.0f},
                    radius, cannonBubble->getCenterPosition(), radius)) {
                cannonBubble->setMoving(false);
                snapBubble();
                return;
            }
        }
    }
}

void Game::snapBubble() {
    SDL_Point gridPosition = getGridPosition(cannon->getLoadedBubble()->getX(), cannon->getLoadedBubble()->getY());
    bubbleArray[gridPosition.x][gridPosition.y] = cannon->getLoadedBubble()->getType();
    recursiveFindCluster(gridPosition.x, gridPosition.y, cannon->getLoadedBubble()->getType());
    if (foundCluster.size() >= 3) {
        for (auto &i: foundCluster) {
            bubbleArray[i.x][i.y] = BLANK;
        }
    }
    if (isGameOver()) { quit(); }
    resetProcess();
    cannon->loadBubble(renderer);
}

bool Game::isGameOver() {
    for (int i = 0; i < columns; i++) {
        if (bubbleArray[i][0] != BLANK) return false;
    }
    return true;
}

SDL_Point Game::getGridPosition(float x, float y) {
    int yGrid = round((y / tileHeight));
    int xOffset = 0;
    if (yGrid % 2 == 1) {
        xOffset = tileWidth / 2;
    }
    int xGrid = round((x - (float) xOffset) / tileWidth);

    return {xGrid, yGrid};
}

void Game::recursiveFindCluster(int xGrid, int yGrid, BubbleColor type) {
    if (xGrid < 0 || xGrid >= columns || yGrid >= rows || yGrid < 0) return;
    BubbleColor targetBubble = bubbleArray[xGrid][yGrid];
    if (toProcess[xGrid][yGrid] == PROCESSED || targetBubble != type || targetBubble == BLANK) {
        return;
    } else {
        foundCluster.push_back({xGrid, yGrid});
        toProcess[xGrid][yGrid] = PROCESSED;
        int tileRow = yGrid % 2;
        for (int i = 0; i < 6; i++) {
            recursiveFindCluster(xGrid + neighborsOffsets[tileRow][i].x, yGrid + neighborsOffsets[tileRow][i].y, type);
        }
    }
}

void Game::resetProcess() {
    for (int i = 0; i < toProcess.size(); i++) {
        for (int j = 0; j < toProcess[0].size(); j++) {
            toProcess[i][j] = NOT_PROCESSED;
        }
    }
    foundCluster.clear();
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

void Game::quit() {
    running = false;
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}


