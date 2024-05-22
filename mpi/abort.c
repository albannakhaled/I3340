#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    if (rank == 0) {
        // Simulate a critical error occurring only in process 0
        printf("Error occurred in process 0. Aborting MPI job.\n");
        MPI_Abort(MPI_COMM_WORLD, 1); // Abort with error code 1
    }
    
    MPI_Finalize();
    
    return 0;
}
