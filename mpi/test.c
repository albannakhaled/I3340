#include<stdio.h>
#include<mpi.h>

void main(int argc , char **argv){
    int size,rank;
    // MPI_Request request;
    // MPI_Status status;
    int value = 0;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if(rank == 0){
        value = 1000 + rank;
    }
    MPI_Bcast(&value,1,MPI_INT,0,MPI_COMM_WORLD);
    printf("value = %d in process %d",value,rank);

    MPI_Finalize();
} 