
#ifndef GSTAGES
#define GSTAGES

#include"preprocessor.hpp"
#include"init.hpp"
#include"global.hpp"
#include"media.hpp"
#include"close.hpp"
#include"obj-functions.hpp"
#include"utilities.hpp"
#include"font-color.hpp"

struct MainMenu
{
  
   int Bw;
   int Bh;
   int Bspacing;

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

extern Button backBS;

void back_handle_event();

enum STAGE{MAIN_MENU,CONTROLS,CREDIT,LEVEL1,LEVEL2};
extern enum STAGE stage;

#endif
