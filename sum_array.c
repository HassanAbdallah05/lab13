#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n = 10000000;
    int *arr = (int *)malloc(n * sizeof(int));
    int sum = 0;
    int i;
    double start, end;

    // fill it with random numbers
    for (i = 0; i < n; i++)
        arr[i] = rand() % 13;

    // Serial sum
    start = omp_get_wtime();
    for (i = 0; i < n; i++)
        sum += arr[i];
    end = omp_get_wtime();
    printf("Serial sum is %d Time needed for serial is %.5f\n", sum, end - start);

    // Parallel sum
    sum = 0;
    start = omp_get_wtime();
    // add parallel sum code here Using OpenMP
    for (i = 0; i < n; i++)
        sum += arr[i];
    end = omp_get_wtime();
    printf("Parallel sum is %d Time needed for parllel is %.5f\n", sum, end - start);

    free(arr);
    return 0;
}

