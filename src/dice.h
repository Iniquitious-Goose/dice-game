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
    std::string toString();
    
    
    private:
    int sides;
    int lastRoll;
    static std::mt19937 rng;
 
   

};


class DiceSet {

    public:
    DiceSet(Die dice, int count = 1, int modifier = 0);
    DiceSet();

    void rollAll();

    int getSum();

    void setCount(const int);
    int getCount();

    void setDie(Die);

    void setSum(const int);
    
    void setModifier(const int);

    int getRoll();

    std::string toString();


    private:
    std::vector<int> diceSet;
    int count, modifier, sum, lastRoll;
    Die dice;

};