#ifndef BUBBLESHOOTER_CANNON_H
#define BUBBLESHOOTER_CANNON_H

#include "Arrow.h"
#include "Bubble.h"
#include "Game.h"


class Cannon {
public:
    Cannon(SDL_Renderer *renderer) : arrow(Point((float) Game::SCREEN_WIDTH / 2, Game::SCREEN_HEIGHT - 20), 200, 90) {
        loadedBubble.loadTexture(R"(C:\Dev\Projects\BubbleShooter\assets\RedBubble.jpg)", renderer);
        loadedBubble.setCenterPosition((float) Game::SCREEN_WIDTH / 2,
                                       Game::SCREEN_HEIGHT - loadedBubble.getBubbleTexture().getHeight() / 2);
    }

private:
    Arrow arrow;
    Bubble loadedBubble;
};


#endif //BUBBLESHOOTER_CANNON_H
