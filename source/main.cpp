#include"header.hpp"


int main()
{
    gameinit();

    if(loadMedia())
    {
        cout<<"media loaded"<<endl;
        player.init();
        background.init();
        enemy_sub_set.init();
        enemy_ship_set.init();
        while(1)
        {
            SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
            SDL_RenderClear(gameRenderer);
            background.render();
            background.scroll();
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
            player.launch_torps();
            player.launch_missiles();
            
            
        if(e.type==SDL_QUIT)
        {
            break;
        }
        SDL_RenderPresent(gameRenderer);
        SDL_Delay(1000/40);
        }
        
    }
    closeMedia();
    gameclose();



    return 0;
}