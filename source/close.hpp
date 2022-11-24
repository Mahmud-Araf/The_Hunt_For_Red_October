//This header contains function to close and free the sdl2 functionalities

#ifndef CLOSE

#define CLOSE

#include"preprocessor.hpp"

extern SDL_Window *gameWindow;
extern SDL_Renderer*gameRenderer;
void gameclose();
#endif