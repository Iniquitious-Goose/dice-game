#include <iostream>
#include <string>
#include "dice.h"



int main() {

    Die test(20);

    
    std::cout << "\n\nTest default sides: " << test.getSides() << '\n';

    for (int i =0; i <6; i++) {
        test.roll();
        std::cout<< "Test roll #" << i << ": " << test.getRoll() << '\n';
    }
    
    return 0;
}