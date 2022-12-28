#include"stages.hpp"

bool is_running=true; // variable related to core game loop

Uint32 mainmenu_delay=0; // variable to store the time spent in mainmenu

enum STAGE stage; 

MainMenu mainmenu;

GameLevels gamelevels;

Controls controls;

Credit credit;

HighScores highscores;

GameOver gameover;

Button mainmenuBS;

Button playagainBS;

Button backBS;

Button level1BS;

Button level2BS;

Button refreshBS;


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

    // mainmenu button
    mainmenuBS.Bdest.x=50;
    mainmenuBS.Bdest.y=FSH-120;
    mainmenuBS.Bdest.w=Bw;
    mainmenuBS.Bdest.h=Bh;
    mainmenuBS.tex1=mainmenuB1;
    mainmenuBS.tex2=mainmenuB2;

    //playagain button
    playagainBS.Bdest.x=FSW-400;
    playagainBS.Bdest.y=FSH-120;
    playagainBS.Bdest.w=Bw;
    playagainBS.Bdest.h=Bh;
    playagainBS.tex1=playagainB1;
    playagainBS.tex2=playagainB2;

    //refresh button
    refreshBS.Bdest.x=FSW-400;
    refreshBS.Bdest.y=FSH-120;
    refreshBS.Bdest.w=Bw;
    refreshBS.Bdest.h=Bh;
    refreshBS.tex1=refreshB1;
    refreshBS.tex2=refreshB2;

    //back button
    backBS.Bdest.x=50;
    backBS.Bdest.y=FSH-120;
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

    int x,y;

    SDL_GetMouseState(&x,&y);

    if(!levelmenuflag)
    {
        if(startgameBS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                levelmenuflag=true;
                current_time=0;
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
                stage=HIGHSCORES;
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

                gamelevels.levelmode=1;

                score=0;

                gamelevels.game_obj_func_init();
            }
        }
        else if(level2BS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                stage=LEVEL2;

                gamelevels.levelmode=2;

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

    if(SDL_GetTicks()-start_frame>1000/FPS)
    {
        frameN++;
        start_frame=SDL_GetTicks();
    }

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

    if(player.life==0)
    {
       stage=GAME_OVER;
    }
    else if(keystate[SDL_SCANCODE_BACKSPACE])
    {
        stage=GAME_OVER;
        mainmenu.levelmenuflag=false;
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

    if(player.life==0)
    {
       stage=GAME_OVER;
    }
    else if(keystate[SDL_SCANCODE_BACKSPACE])
    {
        stage=GAME_OVER;
        mainmenu.levelmenuflag=false;
    }

    SDL_RenderPresent(gameRenderer);
    framerate_controlling();
}


void GameOver::render()
{
    SDL_RenderCopy(gameRenderer,gameoverBG,NULL,NULL);

    loadTextSurfacewithRect("Your Score",Bold1F,black,SDL_Rect{FSW/2-200,200,400,150});
    
    loadTextSurfacewithRect(to_string(score),DigitalF,black,SDL_Rect{FSW/2-40,350,80,150});

    loadTextSurfacewithRect("Enter Your Name:",Bold1F,black,SDL_Rect{FSW/2-250,500,500,150});

    loadTextSurfacewithBG(name_input,Bold2F,red,FSW/2,650);

    mainmenuBS.render();

    playagainBS.render();
}


void GameOver::handle_event()
{
    SDL_StartTextInput();
    int x,y;

    SDL_GetMouseState(&x,&y);

    if(mainmenuBS.check_inside(x,y))
    {   
        if(e.type==SDL_MOUSEBUTTONDOWN)
        {
            stage=MAIN_MENU;

            highscores.save_highscores(name_input,score);
            highscores.scan_highscores();

            SDL_StopTextInput();

            name_input=" ";
            mainmenu.levelmenuflag=false;
        }
    }

    else if(playagainBS.check_inside(x,y))
    {   
        if(e.type==SDL_MOUSEBUTTONDOWN)
        {
            stage=MAIN_MENU;

            highscores.save_highscores(name_input,score);
            highscores.scan_highscores();

            SDL_StopTextInput();

            name_input=" ";
            mainmenu.levelmenuflag=true;
        }
    }

    else if(keystate[SDL_SCANCODE_RETURN])
    {
        stage=MAIN_MENU;

        highscores.save_highscores(name_input,score);
        highscores.scan_highscores();

        SDL_StopTextInput();

        name_input=" ";
        mainmenu.levelmenuflag=false;
    }
    
    if(e.type==SDL_TEXTINPUT)
    {
        if(name_input==" ")
        {
            name_input.pop_back();
        }

        name_input+=e.text.text;
    }

    if(keystate[SDL_SCANCODE_BACKSPACE] && (SDL_GetTicks()-delay_event)>100)
    {
        name_input.pop_back();
        if(name_input.size()==0)
        {
            name_input=" ";
        }
        delay_event=SDL_GetTicks();
    }
}


void GameOver::run()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);
    
    handle_event();
    music_handle_event();
    pause_music();
    resume_music();

    render();

    if(e.type==SDL_QUIT)
    {
       is_running=false;
    }

    if(SDL_GetTicks()-start_frame>1000/FPS)
    {
        frameN++;
        start_frame=SDL_GetTicks();
    }

    SDL_RenderPresent(gameRenderer);
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

    if(e.type==SDL_QUIT)
    {
        is_running=false;
    }

    if(SDL_GetTicks()-start_frame>1000/FPS)
    {
        frameN++;
        start_frame=SDL_GetTicks();
    }

    SDL_RenderPresent(gameRenderer);
}


void HighScores::scan_highscores()
{
    l1_file=fopen("assets/IO/level1hscores.txt","r");

    if(l1_file==NULL)
    {
        cout<<"LEVEL 1 Highscores file is failed to open"<<endl;
    }

    l2_file=fopen("assets/IO/level2hscores.txt","r");

    if(l2_file==NULL)
    {
        cout<<"LEVEL 2 Highscores file is failed to open"<<endl;
    }

    for(int i=0;i<PLAYER_N_HSCORE;i++)
    {
        char c;
        p_namel1[i]="";
        while((c=fgetc(l1_file))!='\n')
        {
            p_namel1[i]+=c;
        }
    }

    for(int i=0;i<PLAYER_N_HSCORE;i++)
    {
        char c;
        p_namel2[i]="";
        while((c=fgetc(l2_file))!='\n')
        {
            p_namel2[i]+=c;
        }
    }

    for(int i=0;i<PLAYER_N_HSCORE;i++)
    {
        fscanf(l1_file,"%d",&p_scorel1[i]);
    }

    for(int i=0;i<PLAYER_N_HSCORE;i++)
    {
        fscanf(l2_file,"%d",&p_scorel2[i]);
    }


    fclose(l1_file);
    fclose(l2_file);

}


void HighScores::print_highscores(string p_name[],int p_score[])
{
    int x_spacing=500;
    int y_spacing=80;
    int width=200;
    int height=150;

    loadTextSurfacewithRect("SERIAL",Bold1F,white,SDL_Rect{150,50,width,height});
    loadTextSurfacewithRect("NAME",Bold1F,white,SDL_Rect{150+x_spacing+width,50,width,height});
    loadTextSurfacewithRect("SCORE",Bold1F,white,SDL_Rect{150+2*x_spacing+width*2,50,width,height});
    
    for(int i=1;i<=PLAYER_N_HSCORE;i++)
    {
       loadTextSurface(to_string(i)+".",DigitalF,white,150,200+i*y_spacing+(i-1)*(height-100));
       loadTextSurface(p_name[PLAYER_N_HSCORE-i],Bold2F,white,150+x_spacing+width,200+i*y_spacing+(i-1)*(height-100));
       loadTextSurface(to_string(p_score[PLAYER_N_HSCORE-i]),DigitalF,white,150+2*x_spacing+2*width,200+i*y_spacing+(i-1)*(height-100));
    }
}


void HighScores::save_highscores(string name, int score)
{
    
    if(gamelevels.levelmode==1)
    {
        if(score>=p_scorel1[0])
        {
            p_scorel1[0]=score;

            if(name==" " || name=="")
            {
               p_namel1[0]="Anonymous";
            }
            else
            {
               p_namel1[0]=name;
            }
            

            //selection sort
            for(int i=0;i<PLAYER_N_HSCORE-1;i++)
            {
                for(int j=i+1;j<PLAYER_N_HSCORE;j++)
                {
                    if(p_scorel1[i]>p_scorel1[j])
                    {
                        swap(p_scorel1[i],p_scorel1[j]);
                        swap(p_namel1[i],p_namel1[j]);

                    }
                }
            }

            l1_file=fopen("assets/IO/level1hscores.txt","w");

            if(l1_file==NULL)
            {
                cout<<"LEVEL 1 Highscores file is failed to open"<<endl;
            }

            for(auto i:p_namel1)
            {
                fprintf(l1_file,"%s\n",(char*)i.c_str());
            }
            for(auto i:p_scorel1)
            {
                fprintf(l1_file,"%d\n",i);
            }

            fclose(l1_file);
        }
    }

    else if(gamelevels.levelmode==2)
    {
        if(score>=p_scorel2[0])
        {
            p_scorel2[0]=score;

            if(name==" "|| name=="")
            {
               p_namel2[0]="Anonymous";
            }
            else
            {
               p_namel2[0]=name;
            }

            //selection sort
            for(int i=0;i<PLAYER_N_HSCORE-1;i++)
            {
                for(int j=i+1;j<PLAYER_N_HSCORE;j++)
                {
                    if(p_scorel2[i]>p_scorel2[j])
                    {
                        swap(p_scorel2[i],p_scorel2[j]);
                        swap(p_namel2[i],p_namel2[j]);
                    }
                }
            }

            l2_file=fopen("assets/IO/level2hscores.txt","w");
  
            if(l2_file==NULL)
            {
                cout<<"LEVEL 2 Highscores file is failed to open"<<endl;
            }

            for(auto i:p_namel2)
            {
                fprintf(l2_file,"%s\n",(char*)i.c_str());
            }
            for(auto i:p_scorel2)
            {
                fprintf(l2_file,"%d\n",i);
            }

            fclose(l2_file);
        }
    }
}


void HighScores::refresh_highscores(int x)
{
    if(x==1)
    {
        for(int i=0;i<PLAYER_N_HSCORE;i++)
        {
            p_namel1[i]="empty";
            p_scorel1[i]=0;
        }

        l1_file=fopen("assets/IO/level1hscores.txt","w");

        if(l1_file==NULL)
        {
            cout<<"LEVEL 1 Highscores file is failed to open"<<endl;
        }

        for(auto i:p_namel1)
        {
            fprintf(l1_file,"%s\n",(char*)i.c_str());
        }
        for(auto i:p_scorel1)
        {
            fprintf(l1_file,"%d\n",i);
        }

        fclose(l1_file);
    }
    else if(x==2)
    {
        for(int i=0;i<PLAYER_N_HSCORE;i++)
        {
            p_namel2[i]="empty";
            p_scorel2[i]=0;
        }

        l2_file=fopen("assets/IO/level2hscores.txt","w");

        if(l2_file==NULL)
        {
            cout<<"LEVEL 2 Highscores file is failed to open"<<endl;
        }

        for(auto i:p_namel2)
        {
            fprintf(l2_file,"%s\n",(char*)i.c_str());
        }
        for(auto i:p_scorel2)
        {
            fprintf(l2_file,"%d\n",i);
        }

        fclose(l2_file);
    }
}


void HighScores::render()
{
    if(!levelmenuflag)
    {
        SDL_RenderCopy(gameRenderer,hscoresBG1,NULL,NULL);

        level1BS.render();
        level2BS.render();
        backBS.render();
    }
    else
    {
        SDL_RenderCopy(gameRenderer,hscoresBG2,NULL,NULL);

        backBS.render();
        refreshBS.render();

        if(levelmode==1)
        {
            print_highscores(p_namel1,p_scorel1);
        }
        else if(levelmode==2)
        {
            print_highscores(p_namel2,p_scorel2); 
        }
    }
}


void HighScores::handle_event()
{
   int x,y;

   SDL_GetMouseState(&x,&y);

   if(!levelmenuflag)
   {
       
       if(level1BS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                levelmenuflag=true;
                levelmode=1;
            }
        }
        else if(level2BS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                levelmenuflag=true;
                levelmode=2;
            }
        }
   }
   else
   {
        if(refreshBS.check_inside(x,y))
        {   
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                refresh_highscores(levelmode);
            }
        }
   }
}


void HighScores::run()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);
    
    handle_event();
    back_handle_event();
    music_handle_event();
    pause_music();
    resume_music();

    render();

    if(e.type==SDL_QUIT)
    {
       is_running=false;
    }

    if(SDL_GetTicks()-start_frame>1000/FPS)
    {
        frameN++;
        start_frame=SDL_GetTicks();
    }


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

    if(e.type==SDL_QUIT)
    {
        is_running=false;
    }

    if(SDL_GetTicks()-start_frame>1000/FPS)
    {
        frameN++;
        start_frame=SDL_GetTicks();
    }

    SDL_RenderPresent(gameRenderer);
}


void back_handle_event()
{
    
    int x,y;

    SDL_GetMouseState(&x,&y);

    if(backBS.check_inside(x,y))
    {   
        
        if(e.type==SDL_MOUSEBUTTONDOWN)
        {
            if(!highscores.levelmenuflag)
            {
                stage=MAIN_MENU;
                mainmenu.levelmenuflag=false;
            }

            else if(highscores.levelmenuflag)
            {
                stage=HIGHSCORES;
                highscores.levelmenuflag=false;
            }
        }
        
    }

    if(e.type==SDL_QUIT)
    {
        is_running=false;
    }
}