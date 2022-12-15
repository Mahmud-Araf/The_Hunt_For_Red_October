#include"stages.hpp"

bool is_running=true;

Uint32 mainmenu_delay=0;
enum STAGE stage;

MainMenu mainmenu;

GameLevels gamelevels;

Controls controls;

Credit credit;

Button backBS;



void MainMenu::init()
{
    Bw=300;
    Bh=100;
    Bspacing=40;
    levelmenuflag=false;
    
    //start button 
    startgameBS.Bdest.x=200;
    startgameBS.Bdest.y=100;
    startgameBS.Bdest.w=Bw;
    startgameBS.Bdest.h=Bh;
    startgameBS.tex1=startgameB1;
    startgameBS.tex2=startgameB2;

    //controls button
    controlsBS.Bdest.x=200;
    controlsBS.Bdest.y=100+Bh+Bspacing;
    controlsBS.Bdest.w=Bw;
    controlsBS.Bdest.h=Bh;
    controlsBS.tex1=controlsB1;
    controlsBS.tex2=controlsB2;

    //highscores button
    highscoresBS.Bdest.x=200;
    highscoresBS.Bdest.y=100+2*Bh+2*Bspacing;
    highscoresBS.Bdest.w=Bw;
    highscoresBS.Bdest.h=Bh;
    highscoresBS.tex1=hscoresB1;
    highscoresBS.tex2=hscoresB2;

    //credit button
    creditBS.Bdest.x=200;
    creditBS.Bdest.y=100+3*Bh+3*Bspacing;
    creditBS.Bdest.w=Bw;
    creditBS.Bdest.h=Bh;
    creditBS.tex1=creditB1;
    creditBS.tex2=creditB2;

    //exit button 
    exitgameBS.Bdest.x=200;
    exitgameBS.Bdest.y=100+4*Bh+4*Bspacing;
    exitgameBS.Bdest.w=Bw;
    exitgameBS.Bdest.h=Bh;
    exitgameBS.tex1=exitB1;
    exitgameBS.tex2=exitB2;

    //level1 easy button
    level1BS.Bdest.x=FSW/2-250;
    level1BS.Bdest.y=FSH/2-250;
    level1BS.Bdest.w=500;
    level1BS.Bdest.h=Bh+50;
    level1BS.tex1=level1B1;
    level1BS.tex2=level1B2;

    //level2 hard button
    level2BS.Bdest.x=FSW/2-250;
    level2BS.Bdest.y=FSH/2+100;
    level2BS.Bdest.w=500;
    level2BS.Bdest.h=Bh+50;
    level2BS.tex1=level2B1;
    level2BS.tex2=level2B2;

    //back button
    backBS.Bdest.x=50;
    backBS.Bdest.y=FSH-150;
    backBS.Bdest.w=Bw;
    backBS.Bdest.h=Bh;
    backBS.tex1=backB1;
    backBS.tex2=backB2;
}


void MainMenu::render()
{
    if(!levelmenuflag)
    {
        SDL_RenderCopy(gameRenderer,mainmenuBG,NULL,NULL);
        startgameBS.render();
        controlsBS.render();
        highscoresBS.render();
        creditBS.render();
        exitgameBS.render();
    }
    else
    {
        SDL_RenderCopy(gameRenderer,levelmenuBG,NULL,NULL);
        level1BS.render();
        level2BS.render();
        backBS.render();
    }

}


void MainMenu::handle_event()
{
    SDL_PollEvent(&e);
    
    int x,y;

    SDL_GetMouseState(&x,&y);

    if(!levelmenuflag)
    {
        if(startgameBS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                levelmenuflag=true;
            }
        }
        else if(controlsBS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                stage=CONTROLS;
            }
        }
        else if(highscoresBS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
            
            }
        }
        else if(creditBS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                stage=CREDIT;
            }
        }
        else if(exitgameBS.check_inside(x,y))
        {
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                is_running=false;
            }
        }
    }
    else
    {
        if(level1BS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                stage=LEVEL1;

                score=0;

                gamelevels.game_obj_func_init();
            }
        }
        else if(level2BS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                stage=LEVEL2;

                score=0;

                gamelevels.game_obj_func_init();
            }
        }

        back_handle_event();
    }
    
}


void MainMenu::run()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);

     handle_event();

     render();

     music_handle_event();
     pause_music();
     resume_music();

     if(e.type==SDL_QUIT)
     {
        is_running=false;
     }

     mainmenu_delay=SDL_GetTicks();
     
     SDL_RenderPresent(gameRenderer);
}


void GameLevels::game_obj_func_init()
{
    player.init();
    gamebackground.init();
    enemy_sub_set.init();
    enemy_ship_set.init();
    esub_increment_start_time=0;
    esub_increment_count_time=0;
    eship_increment_start_time=0;
    eship_increment_count_time=0;
    total_sub=PRIMARY_ESUB_N;
    total_ship=PRIMARY_ESHIP_N;
    current_time=0;
    missile_collision_init();
    ptorp_collision_init();
    start_music();
}


void GameLevels::run_levelOne()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);

    music_handle_event();
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
    else if(e.type==SDL_KEYDOWN)
    {
        if(e.key.keysym.sym==SDLK_BACKSPACE)
        {
            stage=MAIN_MENU;
            mainmenu.levelmenuflag=false;
        }
    }

    SDL_RenderPresent(gameRenderer);
    framerate_controlling();
}


void GameLevels::run_levelTwo()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);

    music_handle_event();
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
    else if(e.type==SDL_KEYDOWN)
    {
        if(e.key.keysym.sym==SDLK_BACKSPACE)
        {
            stage=MAIN_MENU;
            mainmenu.levelmenuflag=false;
        }
    }

    SDL_RenderPresent(gameRenderer);
    framerate_controlling();
}


void Controls::render()
{
    SDL_RenderCopy(gameRenderer,controlsBG,NULL,NULL);

    backBS.render();
}

void Controls::run()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);
    
    render();

    back_handle_event();
    music_handle_event();
    pause_music();
    resume_music();

    SDL_RenderPresent(gameRenderer);
}

void Credit::render()
{
    SDL_RenderCopy(gameRenderer,creditBG,NULL,NULL);

    backBS.render();
}

void Credit::run()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);

    render();

    back_handle_event();
    music_handle_event();
    pause_music();
    resume_music();

    SDL_RenderPresent(gameRenderer);
}

void back_handle_event()
{
    SDL_PollEvent(&e);
    
    int x,y;

    SDL_GetMouseState(&x,&y);

    if(backBS.check_inside(x,y))
    {   
        if(e.type==SDL_MOUSEBUTTONDOWN)
        {
           stage=MAIN_MENU;
           mainmenu.levelmenuflag=false;
        }
    }

    if(e.type==SDL_QUIT)
    {
        is_running=false;
    }
}