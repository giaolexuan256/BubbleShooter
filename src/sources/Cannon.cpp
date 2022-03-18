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
    arrow->render(renderer);
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

void Cannon::setAngleToMousePosition(Point mousePosition) {
    float dx = mousePosition.x - arrow->getTailPoint().x;
    float dy = arrow->getTailPoint().y - (float) mousePosition.y;
    float angle = std::atan2(dy, dx);
    angle = Utility::toDegrees(angle);
    if (angle < 0) angle += 360;
    if (angle > 90 && angle < 270) {
        if (angle > ANGLE_UPPER_BOUND) angle = ANGLE_UPPER_BOUND;
    } else {
        if (angle < ANGLE_LOWER_BOUND || angle >= 270) angle = ANGLE_LOWER_BOUND;
    }
    setAngle(Utility::clamp(angle, 10, 170));
}

