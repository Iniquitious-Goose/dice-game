#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "dice.h"
#include "json.hpp"

using json = nlohmann::json;


class Favorite {
    public:
    //void loadFromFile(const std::string& id= "default");
    void createSet();

    Favorite(const std::string&, const DiceSet);

    std::string toString() const;

    void roll();

    DiceSet getSet() {return dice;}

    std::string getID() const{return id;}


    std::string toString(const std::string& id);

    private:
        std::string id, name;
        DiceSet dice;
        



};

class FavoriteList {
    public:
    void loadFromFile();
     void showFavorites() const;
    void openFile();

    void rollFavorite(std::string&) ;

    std::string toString();
     std::vector<std::string> getIDList();


    private:
        std::vector<Favorite> favList;

        std::vector<std::string> IDList;
        const std::string filename = "data/favorites.json";
        json data;



};