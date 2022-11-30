#pragma once
#include"preprocessor.hpp"
#include"init.hpp"
#include"global.hpp"
#include"media.hpp"
#include"close.hpp"
#include"obj-functions.hpp"
#include"utilities.hpp"
#include"font-color.hpp"



struct GameLevels
{
     static  bool one_running;
     
     static bool two_running;

     void run_levelOne();
     
     void run_levelTwo();
};

extern  GameLevels gamelevels;