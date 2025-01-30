#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <iostream>
#include <string>

class PokemonCard {
private:
    std::string name;
    std::string type;
    int hp;
    int rarity;
    int collectionCount;
    int yearPurchased;

public:
    
    PokemonCard(std::string n, std::string t, int h, int r, int count, int year)
        : name(n), type(t), hp(h), rarity(r), collectionCount(count), yearPurchased(year) {}

    void displayCard() const {
        std::cout << "Name: " << name << "\n"
                  << "Type: " << type << "\n"
                  << "HP: " << hp << "\n"
                  << "Rarity: " << rarity << "\n"
                  << "Collection Count: " << collectionCount << "\n"
                  << "Year Purchased: " << yearPurchased << "\n";
    }
};

#endif
