#include <iostream>
#include <string>
#include "dice.h"




enum class menuOption {
    rollSet =1,
    rollFav,
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



struct gameContext {
    DiceSet set;

    gameContext(int userSide) : set() {}


};


void showMenu(const std::string& fileName);

void waitForEnter();

void setRunning(bool);
bool isRunning();

void handleMainMenu(gameContext& ctx);

void handleRollMenu(gameContext& ctx);

//void rollSingleDie(gameContext& ctx);
void setCustomSides(gameContext& cfx, int sides);

//void rollSet(gameContext& ctx);

std::string getInput();