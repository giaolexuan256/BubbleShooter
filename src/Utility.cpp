#include "Utility.h"

float Utility::degreesToRadians(float angleDegree) {
    return angleDegree / 180 * PI;
}

float Utility::radiansToDegrees(float angleRadian) {
    return angleRadian / PI * 180;
}

float Utility::clamp(float &var, float minValue, float maxValue) {
    if (var < minValue) var = minValue;
    else if (var > maxValue) var = maxValue;
    return var;
}

bool Utility::circleIntersection(Point center1, float radius1, Point center2, float radius2) {
    float dx = center1.x - center2.x;
    float dy = center1.y - center2.y;
    float len = std::sqrt(dx * dx + dy * dy);
    return len < radius1 + radius2;
}
