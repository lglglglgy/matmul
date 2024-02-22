#include <iostream>
#include <fstream>
#include <random>
#include <sys/time.h>
#include <cstring>
#include "file_operations.h"
#include "matrix_operations.h"

using namespace std;

int main(int argc, const char * argv[]){
    int M=1024;
    int N=4096;
    if(argc == 1 || strcmp(argv[1], "1024") == 0 ){
        cout << "RUNNING : M = 1024  PLEASE WAIT ..." << endl;
    }
    else if (argc == 2 && strcmp(argv[1], "4096") == 0)
    {
        cout << "RUNNING : M = 4096  PLEASE WAIT ..." << endl;
        M = 4096;
    }
    else
    {
        cout << "Usage: " << argv[0] << " [1024|4096]" << endl;
        return 1;
    }
    // alloc
    double * A = (double*) malloc(sizeof(double) * M * N);
    double * B = (double*) malloc(sizeof(double) * N * M);
    double * C = (double*) malloc(sizeof(double) * M * M);
    double * res = (double*) malloc(sizeof(double) * M * M);
    matrixInit(A,B,C,M,N);
    struct timeval start, end;
    //↓ time init -> start //计时函数不允许修改(计时区开始)
    gettimeofday(&start, NULL);
  
    matrixMultiplication(A,B,res,M,N);
    matrixSelfAddition(res,C,M,N);

    //↓ time end -> stop //计时函数不允许修改(计时区结束)
    gettimeofday(&end, NULL);
    printf("Using time : %f ms\n", (end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000.0);
    // output and test
    writeMatrixToFile(res, M, "result.txt");
        compareFiles(("./data/refer_"+ to_string(M) +".txt").c_str(), "result.txt");
    // free
    free(A);
    free(B);
    free(C);
    free(res);
}
