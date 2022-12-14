#ifndef OBJ_FUNCTIONS

#define OBJ_FUNCTIONS

#include"preprocessor.hpp"

extern SDL_Event e; // variable for event handling

//collision variable for player missile explosion
extern Uint32 mcollision_start[E_SHIP_N];
extern Uint32 mcollision_count[E_SHIP_N];
extern SDL_Rect mcollision_area[E_SHIP_N];
extern SDL_Rect mcollision_source[MISSILE_COLLISION_SN];
extern int mcollision_sprite_num[E_SHIP_N];

//collision variable for player torp explosion
extern Uint32 ptorp_collision_start[E_SUB_N];
extern Uint32 ptorp_collision_count[E_SUB_N];
extern SDL_Rect ptorp_collision_area[E_SUB_N];
extern SDL_Rect ptorp_collision_source[TORP_COLLISION_SN];
extern int ptorp_collision_sprite_num[E_SUB_N];

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

    void renewal();

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

    //reinitialize necessary missile variable
    void renewal();

    //player missile launch
    void launch_single_missile();
};


struct Mine
{
   SDL_Rect mine_dim;

   int is_active;//variable to check if a mine is rendering or not

   int xy_check; //variable to fix mines' dimension after it is launched

   Uint32 y_move_start;
                     //variables to count and set the time for mines to track player
   Uint32 y_move_count;

   //initializer
    void init();

    //rendering
    void render();

    //reinitialize necessary mine variable
    void renewal();

    //enemy ship single mine drop
    void drop_single_mine();
};



struct GameBackground 
{
    SDL_Texture *texBG; //texture to hold game background textures;

    SDL_Rect bg_dim[BG_N]; // rectangle to hold game background for scrolling

    int scrolling_perframe=0;

    //initiate game background
    void init();

    //scrolls the game background
    void scroll();

    //game background rendering
    void render();
};
extern GameBackground gamebackground;


struct Player
{   
 
    SDL_Rect p_dim; //the rectangle of obj

    Torpedo player_torps[P_TORP_N]; // Torpedo structure for player torpedo

    Missile player_missiles[P_MISSILE_N]; // Missile1 structure for player missile type 1 & 2

    int life; // variable to store life of player

    int step; //variable to move player up,down,left and right;

    int is_exploded; //variable to check whether player is exploded or not

    Uint32 is_started; // variable related to obj revival & explosion

    Uint32 is_counting; //variable related to obj revival & explosion

    Uint32 vibing_started;  //variable related to player vibrating after collision

    Uint32 vibing_counting; //variable related to player vibrating after collision

    Uint32 ptorp_launch_start;
                             //variables related to the time of player sub torpedo launching
    Uint32 ptorp_launch_count;

    Uint32 pmissile_launch_start;
                             //variables related to the time of player sub missile launching
    Uint32 pmissile_launch_count;

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

    //function for detecting and rendering player collision 
    void collision_for_player();

};
extern Player player;


struct Enemy_Sub
{
    SDL_Rect esub_dim; //the rectangle of obj

    Torpedo e_torps[E_TORP_N]; // structure for enemy torpedoset of a single submarine

    int is_exploded; //variable to check whether enemy sub is exploded or not

    Uint32 is_started; // variable related to obj revival & explosion

    Uint32 is_counting; //variable related to obj revival & explosion

    int revival=0;  // variable related to obj revival & explosion

    Uint32 etorp_launch_start;
                             //variables related to the time of enemy sub torpedo launching
    Uint32 etorp_launch_count;

    //rendering
    void render();
    
    //single enemy_submarine torpedo firing
    void single_sub_launch();

};


struct Enemy_Sub_Set
{
    
    Enemy_Sub e_sub[E_SUB_N];

    int esub_speed[E_SUB_N]; //array to store the speed of each submarine

    int y_limit_check[E_SUB_N];

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

    int is_exploded; //variable to check whether enemy ship is exploded or not

    Uint32 is_started; // variable related to obj revival & explosion

    Uint32 is_counting; //variable related to obj revival & explosion

    int revival=0;  // variable related to obj revival & explosion

    Uint32 emine_launch_start;
                             //variables related to the time of enemy ship mine launching
    Uint32 emine_launch_count;

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

void ptorp_collision_init(); // initializing player torpedo collision variables

void ptorp_collision_for_esub();//function for rendering and detecting player torpedo collision


#endif