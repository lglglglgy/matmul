////////////////////////////////////////////////////////////////////////////////////
///                           !!!此文件不允许修改!!!                                ///
////////////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <iostream>
void compareFiles(const char* standardFile, const char* resultFile) {
    FILE* standard = fopen(standardFile, "r");
    FILE* result = fopen(resultFile, "r");

    if (!standard || !result) {
        std::cerr << "Error opening file(s)" << std::endl;
        return;
    }

    double num1, num2;
    bool isCorrect = true;
    while(fscanf(standard, "%lf", &num1) != EOF && fscanf(result, "%lf", &num2) != EOF){
        double diff = num1 - num2;
        if (abs(diff) > 1) {
            isCorrect = false;
            break;
        }
    }

    if (isCorrect) {
        std::cout << "\033[1;32mThe result is correct!\033[0m" << std::endl;
    } else {
        std::cout << "\033[1;31mThe result is wrong!\033[0m" << std::endl;
    }

    fclose(standard);
    fclose(result);
}
void writeMatrixToFile(double* matrix, int size, const char* filename) {
    FILE* out = fopen(filename, "w");
    if (out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            fprintf(out, "%.2lf\t", matrix[i * size + j]);
        }
        fprintf(out, "\n");
    }

    fclose(out);
}
////////////////////////////////////////////////////////////////////////////////////
///                           !!!此文件不允许修改!!!                                ///
////////////////////////////////////////////////////////////////////////////////////