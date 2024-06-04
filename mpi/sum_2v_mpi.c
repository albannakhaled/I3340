#include<stdio.h>
#include<mpi.h>


/*
Write a program with two processes the first one read 2 values from
the keyboard and send the two values to process 2.
Process 2 should wait until he receive the 2 values.
Process 2 compute the sum and send the results back to process 1.
Process 1 display the results.
*/
void main(int argc , char **argv){
    MPI_Init(&argc,&argv);
    int n1 ,n2,rank,size,x1,x2,sum,rec,z;
    printf("enter 2 number:\n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
   

    if(rank == 0){
        MPI_Send(&n1,1,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Send(&n2,1,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Recv(&rec,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
        printf("sum = %d",rec);
    }else if(rank == 1){
        MPI_Recv(&x1,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
        MPI_Recv(&x2,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
        sum=x1+x2;
        MPI_Send(&sum,1,MPI_INT,0,0,MPI_COMM_WORLD);
    }
    MPI_Finalize();
}