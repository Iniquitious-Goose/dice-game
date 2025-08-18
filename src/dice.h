#pragma once
#include <random>

class Die {

    public:
    Die(int sides = 6);

    void roll();
    int getRoll();
    
    void setSides(int);
    int getSides();
    
    
    private:
    int sides;
    int lastRoll;
    std::mt19937 rng;
   

};