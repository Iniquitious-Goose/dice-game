#include <iostream>
#include <string>


#include "dice.h"
#include "rollset.h"

#include "menu.h"

int main() {

    gameContext ctx(4);

    //bool running = true;

    int userSide = 2;



    while (isRunning()) {
        showMenu("data/main-menu.txt");
        menuSelect(ctx);
    
    }


    showMenu("data/exit.txt");


    
    return 0;
}

