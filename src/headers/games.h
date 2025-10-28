#pragma once

#include <iostream>
#include <string>
#include "dice.hpp"

using namespace dice;

/*Farkle Scoring:

1 = 100pts
5 = 50 pts
Three of a kind = x * 100
Four of a kind = x * 200
Five of a kind = x * 400
Six of a kind = x * 800
Three pairs = 1500pts
Straight = 1500pts
Two triples = 2500pts

*/

class farkleHand : public DiceSet {
    public:
    void updateScore();
    
    void bust();
    void endTurn();

    void findScore();

    int getTotalScore() const;
    int getRoundScore() const;
    void updateRoundScore(int);

    int getScoringDie() const;

    void applyScoredDie();
    void setScoredDie(int);

    std::string toString() const;

    private:
    int totalScore = 0, roundScore =0, winningScore = 10000, scoringDie =0;
    std::array <int, 6> counts{};

    bool isBust = false;

};