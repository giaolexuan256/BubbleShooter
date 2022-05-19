
#ifndef BUBBLESHOOTER_GAMETEXTUREHANDLER_H
#define BUBBLESHOOTER_GAMETEXTUREHANDLER_H

#include "TextureAlpha.h"
#include <memory>
#include "ScreenSizeCarrier.h"
#include "ScreenClearer.h"
#include "Color.h"

class GameTextureHandler {
public:

    SDL_Renderer* renderer;
    TTF_Font* font;
    std::shared_ptr<TextureAlpha> winMessage;
    std::shared_ptr<TextureAlpha> loseMessage;
    std::unique_ptr<TextureAlpha> background;
    std::unique_ptr<TextureAlpha> scoreTexture;

    GameTextureHandler(SDL_Renderer *renderer);

    void displayWinMessage();
    void displayLoseMessage();
    void displayPlayerScore(unsigned int score);

};


#endif //BUBBLESHOOTER_GAMETEXTUREHANDLER_H
