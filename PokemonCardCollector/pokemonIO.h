#pragma once
#ifndef POKEMONIO_H
#define POKEMONIO_H

#include "pokemonCollection.h"
#include <iostream>
#include <string>
#include <vector>

extern const std::string FILE_NAME;

void saveCollection(const std::vector<PokemonCard>& collection);
void loadCollection(std::vector<PokemonCard>& collection);
void exportToCSV(const std::vector<PokemonCard>& collection);

#endif
