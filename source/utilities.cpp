#include"header.hpp"

int frameN=0;

int score=0;

bool music_paused=false;

Uint32 start_frame=0;

Uint32 current_time=0,paused_time=0,pause_start=0,pause_count=0;
bool timerflag=false;

const Uint8 *keystate=SDL_GetKeyboardState(NULL);


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
    if( keystate[SDL_SCANCODE_F1] && SDL_GetTicks()-delay_event>500)
    {
        if(!music_paused)
        music_paused=true;
        else
        music_paused=false;

        delay_event=SDL_GetTicks();
        
    }
}


void framerate_controlling()
{
    start_frame=SDL_GetTicks();
    
    for(;SDL_GetTicks()-start_frame<=1000/FPS;);
}


void fps_show()
{   
    SDL_Rect surface={FSW-125,10,50,50};

    SDL_SetRenderDrawColor(gameRenderer,255,0,0,0);

    SDL_RenderFillRect(gameRenderer,&surface);

    string s=to_string((int)(frameN/(SDL_GetTicks()/1000.0)));

    loadTextSurfacewithRect(s,DigitalF,black,SDL_Rect{FSW-125,10,50,50});

    frameN++;
}


void life_show()
{
    SDL_Rect surface={115,20,170,70};

    SDL_SetRenderDrawColor(gameRenderer,255,0,0,0);

    SDL_RenderFillRect(gameRenderer,&surface);

    SDL_Rect life_dim={20,0,100,100};

    SDL_RenderCopy(gameRenderer,lifeObj,NULL,&life_dim);

    string s="Life : "+to_string(player.life);
    
    loadTextSurfacewithRect(s,Bold3F,black,SDL_Rect{120,0,150,100});

}


void score_board()
{
    SDL_Rect surface={115,170,170,70};

    SDL_SetRenderDrawColor(gameRenderer,255,0,0,0);

    SDL_RenderFillRect(gameRenderer,&surface);

    SDL_Rect score_dim={20,150,100,100};

    SDL_RenderCopy(gameRenderer,scoreObj,NULL,&score_dim);

    string s="Score : "+ to_string(score);

    loadTextSurfacewithRect(s,Bold3F,black,SDL_Rect{120,150,150,100});
}


void time_show()
{
    SDL_Rect surface={FSW/2-90,30,170,70};

    SDL_SetRenderDrawColor(gameRenderer,255,0,0,0);

    SDL_RenderFillRect(gameRenderer,&surface);

    SDL_Rect clock_dim={FSW/2-195,10,100,100};

    SDL_RenderCopy(gameRenderer,clockObj,NULL,&clock_dim);

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

    loadTextSurfacewithRect(s,Bold3F,black,SDL_Rect{FSW/2-75,10,150,100});
}

