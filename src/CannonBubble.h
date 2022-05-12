#ifndef BUBBLESHOOTER_CANNONBUBBLE_H
#define BUBBLESHOOTER_CANNONBUBBLE_H

#include "TextureAlpha.h"
#include <iostream>
#include "Utility.h"
#include "Point.h"
#include "BubbleColor.h"
#include "RandomBubbleColorGenerator.h"
#include "BubbleColorConverter.h"
#include <memory>

class CannonBubble {
public:

    static const int BUBBLE_SPEED = 600;

    Point position;

    explicit CannonBubble(SDL_Renderer *renderer);

    CannonBubble(SDL_Renderer* renderer, BubbleColor color);

    void loadTexture(SDL_Renderer *renderer, const std::string& fileName) {
        bubbleTexture->loadFromFile(renderer, fileName);
    }

    bool isMoving() const {
        return moving;
    }

    void setMoving(bool moving);



    void render(SDL_Renderer *renderer);

    void setCenterPosition(float xCenter, float yCenter);

    Point getCenterPosition();

    BubbleColor getType() const;

    float getWidth();

    float getSpeedX();

    float getSpeedY();

    void setSpeedX(float speedX);

    void setSpeedY(float speedY);

    void setSpeed(float speedX, float speedY);

    std::shared_ptr<TextureAlpha> getBubbleTexture() {
        return bubbleTexture;
    }

    void setX(float x) {
        position.x = x;
    }

    void setY(float y) {
        position.y = y;
    }

private:
    BubbleColor bubbleColor;
    std::shared_ptr<TextureAlpha> bubbleTexture;
    bool moving;
    float speedX, speedY;
};


#endif //BUBBLESHOOTER_CANNONBUBBLE_H
