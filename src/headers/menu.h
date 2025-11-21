#pragma once

#include <string>
#include "dice.hpp"
#include "utilities.h"
//using namespace dice;


enum class menuOption {
    rollSet =1,
    rollFav,
    games,
   // viewSet,
   // viewFavorites,
    exit
};

enum class rollOption {
 roll = 1,
 setSide,
 setCount,
 setMod,
 saveSet,
    exit
};



enum class gameOption {
    farkle =1,
    knucklebones,
    highLow,
    exit
};




struct gameContext {
    dice::DiceSet set;
    Program program;

    gameContext(int userSide) : set() {}
};


void showMenu(const std::string& fileName);

void handleMainMenu(gameContext& ctx);

void handleRollMenu(gameContext& ctx);
void handleGameMenu(gameContext& ctx);
