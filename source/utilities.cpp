#include"header.hpp"

int frameN=0;
int score=0;
bool music_paused=false;

Uint32 current_time=0,paused_time=0,pause_start=0,pause_count=0;
bool timerflag=false;

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
    if(is_paused || music_paused)
    {
      Mix_PauseMusic();
    }
}

void resume_music()
{
    if(!is_paused && !music_paused)
    {
        Mix_ResumeMusic();
    }
}

void music_handle_event()
{
    SDL_PollEvent(&e);
    
    if(e.type==SDL_KEYDOWN && SDL_GetTicks()-delay_event>500)
    {
        if(e.key.keysym.sym==SDLK_F1)
        {
            if(!music_paused)
            music_paused=true;
            else
            music_paused=false;
        
            delay_event=SDL_GetTicks();
        }
    }
}


void framerate_controlling()
{
    int start_frame=SDL_GetTicks();
    
    for(;SDL_GetTicks()-start_frame<=1000/FPS;);
}

void fps_show()
{   
    SDL_Rect surface={FSW-125,10,50,50};

    SDL_SetRenderDrawColor(gameRenderer,255,0,0,0);

    SDL_RenderFillRect(gameRenderer,&surface);

    string s=to_string((int)(frameN/(SDL_GetTicks()/1000.0)));

    loadTextSurface(s,DigitalF,black,SDL_Rect{FSW-125,10,50,50});

    frameN++;
}

void life_show()
{
    SDL_Rect surface={50,0+20,150,100-30};

    SDL_SetRenderDrawColor(gameRenderer,255,0,0,0);

    SDL_RenderFillRect(gameRenderer,&surface);

    string s="Life : "+to_string(player.life);
    
    loadTextSurface(s,Bold4F,black,SDL_Rect{50,0,150,100});

}

void score_board()
{
    SDL_Rect surface={50,150+20,150,100-30};

    SDL_SetRenderDrawColor(gameRenderer,255,0,0,0);

    SDL_RenderFillRect(gameRenderer,&surface);

    string s="Score : "+ to_string(score);

    loadTextSurface(s,Bold4F,black,SDL_Rect{50,150,150,100});
}

void time_show()
{
    SDL_Rect surface={FSW/2-75,10+20,150,100-30};

    SDL_SetRenderDrawColor(gameRenderer,255,0,0,0);

    SDL_RenderFillRect(gameRenderer,&surface);

    if(!is_paused && !timerflag)
    {
      current_time=SDL_GetTicks()-paused_time-mainmenu_delay;
    }
    else if(is_paused && !timerflag)
    {
        pause_start=SDL_GetTicks();
        timerflag=true;
    }
    else if(timerflag && !is_paused)
    {
        pause_count=SDL_GetTicks()-pause_start;
        paused_time+=pause_count;
        timerflag=false;
    }
    

    string s="Time : "+to_string((int)(current_time/1000.0));
    s+="s";

    loadTextSurface(s,Bold4F,black,SDL_Rect{FSW/2-75,10,150,100});
}

