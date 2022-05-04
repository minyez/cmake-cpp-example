#include "mymath.hpp"
#include "blas.hpp"

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

double dot_blas(int n, double *v1, double *v2)
{
    int incx = 1, incy = 1;
    return ddot_(&n, v1, &incx, v2, &incy);
}

void dgemv(int nr, int nc, double *mat, double *vi, double *vo)
{
    // cleanup vo
    for (int i = 0; i != nr; i++)
        vo[i] = 0.;
    for (int i = 0; i != nr; i++)
        for (int j = 0; j != nc; j++)
            vo[i] += mat[i * nc + j] * vi[j];
}

void dgemv_blas(int nr, int nc, double *mat, double *vi, double *vo)
{
    double alpha = 1.0, beta = 0.0;
    int inc = 1;
    // NOTE: dgemv is Fortran routine with column-major array, need transpose beforehand
    dgemv_("T", &nr, &nc, &alpha, mat, &nr, vi, &inc, &beta, vo, &inc);
}
