#ifndef BUBBLESHOOTER_GAMETEXTUREHANDLER_H
#define BUBBLESHOOTER_GAMETEXTUREHANDLER_H


#include "TextureAlpha.h"
#include <memory>


class GameTextureHandler {
public:

    std::shared_ptr<TextureAlpha> winMessage;
    std::shared_ptr<TextureAlpha> loseMessage;
    std::unique_ptr<TextureAlpha> background;

    GameTextureHandler(SDL_Renderer *renderer, TTF_Font *gameTextFont);
};


#endif //BUBBLESHOOTER_GAMETEXTUREHANDLER_H
