#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <iostream>
#include <string>
#include <vector>

class PokemonCard {
private:
    std::string name;
    std::string type;
    int hp;
    int rarity;
    int cardCounts;
    int yearPurchased;
    std::vector<std::string> abilities;

public:
    
PokemonCard(std::string n, std::string t, int h, int r, int count, int year, std::vector<std::string> ab);

    std::string getName() const;
    
    void displayCard() const;
};

#endif
