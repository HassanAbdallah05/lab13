#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int count = 0;

    #pragma omp parallel for reduction(+:count) 
    for (int i = 0; i < 1000000; i++) {
        count++;
    }

    printf("Final count: %d\n", count);
    return 0;
}

