#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linalg.h"

struct matrix {
  int lin;
  int col;
  double **arr;
};


void 
*allocateMatrix (int size) {
  void *init = malloc (size);

  if (init == NULL) {
    perror("[!] Error!");
    exit(1);
  }

  return init;
}


Matrix 
*createMatrix (int lin, int col) {
  Matrix *base = (Matrix *) \
  allocateMatrix(sizeof(Matrix));

  base->lin = lin;
  base->col = col;
  base->arr = (double **) \
  allocateMatrix(lin * sizeof(double *));

  for (int i = 0; i < lin; i++) {
    base->arr[i] = (double *) \
    allocateMatrix(col * sizeof(double));
  }

  return base;
}


double 
accessMatrix (Matrix *base, int i, int j) {
  return base->arr[i][j];
}


void 
insertMatrix (Matrix *base, int i, int j, double arr) {
  base->arr[i][j] = arr;
}


int 
getLines (Matrix *base) {
  return base->lin;
}


int 
getColumns (Matrix *base) {
  return base->col;
}


void 
displayMatrix (Matrix *base) {
  const int LIN = getLines(base);
  const int COL = getColumns(base);

  for (int i = 0; i < LIN; i++) {
    for (int j = 0; j < COL; j++) {
      printf("%3.2lf ", accessMatrix(base, i, j));
    }

    putchar('\n');
  }
}


void 
displaySolutionSet (double *S, const int LIN) {
  printf("S = {");
  for (int i = 0; i < LIN; i++) {
    if (i > 0) { putchar(','); }
    printf(" %3.2lf", S[i]);
  }
  printf(" }\n");
}


void 
gaussElimination (Matrix *base) {
  double elementarOperation = 0;

  const int LIN = getLines(base);
  const int COL = getColumns(base);

  for (int i = 0; i < LIN; i++) {
    if (base->arr[i][i] == 0.0) { 
      printf("\n[!] The system is inconsistent!\n");; 
      exit(0); 
    }
    for (int j = 0; j < LIN; j++) {
      if (i != j) {
        elementarOperation = (base->arr[j][i]) / base->arr[i][i];
        for (int k = 0; k < COL; k++) {
          base->arr[j][k] = base->arr[j][k] - \
          (base->arr[i][k] * elementarOperation);
        }
      }
    }
  }
}


double 
gaussSolutionSet (Matrix *base) {
  const int LIN = getLines(base);

  double *S = malloc (LIN * sizeof(double));

  for (int i = 0; i < LIN; i++) {
    S[i] = base->arr[i][LIN] / base->arr[i][i];
  }

  displaySolutionSet(S, LIN);

  free(S);
  S = NULL;
  
  return 0;
}


void 
freeMatrix (Matrix *base) {
  for (int i = 0; i < base->lin; i++) {
    free(base->arr[i]);
  }

  free(base);
  base = NULL;
}
