#ifndef BUBBLESHOOTER_BUBBLETEXTUREHANDLER_H
#define BUBBLESHOOTER_BUBBLETEXTUREHANDLER_H

#include "BubbleColor.h"
#include <string>

class BubbleTextureHandler {
public:
    static std::string getBubbleTexturePath(BubbleColor bubbleColor);

    static std::string toString(BubbleColor color);

    static int toIntegerValue(BubbleColor color);
};


#endif //BUBBLESHOOTER_BUBBLETEXTUREHANDLER_H
