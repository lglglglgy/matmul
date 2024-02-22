#include <random>
#include "matrix_operations.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
///                           !!!此函数不允许修改!!!                                ///
////////////////////////////////////////////////////////////////////////////////////
//↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ //
void matrixInit(double* A, double* B, double* C, int M, int N){
    default_random_engine eng(30);
    uniform_real_distribution<double> distr(MIN,MAX);
    for(int i = 0; i < M * N ; ++ i){
        A[i] = distr(eng);
    }
    for(int i = 0; i < M * N ; ++ i){
        B[i] = distr(eng);
    }
    for(int i = 0; i < M *M; ++ i){
        C[i] = distr(eng);
    }
}
//↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑ //
////////////////////////////////////////////////////////////////////////////////////
///                           !!!此函数不允许修改!!!                                ///
////////////////////////////////////////////////////////////////////////////////////
void matrixMultiplication(double* A, double* B, double* res, int M, int N) {
    for(int i = 0; i < M; ++ i){
        for(int j = 0; j < M; ++ j){
            double t = 0.0;
            for(int k = 0;  k < N; ++ k){
                t += A[i * N + k] * B[k * M + j];
            }
            res[i * M + j] = t;
        }
    }
}
void matrixSelfAddition(double* A, double* B, int M, int N) {
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < M; ++j) {
            A[i * M + j] += B[i * M + j];
        }
    }
}



