#include "Bubble.h"
#include "ScreenSizeCarrier.h"

Bubble::Bubble(SDL_Renderer *renderer) {
    bubbleColor = RandomBubbleColorGenerator::generateRandomBubbleColor();
    bubbleTexture = std::make_shared<TextureAlpha>();
    loadTexture(renderer, BubbleColorConverter::getBubbleTexturePath(bubbleColor));
    setCenterPosition((float) SCREEN_WIDTH / 2,
                      SCREEN_HEIGHT - bubbleTexture->getHeight() / 2);
    setMoving(false);
}

Bubble::Bubble(SDL_Renderer *renderer, BubbleColor color) {
    bubbleTexture = std::make_shared<TextureAlpha>();
    bubbleColor = color;
    loadTexture(renderer, BubbleColorConverter::getBubbleTexturePath(bubbleColor));
    setCenterPosition((float) SCREEN_WIDTH / 2,
                      SCREEN_HEIGHT - bubbleTexture->getHeight() / 2);
    setMoving(false);
}

void Bubble::render(SDL_Renderer *renderer) {
    bubbleTexture->render(renderer, (int) position.x, (int) position.y, nullptr);
}


void Bubble::setCenterPosition(float xCenter, float yCenter) {
    position.x = xCenter - bubbleTexture->getWidth() / 2;
    position.y = yCenter - bubbleTexture->getHeight() / 2;
}

Point Bubble::getCenterPosition() {
    return {position.x + bubbleTexture->getWidth() / 2, position.y + bubbleTexture->getHeight() / 2};
}

float Bubble::getWidth() {
    return Bubble::getBubbleTexture()->getWidth();
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

BubbleColor Bubble::getType() const {
    return bubbleColor;
}
