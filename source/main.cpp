#include"header.hpp"

int main()
{
    gameinit();

    if(!loadMedia())
    {
        cout<<"Failed to load Media"<<endl;
    }

    mainmenu.init();
    highscores.scan_highscores();
    utilities_init();
    
    stage=MAIN_MENU;
    
    while(is_running)
    {   
        SDL_PollEvent(&e);
        
        switch(stage)
        {
            case MAIN_MENU:
                           mainmenu.run();
                           break;
            case CONTROLS:
                           controls.run();
                           break;
            case CREDIT:
                           credit.run();
                           break;
            case HIGHSCORES:
                           highscores.run();
                           break;
            case LEVEL1:
                           gamelevels.run_levelOne();
                           break;
            case LEVEL2:
                           gamelevels.run_levelTwo();
                           break;
            case GAME_OVER:
                           gameover.run();
                           break;
        } 
    }

    closeMedia();
    closeFont();
    gameclose();

    return 0;
}