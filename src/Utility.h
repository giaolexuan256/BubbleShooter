#ifndef BUBBLESHOOTER_UTILITY_H
#define BUBBLESHOOTER_UTILITY_H

#include <cmath>
#include "Point.h"

#define PI 3.141592f

class Utility {
public:
    static float degreesToRadians(float angleDegree);

    static float radiansToDegrees(float angleRadian);

    static float clamp(float &var, float minValue, float maxValue);

    static bool circleIntersection(Point center1, float radius1, Point center2, float radius2);

};


#endif //BUBBLESHOOTER_UTILITY_H
