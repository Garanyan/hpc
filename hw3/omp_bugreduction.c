#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

float naive(float * a, float * b, size_t N)
{
	float sum = 0;
	for (size_t i = 0; i < N; i++) {
        	sum += a[i] * b[i];
    	}
	return sum;
}

float dotprod(float * a, float * b, size_t N)
{
   
    float sum = 0;

#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; ++i)
    {
	sum += (a[i] * b[i]);
#pragma omp critical
	{
		printf("i=%d, a[i]=%f, b[i]=%f, sum=%f\n", i, a[i], b[i], sum);
	}
    }

    return sum;
}

float dot_product(float *x, float *y, int n) {

  //! Compute the dot product of the provided vectors

  float result = 0.0; int i;

#pragma omp parallel for default(none) \
private(i) shared(x,y,n) ordered reduction(+:result)
  for (i = 0; i < n; i++) {
    result = result + x[i]*y[i];
  }

  return result;
}

int main (int argc, char *argv[])
{
    const size_t N = 2000;
    float a[N], b[N];
    int i;
    float local_sum = 0;

    for (i = 0; i < N; ++i)
    {
        a[i] = b[i] = i;
    }

    float naive_sum = naive(a, b, N);
    float sum = dotprod(a, b, N);

    printf("Diff: %f\n", naive_sum - sum);
    printf("diff 2: %f\n", naive_sum - dot_product(a,b,N));
    printf("Sum = %f\n",sum);

    return 0;
}
