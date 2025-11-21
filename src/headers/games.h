#pragma once

#include <iostream>
#include <string>
#include <vector>
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




class ScoringDice {
    public: 
    ScoringDice(bool straight, bool triple) : straight(straight), triplePair(triple), count(6) {}
    ScoringDice(int score,int count) : score(score), count(count){}
    ScoringDice();

    std::string toString() const;
    int getScore() const;

    private:
    bool straight =false, triplePair = false, one = false, five = false;
    int score, count;

};

class FarkleHand : public DiceSet {
    public:
    
//DiceSet::DiceSet(Die dice, int count, int modifier) : count(validateCount(count)), modifier(modifier), sum(0), dice(dice){
//inline DiceSet::DiceSet() : count(1), modifier(0), sum(0), dice(Die(6)){}

    
    FarkleHand();

    void updateScore();
    
    void bust();
    void endTurn();

    void findScore();

    int getTotalScore() const;
    int getRoundScore() const;
    void updateRoundScore(int);

    int getScoringDie() const;

    std::vector <ScoringDice> getScoring() const;

    void applyScoredDie();
    void setScoredDie(int);

    std::string toString() const;

    std::string scoredString() const;
    void select();

    private:
    int totalScore = 0, roundScore =0, scoringDie =0;
    std::array <int, 6> counts{};
    std::vector <ScoringDice> scoring;



    bool isBust = false;

};


class Farkle {
    public:
    Farkle();
    void play();

    
    private:
    FarkleHand playerHand1, playerHand2;
    int winningScore = 10000;
    bool win = false;
};