#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <mpi.h>

void main(int argc , char* argv[]){
	int rank , size ;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD , &rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("HELLO WORLD FROM PROCESS %d OF %d\n",rank,size);

	MPI_Finalize();
}
