#include "CannonBubble.h"
#include "ScreenSizeCarrier.h"

CannonBubble::CannonBubble(SDL_Renderer *renderer) {
    bubbleColor = RandomBubbleColorGenerator::generateRandomBubbleColor();
    bubbleTexture = std::make_shared<TextureAlpha>();
    loadTexture(renderer, BubbleColorConverter::getBubbleTexturePath(bubbleColor));
    setCenterPosition((float) SCREEN_WIDTH / 2,
                      SCREEN_HEIGHT - bubbleTexture->getHeight() / 2);
    setMoving(false);
}

CannonBubble::CannonBubble(SDL_Renderer *renderer, BubbleColor color) {
    bubbleTexture = std::make_shared<TextureAlpha>();
    bubbleColor = color;
    loadTexture(renderer, BubbleColorConverter::getBubbleTexturePath(bubbleColor));
    setCenterPosition((float) SCREEN_WIDTH / 2,
                      SCREEN_HEIGHT - bubbleTexture->getHeight() / 2);
    setMoving(false);
}

void CannonBubble::render(SDL_Renderer *renderer) {
    bubbleTexture->render(renderer, (int) position.x, (int) position.y, nullptr);
}


void CannonBubble::setCenterPosition(float xCenter, float yCenter) {
    position.x = xCenter - bubbleTexture->getWidth() / 2;
    position.y = yCenter - bubbleTexture->getHeight() / 2;
}

Point CannonBubble::getCenterPosition() {
    return {position.x + bubbleTexture->getWidth() / 2, position.y + bubbleTexture->getHeight() / 2};
}

float CannonBubble::getWidth() {
    return CannonBubble::getBubbleTexture()->getWidth();
}

float CannonBubble::getSpeedX() {
    return speedX;
}

float CannonBubble::getSpeedY() {
    return speedY;
}

void CannonBubble::setSpeedX(float speedX) {
    CannonBubble::speedX = speedX;
}

void CannonBubble::setSpeedY(float speedY) {
    CannonBubble::speedY = speedY;
}

void CannonBubble::setSpeed(float speedX, float speedY) {
    setSpeedX(speedX);
    setSpeedY(speedY);
}

BubbleColor CannonBubble::getType() const {
    return bubbleColor;
}

void CannonBubble::setMoving(bool moving) {
    CannonBubble::moving = moving;
    if(!moving) {
        speedX = speedY = 0;
    }
}
