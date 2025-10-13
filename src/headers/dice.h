#pragma once
#include <random>
#include <string>

class Die {

    public:
    Die(int sides = 6);

    void roll();
    int getRoll();
    
    void setSides(int);
    int getSides() const;
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

    int getSides() const;

    void rollAll();
    int getModifier() const;

    int getSum()const;

    void setCount(const int);
    int getCount()const;

    void setDie(Die);

    void setSum(const int);
    
    void setModifier(const int);

    int getRoll () const;

    int getMin() const {return min;}

    int getMax() const {return max;}

    int getMean() const {return mean;}

    void setMin(const int x) {min = x;}
    void setMax(const int x) {max = x;}
    void setMean(const int x) {mean = x;}

    std::string toString() const;
    std::string toBaseString() const;



    private:
    std::vector<int> diceSet;
    int count, modifier, sum, lastRoll, min = 0, max = 0, mean =0;
    Die dice;

};