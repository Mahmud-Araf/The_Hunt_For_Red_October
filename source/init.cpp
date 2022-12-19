/*This file contains all the definition of necessary functions to initiate the game and create 
a window and a renderer*/

#include"init.hpp"

Init init;

SDL_Window *gameWindow;
SDL_Renderer*gameRenderer;

void Init::init_sdl()
{
    if(SDL_Init(SDL_INIT_EVERYTHING))
    {
        cout<<"Initialization Error: "<<SDL_GetError()<<endl;
    }
}

void Init::init_window()
{
    gameWindow=SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FLAG);
    if(!gameWindow)
    {
        cout<<"Window Error: "<<SDL_GetError()<<endl;
    }
}

void Init::init_image()
{
    if(!IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG))
    {
        cout<<"Image Error: "<<SDL_GetError()<<endl;
    }
}

void Init::init_ttf()
{
    if(TTF_Init())
    {
      cout<<"TTF Error: "<<SDL_GetError()<<endl;
    }
}

void Init::init_music()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048))
    {
       cout<<"Mix Error: "<<SDL_GetError()<<endl;
    }
}

void Init::init_renderer()
{
   gameRenderer= SDL_CreateRenderer(gameWindow, -1, RENDERER_FLAG);
   if(!gameRenderer)
   {
      cout<<"Renderer Error: "<<SDL_GetError()<<endl;
   }
}

void gameinit()
{
    init.init_sdl();
    init.init_window();
    init.init_image();
    init.init_music();
    init.init_ttf();
    init.init_renderer();
    srand((unsigned)time(NULL));
}