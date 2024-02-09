//Suraj Raghuvanshi : Orphaned Parallel Loop Reduction
#include <stdio.h>
#include <omp.h>

int main() {
    const int N = 10;
    int i, sum = 0;

    #pragma omp parallel for reduction(+:sum) // Orphaned parallel loop
    for (i = 0; i < N; ++i) {
        sum += i;
    }

    // Parallel region ends here, sum can be accessed safely
    printf("Sum of numbers from 0 to %d is: %d\n", N - 1, sum);

    return 0;
}
