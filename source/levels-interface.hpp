#pragma once
#include"preprocessor.hpp"
#include"init.hpp"
#include"global.hpp"
#include"texture_music.hpp"
#include"media.hpp"
#include"close.hpp"
#include"game_obj-functions.hpp"
#include"game_utilities.hpp"
#include"font-color.hpp"



struct GameLevels
{
     static  bool one_running;
     
     static bool two_running;

     void run_levelOne();
     
     void run_levelTwo();
};

extern  GameLevels gamelevels;