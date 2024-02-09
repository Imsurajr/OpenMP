//Suraj Raghuvanshi : OpenMP Vector Addition
#include <iostream>
#include <omp.h>

void vectorAddition(int *a, int *b, int *result, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        result[i] = a[i] + b[i];
    }
}

int main() {
    const int size = 5;
    int a[size] = {1, 2, 3, 4, 5};
    int b[size] = {6, 7, 8, 9, 10};
    int result[size];

    vectorAddition(a, b, result, size);

    std::cout << "Resultant vector after addition: ";
    for (int i = 0; i < size; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
