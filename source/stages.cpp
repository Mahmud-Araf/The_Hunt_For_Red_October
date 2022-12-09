#include"stages.hpp"


GameLevels gamelevels;

MainMenu mainmenu;

bool is_running=true;

bool MainMenu::running=true;

bool GameLevels::one_running=true;

bool GameLevels::two_running=true;

void MainMenu::init()
{
    Bw=300;
    Bh=100;
    Bspacing=40;
    
    //start button 
    startgame.Bdest.x=200;
    startgame.Bdest.y=100;
    startgame.Bdest.w=Bw;
    startgame.Bdest.h=Bh;
    startgame.tex1=startgameB1;
    startgame.tex2=startgameB2;


    //exit button rect
    exitgame.Bdest.x=200;
    exitgame.Bdest.y=100+Bh+Bspacing;
    exitgame.Bdest.w=Bw;
    exitgame.Bdest.h=Bh;
    exitgame.tex1=exitB1;
    exitgame.tex2=exitB2;

}


void MainMenu::render()
{
    SDL_RenderCopy(gameRenderer,mainmenuBG,NULL,NULL);

    startgame.render();
    exitgame.render();
}

void MainMenu::handle_event()
{
    SDL_PollEvent(&e);
    
    int x,y;

    SDL_GetMouseState(&x,&y);

    if(startgame.check_inside(x,y))
    {   
        if(e.type==SDL_MOUSEBUTTONDOWN)
        {
           running=false;
        }
    }
    if(exitgame.check_inside(x,y))
    {
        if(e.type==SDL_MOUSEBUTTONDOWN)
        {
           running=false;
           is_running=false;
        }
    }
    
}

void MainMenu::run()
{
     render();
     
     handle_event();

     if(e.type==SDL_QUIT)
     {
        is_running=false;
     }

     SDL_RenderPresent(gameRenderer);
}


void GameLevels::run_levelOne()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);

    pause_music();
    resume_music();

    gamebackground.render();
    gamebackground.scroll();

    player.render();
    player.handle_event_movement();
    player.handle_event_torps();
    
    
    enemy_sub_set.render();
    enemy_sub_set.increment();
    enemy_sub_set.xmove();

    enemy_sub_set.launch_torps();

    player.launch_torps();

    player.collision_for_player();
    missile_collision_for_eship();
    ptorp_collision_for_esub();

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
        game_obj_func_init();
        player.life=PLAYER_LIFE;
        total_sub=PRIMARY_ESHIP_N;
    }
    SDL_RenderPresent(gameRenderer);
    framerate_controlling();
}

void GameLevels::run_levelTwo()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);

    pause_music();
    resume_music();

    gamebackground.render();
    gamebackground.scroll();

    player.render();
    player.handle_event_movement();
    player.handle_event_torps();
    player.handle_event_missiles();
   
    
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

    player.collision_for_player();
    missile_collision_for_eship();
    ptorp_collision_for_esub();

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
    framerate_controlling();
}


