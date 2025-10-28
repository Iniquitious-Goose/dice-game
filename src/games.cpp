#include <iostream>
#include <string>
#include <array>
#include "headers/games.h"
#include <algorithm>
#include <sstream>


//Farkle
void farkleHand::updateScore() {totalScore+= roundScore; roundScore = 0;}
void farkleHand::updateRoundScore(int r) {roundScore += r;}

    
void farkleHand::bust() {roundScore = 0; endTurn();}
void farkleHand::endTurn() {return;}

int farkleHand::getTotalScore() const {return totalScore;}
int farkleHand::getRoundScore() const {return roundScore;}

void farkleHand::setScoredDie(int s) {scoringDie = s;}
int farkleHand::getScoringDie() const {return scoringDie;}


void farkleHand::applyScoredDie() {
    if (getScoringDie() == 0) {
        setCount(6);
    }

    else 
        setCount(getCount() - getScoringDie());
}

std::string farkleHand::toString() const{
    std::ostringstream output;

    const auto& dice = getDiceSet();


    for(size_t i =0; i < dice.size(); i++) {
        output << "Roll #" << i+1 << ": " << dice[i] << "\n";
    }
    return output.str();
}
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

void farkleHand::findScore() {


    for (const auto& die : getDiceSet()) {
        if (die >= 1 && die <= 6)
            counts[die - 1]++;
    }

    //straight
    if (std::all_of(counts.begin(), counts.end(), [](int c) {return c ==1; } )) {
        updateRoundScore(1500);
        setScoredDie(6);
        return;
    }
    //three pairs
    if (std::count(counts.begin(), counts.end(), 2) ==3 ) {
        updateRoundScore(1500);
        setScoredDie(6);
        return;
    }
    int score =0, scored =0, setScore =0;

    std::array<int, 6> tempCounts = counts;


    for (int i = 0; i < 6; i++) {
        if(tempCounts[i] >=3) {
            setScore += i == 0 ? 1000: (i +1) *100;

            if (tempCounts[i] > 3) {
                int difference = tempCounts[i] - 3;
                setScore *= 1 <<difference;
                
            }
        score +=setScore;
            scored = tempCounts[i];

            tempCounts[i] = 0;
        }
    }

    score += tempCounts[0] * 100;
    score += tempCounts[4] * 50;

    scored += tempCounts[0] + tempCounts[4];


    if (scored ==0) {
        bust();
        return;
    }

    setScoredDie(scored);
    updateRoundScore(score);

    //getDiceSet;

}
   