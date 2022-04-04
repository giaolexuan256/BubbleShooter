#include "RandomBubbleColorGenerator.h"

BubbleColor RandomBubbleColorGenerator::generateRandomBubbleColor() {
    int randomNumber = RandomNumberGenerator::generateRandomInteger(0, TOTAL_COLORS);
    return static_cast<BubbleColor>(randomNumber);
}
