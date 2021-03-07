#include <stdio.h>
#include "linalg.h"

int main (int argc, char const *argv[]) {
  Matrix *r = createMatrix(3, 4);

  /*
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      insertMatrix(r, i, j, i+1+j);
    }
  }
  */

  insertMatrix(r, 0, 0, 2);
  insertMatrix(r, 0, 1, 1);
  insertMatrix(r, 0, 2, 3);
  insertMatrix(r, 0, 3, 5);
  insertMatrix(r, 1, 0, 4);
  insertMatrix(r, 1, 1, -2);
  insertMatrix(r, 1, 2, 3);
  insertMatrix(r, 1, 3, 5);
  insertMatrix(r, 2, 0, 2);
  insertMatrix(r, 2, 1, 4);
  insertMatrix(r, 2, 2, 2);
  insertMatrix(r, 2, 3, 4);

  gaussElimination(r);
  gaussSolutionSet(r);

  displayMatrix(r);
  freeMatrix(r);

  return 0;
}