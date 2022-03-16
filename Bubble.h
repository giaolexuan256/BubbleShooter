#ifndef BUBBLESHOOTER_BUBBLE_H
#define BUBBLESHOOTER_BUBBLE_H

#include "TextureAlpha.h"


class Bubble {
public:
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    const TextureAlpha &getBubbleTexture() const {
        return bubbleTexture;
    }

    void setX(int x) {
        Bubble::x = x;
    }

    void setY(int y) {
        Bubble::y = y;
    }

    void setBubbleTexture(const TextureAlpha &bubbleTexture) {
        Bubble::bubbleTexture = bubbleTexture;
    }
private:
    int x, y;
    TextureAlpha bubbleTexture;

};


#endif //BUBBLESHOOTER_BUBBLE_H
