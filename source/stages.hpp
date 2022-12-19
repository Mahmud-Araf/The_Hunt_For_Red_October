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

enum STAGE{MAIN_MENU,CONTROLS,CREDIT,HIGHSCORES,LEVEL1,LEVEL2,GAME_OVER};

extern enum STAGE stage;

extern Button mainmenuBS;

extern Button playagainBS;

extern Button backBS;

extern Button level1BS;

extern Button level2BS;

extern Button refreshBS;


struct MainMenu
{
  
   int Bw;
   int Bh;
   int Bspacing;

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


struct GameLevels
{
     int levelmode;

     void game_obj_func_init();

     void run_levelOne();
     
     void run_levelTwo();
};
extern  GameLevels gamelevels;


struct Controls
{
    void render();

    void run();
};
extern Controls controls;


struct Credit
{
    void render();

    void run();
};
extern Credit credit;


struct HighScores
{
    string p_namel1[PLAYER_N_HSCORE];
    string p_namel2[PLAYER_N_HSCORE];
    int p_scorel1[PLAYER_N_HSCORE];
    int p_scorel2[PLAYER_N_HSCORE];

    int levelmode;

    bool levelmenuflag=false;

    FILE *l1_file;

    FILE *l2_file;

    void scan_highscores();

    void print_highscores(string p_name[],int p_score[]);

    void save_highscores(string name, int score);

    void refresh_highscores(int x);

    void render();

    void handle_event();

    void render_highscores();

    void run();
};
extern HighScores highscores;


struct GameOver
{
   string name_input=" ";

   void render();

   void handle_event();

   void run();
};
extern GameOver gameover;

void back_handle_event();

#endif
