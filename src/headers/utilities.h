#pragma once
#include <string>
#include <iostream>

class Program {
    public:

    std::string getInput();


    void waitForEnter();


    void setRunning(bool);


    bool isRunning();

    private:
    bool running = true;

};
