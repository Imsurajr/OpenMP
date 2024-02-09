//Suraj Raghuvanshi : Matrix multiply (specify run of a GPU card, large scale data … Complexity of the problem need to be specified) 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 3
#define M 3
#define P 3

// Function to multiply matrices A and B, storing the result in C
void matrixMultiply(int A[N][M], int B[M][P], int C[N][P]) {
    int i, j, k;

    #pragma omp parallel for shared(A, B, C) private(i, j, k) collapse(2)
    for (i = 0; i < N; ++i) {
        for (j = 0; j < P; ++j) {
            C[i][j] = 0;
            for (k = 0; k < M; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to initialize matrix with random values
void initializeMatrix(int matrix[N][M]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            matrix[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
}

// Function to print matrix
void printMatrix(int matrix[N][P]) {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < P; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][M], B[M][P], C[N][P];

    // Initialize matrices A and B with random values
    initializeMatrix(A);
    initializeMatrix(B);

    // Multiply matrices A and B
    matrixMultiply(A, B, C);

    // Print the matrices
    printf("Matrix A:\n");
    printMatrix(A);

    printf("\nMatrix B:\n");
    printMatrix(B);

    printf("\nResultant matrix C:\n");
    printMatrix(C);

    return 0;
}
