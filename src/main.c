#include <stdio.h>
#include <stdlib.h>
#include "linalg.h"

int main (int argc, char const *argv[]) {
  printf("Gauss Elimination:\n\n");

  Matrix *r = createMatrix(3, 4);

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

  Matrix *resG = gaussianElimination(r);
  displayMatrix(resG);
  displaySolutionSet(resG);
  freeMatrix(resG);


  printf("\nMultiplication:\n\n");

  Matrix *a = createMatrix(3, 3);
  insertMatrix(a, 0, 0, 2);
  insertMatrix(a, 0, 1, 5);
  insertMatrix(a, 0, 2, 6);
  insertMatrix(a, 1, 0, 3);
  insertMatrix(a, 1, 1, 1);
  insertMatrix(a, 1, 2, 4);
  insertMatrix(a, 2, 0, 1);
  insertMatrix(a, 2, 1, 2);
  insertMatrix(a, 2, 2, 8);

  Matrix *b = createMatrix(3, 3);
  insertMatrix(b, 0, 0, 2);
  insertMatrix(b, 0, 1, 5);
  insertMatrix(b, 0, 2, 6);
  insertMatrix(b, 1, 0, 3);
  insertMatrix(b, 1, 1, 1);
  insertMatrix(b, 1, 2, 4);
  insertMatrix(b, 2, 0, 1);
  insertMatrix(b, 2, 1, 2);
  insertMatrix(b, 2, 2, 8);

  Matrix *resM = multiply(a, b);
  displayMatrix(resM);

  freeMatrix(a);
  freeMatrix(b);
  freeMatrix(resM);


  printf("\nAddition:\n\n");

  Matrix *s = createMatrix(3, 3);
  insertMatrix(s, 0, 0, 1);
  insertMatrix(s, 0, 1, 2);
  insertMatrix(s, 0, 2, 3);
  insertMatrix(s, 1, 0, 3);
  insertMatrix(s, 1, 1, 2);
  insertMatrix(s, 1, 2, 1);
  insertMatrix(s, 2, 0, 0);
  insertMatrix(s, 2, 1, 1);
  insertMatrix(s, 2, 2, 2);

  Matrix *j = createMatrix(3, 3);
  insertMatrix(j, 0, 0, 1);
  insertMatrix(j, 0, 1, 2);
  insertMatrix(j, 0, 2, 3);
  insertMatrix(j, 1, 0, 3);
  insertMatrix(j, 1, 1, 2);
  insertMatrix(j, 1, 2, 1);
  insertMatrix(j, 2, 0, 0);
  insertMatrix(j, 2, 1, 1);
  insertMatrix(j, 2, 2, 2);

  Matrix *rSum = sum(s, j);
  displayMatrix(rSum);

  freeMatrix(s);
  freeMatrix(j);
  freeMatrix(rSum);


  printf("\nSubtraction:\n\n");

  Matrix *u = createMatrix(3, 3);
  insertMatrix(u, 0, 0, 3);
  insertMatrix(u, 0, 1, 2);
  insertMatrix(u, 0, 2, 5);
  insertMatrix(u, 1, 0, 6);
  insertMatrix(u, 1, 1, 8);
  insertMatrix(u, 1, 2, 9);
  insertMatrix(u, 2, 0, 0);
  insertMatrix(u, 2, 1, 4);
  insertMatrix(u, 2, 2, 2);

  Matrix *z = createMatrix(3, 3);
  insertMatrix(z, 0, 0, 1);
  insertMatrix(z, 0, 1, 5);
  insertMatrix(z, 0, 2, 6);
  insertMatrix(z, 1, 0, 4);
  insertMatrix(z, 1, 1, 5);
  insertMatrix(z, 1, 2, 2);
  insertMatrix(z, 2, 0, 3);
  insertMatrix(z, 2, 1, 1);
  insertMatrix(z, 2, 2, 2);

  Matrix *rSub = sub(u, z);
  displayMatrix(rSub);

  freeMatrix(u);
  freeMatrix(z);
  freeMatrix(rSub);


  printf("\nTranspose:\n\n");

  Matrix *t = createMatrix(3, 3);
  insertMatrix(t, 0, 0, 1);
  insertMatrix(t, 0, 1, 2);
  insertMatrix(t, 0, 2, 3);
  insertMatrix(t, 1, 0, 3);
  insertMatrix(t, 1, 1, 2);
  insertMatrix(t, 1, 2, 1);
  insertMatrix(t, 2, 0, 0);
  insertMatrix(t, 2, 1, 1);
  insertMatrix(t, 2, 2, 2);

  displayMatrix(t);
  Matrix *resT = transpose(t);
  printf("\n");
  displayMatrix(resT);

  freeMatrix(t);
  freeMatrix(resT);
  
  return 0;
}