#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include "pokemonCollection.h"
#include "menuOptions.h"

int main()
{

    std::vector<PokemonCard> collection;
    char choice;

    // Loading
    loadCollection(collection);

    // menu
    while (true)
    {

        showMenu();
        std::cin >> choice;

        // View existing collection
        if (choice == '1')
        {
            viewCollection(collection);
        }

        // Add new cards
        if (choice == '2')
        {
            addNewCards(collection);
        }

        // Delete a card
        if (choice == '3')
        {
            deleteCard(collection);
        }

        // Export to the csv file.
        if (choice == '4')
        {
            PokemonCard::exportToCSV(collection);
        }

        // Show the whole collection and its stats.

        if (choice == '5')
        {
            if (collection.empty())
            {
                std::cout << "Your collection is currently empty." << std::endl;
            }
            else
            {
                // Setting the initial data
                int totalCards = 0;
                int totalUnique = collection.size();
                int highestHP = 0;
                std::string strongestCard;
                std::map<char, int> rarityCount; // Using Map for the rarities of the collected cards
                int oldestYear = 3000, newestYear = 0;
                std::string oldestCard, newestCard;

                for (const auto &card : collection)
                {
                    totalCards += card.getCount();
                    rarityCount[card.getRarity()]++;

                    if (card.getHP() > highestHP)
                    {
                        highestHP = card.getHP();
                        strongestCard = card.getName();
                    }

                    if (card.getYearPurchased() < oldestYear)
                    {
                        oldestYear = card.getYearPurchased();
                        oldestCard = card.getName();
                    }
                    if (card.getYearPurchased() > newestYear)
                    {
                        newestYear = card.getYearPurchased();
                        newestCard = card.getName();
                    }
                }
                std::cout << "\n=== Collection Stats ===\n";

                std::cout << "Total cards (including extra copies): " << totalCards << "\n";
                std::cout << "Total unique cards: " << totalUnique << "\n";
                std::cout << "Rarity Breakdown:\n";
                for (const auto &[rarity, count] : rarityCount)
                {
                    std::cout << "  " << rarity << ": " << count << "\n";
                }

                std::cout << "Strongest card (highest HP): " << strongestCard << " (" << highestHP << " HP)\n";
                std::cout << "Oldest card: " << oldestCard << " (" << oldestYear << ")\n";
                std::cout << "Newest card: " << newestCard << " (" << newestYear << ")\n";
                std::cout << "========================\n";
            }
        }

        if (choice == 6)
        {
            char filterChoice;
            std::cout << "Filter by:\n";
            std::cout << "1. Type\n";
            std::cout << "2. Rarity\n";
            std::cin >> filterChoice;

            if (filterChoice == '1')
            {
                std::string typeFilter;
                std::cout << "Enter type (e.g., Fire, Water, Grass): ";
                std::cin >> typeFilter;

                for (const auto &card : collection)
                {
                    if (card.getType() == typeFilter)
                    {
                        card.displayCard();
                        std::cout << "*--*--*--*--*--*--*--*--*\n";
                    }
                }
            }
            else if (filterChoice == '2')
            {
                char rarityFilter;
                std::cout << "Enter rarity code (C, U, R, H, etc.): ";
                std::cin >> rarityFilter;

                for (const auto &card : collection)
                {
                    if (card.getRarity() == rarityFilter)
                    {
                        card.displayCard();
                        std::cout << "*--*--*--*--*--*--*--*--*\n";
                    }
                }
            }
        }

        // Sorting the collection by user choice of criteria
        if (choice == '7')
        {
            char sortChoice;
            std::cout << "Sort by:\n";
            std::cout << "1. Name (A-Z)\n";
            std::cout << "2. HP (High-Low)\n";
            std::cout << "3. Year (Old-New)\n";
            std::cout << "4. Rarity\n";
            std::cin >> sortChoice;

            if (sortChoice == '1')
            {
                std::sort(collection.begin(), collection.end(),
                          [](const PokemonCard &a, const PokemonCard &b)
                          {
                              return a.getName() < b.getName();
                          });
            }
            else if (sortChoice == '2')
            {
                std::sort(collection.begin(), collection.end(),
                          [](const PokemonCard &a, const PokemonCard &b)
                          {
                              return a.getHP() > b.getHP();
                          });
            }
            else if (sortChoice == '3')
            {
                std::sort(collection.begin(), collection.end(),
                          [](const PokemonCard &a, const PokemonCard &b)
                          {
                              return a.getYearPurchased() < b.getYearPurchased();
                          });
            }
            else if (sortChoice == '4')
            {
                std::sort(collection.begin(), collection.end(),
                          [](const PokemonCard &a, const PokemonCard &b)
                          {
                              return a.getRarity() < b.getRarity();
                          });
            }

            std::cout << "Collection has been sorted!\n";
        }

        if (choice == 8)
            break;
    }

    // Search feature for cards by name
    std::string searchName;
    std::cout << "Would you like to search for a card by name? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        std::cout << "Enter the name of the card to search: ";
        std::cin >> searchName;
        bool found = false;
        for (const auto &card : collection)
        {
            if (card.getName() == searchName)
            {
                std::cout << "\nCard Found:" << std::endl;
                card.displayCard();
                found = true;
            }
        }
        if (!found)
        {
            std::cout << "No card with the name '" << searchName << "' was found in your collection." << std::endl;
        }
    }

    return 0;
}
