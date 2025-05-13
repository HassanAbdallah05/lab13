#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double vector_dot(double *v1, double *v2, int n) {
    double dot_product = 0.0;

    #pragma omp parallel for reduction(+:dot_product)
    for (int i = 0; i < n; i++) {
        double partial_result = v1[i] * v2[i];

        dot_product += partial_result;

        int thread_num = omp_get_thread_num();
        printf("Thread %d: v1[%d] = %.2f, v2[%d] = %.2f, partial result = %.2f\n", 
               thread_num, i, v1[i], i, v2[i], partial_result);
    }
    return dot_product;
}
int main() {
    int n, i;
    double result;

    printf("Enter the size of the vectors: ");
    scanf("%d", &n);

    double *v1 = malloc(n * sizeof(double));
    double *v2 = malloc(n * sizeof(double));
    if (!v1 || !v2) {
        perror("malloc");
        return 1;
    }

    printf("Enter elements of vector 1:\n");
    for (i = 0; i < n; i++)
        scanf("%lf", &v1[i]);

    printf("Enter elements of vector 2:\n");
    for (i = 0; i < n; i++)
        scanf("%lf", &v2[i]);

    result = vector_dot(v1, v2, n);
    printf("Dot product: %.2f\n", result);

    free(v1);
    free(v2);
    return 0;
}
