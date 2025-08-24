#pragma once
#include <random>
#include <string>

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


class DiceSet {

    public:
    DiceSet(Die dice, int count = 1, int modifier = 0);

    void rollAll();

    int getSum();

    void setCount(int);
    int getCount();

    void setSum(int);
    
    void setModifier(int);

    int getRoll();

    std::string toString();


    private:
    std::vector<int> diceSet;
    int count, modifier, sum, lastRoll;
    Die dice;

};