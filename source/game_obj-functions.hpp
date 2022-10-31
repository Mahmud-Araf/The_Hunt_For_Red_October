#ifndef OBJ_FUNCTIONS

#define OBJ_FUNCTIONS

#include"preprocessor.hpp"

extern SDL_Event e;


struct Torpedo
{
    SDL_Rect t_dim; //dimension for a torpedo

    int is_active; //variable to check if a torpedo is rendering or not

    int xy_check;  //variable to fix torpedos' dimension after it is launched
    
    //initializer
    void init();

};

struct Missile
{
    SDL_Rect m1_dim; //dimension for missile type1

    SDL_Rect m2_dim; //dimension for missile type2


    int is_active; //variable to check if a missile is rendering or not

    int xy_check;  
                   //variable to fix missiles' dimension after it is launched
    int x_check;
    //initializer
    void init();

    //rendering
    void render1(); //rendering for missile type 1

    void render2();//rendering for missile type 2

};



struct Mine
{
   SDL_Rect mine_dim;

   int is_active;//variable to check if a mine is rendering or not

   int xy_check; //variable to fix mines' dimension after it is launched

   int y_move_start;
                     //variables to count and set the time for mines to track player
   int y_move_count;

   //initializer
    void init();

    //rendering
    void render();
};

struct Player
{
    SDL_Rect p_dim; //the rectangle of obj

    Torpedo player_torps[P_TORP_N]; // Torpedo structure for player torpedo

    Missile player_missiles[P_MISSILE_N]; // Missile1 structure for player missile type 1 & 2
    
    int step; //variable to move player up,down,left and right;
    int is_exploded; //variable to check whether player is exploded or not

    int is_started; // variable related to obj revival & explosion

    int is_counting; //variable related to obj revival & explosion

    int p_torp_launch_start;
                             //variables related to the time of player sub torpedo launching
    int p_torp_launch_count;

    int p_missile_launch_start;
                             //variables related to the time of player sub missile launching
    int p_missile_launch_count;

    //initializer
    void init();

    //rendering
    void render();

    //handles keyboard and mouse inputs 
    void handle_event();

    //player torpedo launching
    void launch_torps();
   
   
};

extern Player player;

struct Enemy_Sub
{
    SDL_Rect esub_dim; //the rectangle of obj

    Torpedo e_torps[E_TORP_N]; // structure for enemy torpedoset of a single submarine

    int is_exploded; //variable to check whether player is exploded or not

    int is_started; // variable related to obj revival & explosion

    int is_counting; //variable related to obj revival & explosion

    int e_torp_launch_start;
                             //variables related to the time of enemy sub torpedo launching
    int e_torp_launch_count;

    //initializer
    void init();

    //rendering
    void render();

};

extern Enemy_Sub enemy_sub[E_Sub_N];

struct Enemy_Ship
{
    SDL_Rect eship_dim; //the rectangle of obj

    Mine e_mines[E_MINE_N]; // structure for enemy mineset of a single ship

    int is_exploded; //variable to check whether player is exploded or not

    int is_started; // variable related to obj revival & explosion

    int is_counting; //variable related to obj revival & explosion

    int e_mine_launch_start;
                             //variables related to the time of enemy ship mine launching
    int e_mine_launch_count;

    //initializer
    void init();

    //rendering
    void render();

};

extern Enemy_Ship enemy_ship[E_Ship_N];


#endif