#include <iostream>
#include <string>
#include "headers/utilities.h"



std::string Program::getInput() {
    std::string input;
    std::cout << "\n> ";
    std::getline(std::cin, input);
    return input;

}


void Program::waitForEnter() {
    std::cout<< "\nPress Enter to return to main menu.\n";
    std::cin.get();
}


void Program::setRunning(bool run) {

    running = run;
}

bool Program::isRunning() {
    return running;
}
