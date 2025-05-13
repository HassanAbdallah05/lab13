// matrix_mul.c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n = 500;
    static int A[500][500], B[500][500], C[500][500];
    double start, end;

    // fill A and B with random numbers
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0;            // initialize result
        }

    start = omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end = omp_get_wtime();

    printf("Matrix Multiplication Completed (Time: %.5f seconds)\n",
           end - start);

    // print a few sample elements to stdout
    printf("C[0][0]=%d   C[0][1]=%d   C[1][0]=%d   C[1][1]=%d\n",
           C[0][0], C[0][1], C[1][0], C[1][1]);

    return 0;
}
