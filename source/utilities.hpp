/*This file contains functions and variable related to time show ,frame rate calculaion,score show ,music & button structures*/

#ifndef UTILITIES

#define UTILITIES

#include"preprocessor.hpp"
#include"global.hpp"
#include"media.hpp"


// struct for clickable button in the game
struct Button
{
   SDL_Rect Bsource={350,262,585,202}; // rectangle for button source

   SDL_Rect Bdest; // rectangle for button destination

   SDL_Texture *tex1,*tex2; // texture related to button rendering
   
   bool is_inside; // variable to check if mouse pointer is inside or not

   bool check_inside(int x,int y); // function related for checking if mouse pointer is inside or not

   void render(); // button rendering
   
};

void utilities_init(); // initializing utilities like font , music

void start_music(); 

void pause_music();

void resume_music();

void music_handle_event(); // function to handle pause or resume music events

void framerate_controlling();  // function to restrict certain amount of frame rate per second

void fps_show();  // function that shows frame per second in the game

void life_show();  // shows player's remaining life

void score_board(); // shows player's current score in game

void time_show();  // shows the amount of time after easy or hard level starts

#endif