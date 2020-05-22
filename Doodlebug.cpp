#include "Doodlebug.h"
#include <cstdlib>
#include <cstddef>
using namespace std;

Doodlebug::Doodlebug():Organism(), starveCounter(0)
{
  //intentionally empty
}
Doodlebug::Doodlebug(int theRow, int theColumn): Organism(theRow,theColumn), starveCounter(0)
{
  //intentionally empty
}
Doodlebug::~Doodlebug()
{

}
void Doodlebug::move(Organism*** grid)
{
  setMovedThisTurn(true);
  setTurnsSurvived(getTurnsSurvived()+1);
  int direction;
  direction = rand() % 4;
  if (direction == 0 && getRow() > 0 && grid[getRow() - 1][getColumn()] != NULL && grid[getRow() - 1][getColumn()]->getValue() == 'O') { // UP
    grid[getRow() - 1][getColumn()] = this;
    grid[getRow()][getColumn()] = NULL;
    setRow(getRow() - 1);
    setStarveCounter(0);
    return;
  }
  else if (direction == 1 && getColumn() < 19 && grid[getRow()][getColumn() + 1] != NULL && grid[getRow()][getColumn() + 1]->getValue() == 'O') { // RIGHT
    grid[getRow()][getColumn() + 1] = this;
    grid[getRow()][getColumn()] = NULL;
    setColumn(getColumn() + 1);
    setStarveCounter(0);
    return;
  }
  else if (direction == 2 && getRow() < 19 && grid[getRow() + 1][getColumn()] != NULL && grid[getRow() + 1][getColumn()]->getValue() == 'O') { // DOWN
    grid[getRow() + 1][getColumn()] = this;
    grid[getRow()][getColumn()] = NULL;
    setRow(getRow() + 1);
    setStarveCounter(0);
    return;
  }
  else if (direction == 3 && getColumn() > 0 && grid[getRow()][getColumn() - 1] != NULL && grid[getRow()][getColumn() - 1]->getValue() == 'O') { // LEFT
    grid[getRow()][getColumn() - 1] = this;
    grid[getRow()][getColumn()] = NULL;
    setColumn(getColumn() - 1);
    setStarveCounter(0);
    return;
  }
  else
  {
    direction = rand() % 4;

    if (direction == 0 && getRow() > 0) { //up
      if (grid[getRow() - 1][getColumn()] == NULL) {
          grid[getRow() - 1][getColumn()] = this;
          grid[getRow()][getColumn()] = NULL;
          setRow(getRow() - 1);
          setStarveCounter(getStarveCounter() + 1);
          if (getStarveCounter() >= 3)
          {
            grid[getRow()][getColumn()] = NULL;
            delete this;
          }
          return;
        }
    }
    if (direction == 1 && getColumn() < 19) { //right
      if (grid[getRow()][getColumn() + 1] == NULL) {
          grid[getRow()][getColumn() + 1] = this;
          grid[getRow()][getColumn()] = NULL;
          setColumn(getColumn() + 1);
          setStarveCounter(getStarveCounter() + 1);
          if (getStarveCounter() >= 3)
          {
            grid[getRow()][getColumn()] = NULL;
            delete this;
          }
          return;
        }
    }
    if (direction == 2 && getRow() < 19) {//down
      if (grid[getRow() + 1][getColumn()] == NULL) {
          grid[getRow() + 1][getColumn()] = this;
          grid[getRow()][getColumn()] = NULL;
          setRow(getRow() + 1);
          setStarveCounter(getStarveCounter() + 1);
          if (getStarveCounter() >= 3)
          {
            grid[getRow()][getColumn()] = NULL;
            delete this;
          }
          return;
        }
    }
    if (direction = 3 && getColumn() > 0) {//left
      if (grid[getRow()][getColumn() - 1] == NULL) {
          grid[getRow()][getColumn() - 1] = this;
          grid[getRow()][getColumn()] = NULL;
          setColumn(getColumn() - 1);
          setStarveCounter(getStarveCounter() + 1);
          if (getStarveCounter() >= 3)
          {
            grid[getRow()][getColumn()] = NULL;
            delete this;
          }
          return;
        }
    }
  }
}
void Doodlebug::breed(Organism*** grid)
{
  if (getTurnsSurvived() >= 8) {
    int direction;
    direction = rand() % 4;
    if (direction == 0 && getRow() > 0 && grid[getRow() - 1][getColumn()] == NULL) { // UP
      grid[getRow() - 1][getColumn()] = new Doodlebug(getRow() - 1,getColumn());
      setTurnsSurvived(0);
      return;
    }
    else if (direction == 1 && getColumn() < 19 && grid[getRow()][getColumn() + 1] == NULL) { // RIGHT
      grid[getRow()][getColumn() + 1] = new Doodlebug(getRow(),getColumn() + 1);
      setTurnsSurvived(0);
      return;
    }
    else if (direction == 2 && getRow() < 19 && grid[getRow() + 1][getColumn()] == NULL) { // DOWN
      grid[getRow() + 1][getColumn()] = new Doodlebug(getRow() + 1,getColumn());
      setTurnsSurvived(0);
      return;
    }
    else if (direction == 3 && getColumn() > 0 && grid[getRow()][getColumn() - 1] == NULL) { // LEFT
      grid[getRow()][getColumn() - 1] = new Doodlebug(getRow(),getColumn() - 1);
      setTurnsSurvived(0);
      return;
    }
  }
}
void Doodlebug::starve(Organism*** grid)
{
//  if (getStarveCounter() >= 3)
//  {
    //grid[getRow()][getColumn()] = NULL;
    //delete this;
//  }
}
