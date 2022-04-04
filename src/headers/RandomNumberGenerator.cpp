#include "RandomNumberGenerator.h"

int RandomNumberGenerator::generateRandomInteger(int lowerBound, int upperBound) {
    std::random_device randomDevice;
    std::mt19937 randomNumberGenerator(randomDevice());
    std::uniform_int_distribution<int> uniformIntDistribution(lowerBound, upperBound);
    return uniformIntDistribution(randomNumberGenerator);
}
