#include "pokemonCollection.h"


PokemonCard::PokemonCard(std::string n, std::string t, int h, int r, int count, int year, std::vector<std::string> ab)
    : name(n), type(t), hp(h), rarity(r), cardCounts(count), yearPurchased(year), abilities(ab) {}

std::string PokemonCard::getName() const {
    return name;
}

void PokemonCard::displayCard() const {
    std::cout << "Name: " << name << "\n"
              << "Type: " << type << "\n"
              << "HP: " << hp << "\n"
              << "Rarity: " << rarity << "\n"
              << "Number of collection: " << cardCounts << "\n"
              << "Year Purchased: " << yearPurchased << "\n"
              << "Abilities: ";
    
    if (abilities.empty()) {
        std::cout << "None";
    } else {
        for (const auto& ability : abilities) {
            std::cout << ability << " ";
        }
    }
    std::cout << "\n";
}
