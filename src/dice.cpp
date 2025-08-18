#include "dice.h"


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