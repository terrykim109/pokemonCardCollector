#include <iostream>
#include <vector>
#include <fstream>
#include "pokemonCollection.h"



int main()
{

    std::vector<PokemonCard> collection;
    char choice;

    // Loading
    loadCollection(collection);

    do
    {
        std::string name, type;
        int hp, count, year;
        char rarity;
        std::vector<std::string> abilities;

        std::cout << "Pokemon Card Collection!" << std::endl;
        std::cout << "*--*--*--*--*--*--*--*--*\n";
        std::cout << "(\\__/)\n";
        std::cout << "(o^.^)\n";
        std::cout << "c(\")_(\")\n";
        std::cout << "*--*--*--*--*--*--*--*--*\n";
        std::cout << "Enter Pokemon Card details:\n";
        std::cout << "Pokemon Name: ";
        std::cin >> name;
        std::cout << "Type (Grass, Fire, Water, etc..): ";
        std::cin >> type;

        std::cout << "HP: ";
        while (!(std::cin >> hp) || hp <= 0)
        {
            std::cout << "Please enter a correct number for HP: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "Rarity (C-Common, U-Uncommon, R-Rare, H-Holo Rare, V-Ultra Rare, S-Secret Rare, F-Full Art, P-Promo, A-Amazing Rare): ";
        while (!(std::cin >> rarity) ||
               (rarity != 'C' && rarity != 'U' && rarity != 'R' && rarity != 'H' &&
                rarity != 'V' && rarity != 'S' && rarity != 'F' && rarity != 'P' && rarity != 'A'))
        {
            std::cout << "Please enter the right type of rarity: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "Collection Count: ";
        while (!(std::cin >> count) || count < 0)
        {
            std::cout << "Please enter the right number of collection: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "Year Purchased: ";
        while (!(std::cin >> year) || year < 2000 || year > 2025)
        {
            std::cout << "Please enter a valid year (2000-2025): ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "Enter abilities for the Pokemon card." << std::endl;
        char addAbility;
        do
        {
            std::string ability;
            std::cout << "Ability: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ability);
            abilities.push_back(ability);
            std::cout << "Add another ability? (y/n): ";
            std::cin >> addAbility;
        } while (addAbility == 'y' || addAbility == 'Y');

        collection.emplace_back(name, type, hp, rarity, count, year, abilities);

        std::cout << "Would you like to add another card? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Saving
    saveCollection(collection);

    std::cout << "Your Pokemon Card Collection:" << std::endl;
    for (const auto &card : collection)
    {
        card.displayCard();
        std::cout << "*--*--*--*--*--*--*--*--*\n";
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
