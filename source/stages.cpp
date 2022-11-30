#include"stages.hpp"


GameLevels gamelevels;

bool is_running=true;

bool GameLevels::one_running=true;

bool GameLevels::two_running=false;

void GameLevels::run_levelOne()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);

    pause_music();
    resume_music();

    background.render();
    background.scroll();

    player.render();
    player.handle_event_movement();
    player.handle_event_torps();
    player.collision_for_player();

    missile_collision_for_eship();
    ptorp_collision_for_esub();
    
    enemy_sub_set.render();
    enemy_sub_set.increment();
    enemy_sub_set.xmove();

    enemy_sub_set.launch_torps();

    player.launch_torps();

    fps_show();
    time_show();
    score_board();
    
    life_show();
    if(e.type==SDL_QUIT || player.life==0)
    {
       cout<<"You have been hunted"<<endl;
       is_running=false;
    }
    else if(score==L1_SCORE)
    {
        cout<<"You have Completed level one"<<endl;
        one_running=false;
        two_running=true;
        game_obj_func_init();
        player.life=PLAYER_LIFE;
        total_sub=PRIMARY_ESHIP_N;
    }
    SDL_RenderPresent(gameRenderer);
    frame_controlling();
}

void GameLevels::run_levelTwo()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);

    pause_music();
    resume_music();

    background.render();
    background.scroll();

    player.render();
    player.handle_event_movement();
    player.handle_event_torps();
    player.handle_event_missiles();
    player.collision_for_player();

    missile_collision_for_eship();
    ptorp_collision_for_esub();
    
    enemy_sub_set.render();
    enemy_sub_set.increment();
    enemy_sub_set.xmove();
    enemy_sub_set.ymove();

    enemy_ship_set.render();
    enemy_ship_set.increment();
    enemy_ship_set.xmove();

    enemy_sub_set.launch_torps();
    enemy_ship_set.launch_mines();

    player.launch_torps();
    player.launch_missiles();

    fps_show();
    time_show();
    score_board();
    life_show();

    if(e.type==SDL_QUIT || player.life==0)
    {
       cout<<"You have been hunted"<<endl;
       is_running=false;
    }
    else if(score==L2_SCORE)
    {
        cout<<"You have Won"<<endl;
        is_running=false;
    }
    SDL_RenderPresent(gameRenderer);
    frame_controlling();
}


