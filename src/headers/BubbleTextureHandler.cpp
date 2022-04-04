#include "BubbleTextureHandler.h"

std::string BubbleTextureHandler::getBubbleTexturePath(BubbleColor bubbleColor) {
    return R"(C:\Dev\Projects\BubbleShooter\assets\)" + toString(bubbleColor) + "Bubble.jpg";
}

std::string BubbleTextureHandler::toString(BubbleColor color) {
    std::string result;
    switch (color) {
        case RED:
            result = "Red";
            break;
        case GREEN:
            result = "Green";
            break;
        case BLUE:
            result = "Blue";
            break;
        case PURPLE:
            result = "Purple";
            break;
        case YELLOW:
            result = "Yellow";
            break;
        case PINK:
            result = "Pink";
            break;
        default:
            result = "";
    }
    return result;
}

int BubbleTextureHandler::toIntegerValue(BubbleColor color) {
    int result;
    switch (color) {
        case RED:
            result = 0;
            break;
        case GREEN:
            result = 1;
            break;
        case BLUE:
            result = 2;
            break;
        case PURPLE:
            result = 3;
            break;
        case YELLOW:
            result = 4;
            break;
        case PINK:
            result = 5;
            break;
        default:
            result = -1;
            break;
    }
    return result;
}
