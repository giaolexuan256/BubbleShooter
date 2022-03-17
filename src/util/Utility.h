#ifndef BUBBLESHOOTER_UTILITY_H
#define BUBBLESHOOTER_UTILITY_H
#include <cmath>
#define PI 3.14159265359f

class Utility {
public:
    static float toRadians(float angleDegree);
    static float clamp(float var, float minValue, float maxValue);
};


#endif //BUBBLESHOOTER_UTILITY_H
