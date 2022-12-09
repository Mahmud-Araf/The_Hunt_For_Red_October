
#ifndef UTILITIES

#define UTILITIES

#include"preprocessor.hpp"
#include"global.hpp"
#include"media.hpp"

struct Button
{
   SDL_Rect Bsource={350,262,585,202};

   SDL_Rect Bdest;

   SDL_Texture *tex1,*tex2;
   
   bool is_inside;

   bool check_inside(int x,int y);

   void render();
   
};

void utilities_init();
void start_music();

void pause_music();

void resume_music();

void framerate_controlling();

void fps_show();

void score_board();

void time_show();

void life_show();



#endif