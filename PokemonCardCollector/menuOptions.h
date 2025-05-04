#pragma once
#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include "pokemonCollection.h"

void showMenu();

void viewCollection(const std::vector<PokemonCard>&);

void addNewCards(std::vector<PokemonCard>&);

void deleteCard(std::vector<PokemonCard>&);

void exportCollection(const std::vector<PokemonCard>&);

void viewStats(const std::vector<PokemonCard>&);

void filterCards(const std::vector<PokemonCard>&);

void sortCollection(std::vector<PokemonCard>&);

void searchCard(const std::vector<PokemonCard>&);

#endif

