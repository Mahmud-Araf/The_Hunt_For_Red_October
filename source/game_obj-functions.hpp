#ifndef OBJ_FUNCTIONS

#define OBJ_FUNCTIONS

#include"preprocessor.hpp"

extern SDL_Event e;

//collision variable for player missile explosion
extern int mcollision_start[E_SHIP_N];
extern int mcollision_count[E_SHIP_N];
extern SDL_Rect mcollision_area[E_SHIP_N];
extern SDL_Rect mcollision_source[S_COLLISION_N];
extern int mcollision_sprite_num[E_SHIP_N];

struct Torpedo
{
    SDL_Rect t_dim; //dimension for a torpedo

    int is_active; //variable to check if a torpedo is rendering or not

    int xy_check;  //variable to fix torpedos' dimension after it is launched
    
    //initializer for player torps
    void p_init();
     //initializer for enemy torps
    void e_init();

    //rendering
    void render();

    //player single torp launch
    void launch_single_ptorp();

    //enemy single torp launch
    void launch_single_etorp();

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

    //initialize necessary missile variable
    void renewal();

    //player missile launch
    void launch_single_missile();
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

    //enemy ship single mine drop
    void drop_single_mine();
};



struct Background 
{
    SDL_Rect bg_dim[BG_N]; // rectangle to hold background for scrolling

    int scrolling_perframe=0;

    int bg_width;//a variable to store the width of gameBG texture
    
    //initiate background
    void init();

    //scrolls the background
    void scroll();

    //background rendering
    void render();
};
extern Background background;


struct Player
{   
 
    SDL_Rect p_dim; //the rectangle of obj

    Torpedo player_torps[P_TORP_N]; // Torpedo structure for player torpedo

    Missile player_missiles[P_MISSILE_N]; // Missile1 structure for player missile type 1 & 2

    int step; //variable to move player up,down,left and right;
    int is_exploded; //variable to check whether player is exploded or not

    int is_started; // variable related to obj revival & explosion

    int is_counting; //variable related to obj revival & explosion

    int ptorp_launch_start;
                             //variables related to the time of player sub torpedo launching
    int ptorp_launch_count;

    int pmissile_launch_start;
                             //variables related to the time of player sub missile launching
    int pmissile_launch_count;

    //initializer
    void init();

    //rendering
    void render();

    //handles keyboard events to move player submarine
    void handle_event_movement();

    //handles mouse events to  launch torpedos
    void handle_event_torps();

    //handle mouse events to launch missiles
    void handle_event_missiles();

    //player torpedo launching
    void launch_torps();

    //player missile launching
    void launch_missiles();

};
extern Player player;


struct Enemy_Sub
{
    SDL_Rect esub_dim; //the rectangle of obj

    Torpedo e_torps[E_TORP_N]; // structure for enemy torpedoset of a single submarine

    int is_exploded; //variable to check whether player is exploded or not

    int is_started; // variable related to obj revival & explosion

    int is_counting; //variable related to obj revival & explosion

    int etorp_launch_start;
                             //variables related to the time of enemy sub torpedo launching
    int etorp_launch_count;

    //rendering
    void render();
    
    //single enemy_submarine torpedo firing
    void single_sub_launch();

};


struct Enemy_Sub_Set
{
    
    Enemy_Sub e_sub[E_SUB_N];

    int esub_speed[E_SUB_N];//array to store the speed of each submarine

    int y_limit_check[E_SUB_N]={};

    //initialize
    void init();

    //rendering
    void render();

    // increases the number of sub after a certain time
    void increment();

    //sets the speed of a enemy submarine in x axis
    void xmove_setting();
    
    //moves the submarine in x axis
    void xmove();

    //moves the submarine in x axis
    void ymove();

    //enemy submarines torpedo firing
    void launch_torps();
    
};
extern Enemy_Sub_Set enemy_sub_set;


struct Enemy_Ship
{
    SDL_Rect eship_dim; //the rectangle of obj

    Mine emines[E_MINE_N]; // structure for enemy mineset of a single ship

    int is_exploded; //variable to check whether player is exploded or not

    int is_started; // variable related to obj revival & explosion

    int is_counting; //variable related to obj revival & explosion

    int emine_launch_start;
                             //variables related to the time of enemy ship mine launching
    int emine_launch_count;

    //rendering
    void render();

    //single enemy ship mine dropping
    void single_ship_drop();

};

struct Enemy_Ship_Set
{
    
    Enemy_Ship e_ship[E_SHIP_N];

    int eship_speed[E_SHIP_N];
    
    //initializing
    void init();

    //rendering
    void render();

    // increases the number of ship after a certain time
    void increment();

    //sets the speed of a enemy ship in x axis
    void xmove_setting();
    
    //moves the submarine in x axis
    void xmove();

    //enemy ships mine dropping
    void launch_mines();
};

extern Enemy_Ship_Set enemy_ship_set;

void missile_collision_init(); // initializing missile collision variables

void missile_collision_for_eship();//function for rendering and detecting missile collision



#endif