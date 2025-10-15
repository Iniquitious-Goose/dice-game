#include <iostream>
#include <string>


#include "headers/dice.hpp"
#include "headers/favorite.h"
#include "headers/menu.h"

int main() {

    gameContext ctx(4);

    while (isRunning()) {
        showMenu("data/main-menu.txt");
        handleMainMenu(ctx);
    
    }


    showMenu("data/exit.txt");


    
    return 0;
}

