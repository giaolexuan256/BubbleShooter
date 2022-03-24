#ifndef BUBBLESHOOTER_BUBBLE_H
#define BUBBLESHOOTER_BUBBLE_H

#include "TextureAlpha.h"
#include "Utility.h"
#include "Point.h"
#include "BubbleColor.h"
#include "RandomBubbleColorGenerator.h"
#include "BubbleTextureHandler.h"
#include <memory>

class Bubble {
public:

    Bubble(SDL_Renderer *renderer);

    void loadTexture(SDL_Renderer *renderer, const std::string& fileName) {
        bubbleTexture->loadFromFile(renderer, fileName);
    }

    bool isMoving() const {
        return moving;
    }

    void setMoving(bool moving) {
        Bubble::moving = moving;
    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void render(SDL_Renderer *renderer);

    void renderCenter(SDL_Renderer *renderer);

    void setCenterPosition(float xCenter, float yCenter);

    Point getCenterPosition();

    BubbleColor getType() const;

    float getWidth();

    float getHeight();

    float getSpeedX();

    float getSpeedY();

    void setSpeedX(float speedX);

    void setSpeedY(float speedY);

    void setSpeed(float speedX, float speedY);

    float getX() {
        return x;
    }

    float getY() {
        return y;
    }

    std::shared_ptr<TextureAlpha> getBubbleTexture() {
        return bubbleTexture;
    }

    void setX(float x) {
        this->x = x;
    }

    void setY(float y) {
        this->y = y;
    }

private:
    float x, y;
    BubbleColor type;
    std::shared_ptr<TextureAlpha> bubbleTexture;
    bool moving;
    float speedX, speedY;
};


#endif //BUBBLESHOOTER_BUBBLE_H
