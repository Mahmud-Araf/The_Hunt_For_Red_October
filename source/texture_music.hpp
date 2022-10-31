
/*This header contains all the texture and music prototype of the game 
texture used in the game follow a naming scheme 
BG for Background related
B for buttons
Obj for game objects
Text for texts
*/

#ifndef Texture_Music

#define TExture_Music

#include"preprocessor.hpp"

//texture part
extern SDL_Texture *introBG;
extern SDL_Texture *gameBG;
extern SDL_Texture *player_subObj;
extern SDL_Texture *player_torpObj;
extern SDL_Texture *player_missile1Obj;
extern SDL_Texture *player_missile2Obj;
extern SDL_Texture *enemy_subObj;
extern SDL_Texture *enemy_torpObj;
extern SDL_Texture *enemy_shipObj;
extern SDL_Texture *enemy_mineObj;
extern SDL_Texture *explo_surfaceObj;
extern SDL_Texture *explo_waterObj;

//sound part

extern Mix_Music *gamemusic;
extern Mix_Chunk *missileL1;
extern Mix_Chunk *missileL2;
extern Mix_Chunk *torpL;
extern Mix_Chunk *E_surface;
extern Mix_Chunk *E_water;


#endif