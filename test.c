/*
Write a C program that count the number of occurrence of a number
v in a table. Parallelize that program with OpenMP.
• What do you observe when the program is executed several times?
To have a correct answer you should use the reduction clause,
modify the program and observe the changes after using reduction
clause.
Compare sequential execution time and parallel execution time.
*/

#include<stdio.h>
#include<omp.h>
void main()
{
    int a[1000], i, v, count = 0;
    for (i = 0; i < 1000; i++)
    {
        a[i] = i % 10;
    }
    v = 5;
    #pragma omp parallel for reduction(+:count)
    for (i = 0; i < 1000; i++)
    {
        if (a[i] == v)
        {
            count++;
        }
    }
    printf("The number of occurrences of %d is %d\n", v, count);
}