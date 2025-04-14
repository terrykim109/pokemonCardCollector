#pragma once
#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <iostream>
#include <string>
#include <vector>

class PokemonCard
{
private:
    std::string name;
    std::string type;
    int hp;
    char rarity;
    int cardCounts;
    int yearPurchased;
    std::vector<std::string> abilities; // Using vector for abilities which can be more than one

public:
    // Constructor with default values for name, type, hp, rarity, cardCounts and yearPurchased
    PokemonCard(std::string n, std::string t, int h, char r, int c, int y, std::vector<std::string> ab);

    // Gettors
    std::string getName() const;
    std::string getType() const;
    int getHP() const;
    char getRarity() const;
    int getCount() const;
    int getYearPurchased() const;
    std::vector<std::string> getAbilities() const;

    void displayCard() const;

    void saveToFile(std::ofstream &outFile) const;
    static PokemonCard loadFromFile(std::ifstream &inFile);
    
    void static exportToCSV(const std::vector<PokemonCard> &collection);

    // Overloading the operators
    friend std::ostream &operator<<(std::ostream &os, const PokemonCard &card);
    friend std::istream &operator>>(std::istream &is, PokemonCard &card);
};

void saveCollection(const std::vector<PokemonCard> &collection);
void loadCollection(std::vector<PokemonCard> &collection);

#endif
