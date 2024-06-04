#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int data_send = 42;
    int data_send1 = 4;
    int data_recv;
    int data_recv2;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);// means get the rank of the process
    MPI_Comm_size(MPI_COMM_WORLD, &size);// means get the size of the process

    if (size < 2) {
        printf("This example requires at least 2 processes.\n");
        MPI_Finalize();
        return 1;
    }

    if (rank == 0) {
        // Process 0 sends data to process 1
        MPI_Send(&data_send, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&data_send1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent data: %d\n", data_send);
        printf("Process 0 sent data: %d\n", data_send1);
    } else if (rank == 1) {
        // Process 1 receives data from process 0
        MPI_Recv(&data_recv, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&data_recv2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received data: %d\n", data_recv);
        printf("Process 1 received data: %d\n", data_recv2);
    }

    MPI_Finalize();

    return 0;
}
