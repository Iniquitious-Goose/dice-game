#include <iostream>
#include <string>
#include "dice.h"




enum class menuOption {
    rollSet =1,
    createSet,
    viewSet,
    exit
};


struct gameContext {
    Die d20;
    Die d12;
    Die d10;
    Die d8;
    Die d6;
    Die d4;
    Die dArbitrary;
    DiceSet set;

    gameContext(int userSide) : d20(20), d12(12), d10(10), d8(8), d6(6), d4(4), dArbitrary(userSide), set() {}


};


void showMenu(const std::string& fileName);

void waitForEnter();

void setRunning(bool);
bool isRunning();

void menuSelect(gameContext& ctx);

//void rollSingleDie(gameContext& ctx);
void setCustomSides(gameContext& cfx, int sides);

void rollSet(gameContext& ctx);