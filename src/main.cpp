#include <iostream>
#include <string>
#include "dice.h"



int main() {

    Die d20(20), d10(10), d6(6), d4(4), dArbitrary{};

    DiceSet test(d20, 3, -4);

    
    std::cout << "\n\nTest set: \n" << test.toString() << "\nSum: " << test.getSum() << '\n';


    
    return 0;
}