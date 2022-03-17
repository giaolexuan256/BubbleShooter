#ifndef BUBBLESHOOTER_BUBBLE_H
#define BUBBLESHOOTER_BUBBLE_H

#include "TextureAlpha.h"
#include "util/Utility.h"
#include "util/Point.h"

class Bubble {
public:

    bool isMoving() {
        return moving;
    }

    void setMoving(bool moving) {
        Bubble::moving = moving;
    }

    void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setCenterPosition(float xCenter, float yCenter);
    Point getCenterPosition();
    float getWidth();
    float getHeight();

    float getX() {
        return x;
    }

    float getY() {
        return y;
    }

    TextureAlpha getBubbleTexture() {
        return bubbleTexture;
    }

    void setX(float x) {
        this->x = x;
    }

    void setY(float y) {
        this->y = y;
    }

    void setBubbleTexture(TextureAlpha bubbleTexture) {
        this->bubbleTexture = bubbleTexture;
    }

    void loadTexture(const std::string &fileName, SDL_Renderer *renderer) {
        bubbleTexture.loadFromFile(fileName, renderer);
    }

private:
    float x, y;
    TextureAlpha bubbleTexture;
    bool moving;
};


#endif //BUBBLESHOOTER_BUBBLE_H
