#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<bits/stdc++.h>
using namespace std;

SDL_Window *win=NULL;

int winWidth=1200;
int winHeight=1000;

SDL_Renderer *render=NULL;

void init()
{   if(SDL_Init(SDL_INIT_VIDEO)<0)
    {  
      cout<<"Init failure: "<<SDL_GetError()<<endl;
    }
    else
    {
       win=SDL_CreateWindow("The Hunt For Red October",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,winWidth,winHeight,SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
        if(!win)
        {   
            cout<<"Window failure: "<<SDL_GetError()<<endl;
            SDL_Quit();
        }
    }
    if(IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG)<0)
    {
        cout<<"IMG failure: "<<SDL_GetError()<<endl;
    }
    render =SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(!render)
    {
       cout<<"Render failure: "<<SDL_GetError()<<endl;
    }
}

void close()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
}
