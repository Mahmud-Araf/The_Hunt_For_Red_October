/*This header contains necessary global variables*/

#ifndef GLOBAL
#define GLOBAL
#include "preprocessor.hpp"

/*
variable used in the game follows a naming scheme

prefix esub = enemy submarine
prefix eship = enemy ship
suffix pos = position
x = related to x axis
y = related to y axis
w = width 
h = height
*/
extern SDL_Window *gameWindow;  // game window 
extern SDL_Renderer *gameRenderer; // game renderer
extern SDL_Event e;        // game event variable
extern const Uint8 *keystate; // game keystate variable

extern Uint32 first_time_torp_launch;
extern Uint32 first_time_missile_launch;

extern int player_x_pos;
extern int player_y_pos;

extern int esub_x_pos;
extern int esub_y_pos;

extern int eship_x_pos;
extern int eship_y_pos;

extern int eship_w;
extern int eship_h;

extern int is_paused; // variable related to game pausing

extern Uint32 delay_event;

extern Uint32 mainmenu_delay; // variable to store the time spent in mainmenu

extern int total_sub;
extern Uint32 esub_increment_start_time;
extern Uint32 esub_increment_count_time;

extern int total_ship;
extern Uint32 eship_increment_start_time;
extern Uint32 eship_increment_count_time;

extern Uint32 current_time,paused_time,pause_start,pause_count;

extern bool timerflag; 

extern int score;  // player score

extern int frameN;
extern Uint32 start_frame;

extern bool is_running; // variable related to core game loop

extern bool music_paused;

#endif
