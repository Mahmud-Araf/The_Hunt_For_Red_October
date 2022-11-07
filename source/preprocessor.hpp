
/*including SDL2,SDL2_image,SDL2_ttf,SDL2_mixer and standard C++ library functions that
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
#define BG_N 2
#define WINDOW_TITLE "The Hunt For Red October"
#define RENDERER_FLAGS SDL_RENDERER_ACCELERATED
#define P_TORP_N 15
#define P_MISSILE_N 10
#define E_TORP_N 5
#define E_MINE_N 5
#define E_SUB_N  10
#define PRIMARY_ESUB_N 2
#define INCREMENT_SUB 30000
#define P_TORP_SPEED 7
#define P_TORP_DELAY 500
#define P_MISSILE_SPEED 14
#define P_MISSILE_DELAY 2500
#define E_TORP_SPEED 8
#define E_TORP_DELAY 5000
#define E_SHIP_N 5
#define PRIMARY_ESHIP_N 1
#define INCREMENT_SHIP 120000
#define E_MINE_SPEED 6
#define E_MINE_DELAY 7000
#define E_MINE_Y_DELAY 200
#define MISSILE_COLLISION_SN 4
#define TORP_COLLISION_SN 9
#define EXP_SPEED 3
#define EXP_DELAY_SURFACE 150
#define EXP_DELAY_WATER 100
#define BG_N 2
#define SPF  3
#define FSW 1980
#define FSH 1080
#define FPS 40

#endif
