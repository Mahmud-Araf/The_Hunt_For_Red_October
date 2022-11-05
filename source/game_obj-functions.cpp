#include"game_obj-functions.hpp"
#include"texture_music.hpp"
#include"global.hpp"
#include"media.hpp"

//game object structures and variables

//game obj structures
Player player;
Background background;
Enemy_Sub_Set enemy_sub_set;
Enemy_Ship_Set enemy_ship_set;


//necessary variables
SDL_Event e;
int is_paused=0; // variable to pause the game

int first_time_torp_launch=0;  
                                 // variables to make sure that first torp or missile launch doesn't cause time delay
int first_time_missile_launch=0;

int player_x_pos;
                  //global variable to store the x and y co-ordinates of player submarine
int player_y_pos;

int esub_x_pos;
                 //global variable to store the x and y co-ordinates of enemy submarine
int esub_y_pos;

int eship_x_pos;
                 //global variable to store the x and y co-ordinates of enemy ship
int eship_y_pos;

int eship_w;
            //global variable to store the width and height of a enemy ship
int eship_h;

int total_sub=PRIMARY_ESUB_N;
int esub_increment_start_time=0;
int esub_increment_count_time=0;

int total_ship=PRIMARY_ESHIP_N;
int eship_increment_start_time=0;
int eship_increment_count_time=0;

//global variable necessary for missile collision
int mcollision_start[E_SHIP_N];
int mcollision_count[E_SHIP_N];
SDL_Rect mcollision_area[E_SHIP_N];
SDL_Rect mcollision_source[S_COLLISION_N];
int mcollision_sprite_num[E_SHIP_N];



//functions


void Torpedo::p_init()
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

void Torpedo::e_init()
{
    SDL_QueryTexture(player_torpObj,0,0,&t_dim.w,&t_dim.h);

    //torpedo dimension
    t_dim.x=3000;
    t_dim.y=3000;
    t_dim.w=(int)t_dim.w*0.7;
    t_dim.h=(int)t_dim.h*0.7;

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

void Torpedo::launch_single_etorp()
{
     if(is_active)
    {
        if(!xy_check)
        {
            t_dim.x=esub_x_pos-70;
            t_dim.y=esub_y_pos+50;
            xy_check=1;
        }

        SDL_RenderCopyEx(gameRenderer,enemy_torpObj,0,&t_dim,0,0,SDL_FLIP_HORIZONTAL);

        if(!is_paused)
        {
        t_dim.x-=E_TORP_SPEED;
        }
        if(t_dim.x<=-500)
        {
            is_active=0;
            xy_check=0;
            t_dim.x=-3000;
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


void Missile::renewal()
{
    is_active=0;
    xy_check=0;
    x_check=0;
    m1_dim.x=3000;
    m2_dim.x=3000;

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


void Mine::init()
{
    SDL_QueryTexture(player_torpObj,0,0,&mine_dim.w,&mine_dim.h);

    //mine dimension
    mine_dim.x=3000;
    mine_dim.y=3000;
    mine_dim.w=(int)mine_dim.w*0.06;
    mine_dim.h=(int)mine_dim.h*0.06;

    //mine variable initialization
    is_active=0;
    xy_check=0;
}


void Mine::render()
{
    SDL_RenderCopy(gameRenderer,enemy_mineObj,0,&mine_dim);
}


void Mine::drop_single_mine()
{
   if(is_active)
   {
      if(!xy_check)
      {
        mine_dim.x=eship_x_pos+eship_w/2-25;
        mine_dim.y=eship_y_pos+eship_h/2+25;
        xy_check=1;
      }

      render();

      y_move_count=SDL_GetTicks()-y_move_start;

      if(!is_paused)
      {
        if(mine_dim.y<=600)
        {
            mine_dim.y+=(E_MINE_SPEED/2);
        }
        else
        {
            mine_dim.x-=(E_MINE_SPEED/6)*5;
            if(y_move_count>E_MINE_Y_DELAY)
            {
               if(mine_dim.y>player_y_pos+315)
               {
                 mine_dim.y-=6;
                 y_move_start=SDL_GetTicks();
               }
               else if(mine_dim.y<player_y_pos+275)
               {
                 mine_dim.y+=6;
                 y_move_start=SDL_GetTicks();
               }
            }
        }
        if(mine_dim.x<=-500)
        {
            is_active=0;
            xy_check=0;
            mine_dim.x=-3000;
        }
      }
      
   }
}


void Background::init()
{
    SDL_QueryTexture(gameBG,0,0,&bg_width,0);

    for(int i=0;i<BG_N;i++)
    {
        bg_dim[i].x=0;
        bg_dim[i].y=0;
        bg_dim[i].w=FSW;
        bg_dim[i].h=FSH;
    }
}


void Background::scroll()
{
    bg_dim[0].x=scrolling_perframe;
    bg_dim[1].x=scrolling_perframe+bg_width-615;

    if(!is_paused)
    {
        scrolling_perframe-=SPF;
    }
    if(scrolling_perframe<-(bg_width-615))
    {
        scrolling_perframe=0;
    }

}

void Background::render()
{
    SDL_RenderCopy(gameRenderer,gameBG,0,&bg_dim[0]);
    SDL_RenderCopy(gameRenderer,gameBG,0,&bg_dim[1]);
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
        player_torps[i].p_init();
    }

    for(int i=0;i<P_MISSILE_N;i++)
    {
        player_missiles[i].init();
    }

    step=5;
    is_exploded=0;
    is_started=0;
    is_counting=0;
    ptorp_launch_start=0;
    ptorp_launch_count=0;
    pmissile_launch_start=0;
    pmissile_launch_count=0;
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
            if (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s)
            {
                p_dim.y +=step;
                if (p_dim.y >= 620)
                {
                    p_dim.y = 620;
                }
            }
            else if (e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)
            {
                p_dim.y -=step;
                if (p_dim.y <= 330)
                {
                    p_dim.y = 330;
                }
            }
            else if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d)
            {
                p_dim.x +=step;

                if(p_dim.x>=WINDOW_WIDTH-160)
                {
                    p_dim.x=WINDOW_WIDTH-160;
                }
            }
            else if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a)
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
        ptorp_launch_count= SDL_GetTicks() - ptorp_launch_start;
      
        if (e.button.button == SDL_BUTTON_LEFT && (ptorp_launch_count > P_TORP_DELAY || first_time_torp_launch==0))
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
            ptorp_launch_start = SDL_GetTicks();
        }
    }
}


void Player::handle_event_missiles()
{    
     SDL_PollEvent(&e);
   
     if (e.type == SDL_MOUSEBUTTONDOWN && is_paused==0)
     {
            pmissile_launch_count= SDL_GetTicks() - pmissile_launch_start;

            if (e.button.button == SDL_BUTTON_RIGHT && (pmissile_launch_count > P_MISSILE_DELAY ||first_time_missile_launch== 0))
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
                pmissile_launch_start= SDL_GetTicks();
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


void Enemy_Sub::render()
{
  if(!is_exploded)
  {
    SDL_RenderCopyEx(gameRenderer,enemy_subObj,NULL,&esub_dim,0,0,SDL_FLIP_HORIZONTAL);
  }
}


void Enemy_Sub::single_sub_launch()
{
    if(!is_paused)
    {
        etorp_launch_count=SDL_GetTicks()-etorp_launch_start;

        if(etorp_launch_count>E_TORP_DELAY && is_exploded==0 && esub_dim.x<=WINDOW_WIDTH-100)
        {
            for(int j=0;j<E_TORP_N;j++)
            {
                if(e_torps[j].is_active==0)
                {
                    e_torps[j].is_active=1;
                    break;
                }
            }
            etorp_launch_start=SDL_GetTicks();
        }
    }
    esub_x_pos=esub_dim.x;
    esub_y_pos=esub_dim.y;

    for(int j=0;j<E_TORP_N;j++)
    {
        e_torps[j].launch_single_etorp();
    }
    
}


void Enemy_Sub_Set::init()
{
    int w=0,h=0;
    SDL_QueryTexture(enemy_subObj,0,0,&w,&h);

    for(int i=0;i<E_SUB_N;i++)
    {
        int random=rand()%6;

        switch (random)
        {
        case 0:
            e_sub[i].esub_dim={WINDOW_WIDTH+300,380,(int)(w*0.8),(int)(h*0.8)};
            break;

        case 1:
            e_sub[i].esub_dim={WINDOW_WIDTH+300,450,(int)(w*0.8),(int)(h*0.8)};
            break;
        
        case 2:
            e_sub[i].esub_dim={WINDOW_WIDTH+300,500,(int)(w*0.8),(int)(h*0.8)};
            break;
        
        case 3:
            e_sub[i].esub_dim={WINDOW_WIDTH+300,550,(int)(w*0.8),(int)(h*0.8)};
            break;
        
        case 4:
            e_sub[i].esub_dim={WINDOW_WIDTH+300,600,(int)(w*0.8),(int)(h*0.8)};
            break;
        
        case 5:
            e_sub[i].esub_dim={WINDOW_WIDTH+300,630,(int)(w*0.8),(int)(h*0.8)};
            break;

        default:
            e_sub[i].esub_dim={WINDOW_WIDTH,590,(int)(w*0.8),(int)(h*0.8)};
            break;
        }
        
        for(int j=0;j<E_TORP_N;j++)
        {
            e_sub[i].e_torps[j].e_init();
        }
        e_sub[i].is_started=0;
        e_sub[i].is_counting=0;
        e_sub[i].is_exploded=0;

    }

    xmove_setting();
}

void Enemy_Sub_Set::render()
{
    for(int i=0;i<total_sub;i++)
    {
        e_sub[i].render();
    }
}


void Enemy_Sub_Set::increment()
{
    esub_increment_count_time=SDL_GetTicks()-esub_increment_start_time;

    if(esub_increment_count_time>INCREMENT_SUB && total_sub<E_SUB_N && !is_paused)
    {
        total_sub++;
        esub_increment_start_time=SDL_GetTicks();

    }
}


void Enemy_Sub_Set::xmove_setting()
{
    for(int i=0;i<E_SUB_N;i++)
    {
        int random=rand()%9;
        switch(random)
        {
            case 3:
                esub_speed[i]=3;
                break;
            case 4:
                esub_speed[i]=4;
                break;
            case 5:
                esub_speed[i]=5;
                break;
            case 6:
                esub_speed[i]=6;
                break;
            default:
                esub_speed[i]=2;
                break;
        }
    }
    
}

void Enemy_Sub_Set::xmove()
{
    if(!is_paused)
    {
    for(int i=0;i<total_sub;i++)
    {
        e_sub[i].esub_dim.x-=esub_speed[i];

        if(e_sub[i].esub_dim.x<=-500)
        {
                e_sub[i].esub_dim.x=WINDOW_WIDTH+300;
        }
    }
    }
    
}

void Enemy_Sub_Set::ymove()
{

    if(!is_paused)
    {
        for(int i=0;i<total_sub;i++)
        {   
            if (e_sub[i].esub_dim.y >= 670)
            {
                y_limit_check[i] = 1;
            }
            else if (e_sub[i].esub_dim.y <= 360)
            {
                y_limit_check[i] = 0;
            }


            if(y_limit_check[i])
            {
                if(i%5==0)
                {
                    e_sub[i].esub_dim.y-=1;
                }
                else if(i%5==1)
                {
                    e_sub[i].esub_dim.y-=2;
                }
                else if(i%5==2)
                {
                    e_sub[i].esub_dim.y-=3;
                }
                else if(i%5==3)
                {
                    e_sub[i].esub_dim.y-=4;
                }
                else if(i%5==4)
                {
                    e_sub[i].esub_dim.y-=5;
                }
            }
            else 
            {
                if(i%5==0)
                {
                    e_sub[i].esub_dim.y+=1;
                }
                else if(i%5==1)
                {
                    e_sub[i].esub_dim.y+=2;
                }
                else if(i%5==2)
                {
                    e_sub[i].esub_dim.y+=3;
                }
                else if(i%5==3)
                {
                    e_sub[i].esub_dim.y+=4;
                }
                else if(i%5==4)
                {
                    e_sub[i].esub_dim.y+=5;
                }
            }
        }
    }
}

void Enemy_Sub_Set::launch_torps()
{
    for(int i=0;i<total_sub;i++)
    {
        e_sub[i].single_sub_launch();
    }
}


void Enemy_Ship::render()
{
   if(!is_exploded)
   {
     SDL_RenderCopyEx(gameRenderer,enemy_shipObj,NULL,&eship_dim,0,0,SDL_FLIP_HORIZONTAL);
   }
}


void Enemy_Ship::single_ship_drop()
{
    if(!is_paused)
    {
        emine_launch_count=SDL_GetTicks()-emine_launch_start;

        if(emine_launch_count>E_MINE_DELAY && !is_exploded && eship_dim.x<=WINDOW_WIDTH-100)
        {
            for(int j=0;j<E_MINE_N;j++)
            {
                if(emines[j].is_active==0)
                {
                    emines[j].is_active=1;
                    break;
                }
            }
            emine_launch_start=SDL_GetTicks();
        }
    }
    
    eship_x_pos=eship_dim.x;
    eship_y_pos=eship_dim.y;

    for(int j=0;j<E_MINE_N;j++)
    {
        emines[j].drop_single_mine();
    }
}


void Enemy_Ship_Set::init()
{
    int w=0,h=0;
    SDL_QueryTexture(enemy_shipObj,0,0,&w,&h);
    
    eship_w=(int)(w*0.25);
    eship_h=(int)(h*0.25);

    for(int i=0;i<E_SHIP_N;i++)
    {
        
        e_ship[i].eship_dim={WINDOW_WIDTH+300,495,(int)(w*0.25),(int)(h*0.25)};
        
        for(int j=0;j<E_MINE_N;j++)
        {
           e_ship[i].emines[j].init();
        }
        e_ship[i].is_started=0;
        e_ship[i].is_counting=0;
        e_ship[i].is_exploded=0;

    }

    xmove_setting();
}


void Enemy_Ship_Set::xmove_setting()
{
    for(int i=0;i<E_SHIP_N;i++)
    {
        int r=i%5;
        switch(r)
        {
            case 0:
                eship_speed[i]=4;
                break;
            case 1:
                eship_speed[i]=5;
                break;
            case 2:
                eship_speed[i]=6;
                break;
            case 3:
                eship_speed[i]=7;
                break;
            default:
                eship_speed[i]=6;
                break;
        }
    }
}


void Enemy_Ship_Set::render()
{
    for(int i=0;i<total_ship;i++)
    {
        e_ship[i].render();
    }
}


void Enemy_Ship_Set::increment()
{
    eship_increment_count_time=SDL_GetTicks()-eship_increment_start_time;

    if(eship_increment_count_time>INCREMENT_SHIP && total_ship<E_SHIP_N &&!is_paused)
    {
        total_ship++;
        eship_increment_start_time=SDL_GetTicks();

    }
}


void Enemy_Ship_Set::xmove()
{
    for(int i=0;i<total_ship;i++)
    {
        if(!is_paused)
        {
          e_ship[i].eship_dim.x-=eship_speed[i];
        }
        if(e_ship[i].eship_dim.x<=-500)
        {
           e_ship[i].eship_dim.x=WINDOW_WIDTH+300;
           e_ship[i].is_exploded=0;
        }
    }
}


void Enemy_Ship_Set::launch_mines()
{
    for(int i=0;i<total_ship;i++)
    {
        e_ship[i].single_ship_drop();
    }
}


void missile_collision_init()
{
    mcollision_source[0]={0,0,240,560};
    mcollision_source[1]={240,0,300,560};
    mcollision_source[2]={540,0,360,560};
    mcollision_source[3]={900,0,480,560};
    for(int i=0;i<E_SHIP_N;i++)
    {
        mcollision_area[i]={0,0,250,270};
        mcollision_sprite_num[i]=0;
    }
}


void missile_collision_for_eship()
{
    for(int i=0;i<total_ship;i++)
    {
        for(int j=0;j<P_MISSILE_N;j++)
        {
            if(enemy_ship_set.e_ship[i].is_exploded==0 && enemy_ship_set.e_ship[i].eship_dim.x<=WINDOW_WIDTH+300)
            {
                if(enemy_ship_set.e_ship[i].eship_dim.x<=player.player_missiles[j].m2_dim.x && enemy_ship_set.e_ship[i].eship_dim.x+300>=player.player_missiles[j].m2_dim.x)
                {
                    enemy_ship_set.e_ship[i].is_exploded=1;
                    player.player_missiles[j].renewal();
                    mcollision_area[i].x=enemy_ship_set.e_ship[i].eship_dim.x+20;
                    mcollision_area[i].y=enemy_ship_set.e_ship[i].eship_dim.y-145;
                    mcollision_sprite_num[i]=0;
                    Mix_PlayChannel(-1,explosion_surface_chunk,0);
                    mcollision_start[i]=SDL_GetTicks();
                    score++;
                    break;
                }
            }
        }
        if(enemy_ship_set.e_ship[i].is_exploded==1 && mcollision_sprite_num[i]<=3)
        {
           mcollision_count[i]=SDL_GetTicks()-mcollision_start[i];
           if(mcollision_count[i]<=EXP_DELAY)
           {
                SDL_RenderCopy(gameRenderer,explo_surfaceObj,&mcollision_source[mcollision_sprite_num[i]],&mcollision_area[i]);
                if(!is_paused)
                {
                    mcollision_area[i].x-=EXP_SPEED;
                }
           }
           else if(mcollision_count[i]>EXP_DELAY && is_paused==1)
           {
             SDL_RenderCopy(gameRenderer,explo_surfaceObj,&mcollision_source[mcollision_sprite_num[i]],&mcollision_area[i]);
             mcollision_start[i]=SDL_GetTicks();
           }
           else
           { 
                mcollision_sprite_num[i]++;
                if(mcollision_sprite_num[i]<=3)
                {
                Mix_PlayChannel(-1,explosion_surface_chunk,0);
                }
                mcollision_start[i]=SDL_GetTicks();
           }
        }
        
    }
}
