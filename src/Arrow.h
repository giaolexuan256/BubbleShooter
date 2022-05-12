#ifndef BUBBLESHOOTER_ARROW_H
#define BUBBLESHOOTER_ARROW_H


#include "Point.h"
#include <cmath>
#include <SDL.h>
#include "Utility.h"

class Arrow {
public:
    Arrow(Point tail, float length, float angle) : tail(tail), length(length), angle(angle) {
        calculateHeadPositionAccordingToAngle(angle);
    }

    void render(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, (int) getTailPoint().x, (int) getTailPoint().y, (int) getHeadPoint().x,
                           (int) getHeadPoint().y);
    }

    void setAngle(float angle) {
        Arrow::angle = angle;
        calculateHeadPositionAccordingToAngle(angle);
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
    Point head;
    float length;
    float angle;

    void calculateHeadPositionAccordingToAngle(float angle) {
        head.x = tail.x + length * std::cos(Utility::degreesToRadians(angle));
        head.y = tail.y - length * std::sin(Utility::degreesToRadians(angle));
    }
};


#endif //BUBBLESHOOTER_ARROW_H
