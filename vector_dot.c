#include <stdio.h>
#include <stdlib.h>

// Add parallel vector dot code here Using OpenMP
double vector_dot(double *v1, double *v2, int n) {
    double dot_product = 0.0;
    for (int i = 0; i < n; i++) {
        dot_product += v1[i] * v2[i];
    }
    return dot_product;
}

int main() {
    int n, i;
    double result;
    printf("Enter the size of the vectors: ");
    scanf("%d", &n);

    int *v1 = malloc(n * sizeof(double));
    int *v2 = malloc(n * sizeof(double));
    if (!v1 || !v2) {
        perror("Memory allocation failed");
        return -1;
    }

    printf("Enter elements of vector 1:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v1[i]);
    }

    printf("Enter elements of vector 2:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }

    result = vector_dot(v1, v2, n);
    printf("Dot product: %.2f\n", result);

    free(v1);
    free(v2);

    return 0;
}

