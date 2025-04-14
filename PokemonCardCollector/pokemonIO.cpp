#include "pokemonIO.h"
#include <fstream>

const std::string FILE_NAME = "pokemon_collection.txt";

// Saving to file
void saveCollection(const std::vector<PokemonCard> &collection)
{
    std::ofstream outFile(FILE_NAME);
    if (!outFile)
    {
        std::cerr << "Error saving collection!\n";
        return;
    }
    outFile << collection.size() << '\n';
    for (const auto &card : collection)
    {
        outFile << card;
    }
}

// Loading from file
void loadCollection(std::vector<PokemonCard> &collection)
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

// Exporting to CSV
void exportToCSV(const std::vector<PokemonCard> &collection)
{
    std::ofstream outFile("pokemonCollection.csv");
    if (!outFile)
    {
        std::cerr << "Error creating the file.\n";
        return;
    }

    outFile << "Name,Type,HP,Rarity,Count,Year,Abilities\n";

    for (const auto &card : collection)
    {
        outFile << card.getName() << ","
                << card.getType() << ","
                << card.getHP() << ","
                << card.getRarity() << ","
                << card.getCount() << ","
                << card.getYearPurchased() << ",";

        const auto &abilities = card.getAbilities();
        for (size_t i = 0; i < abilities.size(); ++i)
        {
            outFile << abilities[i];
            if (i < abilities.size() - 1)
                outFile << " / ";
        }

        outFile << "\n";
    }

    outFile.close();
    std::cout << "Collection exported to 'pokemonCollection.csv'\n";
}