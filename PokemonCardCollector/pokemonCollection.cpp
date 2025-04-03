#include "pokemonCollection.h"
#include <fstream>

const std::string FILE_NAME = "pokemon_collection.txt";

PokemonCard::PokemonCard(std::string n, std::string t, int h, char r, int count, int year, std::vector<std::string> ab)
    : name(n), type(t), hp(h), rarity(r), cardCounts(count), yearPurchased(year), abilities(ab) {}

std::string PokemonCard::getName() const
{
    return name;
}

void PokemonCard::displayCard() const
{
    std::cout << "Name: " << name << "\n"
              << "Type: " << type << "\n"
              << "HP: " << hp << "\n"
              << "Rarity: " << rarity << "\n"
              << "Number of collection: " << cardCounts << "\n"
              << "Year Purchased: " << yearPurchased << "\n"
              << "Abilities: ";

    if (abilities.empty())
    {
        std::cout << "None";
    }
    else
    {
        for (const auto &ability : abilities)
        {
            std::cout << ability << " ";
        }
    }
    std::cout << "\n";
}

void PokemonCard::saveToFile(std::ofstream &outFile) const
{
    outFile << name << '\n'
            << type << '\n'
            << hp << '\n'
            << rarity << '\n'
            << cardCounts << '\n'
            << yearPurchased << '\n'
            << abilities.size() << '\n';

    for (const auto &ability : abilities)
    {
        outFile << ability << '\n';
    }
}

PokemonCard PokemonCard::loadFromFile(std::ifstream &inFile) 
{
    std::string name, type;
    int hp, count, year, abilityCount;
    char rarity;

    std::getline(inFile, name);
    std::getline(inFile, type);
    inFile >> hp >> rarity >> count >> year >> abilityCount;
    inFile.ignore();  

    std::vector<std::string> abilities;
    for (int i = 0; i < abilityCount; ++i)
    {
        std::string ability;
        std::getline(inFile, ability);
        abilities.push_back(ability);
    }

    return PokemonCard(name, type, hp, rarity, count, year, abilities);
}

std::ostream& operator<<(std::ostream& os, const PokemonCard& card)
{
    os << card.name << '\n'
       << card.type << '\n'
       << card.hp << '\n'
       << card.rarity << '\n'
       << card.cardCounts << '\n'
       << card.yearPurchased << '\n'
       << card.abilities.size() << '\n';
    for (const auto& ability : card.abilities)
    {
        os << ability << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, PokemonCard& card)
{
    std::getline(is, card.name);
    std::getline(is, card.type);
    is >> card.hp >> card.rarity >> card.cardCounts >> card.yearPurchased;
    
    int abilityCount;
    is >> abilityCount;
    is.ignore();

    card.abilities.clear();
    for (int i = 0; i < abilityCount; ++i)
    {
        std::string ability;
        std::getline(is, ability);
        card.abilities.push_back(ability);
    }
    return is;
}

void saveCollection(const std::vector<PokemonCard>& collection)
{
    std::ofstream outFile(FILE_NAME);
    if (!outFile)
    {
        std::cerr << "Error saving collection!\n";
        return;
    }
    outFile << collection.size() << '\n';
    for (const auto& card : collection)
    {
        outFile << card;
    }
}

void loadCollection(std::vector<PokemonCard>& collection)
{
    std::ifstream inFile(FILE_NAME);
    if (!inFile)
        return;

    int size;
    inFile >> size;
    inFile.ignore();

    collection.clear();
    for (int i = 0; i < size; ++i)
    {
        PokemonCard card("", "", 0, 'C', 0, 2000, {});
        inFile >> card;
        collection.push_back(card);
    }
}