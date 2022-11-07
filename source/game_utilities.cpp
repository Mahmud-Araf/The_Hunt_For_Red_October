#include"game_utilities.hpp"
#include"font-color.hpp"

int frameN=0;
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
    
    for(;SDL_GetTicks()-start_frame<=1000/FPS;);
}

void fps_show()
{
    string framerate=to_string((int)(frameN/(SDL_GetTicks()/1000.0)));

    loadTextSurface(framerate,Digital,red,SDL_Rect{FSW-125,10,50,50});

    frameN++;
}

void score_board()
{
    string scoreB="Score : "+ to_string(score);

    loadTextSurface(scoreB,Bold1,red,SDL_Rect{50,100,150,100});
}

void time_show()
{
    string time="Time : "+to_string((int)(SDL_GetTicks()/1000));
    time+="s";

    loadTextSurface(time,Bold3,black,SDL_Rect{FSW/2-75,10,150,100});
}