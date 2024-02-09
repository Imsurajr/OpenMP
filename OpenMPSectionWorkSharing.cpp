//Suraj Raghuvanshi : OpenMP Section Work Sharing
#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("Thread %d executing section 1\n", omp_get_thread_num());
            }

            #pragma omp section
            {
                printf("Thread %d executing section 2\n", omp_get_thread_num());
            }
        }
    }

    return 0;
}
