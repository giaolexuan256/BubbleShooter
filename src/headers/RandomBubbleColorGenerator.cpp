#include "RandomBubbleColorGenerator.h"

BubbleColor RandomBubbleColorGenerator::generateRandomBubbleColor() {
    std::random_device randomDevice;
    std::mt19937 randomNumberGenerator(randomDevice());
    std::uniform_int_distribution<int> uniformIntDistribution(0, 5);
    int randomNumber = uniformIntDistribution(randomNumberGenerator);
    return static_cast<BubbleColor>(randomNumber);
}
