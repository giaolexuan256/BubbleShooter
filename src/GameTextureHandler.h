#ifndef BUBBLESHOOTER_GAMETEXTUREHANDLER_H
#define BUBBLESHOOTER_GAMETEXTUREHANDLER_H


#include "TextureAlpha.h"
#include <memory>
#include "ScreenSizeCarrier.h"


class GameTextureHandler {
public:

    std::shared_ptr<TextureAlpha> winMessage;
    std::shared_ptr<TextureAlpha> loseMessage;
    std::unique_ptr<TextureAlpha> background;
    std::unique_ptr<TextureAlpha> score;

    GameTextureHandler(SDL_Renderer *renderer, TTF_Font *gameTextFont);

    void renderTotalScore(SDL_Renderer *renderer, TTF_Font *gameTextFont, unsigned int totalScore) const;
};


#endif //BUBBLESHOOTER_GAMETEXTUREHANDLER_H
