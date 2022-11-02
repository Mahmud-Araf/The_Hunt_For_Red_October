#include"header.hpp"


int main()
{
    gameinit();

    if(loadMedia())
    {
        cout<<"media loaded"<<endl;
        player.init();
        while(1)
        {
           SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
           SDL_RenderClear(gameRenderer);
           SDL_RenderCopy(gameRenderer,gameBG,0,0);
            player.render();
            player.handle_event_movement();
            player.handle_event_torps();
            player.handle_event_missiles();
            player.launch_torps();
            player.launch_missiles();
            
        if(e.type==SDL_QUIT)
        {
            break;
        }
        SDL_RenderPresent(gameRenderer);
        SDL_Delay(1000/30);
        }
        
    }
    closeMedia();
    gameclose();



    return 0;
}