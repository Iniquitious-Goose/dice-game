#include <iostream>
#include <string>
#include <array>
#include "headers/games.h"
#include "headers/menu.h"
#include <algorithm>
#include <sstream>
#include <vector>

//Farkle
void FarkleHand::updateScore() {totalScore+= roundScore; roundScore = 0;}
void FarkleHand::updateRoundScore(int r) {roundScore += r;}

    
void FarkleHand::bust() {roundScore = 0; endTurn();}
void FarkleHand::endTurn() {return;}

int FarkleHand::getTotalScore() const {return totalScore;}
int FarkleHand::getRoundScore() const {return roundScore;}

void FarkleHand::setScoredDie(int s) {scoringDie = s;}
int FarkleHand::getScoringDie() const {return scoringDie;}


void FarkleHand::applyScoredDie() {
    if (getScoringDie() == 0) {
        setCount(6);
    }

    else 
        setCount(getCount() - getScoringDie());
}

std::string FarkleHand::scoredString() const{

    std::ostringstream output;

    const auto& dice = scoring;


    for(size_t i =0; i < dice.size(); i++) {
        output << "#" << i+1 << ": " << dice.at(i).toString() << "\n";
    }

    output << dice.size() + 1 << ": " << "End turn." << "\n";
    return output.str();


}



std::string FarkleHand::toString() const{
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

void FarkleHand::findScore() {


    for (const auto& die : getDiceSet()) {
        if (die >= 1 && die <= 6)
            counts[die - 1]++;
    }

    //straight
    if (std::all_of(counts.begin(), counts.end(), [](int c) {return c ==1; } )) {
        scoring.push_back(ScoringDice(true, false));
        return;
    }
    //three pairs
    if (std::count(counts.begin(), counts.end(), 2) ==3 ) {
        scoring.push_back(ScoringDice(false, true));
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
            scoring.push_back(ScoringDice(setScore, scored));

        }
       // scoring.push_back(ScoringDice(setScore, scored));
    }

    setScore = 0; 

    for (int i=0; i < tempCounts[0]; i++) {
        scoring.push_back(ScoringDice(100,1));
    }
 
 //   setScore += tempCounts[0] * 100;
   // scoring.push_back(ScoringDice(setScore, tempCounts[0]));

    setScore =0;

    for (int i =0; i < tempCounts[4]; i++) {
        scoring.push_back(ScoringDice(50,1));
    }
    
    //setScore += tempCounts[4] * 50;
    //scoring.push_back(ScoringDice(setScore, tempCounts[4]));


    //scored += tempCounts[0] + tempCounts[4];


    if (scored ==0) {
        bust();
        return;
    }

    //getDiceSet;

}
   

std::vector <ScoringDice> FarkleHand::getScoring() const {
    return scoring;
}


std::string ScoringDice::toString() const{
    std::ostringstream output;

    if (straight) {
        output << "Straight: ";
    }

    else if (triplePair) {
        output << "Triple pair: ";
    }

    else if (count >= 3) {
        output << count << " of a kind: ";
    }

    else {
        output << "Single: ";
    }

    output << score;
    return output.str();
}

int ScoringDice::getScore() const {
    return score;
}
void FarkleHand::select() {
    return;
}


FarkleHand::FarkleHand() {
    setDie(Die(6));
    setCount(6);
    setModifier(0);
}


Farkle::Farkle() {
    playerHand1;
    playerHand2;
}

void Farkle::play() {

    FarkleHand* currentPlayer = &playerHand1;


    for(int turn =0; turn <2;turn++) {
        if(turn%2==0) {
            currentPlayer = &playerHand1;
        }
        else {currentPlayer = &playerHand2;} 


         currentPlayer->rollAll();
        currentPlayer->findScore();
        std::cout << currentPlayer->toString();

        for (int i =0; i< currentPlayer->getScoring().size(); i++) {
            if (currentPlayer->getScoring()[i].getScore() !=0) {
            std::cout<<currentPlayer->getScoring()[i].toString() << "\n";
            }
        }        

    }



   /* while(!win) {
        playerHand1.rollAll();
        playerHand1.findScore();
        std::cout << playerHand1.toString();

        for (int i =0; i< playerHand1.getScoring().size(); i++) {
            if (playerHand1.getScoring()[i].getScore() !=0) {
            std::cout<<playerHand1.getScoring()[i].toString() << "\n";
            }
        }        

        win = true;
    }*/
}