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
            player.handle_event();
            player.launch_torps();
            
        if(e.type==SDL_QUIT)
        {
            break;
        }
        SDL_RenderPresent(gameRenderer);
        SDL_Delay(1000/30);
        }
        
    }
    closeMedia();
    close();



    return 0;
}