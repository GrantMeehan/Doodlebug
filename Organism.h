#ifndef ORGANISM_H
#define ORGANISM_H

using namespace std;

class Organism
{
public:
  Organism();
  Organism(int theRow, int thecolumn);
  virtual ~Organism();
  void virtual move(Organism*** grid){}
  void virtual breed(Organism*** grid){}
  void virtual starve(Organism*** grid){}
  char virtual getValue() const{}
  int getRow() const {return row;}
  int getColumn() const {return column;}
  int getTurnsSurvived() const {return turnsSurvived;}
  bool getMovedThisTurn() const {return movedThisTurn;}
  void setRow(int theRow) {row = theRow;}
  void setColumn(int thecolumn) {column = thecolumn;}
  void setTurnsSurvived(int theTurnsSurvived) {turnsSurvived = theTurnsSurvived;}
  void setMovedThisTurn(bool theMovedThisTurn) {movedThisTurn = theMovedThisTurn;}
protected:
  int row, column;
	int turnsSurvived;
	bool movedThisTurn;
};

#endif //ORGANISM_H
