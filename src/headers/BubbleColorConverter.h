#ifndef BUBBLESHOOTER_BUBBLECOLORCONVERTER_H
#define BUBBLESHOOTER_BUBBLECOLORCONVERTER_H

#include "BubbleColor.h"
#include <string>

class BubbleColorConverter {
public:
    static std::string getBubbleTexturePath(BubbleColor bubbleColor);

    static std::string toString(BubbleColor color);

    static int toIntegerValue(BubbleColor color);
};


#endif //BUBBLESHOOTER_BUBBLECOLORCONVERTER_H
