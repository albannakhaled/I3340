#include <stdio.h>
#include <omp.h>

int main()
{
    size_t nb_steps = 1000000;
    double pi, term;
    double sum = 0.;
    double step = 1. / (double)nb_steps;

    double t_start, t_end;

    t_start = omp_get_wtime();

    #pragma omp parallel for shared(sum) private(term) num_threads(4)
    for (size_t i = 0; i < nb_steps; i++)
    {
        #pragma omp critical
        {
            term = (i + 0.5) * step;
            sum += 4. / (1. + term * term);
        }
    }

    pi = step * sum;

    t_end = omp_get_wtime();

    printf("pi = %f\n", pi);
    printf("Time taken : %f seconds\n", t_end - t_start);

    return 0;
}

