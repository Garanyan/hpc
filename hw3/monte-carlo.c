#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seedThreads(const size_t nThreads, unsigned int* seeds) {
    int my_thread_id;
    unsigned int seed;
    #pragma omp parallel private (seed, my_thread_id)
    {
        my_thread_id = omp_get_thread_num();

        unsigned int seed = (unsigned) time(NULL);

        seeds[my_thread_id] = (seed & 0xFFFFFFF0) | (my_thread_id + 1);
    }
}

int main (int argc, char *argv[])
{
	size_t N = 200000, count = 0;
	const size_t nThreads = omp_get_num_threads();
	unsigned int seeds[nThreads];
	seedThreads(nThreads, seeds);
#pragma omp parallel
	{
		unsigned int seed = seeds[omp_get_thread_num()];
		srandom(seed);
#pragma omp for reduction(+:count) 
		for(size_t i=0; i < N; i++)
		{
			double x = (double) random() / RAND_MAX;
			unsigned int y_seed = seed + 1;
			double y = (double) random() / RAND_MAX;
			if((x * x + y * y) <= 1.0)
			{
				++count;
			}
		}
	}

	double pi = 4 * (double)count / N;
	printf("Pi = %f\n", pi);

	return 0;
}
