#ifndef ANT_H
#define ANT_H

#include "Organism.h"
using namespace std;

class Ant : public Organism
{
public:
  Ant();
  Ant(int theRow, int theColumn);
  virtual ~Ant();
  void move(Organism*** grid);
  void breed(Organism*** grid);;
  char getValue() const {return value;}
private:
  static const char value = 'O';
};

#endif //ANT_H
