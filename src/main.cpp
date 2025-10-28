#include <iostream>
#include <string>


#include "headers/dice.hpp"
#include "headers/favorite.h"
#include "headers/menu.h"
#include "headers/utilities.h"

int main() {
    gameContext ctx(4);

    while (ctx.program.isRunning()) {
        showMenu("data/main-menu.txt");
        handleMainMenu(ctx);
    
    }


    showMenu("data/exit.txt");


    
    return 0;
}

