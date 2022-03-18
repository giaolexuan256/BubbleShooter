#ifndef BUBBLESHOOTER_BUBBLEMANAGER_H
#define BUBBLESHOOTER_BUBBLEMANAGER_H


#include <list>
#include "Bubble.h"

class BubbleManager {
public:
    void loadBubbleToCannon(SDL_Renderer* renderer);
    void renderAllBubbles(SDL_Renderer* renderer);
private:
    std::list<Bubble*> listOfBubbles;
};


#endif //BUBBLESHOOTER_BUBBLEMANAGER_H
