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
           for(int i=0;i<P_TORP_N;i++)
    {
       if(player.player_torps[i].is_active)
       {
          if(!player.player_torps[i].xy_check)
          {
            player.player_torps[i].t_dim.x=player.p_dim.x+270;
            player.player_torps[i].t_dim.y=player.p_dim.y+73;
            Mix_PlayChannel(-1,torpL,0);
            player.player_torps[i].xy_check=1;
          }
        
          player.player_torps[i].t_dim.x+=P_TORP_SPEED;
          
          SDL_RenderCopy(gameRenderer,player_torpObj,NULL,&player.player_torps[i].t_dim);
          if(player.player_torps[i].t_dim.x>=1680)
          {
            player.player_torps[i].is_active=0;
            player.player_torps[i].xy_check=0;
            player.player_torps[i].t_dim.x=3000;
          }

       }
    }
            
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