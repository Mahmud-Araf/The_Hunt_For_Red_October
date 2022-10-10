#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<bits/stdc++.h>
using namespace std;
extern int winWidth;
extern int winHeight;
extern SDL_Renderer *render;

SDL_Surface *surface=NULL;
SDL_Texture *redmain=NULL;
SDL_Texture *background=NULL;
SDL_Rect main1;
void load_media()
{
   surface=IMG_Load("/home/araf/Documents/The_Hunt_For_Red_October/assets/red october1.png");
   redmain=SDL_CreateTextureFromSurface(render,surface);
   if(!redmain)
   {
    cout<<"Texture failor: "<<SDL_GetError()<<endl;
   }
   SDL_FreeSurface(surface);
   SDL_QueryTexture(redmain,NULL,NULL,&main1.w,&main1.h);

   surface=IMG_Load("/home/araf/Documents/The_Hunt_For_Red_October/assets/background1.png");
   background=SDL_CreateTextureFromSurface(render,surface);
   if(!background)
   {
     cout<<"Texture failor: "<<SDL_GetError()<<endl;
   }

   SDL_FreeSurface(surface);

   main1.x=-800;
   main1.y=winHeight*.5;
   main1.w=(int)main1.w*.4;
   main1.h=(int)main1.h*.4;

}
void free_media()
{
    SDL_DestroyTexture(redmain);
    SDL_DestroyTexture(background);
}