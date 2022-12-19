/*This header contains necessary variable and function to initiate the game*/


#ifndef GINIT

#define GINIT

#include"preprocessor.hpp"

extern SDL_Window *gameWindow;

extern SDL_Renderer *gameRenderer;

struct Init
{
    void init_sdl();
    void init_window();
    void init_renderer();
    void init_image();
    void init_music();
    void init_ttf();
};

extern Init init;

void gameinit();

#endif
