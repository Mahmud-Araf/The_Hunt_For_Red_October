#ifndef FONT_COLOR

#define FONT_COLOR

#include"preprocessor.hpp"

extern SDL_Color white;
extern SDL_Color black;
extern SDL_Color red;

extern TTF_Font *Bold1;
extern TTF_Font *Bold2;
extern TTF_Font *Bold3;
extern TTF_Font *Norm1;
extern TTF_Font *Digital;


void loadTextSurface(std::string path,TTF_Font *font,SDL_Color color,SDL_Rect area);

void font_init();

void closeFont();

#endif