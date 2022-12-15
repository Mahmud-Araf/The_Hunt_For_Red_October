#ifndef Media

#define Media

#include "preprocessor.hpp"
#include"global.hpp"

//loads texuture
SDL_Texture *loadTexture(std::string path);

SDL_Texture *loadTexturewithKey(std::string path);


//loads texure and sound
bool loadMedia();

//destroys texture and files from memory, closes all systems and shuts down
void closeMedia();


//texture part
extern SDL_Texture *mainmenuBG;
extern SDL_Texture *levelmenuBG;
extern SDL_Texture *controlsBG;
extern SDL_Texture *creditBG;
extern SDL_Texture *startgameB1;
extern SDL_Texture *startgameB2;
extern SDL_Texture *controlsB1;
extern SDL_Texture *controlsB2;
extern SDL_Texture *hscoresB1;
extern SDL_Texture *hscoresB2;
extern SDL_Texture *creditB1;
extern SDL_Texture *creditB2;
extern SDL_Texture *exitB1;
extern SDL_Texture *exitB2;
extern SDL_Texture *backB1;
extern SDL_Texture *backB2;
extern SDL_Texture *level1B1;
extern SDL_Texture *level1B2;
extern SDL_Texture *level2B1;
extern SDL_Texture *level2B2;
extern SDL_Texture *lifeObj;
extern SDL_Texture *scoreObj;
extern SDL_Texture *clockObj;
extern SDL_Texture *gameBG1;
extern SDL_Texture *gameBG2;
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
extern Mix_Chunk *missileL1_chunk;
extern Mix_Chunk *missileL2_chunk;
extern Mix_Chunk *torpL_chunk;
extern Mix_Chunk *explosion_surface_chunk;
extern Mix_Chunk *explosion_water_chunk;

#endif