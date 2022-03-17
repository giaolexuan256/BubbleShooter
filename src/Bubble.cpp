#include "Bubble.h"

void Bubble::setCenterPosition(float xCenter, float yCenter) {
    x = xCenter - bubbleTexture.getWidth() / 2;
    y = yCenter - bubbleTexture.getHeight() / 2;
}

Point Bubble::getCenterPosition() {
    return {x + bubbleTexture.getWidth() / 2, y + bubbleTexture.getHeight() / 2};
}
