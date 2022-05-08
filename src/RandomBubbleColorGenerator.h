#ifndef BUBBLESHOOTER_RANDOMBUBBLECOLORGENERATOR_H
#define BUBBLESHOOTER_RANDOMBUBBLECOLORGENERATOR_H


#include <random>
#include "BubbleColor.h"
#include "RandomNumberGenerator.h"

class RandomBubbleColorGenerator {
public:
    static BubbleColor generateRandomBubbleColor();
};


#endif //BUBBLESHOOTER_RANDOMBUBBLECOLORGENERATOR_H
