#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n = 10000000;
    int *arr = malloc(n * sizeof(int));
    int sum = 0;
    double start, end;

    // fill with random numbers
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 13;

    // Serial sum
    start = omp_get_wtime();
    for (int i = 0; i < n; i++)
        sum += arr[i];
    end = omp_get_wtime();
    printf("Serial sum is %d   Time needed for serial is %.5f s\n",
           sum, end - start);

    // Print how many threads will be used
    #pragma omp parallel
    {
        #pragma omp master
        {
            int nt = omp_get_num_threads();
            printf("Parallel region will use %d threads\n", nt);
        }
    }

    // Parallel sum with reduction
    sum = 0;
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++)
        sum += arr[i];
    end = omp_get_wtime();
    printf("Parallel sum is %d   Time needed for parallel is %.5f s\n",
           sum, end - start);

    free(arr);
    return 0;
}
