//
// Created by giaol on 3/17/2022.
//

#include "../headers/Cannon.h"

Cannon::Cannon(SDL_Renderer *renderer) {
    arrow = new Arrow(Point((float) SCREEN_WIDTH / 2, SCREEN_HEIGHT - 40), 200, 90);
    loadBubble(renderer);
}

void Cannon::loadBubble(SDL_Renderer *renderer) {
    loadedBubble = new Bubble(renderer);
    loadedBubble->setCenterPosition((float) SCREEN_WIDTH / 2 + loadedBubble->getBubbleTexture().getWidth() / 2,
                                    SCREEN_HEIGHT - loadedBubble->getBubbleTexture().getHeight() / 2);
}

void Cannon::render(SDL_Renderer *renderer) {
    loadedBubble->getBubbleTexture().renderCenter(renderer, (int) loadedBubble->getX(), (int) loadedBubble->getY());
}


Arrow *Cannon::getArrow() {
    return arrow;
}

Bubble *Cannon::getLoadedBubble() {
    return loadedBubble;
}

void Cannon::setAngle(float angleDegree) {
    arrow->setAngle(angleDegree);
}

float Cannon::getAngle() {
    return arrow->getAngle();
}

