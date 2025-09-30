#include <iostream>
#include <string>


#include "headers/dice.h"
#include "headers/rollset.h"
#include "headers/favorite.h"
#include "headers/menu.h"

int main() {

    gameContext ctx(4);

    //bool running = true;

    //int userSide = 2;




    while (isRunning()) {
        showMenu("data/main-menu.txt");
        handleMainMenu(ctx);
    
    }


    showMenu("data/exit.txt");


    
    return 0;
}

