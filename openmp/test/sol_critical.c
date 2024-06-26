#include <omp.h>
#include <stdio.h>

int main()
{
    int p;

    omp_lock_t lock1;
    omp_init_lock(&lock1);
    omp_set_lock(&lock1);

    omp_lock_t lock2;
    omp_init_lock(&lock2);
    omp_set_lock(&lock2);

    #pragma omp parallel sections default(shared) private(p)
    {
        #pragma omp section
        {
            p = omp_get_thread_num();

            printf("Th%d: Hello\n",p);

            omp_unset_lock(&lock1);
        }

        #pragma omp section
        {
            p = omp_get_thread_num();
            omp_set_lock(&lock1);

            printf("Th%d: World\n",p);

            omp_unset_lock(&lock1);
            omp_unset_lock(&lock2);
        }

        #pragma omp section
        {
            p = omp_get_thread_num();
            omp_set_lock(&lock2);

            printf("Th%d: Bye\n",p);

            omp_unset_lock(&lock2);
        }
    }

    omp_destroy_lock(&lock1);
    omp_destroy_lock(&lock2);

    return 0;
}