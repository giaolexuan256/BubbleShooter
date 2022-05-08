//
// Created by giaol on 3/16/2022.
//

#include <SDL_ttf.h>
#include "TextureAlpha.h"

void TextureAlpha::loadFromFile(SDL_Renderer *renderer, const std::string &fileName) {
    free();
    SDL_Surface *loadedSurface = IMG_Load(fileName.c_str());
    if (loadedSurface == nullptr) {
        printf("Failed to load image %s!\nSDL_image error: %s", fileName.c_str(), IMG_GetError());
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        width = loadedSurface->w;
        height = loadedSurface->h;
        SDL_FreeSurface(loadedSurface);
    }

}

void TextureAlpha::render(SDL_Renderer *renderer, int x, int y, SDL_Rect *sourceRectangle) {
    SDL_Rect destinationRectangle = {x, y, width, height};
    if (sourceRectangle != nullptr) {
        destinationRectangle.w = sourceRectangle->w;
        destinationRectangle.h = sourceRectangle->h;
    }

    SDL_RenderCopy(renderer, texture, sourceRectangle, &destinationRectangle);
}

void TextureAlpha::renderCenter(SDL_Renderer *renderer, int x, int y, SDL_Rect *sourceRectangle) {
    render(renderer, x - (int) getWidth() / 2, y - (int) getHeight() / 2, sourceRectangle);
}

void TextureAlpha::renderExtra(SDL_Renderer *renderer, SDL_Rect *clip, SDL_Rect renderQuad, double angle, SDL_Point *center,
                               SDL_RendererFlip flip) {
    //Set rendering space and render to screen
    //Set clip rendering dimensions
    //Render to screen
    SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}

void TextureAlpha::free() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

float TextureAlpha::getWidth() const {
    return width;
}

float TextureAlpha::getHeight() const {
    return height;
}

void TextureAlpha::loadFromRenderedText(SDL_Renderer *renderer, TTF_Font *font, const std::string &textureText, SDL_Color textColor) {
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if (textSurface == nullptr) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (texture == nullptr) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        } else {
            //Get image dimensions
            width = textSurface->w;
            height = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }
}
