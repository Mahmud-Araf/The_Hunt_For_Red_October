#include"game_obj-functions.hpp"
#include"texture_music.hpp"
#include"global.hpp"
#include"media.hpp"

//game object structure and variable
Player player;
Enemy_Sub enemy_sub[E_Sub_N];
Enemy_Ship enemy_ship[E_Ship_N];

SDL_Event e;

int is_paused=0; // variable to pause the game
int first_time_torp_launch=0;  
                                 // variables to make sure that first torp or missile launch don't cause time delay
int first_time_missile_launch=0;

int player_x_pos;

int player_y_pos;

void Torpedo:: init()
{
    SDL_QueryTexture(player_torpObj,0,0,&t_dim.w,&t_dim.h);

    //torpedo dimension
    t_dim.x=3000;
    t_dim.y=3000;
    t_dim.w=(int)t_dim.w*0.8;
    t_dim.h=(int)t_dim.h*0.8;

    //torpedo variable initialization
    is_active=0;
    xy_check=0;
}

void Torpedo::render()
{
    SDL_RenderCopy(gameRenderer,player_torpObj,NULL,&t_dim);
}

void Torpedo::launch_single_ptorp()
{
    if(is_active)
    {
        if(!xy_check)
        {
            t_dim.x=player_x_pos+280;
            t_dim.y=player_y_pos+73;
            Mix_PlayChannel(-1,torpL_chunk,0);
            xy_check=1;
        }

        render();
        if(!is_paused)
        {
        t_dim.x+=P_TORP_SPEED;
        }
        if(t_dim.x>=1700)
        {
            is_active=0;
            xy_check=0;
            t_dim.x=3000;
        }


    }
}
void Missile::init()
{
    SDL_QueryTexture(player_missile1Obj,0,0,&m1_dim.w,&m1_dim.h);
    SDL_QueryTexture(player_missile2Obj,0,0,&m2_dim.w,&m2_dim.h);
    //missile1 dimension

    m1_dim.x=3000;
    m1_dim.y=3000;
    m1_dim.w=(int)m1_dim.w*0.2;
    m1_dim.h=(int)m1_dim.h*0.2;

    //missile2 dimension
    m2_dim.x=3000;
    m2_dim.y=3000;
    m2_dim.w=(int)m2_dim.w*0.2;
    m2_dim.h=(int)m2_dim.h*0.2;

    is_active=0;
    xy_check=0;
    x_check=0;
}

void Missile::render1()
{
    SDL_RenderCopy(gameRenderer,player_missile1Obj,0,&m1_dim);
}

void Missile::render2()
{
    SDL_RenderCopy(gameRenderer,player_missile2Obj,0,&m2_dim);
}

void Missile::launch_single_missile()
{
    if(is_active)
    {
        if(!xy_check)
        {
            m1_dim.x=player_x_pos+430;
            m1_dim.y=player_y_pos+180;
            Mix_PlayChannel(-1,missileL1_chunk,0);
            xy_check=1;
        }
        if(m1_dim.y>=525)
        {
            render1();
            if(!is_paused)
            {
            m1_dim.y-=(int)P_MISSILE_SPEED/2.0;
            }
        }
        else
        {
            if(!x_check)
            {
                m2_dim.x=m1_dim.x-5;
                m2_dim.y=m1_dim.y-50;
                Mix_PlayChannel(-1,missileL2_chunk,0);
                x_check=1;
            }

            render2();
            if(!is_paused)
            {
            m1_dim.x+=P_MISSILE_SPEED;
            m2_dim.x=m1_dim.x;
            }
        }
        if(m1_dim.x>=1850)
        {
            is_active=0;
            xy_check=0;
            x_check=0;
            m1_dim.x=3000;
            m2_dim.x=3000;
        }
    }
}

void Player::init()
{
    SDL_QueryTexture(player_subObj,0,0,&p_dim.w,&p_dim.h);
    player_x_pos=p_dim.x=-260;
    player_y_pos=p_dim.y=(int)(WINDOW_HEIGHT*0.35);
    p_dim.w=(int)p_dim.w*0.4;
    p_dim.h=(int)p_dim.h*0.4;

    for(int i=0;i<P_TORP_N;i++)
    {
        player_torps[i].init();
    }

    for(int i=0;i<P_MISSILE_N;i++)
    {
        player_missiles[i].init();
    }

    step=5;
    is_exploded=0;
    is_started=0;
    is_counting=0;
    p_torp_launch_start=0;
    p_torp_launch_count=0;
    p_missile_launch_start=0;
    p_missile_launch_count=0;
}

void Player::render()
{
    SDL_RenderCopy(gameRenderer,player_subObj,NULL,&p_dim);
}

void Player::handle_event_movement()
{
    SDL_PollEvent(&e);

    player_x_pos=p_dim.x;
    player_y_pos=p_dim.y;
    
    if (e.type == SDL_KEYDOWN)
    {   
        if(e.key.keysym.sym==SDLK_SPACE && is_paused==0)
        {
            is_paused=1;
        }
        else if(e.key.keysym.sym==SDLK_SPACE && is_paused==1)
        {
            is_paused=0;
        }
        if(!is_paused)
        {
            if (e.key.keysym.sym == SDLK_DOWN)
            {
                p_dim.y +=step;
                if (p_dim.y >= 620)
                {
                    p_dim.y = 620;
                }
            }
            else if (e.key.keysym.sym == SDLK_UP)
            {
                p_dim.y -=step;
                if (p_dim.y <= 330)
                {
                    p_dim.y = 330;
                }
            }
            else if (e.key.keysym.sym == SDLK_RIGHT)
            {
                p_dim.x +=step;

                if(p_dim.x>=WINDOW_WIDTH-160)
                {
                    p_dim.x=WINDOW_WIDTH-160;
                }
            }
            else if (e.key.keysym.sym == SDLK_LEFT)
            {
                p_dim.x -=step;
                if(p_dim.x<=-260)
                {
                    p_dim.x=-260;
                }
            }
        }
        
    }
    
        
    

}

void Player::handle_event_torps()
{
    SDL_PollEvent(&e);

    if (e.type == SDL_MOUSEBUTTONDOWN && is_paused==0)
    {
        p_torp_launch_count= SDL_GetTicks() - p_torp_launch_start;
      
        if (e.button.button == SDL_BUTTON_LEFT && (p_torp_launch_count > 500 || first_time_torp_launch==0))
        {
            if (is_exploded== 0)
            {
                for (int i = 0; i < 15; i++)
                {
                    if (player_torps[i].is_active== 0)
                    {
                        player_torps[i].is_active=1;
                        break;
                    }
                }
            }
            
            first_time_torp_launch++;
            p_torp_launch_start = SDL_GetTicks();
        }
    }
}

void Player::handle_event_missiles()
{    
     SDL_PollEvent(&e);
   
     if (e.type == SDL_MOUSEBUTTONDOWN && is_paused==0)
     {
            p_missile_launch_count= SDL_GetTicks() - p_missile_launch_start;

            if (e.button.button == SDL_BUTTON_RIGHT && ( p_missile_launch_count > 2500 ||first_time_missile_launch== 0))
            {

                if (is_exploded == 0)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        if (player_missiles[i].is_active== 0)
                        {
                            player_missiles[i].is_active=1;
                            break;
                        }
                    }
                }

                first_time_missile_launch++;
                p_missile_launch_start= SDL_GetTicks();
            }

     }
}
void Player::launch_torps()
{
    for(int i=0;i<P_TORP_N;i++)
    {
       player_torps[i].launch_single_ptorp();
    }
    
}

void Player::launch_missiles()
{
    for(int i=0;i<P_MISSILE_N;i++)
    {
        player_missiles[i].launch_single_missile();
    }
}