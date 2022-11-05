#include"game_utilities.hpp"

int score=0;

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


void frame_controlling()
{
    int start_frame=SDL_GetTicks();
    
    while(SDL_GetTicks()-start_frame<=1000/FPS);
}