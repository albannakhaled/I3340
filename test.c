#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
    #pragma omp parallel
    {
        #pragma omp for nowait
        for (int i = 0; i < 2; i++)
        {
            printf("hello \n");
        }
        #pragma omp barrier
        #pragma omp for
        for (int i = 0; i < 2; i++)
        {
            printf("world \n");
        }
        
    }


}