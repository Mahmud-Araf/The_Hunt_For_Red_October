#include"header.hpp"


int main()
{
    
    
    gameinit();
    if(!loadMedia())
    {
        cout<<"Failed to load Media"<<endl;
    }

    mainmenu.init();
    utilities_init();
    game_obj_func_init();


    while(is_running)
    {   
        if(mainmenu.running)
        {
            mainmenu.run();
        }
        else if(gamelevels.one_running)
        {
            gamelevels.run_levelOne();
        }
        else if(gamelevels.two_running)
        {
            gamelevels.run_levelTwo();
        }
    }

    closeMedia();
    closeFont();
    gameclose();



    return 0;
}