#ifndef BUBBLESHOOTER_INPUTHANDLER_H
#define BUBBLESHOOTER_INPUTHANDLER_H


#include <SDL.h>
/**
 * Handle keyboard and mouse input.
 * To poll input event, call poll() method.
 * For handling other types of input, using unhandledEvent field.
 */
class InputHandler {
private:

    const static int KEY_LENGTH = 322;

    bool keys[KEY_LENGTH];
    int polled[KEY_LENGTH];

    SDL_Point mousePosition;

public:
    SDL_Event unhandledEvent;

    void poll();
    bool keyDownOnce(SDL_Keycode keycode);
    bool keyDown(SDL_Keycode keycode);
    SDL_Point getMousePosition();
};


#endif //BUBBLESHOOTER_INPUTHANDLER_H
