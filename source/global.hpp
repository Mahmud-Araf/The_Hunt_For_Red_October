/*This header contains necessary global variables*/

#ifndef GLOBAL
#define GLOBAL
#include"preprocessor.hpp"

extern SDL_Window *gameWindow;
extern SDL_Renderer *gameRenderer;
extern SDL_Event e;

extern int first_time_torp_launch;

extern int first_time_missile_launch;

extern int player_x_pos;
extern int player_y_pos;
#endif

