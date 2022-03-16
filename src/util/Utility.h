#ifndef BUBBLESHOOTER_UTILITY_H
#define BUBBLESHOOTER_UTILITY_H
#include <cmath>
#define PI 3.14159265359

class Utility {
public:
    static float toRadians(float angleDegree) {
        return angleDegree / 180 * PI;
    }
};


#endif //BUBBLESHOOTER_UTILITY_H
