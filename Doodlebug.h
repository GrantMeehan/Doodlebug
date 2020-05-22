#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Organism.h"
using namespace std;

class Doodlebug : public Organism
{
public:
  Doodlebug();
  Doodlebug(int theRow, int theColumn);
  virtual ~Doodlebug();
  void move(Organism*** grid);
  void breed(Organism*** grid);
  void starve(Organism*** grid);
  char getValue() const {return value;}
  int getStarveCounter() const {return starveCounter;}
  void setStarveCounter(int theStarveCounter) {starveCounter = theStarveCounter;}
private:
  static const char value = 'X';
  int starveCounter;
};

#endif //DOODLEBUG_H
