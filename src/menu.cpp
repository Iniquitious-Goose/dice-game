#include <iostream>
#include <string>
#include <fstream>
#include <string>

#include "headers/menu.h"
#include "headers/favorite.h"
#include "headers/utilities.h"


void showMenu(const std::string& fileName) {
    std::ifstream menuFile(fileName);
    
    if (!menuFile) {
        std::cerr << "Error: " << fileName << " could not be loaded.\n";

        return;
    }
    std::string line;

    while (getline(menuFile, line)) {
        std::cout << line<< '\n';
    }
}


void handleMainMenu(gameContext& ctx) {
    int userChoice;
    std::string id = "default";


    FavoriteList favList;



    favList.openFile();
    favList.loadFromFile();

    try {

        userChoice = std::stoi(ctx.program.getInput());


        menuOption option = static_cast<menuOption>(userChoice);

        switch (option) {

            case menuOption::rollSet:
                handleRollMenu(ctx);
                break;

            case menuOption::rollFav:
                favList.showFavorites();
                std::cout<< "\n\nEnter favorite ID: ";
                id = ctx.program.getInput();
                favList.rollFavorite(id);
                

                break;

            case menuOption::games:
                handleGameMenu(ctx);
                break;

                


         case menuOption::exit:
            ctx.program.setRunning(false);
        
        }

            ctx.program.waitForEnter();


    }
    catch (const std::invalid_argument& e) {
        std::cerr<< "Invalid input: not a number. Returning to main menu...\n";

        return;

    }
    catch (const std::out_of_range& e) {
        std::cerr << "Invalid input: out of range. Returning to main menu...\n";
        
        return;
    }

    catch (...) {
        std::cerr << "An unknown error occured. Exiting...\n";
        ctx.program.setRunning(false);
    }






}




void handleRollMenu(gameContext& ctx) {

    bool rolled = false;
    while(!rolled) {
    showMenu("data/roll-multiple.txt");


    int userChoice;

    std::string id = "default";


    FavoriteList favList;
    std::cout << "\nCurrent set: " << ctx.set.toBaseString();

    

    try {

        userChoice = std::stoi(ctx.program.getInput());


        rollOption option = static_cast<rollOption>(userChoice);

        switch (option) {

            case rollOption::roll:
                ctx.set.rollAll();
                std::cout << ctx.set.toString();
                rolled = true;
                break;

            case rollOption::setSide:


                userChoice = std::stoi(ctx.program.getInput());

                ctx.set.setDie(Die(userChoice));
                

                break;

                case rollOption::setCount:
                userChoice = std::stoi(ctx.program.getInput());

                ctx.set.setCount(userChoice);
                break;
                
                
                case rollOption::setMod:
                
                userChoice = std::stoi(ctx.program.getInput());
                ctx.set.setModifier(userChoice);

                break;
                
                case rollOption::saveSet:
                return;
                break;
                


         case rollOption::exit:
            return;
        
        }

    }
    catch (const std::invalid_argument& e) {
        std::cerr<< "Invalid input: not a number. Returning to main menu...\n";

        return;

    }
    catch (const std::out_of_range& e) {
        std::cerr << "Invalid input: out of range. Returning to main menu...\n";
        
        return;
    }

    catch (...) {
        std::cerr << "An unknown error occured. Exiting...\n";
        ctx.program.setRunning(false);
    }



    }




}


void handleGameMenu(gameContext& ctx) {

    bool rolled = false;
    while(!rolled) {
    showMenu("data/game-menu.txt");


    int userChoice;

    try {

        userChoice = std::stoi(ctx.program.getInput());


        gameOption option = static_cast<gameOption>(userChoice);

        switch (option) {

            case gameOption::farkle:
            
                break;

            case gameOption::knucklebones:
            
                break;
        
             case gameOption::highLow:
            
                break;

            case gameOption::exit:
            
                return;
        }

    }
    catch (const std::invalid_argument& e) {
        std::cerr<< "Invalid input: not a number. Returning to main menu...\n";

        return;

    }
    catch (const std::out_of_range& e) {
        std::cerr << "Invalid input: out of range. Returning to main menu...\n";
        
        return;
    }

    catch (...) {
        std::cerr << "An unknown error occured. Exiting...\n";
        ctx.program.setRunning(false);
    }



    }




}
