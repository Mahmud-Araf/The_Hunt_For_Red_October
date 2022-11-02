#pragma once
#include"preprocessor.hpp"
extern SDL_Window *gameWindow;
extern SDL_Renderer*gameRenderer;
void gameclose()
{
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(gameWindow);
}