
/*This file includes SDL2,SDL2_image,SDL2_ttf,SDL2_mixer and standard C++ library functions that
will be necessary to call standard C++ and SDL2 functions*/

#ifndef Preprocessor

#define Preprocessor

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1000
#define WINDOW_TITLE "The Hunt For Red October"
#define WINDOW_FLAG  SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP
#define RENDERER_FLAG SDL_RENDERER_ACCELERATED
#define FSW 1980
#define FSH 1080
#define FPS 45
#define PLAYER_LIFE 10
#define PLAYER_N_HSCORE 5
#define BG_N 2
#define SPF  3
#define P_TORP_N 15
#define P_MISSILE_N 10
#define PLAYER_COLLISION_TIME 3000
#define PLAYER_VIBING_DELAY 150
#define E_TORP_N 5
#define E_MINE_N 5
#define E_SUB_N  10
#define PRIMARY_ESUB_N 2
#define INCREMENT_SUB_LONE 20000
#define INCREMENT_SUB_LTWO 20000
#define E_SUB_REVIVAL_DELAY 4000
#define P_TORP_SPEED 7
#define P_TORP_DELAY 500
#define P_MISSILE_SPEED 14
#define P_MISSILE_DELAY 1000
#define E_TORP_SPEED 8
#define E_TORP_DELAY 5000
#define E_SHIP_N 5
#define PRIMARY_ESHIP_N 1
#define ESHIP_SPEED 5
#define INCREMENT_SHIP 50000
#define E_SHIP_REVIVAL_DELAY 3000
#define E_MINE_SPEED 14
#define E_MINE_DELAY 5000
#define E_MINE_Y_DELAY 150
#define MISSILE_COLLISION_SN 4
#define TORP_COLLISION_SN 9
#define EXP_SPEED 3
#define EXP_DELAY_SURFACE 150
#define EXP_DELAY_WATER 100

#endif

