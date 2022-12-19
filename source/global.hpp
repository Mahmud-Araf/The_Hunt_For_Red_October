/*This header contains necessary global variables*/

#ifndef GLOBAL
#define GLOBAL
#include "preprocessor.hpp"

extern SDL_Window *gameWindow;
extern SDL_Renderer *gameRenderer;
extern SDL_Event e;

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

extern int is_paused;

extern Uint32 delay_event;

extern Uint32 mainmenu_delay;

extern int total_sub;
extern Uint32 esub_increment_start_time;
extern Uint32 esub_increment_count_time;

extern int total_ship;
extern Uint32 eship_increment_start_time;
extern Uint32 eship_increment_count_time;

extern Uint32 current_time,paused_time,pause_start,pause_count;

extern bool timerflag;

extern int score;

extern int frameN;
extern Uint32 start_frame;

extern bool is_running;

extern bool music_paused;

extern const Uint8 *keystate;

#endif
