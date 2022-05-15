#include "GameTextureHandler.h"

GameTextureHandler::GameTextureHandler(SDL_Renderer *renderer, TTF_Font *gameTextFont) {
    winMessage = std::make_shared<TextureAlpha>();
    winMessage->loadFromRenderedText(renderer, gameTextFont, "Winner Winner Chicken Dinner!!!",
                                     SDL_Color{255, 255, 0, 255});

    loseMessage = std::make_shared<TextureAlpha>();
    loseMessage->loadFromRenderedText(renderer, gameTextFont, "You Lost =(", SDL_Color{255, 255, 0, 255});

    background = std::make_unique<TextureAlpha>();
    background->loadFromFile(renderer, R"(C:\Dev\Projects\CLion\BubbleShooter\assets\background.jpg)");

    score = std::make_unique<TextureAlpha>();
}

void GameTextureHandler::renderTotalScore(SDL_Renderer *renderer, TTF_Font *gameTextFont, unsigned int totalScore) const {
    score->loadFromRenderedText(renderer, gameTextFont, "Total Score: " + std::to_string(totalScore), SDL_Color{255, 255, 0});
    score->render(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 400);
}
