#include "Utility.h"

float Utility::toRadians(float angleDegree) {
    return angleDegree / 180 * PI;
}

float Utility::toDegrees(float angleRadian) {
    return angleRadian / PI * 180;
}

float Utility::clamp(float var, float minValue, float maxValue) {
    float result = var;
    if(var < minValue) result = minValue;
    else if(var > maxValue) result = maxValue;
    return result;
}
