// clang -Xclang -fopenmp -L/opt/homebrew/opt/libomp/lib -I/opt/homebrew/opt/libomp/include -lomp 02_Error_Checking.c -o error
#include<stdio.h>
#include<stdlib.h>
#ifdef _OPENMP
    #include<omp.h>
#endif

void Hello(void);

int main(int argc, char* argv[]) {
    
    int thread_count = strtol(argv[1], NULL, 10); // Get number of threads from Command Line

#pragma omp parallel num_threads(thread_count)
    Hello();

    return 0;
}

void Hello(void) {
    #ifdef _OPENMP
        int my_rank = omp_get_thread_num();
        int thread_count = omp_get_num_threads();
    #else
        int my_rank = 0;
        int thread_count = 1;
    #endif
        
    printf("Hello from thread %d of %d\n", my_rank, thread_count);

    return;
}