#ifndef BUBBLESHOOTER_TEXTUREALPHA_H
#define BUBBLESHOOTER_TEXTUREALPHA_H

#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>


class TextureAlpha {
public:

    void loadFromFile(SDL_Renderer *renderer, const std::string &fileName);

    void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *sourceRectangle = nullptr);

    void renderCenter(SDL_Renderer *renderer, int x, int y, SDL_Rect *sourceRectangle = nullptr);

    void renderExtra(SDL_Renderer *renderer, SDL_Rect *clip, SDL_Rect renderQuad, double angle, SDL_Point *center,
                     SDL_RendererFlip flip);

    void loadFromRenderedText(SDL_Renderer *renderer, TTF_Font *font, const std::string& textureText, SDL_Color textColor);

    void free();

    float getWidth() const;

    float getHeight() const;


private:
    int width;
    int height;
    SDL_Texture *texture;

};


#endif //BUBBLESHOOTER_TEXTUREALPHA_H
