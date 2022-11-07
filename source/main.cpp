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
        font_init();
        missile_collision_init();
        ptorp_collision_init();
        start_music();
        while(1)
        {
            SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
            SDL_RenderClear(gameRenderer);
            pause_music();
            resume_music();
            background.render();
            background.scroll();
            player.render();
            missile_collision_for_eship();
            ptorp_collision_for_esub();
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
            fps_show();
            time_show();
            score_board();
        if(e.type==SDL_QUIT)
        {
            break;
        }
        SDL_RenderPresent(gameRenderer);
        frame_controlling();
        }
        
    }
    closeMedia();
    closeFont();
    gameclose();



    return 0;
}