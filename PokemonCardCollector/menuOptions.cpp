#include "menuOptions.h"

void showMenu(){
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
    std::cout << "6. Filter cards by type or rarity\n";\
    std::cout << "7. Sort collection\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice (1, 2, 3, 4, 5, 6 ,7 or 8.): ";
};

void viewCollection(const std::vector<PokemonCard>& collection) {

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

void addNewCards(std::vector<PokemonCard>&);

void deleteCard(std::vector<PokemonCard>&);

void exportCollection(const std::vector<PokemonCard>&);

void viewStats(const std::vector<PokemonCard>&);

void filterCards(const std::vector<PokemonCard>&);

void sortCollection(std::vector<PokemonCard>&);

void searchCard(const std::vector<PokemonCard>&);
