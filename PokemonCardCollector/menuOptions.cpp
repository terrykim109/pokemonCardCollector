#include "menuOptions.h"

void showMenu()
{

    std::cout << "Pokemon Card Collection!" << std::endl;
    std::cout << "*--*--*--*--*--*--*--*--*\n";
    std::cout << "(\\__/)\n";
    std::cout << "(o^.^)\n";
    std::cout << "c(\")_(\")\n";
    std::cout << "*--*--*--*--*--*--*--*--*\n";

    std::cout << "What would you like to do?\n";
    std::cout << "1. View existing collection\n";
    std::cout << "2. Add new cards\n";
    std::cout << "3. Delete a card\n";
    std::cout << "4. Export collection to file\n";
    std::cout << "5. View collection stats\n";
    std::cout << "6. Filter cards by type or rarity\n";
    std::cout << "7. Sort collection\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice (1, 2, 3, 4, 5, 6 ,7 or 8.): ";
};

void viewCollection(const std::vector<PokemonCard> &collection)
{

    if (collection.empty())
    {
        std::cout << "Your collection is currently empty." << std::endl;
    }
    else
    {
        std::cout << "Your Pokemon Card Collection:\n";
        for (const auto &card : collection)
        {
            card.displayCard();
            std::cout << "*--*--*--*--*--*--*--*--*\n";
        }
    }
}

void addNewCards(std::vector<PokemonCard> &collection)
{
    std::string name, type;
    int hp, count, year;
    char rarity;
    std::vector<std::string> abilities;

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
}

void deleteCard(std::vector<PokemonCard> &);

void exportCollection(const std::vector<PokemonCard> &);

void viewStats(const std::vector<PokemonCard> &);

void filterCards(const std::vector<PokemonCard> &);

void sortCollection(std::vector<PokemonCard> &);

void searchCard(const std::vector<PokemonCard> &);
