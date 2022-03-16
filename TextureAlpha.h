#ifndef BUBBLESHOOTER_TEXTUREALPHA_H
#define BUBBLESHOOTER_TEXTUREALPHA_H

#include <SDL.h>
#include <string>
#include <SDL_image.h>


class TextureAlpha {
public:
    TextureAlpha() = default;

    ~TextureAlpha() = default;

    bool free() {
        if (texture != nullptr) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
            width = 0;
            height = 0;
        }
    }

    void loadFromFile(const std::string &fileName, SDL_Renderer *renderer) {
        free();

        SDL_Surface *loadedSurface = IMG_Load(fileName.c_str());
        if (loadedSurface == nullptr) {
            printf("Failed to load image %s!\nSDL_image error: %s", fileName.c_str(), IMG_GetError());
        } else {
            SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 255, 255));
            SDL_Texture *newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
            width = loadedSurface->w;
            height = loadedSurface->h;
            SDL_FreeSurface(loadedSurface);
            texture = newTexture;
        }

    }

    void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *sourceRectangle = nullptr) {
        SDL_Rect destinationRectangle = {x, y, width, height};
        if (sourceRectangle != nullptr) {
            destinationRectangle.w = sourceRectangle->w;
            destinationRectangle.h = sourceRectangle->h;
        }

        SDL_RenderCopy(renderer, texture, sourceRectangle, &destinationRectangle);
    }

    void renderCenter(SDL_Renderer *renderer, int x, int y, SDL_Rect *sourceRectangle = nullptr) {
        render(renderer, x - getWidth() / 2, y - getHeight() / 2, sourceRectangle);
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }


private:
    int width;
    int height;
    SDL_Texture *texture;

};


#endif //BUBBLESHOOTER_TEXTUREALPHA_H
