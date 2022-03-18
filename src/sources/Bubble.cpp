#include "../headers/Bubble.h"

void Bubble::setCenterPosition(float xCenter, float yCenter) {
    x = xCenter - bubbleTexture.getWidth() / 2;
    y = yCenter - bubbleTexture.getHeight() / 2;
}

Point Bubble::getCenterPosition() {
    return {x + bubbleTexture.getWidth() / 2, y + bubbleTexture.getHeight() / 2};
}

float Bubble::getWidth() {
    return Bubble::getBubbleTexture().getWidth();
}

float Bubble::getHeight() {
    return Bubble::getBubbleTexture().getHeight();
}

float Bubble::getSpeedX() {
    return speedX;
}

float Bubble::getSpeedY() {
    return speedY;
}

void Bubble::setSpeedX(float speedX) {
    Bubble::speedX = speedX;
}

void Bubble::setSpeedY(float speedY) {
    Bubble::speedY = speedY;
}

void Bubble::setSpeed(float speedX, float speedY) {
    setSpeedX(speedX);
    setSpeedY(speedY);
}
