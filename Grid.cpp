#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"

Organism*** makeGrid()
{
  Organism*** grid = new Organism**[20];
  for (int i = 0; i < 20; i++)
  {
    grid[i] = new Organism*[20];
  }

  for (int i = 0; i < 20; i++) { //fills all spots in grid to NULL
    for (int j = 0; j < 20; j++) {
      grid[i][j] = NULL;
    }
  }

  return grid;
}

void populateGrid(Organism*** grid)
{
  int numAnts = 100;
  int numDoodlebugs = 5;

  while(numAnts > 0) //fills Ants in grid
  {
    int rRow = rand() % 20;
    int rColumn = rand() % 20;

    if (grid[rRow][rColumn] == NULL) {
      grid[rRow][rColumn] = new Ant(rRow, rColumn);
      numAnts--;
    }
  }
  while(numDoodlebugs > 0) //fills Doodlebugs in grid
  {
    int rRow = rand() % 20;
    int rColumn = rand() % 20;

    if (grid[rRow][rColumn] == NULL) {
      grid[rRow][rColumn] = new Doodlebug(rRow, rColumn);
      numDoodlebugs--;
    }
  }
}

void displayGrid(Organism*** grid)
{
  cout << "--------------------------------------------" << endl;
  for (int i = 0; i < 20; i++) { //prints out grid with Ants and Doodlebugs
    cout << "| ";
    for (int j = 0; j < 20; j++) {
      if (grid[i][j] != NULL) {
        cout << grid[i][j]->getValue() << " ";
      }
      else
        cout << " " << " ";
    }
    cout << "|" << endl;
  }
  cout << "--------------------------------------------" << endl;
}

void moveGrid(Organism*** grid)
{
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (grid[i][j] != NULL)
        grid[i][j]->setMovedThisTurn(false);
    }
  }
  for (int i = 0; i < 20; i++) { // MOVE DOODLEBUGS
    for (int j = 0; j < 20; j++) {
      if (grid[i][j] != NULL && grid[i][j]->getValue()=='X' && grid[i][j]->getMovedThisTurn()==false) {
        grid[i][j]->move(grid);
      }
    }
  }
  for (int i = 0; i < 20; i++) { // MOVE ANTS
    for (int j = 0; j < 20; j++) {
      if (grid[i][j] != NULL && grid[i][j]->getValue()=='O' && grid[i][j]->getMovedThisTurn()==false) {
        grid[i][j]->move(grid);
      }
    }
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (grid[i][j] != NULL)
        grid[i][j]->setMovedThisTurn(false);
    }
  }
}
void breedGrid(Organism*** grid)
{
  for (int i = 0; i < 20; i++) { // MOVE DOODLEBUGS
    for (int j = 0; j < 20; j++) {
      if (grid[i][j] != NULL && grid[i][j]->getValue()=='X') {
        grid[i][j]->breed(grid);
      }
    }
  }
  for (int i = 0; i < 20; i++) { // MOVE ANTS
    for (int j = 0; j < 20; j++) {
      if (grid[i][j] != NULL && grid[i][j]->getValue()=='O') {
        grid[i][j]->breed(grid);
      }
    }
  }
}
