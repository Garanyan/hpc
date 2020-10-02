#include "iostream"
#include "matrix.hpp"
#include <chrono>

using namespace std::chrono;

void MatrixMultTest(size_t s)
{
    Matrix a(s);
    Matrix b(s);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Matrix c(a * b);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "Matrix * Matrix: " << time_span.count() << " seconds." << std::endl;
}

void MatrixVectorMultTest(size_t s)
{
    Matrix a(s);
    Vector b(s);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Vector c(a * b);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << s << " Matrix * Vector: " << time_span.count() << " seconds." << std::endl;
}

int main()
{
    MatrixVectorMultTest(512);
    MatrixMultTest(512);

    MatrixVectorMultTest(1024);
    MatrixMultTest(1024);

    MatrixVectorMultTest(1024 * 2);
    MatrixMultTest(1024 * 2);

    MatrixVectorMultTest(1024 * 4);
    MatrixMultTest(1024 * 4);

    return 0;
}
