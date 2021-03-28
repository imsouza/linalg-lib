#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linalg.h"

struct matrix {
  int row;
  int col;
  double **v;
};


Matrix 
*createMatrix (int row, int col) {
  Matrix *m = (Matrix *) malloc (sizeof(Matrix));

  if (m == NULL) {
    free(m);
    perror("[!] Error! ");
    exit(1);
  }

  m->row = row;
  m->col = col;
  m->v = (double **) malloc (row * sizeof(double *));

  if (m->v == NULL) {
    free(m->v);
    perror("[!] Error! ");
    exit(1);
  }

  for (int i = 0; i < row; i++) {
    m->v[i] = (double *) malloc (col * sizeof(double));
  }

  return m;
}


double 
accessMatrix (Matrix *m, int i, int j) {
  if (i < 0 || j < 0 || i >= m->row || j >= m->col) {
    printf("\n[!] Error! Incorrect values!\n");
    exit(1);
  }

  return m->v[i][j];
}


void 
insertMatrix (Matrix *m, int i, int j, double v) {
  if (i < 0 || j < 0 || i >= m->row || j >= m->col) {
    printf("\n[!] Error! Incorrect values!\n");
    exit(1);
  }

  m->v[i][j] = v;
}


int 
getRows (Matrix *m) {
  return m->row;
}


int 
getColumns (Matrix *m) {
  return m->col;
}


void 
displayMatrix (Matrix *m) {
  const int row = getRows(m);
  const int col = getColumns(m);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%3.2lf ", accessMatrix(m, i, j));
    }

    putchar('\n');
  }
}


void 
displaySolutionSet (Matrix *m) {
  const int row = getRows(m);

  double *S = calloc (row, sizeof(double));

  if (S == NULL) {
    perror("[!] Error! ");
    exit(1);
  }

  for (int i = 0; i < row; i++) {
    S[i] = m->v[i][row] / m->v[i][i];
  }

  printf("\nS = {");
  for (int i = 0; i < row; i++) {
    if (i > 0) { putchar(','); }
    printf(" %3.2lf", S[i]);
  }
  printf(" }\n");

  free(S);
  S = NULL;
}



Matrix 
*gaussianElimination (Matrix *m) {
  double elementarOperation = 0;

  const int row = getRows(m);
  const int col = getColumns(m);

  for (int i = 0; i < row; i++) {
    if (m->v[i][i] == 0.0) { 
      printf("\n[!] Error! The system is inconsistent!\n");
      exit(0); 
    }
    for (int j = 0; j < row; j++) {
      if (i != j) {
        elementarOperation = (m->v[j][i]) / m->v[i][i];
        for (int k = 0; k < col; k++) {
          m->v[j][k] = m->v[j][k] - \
          (m->v[i][k] * elementarOperation);
        }
      }
    }
  }

  return m;
}


Matrix 
*multiply (Matrix *a, Matrix *b) {
  const int col = getColumns(a);
  const int row = getRows(b);

  if (col == row) {
    int index = 0;
    Matrix *M = createMatrix(row, col);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        for (int k = 0; k < row; k++) {
          index += a->v[i][k] * b->v[k][j];
        }

        M->v[i][j] = index;
        index = 0;
      }
    }

    return M;
  } else {
    printf("\n[!] Error! Incorrect dimensions.\n");
    exit(0);
  }

  return 0; 
}


Matrix
*sum (Matrix *a, Matrix *b) {
  const int rowA = getRows(a);
  const int colA = getColumns(a);
  const int rowB = getRows(b);
  const int colB = getColumns(b);

  if (rowA != rowB || colA != colB){
    printf("\n[!] Error! Incorrect dimensions.\n");
    exit(0);
  }

  Matrix *S = createMatrix(rowA, colA);

  for (int i = 0; i < rowA; i++){
    for (int  j = 0; j < colA; j++){
      S->v[i][j] = a->v[i][j] + b->v[i][j];
    }
  }

  return S;
}


Matrix
*sub (Matrix *a, Matrix *b) {
  const int rowA = getRows(a);
  const int colA = getColumns(a);
  const int rowB = getRows(b);
  const int colB = getColumns(b);

  if (rowA != rowB || colA != colB){
    printf("\n[!] Error! Incorrect dimensions.\n");
    exit(0);
  }

  Matrix *S = createMatrix(rowA, colA);

  for (int i = 0; i < rowA; i++){
    for (int  j = 0; j < colA; j++){
      S->v[i][j] = a->v[i][j] - b->v[i][j];
    }
  }
  
  return S;
}


Matrix
*transpose (Matrix *m) {
  const int col = getColumns(m);
  const int row = getRows(m);

  Matrix *T = createMatrix(row, col);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      T->v[i][j] = m->v[j][i];
    }
  }

  return T;
}


void 
freeMatrix (Matrix *m) {
  for (int i = 0; i < m->row; i++) {
    free(m->v[i]);
  }

  free(m->v);

  free(m);

  m = NULL;
}
