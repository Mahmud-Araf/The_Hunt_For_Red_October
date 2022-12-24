/*This file contains all game stage structures and functions*/

#ifndef GSTAGES

#define GSTAGES

#include"preprocessor.hpp"
#include"init.hpp"
#include"global.hpp"
#include"media.hpp"
#include"close.hpp"
#include"obj-functions.hpp"
#include"utilities.hpp"
#include"text.hpp"

/*

variable and functions used here following naming scheme
BS = Button Screen
init() = initializes assigned stage
run() = runs assigned stage
render() = renders assigned stage
handle_event() = handles event of assigned stage

*/

// enumeration for game stages
enum STAGE{MAIN_MENU,CONTROLS,CREDIT,HIGHSCORES,LEVEL1,LEVEL2,GAME_OVER};

extern enum STAGE stage;

extern Button mainmenuBS; 

extern Button playagainBS;

extern Button backBS;

extern Button level1BS;

extern Button level2BS;

extern Button refreshBS;

//structure for stage Mainmenu
struct MainMenu
{
  
   int Bw; // width of button
   int Bh; // height of button
   int Bspacing; // spacing between two buttons

   bool levelmenuflag;

   Button startgameBS;

   Button controlsBS;

   Button highscoresBS;

   Button creditBS;

   Button exitgameBS;

   void run(); 

   void handle_event(); 

   void render();

   void init();

};
extern MainMenu mainmenu;

// structure for two game levels
struct GameLevels
{
     int levelmode;

     void game_obj_func_init();

     void run_levelOne();
     
     void run_levelTwo();
};
extern  GameLevels gamelevels;

// structure for game over stage
struct GameOver
{
   string name_input=" "; // variable to store player name

   void render();

   void handle_event();

   void run();
};
extern GameOver gameover;

// struct for controls stage
struct Controls
{
    void render();

    void run();
};
extern Controls controls;

// structure for highscores stage
struct HighScores
{
    // variable for storing player name and scores
    string p_namel1[PLAYER_N_HSCORE];
    string p_namel2[PLAYER_N_HSCORE];
    int p_scorel1[PLAYER_N_HSCORE];
    int p_scorel2[PLAYER_N_HSCORE];

    int levelmode;

    bool levelmenuflag=false;

    FILE *l1_file;

    FILE *l2_file;

    void scan_highscores(); // scans highscores from IO files

    void print_highscores(string p_name[],int p_score[]); // renders the highscores from IO files

    void save_highscores(string name, int score); // saves player name and score in IO files if it is greater than lowest player's score

    void refresh_highscores(int x); // refreshes highscores of parameter level 

    void render();

    void handle_event();

    void render_highscores();

    void run();
};
extern HighScores highscores;

// structure for credit stage
struct Credit
{
    void render();

    void run();
};
extern Credit credit;

void back_handle_event(); // function for back button event handling

#endif
