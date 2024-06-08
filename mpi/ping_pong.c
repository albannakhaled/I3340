/*
Write a program in which the process 0 sends a message containing
1000 random reals to process 1.
Insert timing calls to measure the time taken for 1000 messages.
Write another program in such a way that the process 1 sends back
the message to the process 0, and measure the communication
duration with the MPI_Wtime() function.
Investigate how the time taken varies with the size of the message.
*/
#include <stdio.h>
#include<mpi.h>

void main(int argc, char *argv[])
{
    int rank, size, i;
    double start, end;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    double a[1000];
    if (rank == 0)
    {
        for (i = 0; i < 1000; i++)
        {
            a[i] = (double)rand();
        }
        start = MPI_Wtime();
        MPI_Send(a, 1000, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        end = MPI_Wtime();
        printf("Time taken for 1000 messages is %f\n", end - start);
    }
    else if (rank == 1)
    {
        MPI_Recv(a, 10000000, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    MPI_Finalize();
}