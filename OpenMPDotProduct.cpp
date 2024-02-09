//Suraj Raghuvanshi : OpenMP Dot Product
#include <iostream>
#include <omp.h>

int dotProduct(int *a, int *b, int size) {
    int result = 0;
    #pragma omp parallel for reduction(+:result)
    for (int i = 0; i < size; ++i) {
        result += a[i] * b[i];
    }
    return result;
}

int main() {
    const int size = 5;
    int a[size] = {1, 2, 3, 4, 5};
    int b[size] = {6, 7, 8, 9, 10};

    int result = dotProduct(a, b, size);

    std::cout << "Dot product of the vectors: " << result << std::endl;

    return 0;
}
