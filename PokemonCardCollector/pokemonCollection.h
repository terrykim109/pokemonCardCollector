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
    std::vector<std::string> abilities;

public:
    PokemonCard(std::string n, std::string t, int h, char r, int count, int year, std::vector<std::string> ab);

    std::string getName() const;

    void displayCard() const;

    void saveToFile(std::ofstream &outFile) const;
    static PokemonCard loadFromFile(std::ifstream &inFile);


    friend std::ostream& operator<<(std::ostream& os, const PokemonCard& card);
    friend std::istream& operator>>(std::istream &is, PokemonCard &card);
}; 


void saveCollection(const std::vector<PokemonCard>& collection);

void loadCollection(std::vector<PokemonCard>& collection);

#endif
