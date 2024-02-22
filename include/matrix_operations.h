#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

void matrixInit(double* A, double* B, double* C, int M, int N);
void matrixMultiplication(double* A, double* B, double* res, int M, int N);
void matrixSelfAddition(double* A, double* B, int M, int N);


// #define M 1024
// #define N 4096

#define MIN 1
#define MAX 50

#endif // MATRIX_OPERATIONS_H
