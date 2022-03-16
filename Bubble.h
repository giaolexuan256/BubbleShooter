#ifndef BUBBLESHOOTER_BUBBLE_H
#define BUBBLESHOOTER_BUBBLE_H

#include "TextureAlpha.h"


class Bubble {
public:

    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    TextureAlpha getBubbleTexture() {
        return bubbleTexture;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setBubbleTexture(TextureAlpha bubbleTexture) {
        this->bubbleTexture = bubbleTexture;
    }

    void loadTexture(const std::string& fileName, SDL_Renderer *renderer) {
        bubbleTexture.loadFromFile(fileName, renderer);
    }

private:
    int x, y;
    TextureAlpha bubbleTexture;
};


#endif //BUBBLESHOOTER_BUBBLE_H
