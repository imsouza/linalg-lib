#ifndef LINALG_H
#define LINALG_H

typedef struct matrix Matrix;

Matrix *createMatrix (int row, int col);
double accessMatrix (Matrix *m, int i, int j);
void insertMatrix (Matrix *m, int i, int j, double v);
void displayMatrix (Matrix *m);
void displaySolutionSet(Matrix *m);
int getRows(Matrix *m);
int getColumns(Matrix *m);
Matrix *gaussianElimination(Matrix *m);
Matrix *multiply (Matrix *a, Matrix *b);
Matrix *sum(Matrix *a, Matrix *b);
Matrix *sub(Matrix *a, Matrix *b);
Matrix *transpose(Matrix *m);
double laplaceExpansion(Matrix *m, int max);
void freeMatrix(Matrix *m);

#endif