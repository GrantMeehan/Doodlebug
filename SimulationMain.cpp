/// Question 2 - Problem 3 on page 695
//

#include "Grid.h"
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  srand(time(NULL));

  cout << "Question 2 Output:\n" << endl;

  Organism*** grid = makeGrid();

  populateGrid(grid);

  int turns = 0;
  bool input = true;
  while(input){
    cout << "Organism simulation grid after " << turns << " moves." << endl;
    displayGrid(grid);
    moveGrid(grid);
    breedGrid(grid);
    turns++;

    cout << "Press 'enter' to see result of move " << turns << "." << endl;
    cout << "Press any other key + 'enter' to exit." << endl;
    char temp = cin.get();
    if(temp=='\n')
      input = true;
    else
      input = false;
  }

  return 0;
}

//
///
