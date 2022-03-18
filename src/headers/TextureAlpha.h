#ifndef BUBBLESHOOTER_TEXTUREALPHA_H
#define BUBBLESHOOTER_TEXTUREALPHA_H

#include <SDL.h>
#include <string>
#include <SDL_image.h>


class TextureAlpha {
public:
    void free() {
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

    void renderExtra(SDL_Renderer *renderer, SDL_Rect *clip, SDL_Rect renderQuad, double angle, SDL_Point *center, SDL_RendererFlip flip) {
        //Set rendering space and render to screen
        //Set clip rendering dimensions
        //Render to screen
        SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
    }

    float getWidth() const {
        return width;
    }

    float getHeight() const {
        return height;
    }


private:
    int width;
    int height;
    SDL_Texture *texture;

};


#endif //BUBBLESHOOTER_TEXTUREALPHA_H
