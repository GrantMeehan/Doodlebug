#include "Organism.h"
using namespace std;

Organism::Organism(): row(0), column(0), turnsSurvived(0), movedThisTurn(false)
{
  //intentionally empty
}
Organism::Organism(int theRow, int theColumn):
        row(theRow), column(theColumn), turnsSurvived(0), movedThisTurn(false)
{
  //intentionally empty
}
Organism::~Organism()
{
  //intentionally empty
}
