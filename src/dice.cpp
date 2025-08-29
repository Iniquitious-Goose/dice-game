#include "dice.h"
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <iostream>


//Methods for Die
Die::Die(int sides) : sides(sides), lastRoll(0){}

std::mt19937 Die::rng{std::random_device{}()};

void Die::roll() {
    std::uniform_int_distribution<int> dist(1, sides);

    lastRoll = dist(rng);
}

int Die::getRoll() {
    return lastRoll;
}

void Die::setSides(const int x) {
    if (x < 1) {
        std::cerr<<"Error: Sides cannot be < 1. Defaulting to 6 for safety";

        sides = 6;
        return;
    }
    sides = x;
}

int Die::getSides(){
    return sides;
}

std::string Die::toString() {
    std::ostringstream output;
    
    output << "Rolled" << ": " << getRoll() << "\n";


    return output.str();
}






//Methods exclusive to DiceSet
DiceSet::DiceSet(Die dice, int count, int modifier) : count(count), modifier(modifier), sum(0), dice(dice){

    rollAll();
    sum += modifier;
}

DiceSet::DiceSet() {}

void DiceSet::setModifier(const int x) {modifier = x;}
void DiceSet::setSum(const int x) {sum = x;}

int DiceSet::getSum() {
    return sum;
}

void DiceSet::setCount(const int x) {count =x;}


int DiceSet::getCount() {return count;}
int DiceSet::getRoll() {return lastRoll;}

void DiceSet::rollAll() {
    
        setSum(modifier);

        diceSet.clear();

       for (int i =0; i < getCount(); i++) {
        dice.roll();
        diceSet.push_back(dice.getRoll());
        sum +=dice.getRoll();
    }

}

void DiceSet::setDie(Die die) {
    dice = die;
}
std::string DiceSet::toString() {
    std::ostringstream output;
    
    for(size_t i =0; i < diceSet.size(); i++) {
        output << "Roll #" << i+1 << ": " << diceSet[i] << "\n";
    }

    output << "Modifier: " << modifier << "\nSum: " << sum;
    return output.str();
}