#include"close.hpp"

void gameclose()
{
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(gameWindow);
}