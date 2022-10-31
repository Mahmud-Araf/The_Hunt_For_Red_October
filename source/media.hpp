#ifndef Media

#define Media

#include "preprocessor.hpp"
#include"global.hpp"
#include "texture_music.hpp"

//loads texuture
SDL_Texture *loadTexture(std::string path);

//loads texure and sound
bool loadMedia();

//destroys texture and files from memory, closes all systems and shuts down
void closeMedia();

#endif