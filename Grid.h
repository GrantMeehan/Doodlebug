#ifndef GRID_H
#define GRID_H

#include <iostream>
using namespace std;

#include "Organism.h"

Organism*** makeGrid();
void populateGrid(Organism*** grid);
void displayGrid(Organism*** grid);
void destroyGrid(Organism*** grid);
void moveGrid(Organism*** grid);
void breedGrid(Organism*** grid);
void deleteObject(Organism*** grid, int row, int column);

#endif //GRID_H
