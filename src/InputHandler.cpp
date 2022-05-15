#include "InputHandler.h"


void InputHandler::poll() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYUP:
                for (int i = 0; i < KEY_LENGTH; i++) {
                    keys[event.key.keysym.sym] = false;
                }
                break;
            case SDL_KEYDOWN:
                for (int i = 0; i < KEY_LENGTH; i++) {
                    keys[event.key.keysym.sym] = true;
                }
                break;
            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
                break;
            default:
                unhandledEvent = event;
        }
        for (int i = 0; i < KEY_LENGTH; i++) {
            if (keys[i]) { polled[i]++; }
            else { polled[i] = 0; }
        }
    }
}

bool InputHandler::keyDownOnce(SDL_Keycode keycode) {
    return polled[keycode] == 1;
}

bool InputHandler::keyDown(SDL_Keycode keycode) {
    return polled[keycode] > 0;
}

SDL_Point InputHandler::getMousePosition() {
    return mousePosition;
}




