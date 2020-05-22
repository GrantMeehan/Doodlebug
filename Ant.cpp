#include "Ant.h"
#include <cstdlib>
#include <cstddef>
#include <iostream>
using namespace std;

Ant::Ant():Organism()
{
  //intentionally empty
}
Ant::Ant(int theRow, int theColumn): Organism(theRow, theColumn)
{
  //intentionally empty
}
Ant::~Ant()
{

}
void Ant::move(Organism*** grid) //MOVE RIGHT NOT WORKING???
{
  int direction = rand() % 4;
  setMovedThisTurn(true);
  setTurnsSurvived(getTurnsSurvived()+1);

  if (direction == 0 && getRow() > 0) { //up
    if (grid[getRow() - 1][getColumn()] == NULL) {
				grid[getRow() - 1][getColumn()] = this;
				grid[getRow()][getColumn()] = NULL;
				setRow(getRow() - 1);
        return;
			}
  }
  if (direction == 1 && getColumn() < 19) { //right
    if (grid[getRow()][getColumn() + 1] == NULL) {
				grid[getRow()][getColumn() + 1] = this;
				grid[getRow()][getColumn()] = NULL;
				setColumn(getColumn() + 1);
        return;
			}
  }
  if (direction == 2 && getRow() < 19) {//down
    if (grid[getRow() + 1][getColumn()] == NULL) {
				grid[getRow() + 1][getColumn()] = this;
				grid[getRow()][getColumn()] = NULL;
				setRow(getRow() + 1);
        return;
			}
  }
  if (direction = 3 && getColumn() > 0) {//left
    if (grid[getRow()][getColumn() - 1] == NULL) {
				grid[getRow()][getColumn() - 1] = this;
				grid[getRow()][getColumn()] = NULL;
				setColumn(getColumn() - 1);
        return;
			}
  }

}
void Ant::breed(Organism*** grid)
{
  if (getTurnsSurvived() >= 3) {
    int direction;
    direction = rand() % 4;
    if (direction == 0 && getRow() > 0 && grid[getRow() - 1][getColumn()] == NULL) { // UP
      grid[getRow() - 1][getColumn()] = new Ant(getRow() - 1,getColumn());
      setTurnsSurvived(0);
    }
    else if (direction == 1 && getColumn() < 19 && grid[getRow()][getColumn() + 1] == NULL) { // RIGHT
      grid[getRow()][getColumn() + 1] = new Ant(getRow(),getColumn() + 1);
      setTurnsSurvived(0);
    }
    else if (direction == 2 && getRow() < 19 && grid[getRow() + 1][getColumn()] == NULL) { // DOWN
      grid[getRow() + 1][getColumn()] = new Ant(getRow() + 1,getColumn());
      setTurnsSurvived(0);
    }
    else if (direction == 3 && getColumn() > 0 && grid[getRow()][getColumn() - 1] == NULL) { // LEFT
      grid[getRow()][getColumn() - 1] = new Ant(getRow(),getColumn() - 1);
      setTurnsSurvived(0);
    }
  }
}
