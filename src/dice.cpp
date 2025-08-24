#include "dice.h"
#include <iomanip>
#include <stdexcept>
#include <sstream>


//Methods for Die
Die::Die(int sides) : sides(sides), lastRoll(0), rng(std::random_device{}()) {}


void Die::roll() {
    std::uniform_int_distribution<int> dist(1, sides);

    lastRoll = dist(rng);
}

int Die::getRoll() {
    return lastRoll;
}

void Die::setSides(int x) {
    sides = x;
}

int Die::getSides(){
    return sides;
}






//Methods exclusive to DiceSet
DiceSet::DiceSet(Die dice, int count, int modifier) : count(count), modifier(modifier), sum(0), dice(dice){

    rollAll();
    sum += modifier;
}

void DiceSet::setModifier(int x) {modifier = x;}
void DiceSet::setSum(int x) {sum = x;}

int DiceSet::getSum() {
    return sum;
}

void DiceSet::setCount(int x) {count =x;}


int DiceSet::getCount() {return count;}
int DiceSet::getRoll() {return lastRoll;}

void DiceSet::rollAll() {
    
        diceSet.clear();

       for (int i =0; i < getCount(); i++) {
        dice.roll();
        diceSet.push_back(dice.getRoll());
        sum +=dice.getRoll();
    }

}


std::string DiceSet::toString() {
    std::ostringstream output;
    
    for(size_t i =0; i < diceSet.size(); ++i) {
        output << "Roll #" << i << ": " << diceSet[i] << "\n";
    }

    output << "Modifier: " << modifier;
    return output.str();
}