#include"utilities.hpp"
#include"font-color.hpp"
#include"obj-functions.hpp"

int frameN=0;
int score=0;

void utilities_init()
{
    font_init();
    start_music();
}

void Button::render()
{   if(!is_inside)
    {
      SDL_RenderCopy(gameRenderer,tex1,&Bsource,&Bdest);
    }
    else
    {
      SDL_RenderCopy(gameRenderer,tex2,&Bsource,&Bdest);
    }
}

bool Button::check_inside(int x,int y)
{
    if(x>=Bdest.x && x<=Bdest.x+Bdest.w && y>=Bdest.y && y<=Bdest.y+Bdest.h)
    {
        is_inside=true;
        return true;
    }
    else
    {   is_inside=false;
        return false;
    }
}

void start_music()
{
    Mix_PlayMusic(gamemusic,-1);
}

void pause_music()
{
    if(is_paused)
    {
      Mix_PauseMusic();
    }
}

void resume_music()
{
    if(!is_paused)
    {
        Mix_ResumeMusic();
    }
}


void framerate_controlling()
{
    int start_frame=SDL_GetTicks();
    
    for(;SDL_GetTicks()-start_frame<=1000/FPS;);
}

void fps_show()
{
    string s=to_string((int)(frameN/(SDL_GetTicks()/1000.0)));

    loadTextSurface(s,Digital,red,SDL_Rect{FSW-125,10,50,50});

    frameN++;
}

void score_board()
{
    string s="Score : "+ to_string(score);

    loadTextSurface(s,Bold1,red,SDL_Rect{50,100,150,100});
}

void time_show()
{
    string s="Time : "+to_string((int)(SDL_GetTicks()/1000));
    s+="s";

    loadTextSurface(s,Bold3,black,SDL_Rect{FSW/2-75,10,150,100});
}

void life_show()
{
    string s="Life : "+to_string(player.life);
    
    loadTextSurface(s,Bold1,red,SDL_Rect{50,0,150,100});

}