//Suraj Raghuvanshi : OpenMP Loop Sharing Work
#include <stdio.h>
#include <omp.h>

int main() {
    const int N = 10;
    int i, sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < N; ++i) {
        sum += i;
    }

    printf("Sum of numbers from 0 to %d is: %d\n", N - 1, sum);

    return 0;
}
