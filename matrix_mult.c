#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n = 500;
    int A[500][500], B[500][500], C[500][500];
    double start, end;

    // fill matrix with random numbers
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }

    // Add Parallel matrix multiplication Code here using OpenMP
    start = omp_get_wtime();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    end = omp_get_wtime();

    printf("Matrix Multiplication Completed (Time: %.5f seconds)\n", end - start);

    return 0;
}
