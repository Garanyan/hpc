CC = g++
.cc.o:
	$(CC) -ggdb -c $<
default:
	make omp_hello
hello:  omp_hello.c
	gcc omp_hello.c -o hello -fopenmp
outmes: omp_outmes.c
	g++ omp_outmes.c -o outmes -fopenmp
sumarray: omp_sumarray.c
	g++ omp_sumarray.c -o sumarray -fopenmp
privateshared: omp_privateshared.c
	$(CC) omp_privateshared.c -o privateshared -fopenmp
parsec:  omp_parsec.c
	$(CC) omp_parsec.c -o parsec -fopenmp
bugreduction:  omp_bugreduction.c
	$(CC) omp_bugreduction.c -o bugreduction -fopenmp
bugparfoc:  omp_bugparfoc.c
	$(CC) omp_bugparfoc.c -o bugparfoc -fopenmp
monte-carlo: monte-carlo.c
	$(CC) monte-carlo.c -o monte-carlo -fopenmp
all: sumarray hello outmes privateshared parsec bugreduction bugparfoc monte-carlo
clean:
	rm -f  *.o sumarray hello outmes privateshared parsec bugreduction bugparfoc monte-carlo
