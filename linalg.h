#ifndef LINALG_H
#define LINALG_H

typedef struct matrix Matrix;

Matrix *createMatrix (int lin, int col);
double accessMatrix (Matrix *base, int i, int j);
void insertMatrix (Matrix *base, int i, int j, double arr);
void displayMatrix (Matrix *base);
int getLines (Matrix *base);
int getColumns (Matrix *base);
void gaussElimination (Matrix *base);
double gaussSolutionSet (Matrix *base);
void freeMatrix (Matrix *base);

#endif