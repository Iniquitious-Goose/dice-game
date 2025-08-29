#include "dice.h"
#include "menu.h"

void setCustomSides(gameContext& cfx, int sides) {
    if (sides < 1 ) {
        std::cerr<<"Error: Sides cannot be < 1.\n";
        return;

    }
    cfx.dArbitrary = Die(sides);
}

void rollSet(gameContext& ctx) {
    int userChoice;
    std::string input;
    int sides = 6, modifier =0, count =1;
    DiceSet dice(ctx.d6, count, modifier);

    bool readyToRoll = false;

    while (!readyToRoll){
    readyToRoll = true;

    //dice.setModifier(0);
    //dice.setCount(2);


    std::cout<< "Dice to roll: " << count;
    std::cout << "\nModifier: " << modifier;
    std::cout << "\n> ";
    std::getline(std::cin, input);
    userChoice = std::stoi(input);


    switch (userChoice) {
        case 1:
        dice.setDie(ctx.d4);
        break;
        
        case 2:
        dice.setDie(ctx.d6);


        break;
        
        case 3:
        dice.setDie(ctx.d8);


        break;
        
        case 4:
        dice.setDie(ctx.d10);

        break;
        
        case 5:
        dice.setDie(ctx.d12);

        break;
        
        case 6:
        dice.setDie(ctx.d20);

        break;

        case 7:
        std::cout << "\n> ";
        std::getline(std::cin, input);
        sides = std::stoi(input);

        setCustomSides(ctx, sides);
        dice.setDie(ctx.dArbitrary);
        break;


        case 8:
        std::cout << "\n> ";
        std::getline(std::cin, input);
        readyToRoll = false;
        
        count = std::stoi(input);
        dice.setCount(count);
        break;

        case 9:
        std::cout << "\n> ";
        std::getline(std::cin, input);
        readyToRoll = false;


        modifier = std::stoi(input);

        dice.setModifier(modifier);
        break;

        default:

        return;
    }

    showMenu("data/roll-multiple.txt");

}
    
        dice.rollAll();
        std::cout<<dice.toString();





}
