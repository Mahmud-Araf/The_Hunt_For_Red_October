#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<bits/stdc++.h>
using namespace std;
extern int winWidth;
extern int winHeight;
extern SDL_Renderer *render;
extern SDL_Texture *redmain;
extern SDL_Texture *background;
extern SDL_Surface *surface;
extern SDL_Rect main1;

void loop()
{
    SDL_Event e;
    while(1)
    {
        
        SDL_PollEvent(&e);
        if(e.type==SDL_QUIT)
        {
            break;
        }
        else
        {
            SDL_SetRenderDrawColor(render,255,255,255,255);
            SDL_RenderClear(render);
            SDL_RenderCopy(render,background,NULL,NULL);
            SDL_RenderCopy(render,redmain,NULL,&main1);
            main1.x+=5;
            if(main1.x>=winWidth+500)
            {
               main1.x=-800;
            }
            SDL_RenderPresent(render);
            SDL_Delay(1000/45);
        }
    }
}