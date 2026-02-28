#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }
    if (TTF_Init() < 0) {
        printf("TTF_Init failed: %s\n", TTF_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Test", 0, 0, 640, 480, SDL_WINDOW_OPENGL);
    if (!window) {
        printf("Window failed: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer failed: %s\n", SDL_GetError());
        return 1;
    }

    TTF_Font* font = TTF_OpenFont("/home/ubuntu/games/share/hedgewars/Data/Fonts/DejaVuSans-Bold.ttf", 24);
    if (!font) {
        printf("Font failed: %s\n", TTF_GetError());
        return 1;
    }

    SDL_Color color = {255,255,255,255};
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, "Hello", color);
    if (!surface) {
        printf("Surface creation failed: %s\n", TTF_GetError());
        return 1;
    }
    printf("Surface created: %dx%d\n", surface->w, surface->h);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        printf("Texture creation failed: %s\n", SDL_GetError());
        return 1;
    }
    printf("Texture created successfully\n");

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
