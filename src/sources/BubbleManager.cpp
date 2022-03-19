//
// Created by giaol on 3/18/2022.
//

#include "../headers/BubbleManager.h"
#include "../headers/ScreenSizeCarrier.h"

void BubbleManager::loadBubbleToCannon(SDL_Renderer *renderer) {
    auto *bubble = new Bubble(renderer);
    listOfBubbles.push_back(bubble);
    bubble->setCenterPosition((float) SCREEN_WIDTH / 2 + bubble->getBubbleTexture().getWidth() / 2,
                              SCREEN_HEIGHT - bubble->getBubbleTexture().getHeight() / 2);
}

void BubbleManager::renderAllBubbles(SDL_Renderer *renderer) {
    for (auto bubble: listOfBubbles) {
        bubble->render(renderer);
    }
}

const std::list<Bubble *> &BubbleManager::getListOfBubbles() const {
    return listOfBubbles;
}
