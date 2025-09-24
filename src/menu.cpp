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


void menuSelect(gameContext& ctx) {
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
                showMenu("data/roll-multiple.txt");
                rollSet(ctx);
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


         case::menuOption::exit:
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

