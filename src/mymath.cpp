#include "mymath.hpp"

int sum(int n)
{
    int s = 0;
    for (int i = 0; i != n; i++)
        s += i;
    return s;
}

double dot(int n, double *v1, double *v2)
{
    // method 1: manually dot
    double prod = 0.0;
    for (int i = 0; i != n; i++)
        prod += v1[i] * v2[i];
    return prod;
}
