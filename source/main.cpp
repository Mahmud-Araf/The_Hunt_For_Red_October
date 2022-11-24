#include"header.hpp"


int main()
{
    
    
    gameinit();
    game_obj_func_init();

    while(is_running)
    {
        if(gamelevels.one_running)
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