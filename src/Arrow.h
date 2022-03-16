#ifndef BUBBLESHOOTER_ARROW_H
#define BUBBLESHOOTER_ARROW_H


#include "Point.h"
#include <cmath>

class Arrow {
public:
    Arrow(Point tail, float length, float angle) : tail(tail), length(length), angle(angle) {
        head.x = tail.x - length * std::cos(angle / 180);
        head.y = tail.y - length * std::sin(angle / 180);
    }

    Arrow(Point tail, Point head) : tail(tail), head(head) {
        length = (float) sqrt(pow(tail.x - head.x, 2) + pow(tail.y - head.y, 2));
        angle = std::atan((float) (head.y - tail.y) / (float)(head.x - head.y));
    }

    void setPosition(Point tail, Point head) {
        Arrow::tail = tail;
        Arrow::head = head;
    }

    void setLength(float length) {
        Arrow::length = length;
    }

    void setAngle(float angle) {
        Arrow::angle = angle;
    }

    Point getTailPoint() {
        return tail;
    }

    Point getHeadPoint() {
        return head;
    }

    float getLength() {
        return length;
    }

    float getAngle() {
        return angle;
    }



private:
    Point tail;
    Point head = Point(0, 0);
    float length;
    float angle;
};


#endif //BUBBLESHOOTER_ARROW_H
