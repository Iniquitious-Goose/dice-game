#include "headers/favorite.h"
#include <fstream>
#include <iostream>
#include <ostream>

using namespace dice;


void FavoriteList::openFile() {
     
    std::ifstream file(filename);


        if (!file) {
            std::cerr << "Error opening " << filename << "\n";
            return;
        }

        file >> data;

}


 std::vector<std::string> FavoriteList::getIDList() {


//        std::vector<std::string> ids;

        for(auto it = data.begin(); it !=data.end(); ++it) {
            IDList.push_back(it.key());
        }

        return IDList;
    }



void FavoriteList::loadFromFile() {
    



    for(auto it = data.begin(); it !=data.end(); ++it) {
            std::string id = it.key();
            auto& obj = it.value();

            int sides = obj.value("sides",6);
            int count = obj.value("count", 1);
            int modifier = obj.value("modifier",0);

            Die tempdie(sides);

            DiceSet tempset(tempdie, count, modifier);

            favList.emplace_back(id,tempset);

        }

}


std::string FavoriteList::toString() {
        
    std::ostringstream output;


     for (const auto& fav : favList) {
        output << fav.toString() << "\n";
    }

    return output.str();

}

void FavoriteList::showFavorites() const{

    for (const auto& fav : favList) {
        std::cout << fav.toString();

    }
}


void FavoriteList::rollFavorite(std::string& id) {
    
     for (auto& fav : favList) {
        if(fav.getID() == id) {
            fav.roll();

            
            std::cout<<fav.getSet().toString();

            return;
        }
        

    }
}


std::string Favorite::toString() const{
    
    std::ostringstream output;


    output << "\nName: " << id << "\nSet: " << dice.getCount() << "d" << dice.getSides() << " ";
    if(dice.getModifier() >= 0) {
        output << "+ ";
    }

    output << dice.getModifier();

    output << "\nName: " << id << "\n" <<dice.toBaseString();

    return output.str();


    
    
    //output << "ID: " << id << "| "<< dice.toString();

    return output.str();

}


void Favorite::roll() {
    dice.rollAll();



}

Favorite::Favorite(const std::string& id, const DiceSet dice) :  id(id), dice(dice){

}

  //gameContext(int userSide) : d20(20), d12(12), d10(10), d8(8), d6(6), d4(4), dArbitrary(userSide), set() {}


/*void Favorite::loadFromFile(const std::string& id) {

       

        if (id.empty()) {
            std::cerr << "ID \"" << id << "\" could not be found in file \"" << filename;
            return;
        }

        data = data[id];

        name = data.value("name", "");
        sides = data.value("sides", 6);
        count = data.value("count", 1);
        modifier = data.value("modifier", 0);

}*/


/*std::string Favorite::toString(const std::string& id) {
    std::ostringstream output;
    
    //output << ("Name: %s\nSet: %dd%d + %d", name, count, sides, modifier);

    output << "Name: " << name << "\nSet: " << dice.getCount() << "d" << dice.getSides() << " ";
    if(dice.getModifier() >= 0) {
        output << "+ ";
    }

    output << dice.getModifier();

    return output.str();



}*/


 /*std::vector<std::string> Favorite::getIDList() {


//        std::vector<std::string> ids;

        for(auto it = data.begin(); it !=data.end(); ++it) {
            IDList.push_back(it.key());
        }

        return IDList;
    }

*/