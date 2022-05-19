#include "GameTextureHandler.h"

GameTextureHandler::GameTextureHandler(SDL_Renderer *renderer) {
    GameTextureHandler::renderer = renderer;
    if (TTF_Init() == -1) {
        printf("SDL_ttf couldn't initialize: TTF_GetError: %s\n", TTF_GetError());
    } else {
        font = TTF_OpenFont("assets/VeraMoBd.ttf", 28);
        if (font == nullptr) {
            printf("Failed to load gameTextFont! SDL_ttf Error: %s\n", TTF_GetError());
        }
    }

    winMessage = std::make_shared<TextureAlpha>();
    winMessage->loadFromRenderedText(renderer, font, "Winner Winner Chicken Dinner!!!",
                                     COLOR_YELLOW);

    loseMessage = std::make_shared<TextureAlpha>();
    loseMessage->loadFromRenderedText(renderer, font, "You Lost =(", COLOR_YELLOW);

    background = std::make_unique<TextureAlpha>();
    background->loadFromFile(renderer, "assets/background.jpg");

    scoreTexture = std::make_unique<TextureAlpha>();
}

void GameTextureHandler::displayWinMessage() {
    ScreenClearer::clearScreen(renderer, COLOR_BLACK);
    winMessage->renderCenter(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}

void GameTextureHandler::displayLoseMessage() {
    ScreenClearer::clearScreen(renderer, COLOR_BLACK);
    loseMessage->renderCenter(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}

void GameTextureHandler::displayPlayerScore(unsigned int score) {
    scoreTexture->loadFromRenderedText(renderer, font, "Score: " + std::to_string(score), COLOR_YELLOW);
    scoreTexture->renderCenter(renderer, SCREEN_WIDTH - 100, SCREEN_HEIGHT - 50);
}

