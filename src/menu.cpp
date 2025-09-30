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
    std::string input;
    std::string id = "default";


    FavoriteList favList;


    std::cout << "\n> ";
    std::getline(std::cin, input);

    favList.openFile();
    favList.loadFromFile();

    try {

        userChoice = std::stoi(input);


        menuOption option = static_cast<menuOption>(userChoice);

        switch (option) {

            case menuOption::rollSet:
                handleRollMenu(ctx);
                break;

            case menuOption::rollFav:
                favList.showFavorites();
                std::cout<< "\n\nEnter favorite ID: ";
                std::getline(std::cin, id);
                favList.rollFavorite(id);
                


                //favorite.loadFromFile(id);
                //std::cout<<favorite.toString();

                break;
                
            
            //case menuOption::viewFavorites:
              //  favList.openFile();
                //favList.showFavorites();


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
    std::string input;
    std::string id = "default";


    FavoriteList favList;
    std::cout << "\nCurrent set: " << ctx.set.toBaseString();


    std::cout << "\n> ";
    std::getline(std::cin, input);

    

    try {

        userChoice = std::stoi(input);


        rollOption option = static_cast<rollOption>(userChoice);

        switch (option) {

            case rollOption::roll:
                ctx.set.rollAll();
                std::cout << ctx.set.toString();
                rolled = true;
                break;

            case rollOption::setSide:

                std::cout << "\n> ";
                std::getline(std::cin, input);
                userChoice = std::stoi(input);

                ctx.set.setDie(Die(userChoice));
                

                break;

                case rollOption::setCount:
                std::cout << "\n> ";
                std::getline(std::cin, input);
                userChoice = std::stoi(input);

                ctx.set.setCount(userChoice);
                break;
                
                
                case rollOption::setMod:
                
                std::cout << "\n> ";
                std::getline(std::cin, input);
                userChoice = std::stoi(input);
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