#include <stdio.h>
#include <omp.h>

void task_function(int task_id) {
    printf("Task %d executed by thread %d\n", task_id, omp_get_thread_num());
}

int main() {
    // Set the number of threads
    omp_set_num_threads(4);

    // Create and execute tasks in parallel
    #pragma omp parallel
    {
        #pragma omp single
        {
            // Create tasks
            #pragma omp task
            task_function(1);

            #pragma omp task
            task_function(2);

            #pragma omp task
            task_function(3);

            #pragma omp task
            task_function(4);
        }
    }

    return 0;
}
