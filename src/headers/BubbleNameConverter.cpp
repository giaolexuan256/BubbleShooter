#include "BubbleNameConverter.h"

std::string BubbleNameConverter::toString(BubbleColor color) {
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
