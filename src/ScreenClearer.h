#ifndef BUBBLESHOOTER_SCREENCLEARER_H
#define BUBBLESHOOTER_SCREENCLEARER_H

#include <SDL.h>

class ScreenClearer {
public:
    static void clearScreen(SDL_Renderer *renderer, SDL_Color color);
};


#endif //BUBBLESHOOTER_SCREENCLEARER_H
