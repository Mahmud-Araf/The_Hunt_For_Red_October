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

extern int esub_x_pos;
extern int esub_y_pos;

extern int eship_x_pos;
extern int eship_y_pos;

extern int eship_w;
extern int eship_h;



extern int is_paused;

extern int total_sub;
extern int esub_increment_start_time;
extern int esub_increment_count_time;

extern int total_ship;
extern int eship_increment_start_time;
extern int eship_increment_count_time;


extern int score;

extern int frameN;


#endif

