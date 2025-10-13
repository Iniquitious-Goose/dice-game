#include <iostream>
#include <string>
#include <fstream>
#include <string>

#include "headers/menu.h"
#include "headers/favorite.h"

bool running = true;

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

        userChoice = std::stoi(getInput());


        menuOption option = static_cast<menuOption>(userChoice);

        switch (option) {

            case menuOption::rollSet:
                handleRollMenu(ctx);
                break;

            case menuOption::rollFav:
                favList.showFavorites();
                std::cout<< "\n\nEnter favorite ID: ";
                id = getInput();
                favList.rollFavorite(id);
                

                break;
                


         case menuOption::exit:
            setRunning(false);
        
        }

            waitForEnter();


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
        setRunning(false);
    }






}

void setRunning(bool run) {

    running = run;
}

bool isRunning() {
    return running;
}



void waitForEnter() {
    std::cout<< "\nPress Enter to return to main menu.\n";
    std::cin.get();
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

        userChoice = std::stoi(getInput());


        rollOption option = static_cast<rollOption>(userChoice);

        switch (option) {

            case rollOption::roll:
                ctx.set.rollAll();
                std::cout << ctx.set.toString();
                rolled = true;
                break;

            case rollOption::setSide:


                userChoice = std::stoi(getInput());

                ctx.set.setDie(Die(userChoice));
                

                break;

                case rollOption::setCount:
                userChoice = std::stoi(getInput());

                ctx.set.setCount(userChoice);
                break;
                
                
                case rollOption::setMod:
                
                userChoice = std::stoi(getInput());
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
        setRunning(false);
    }



    }




}

std::string getInput() {
    std::string input;
    std::cout << "\n> ";
    std::getline(std::cin, input);
    return input;

}