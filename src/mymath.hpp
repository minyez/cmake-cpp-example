#ifndef SUM_H

//! compute sum up to n
int sum(int n);
//! compute the dot product of two vectors manually
double dot(int n, double *v1, double *v2);
//! compute the dot product of two vectors with level 1 BLAS routine
double dot_blas(int n, double *v1, double *v2);
//! compute the dot product of vector and matrix manually
void dgemv(int nr, int nc, double *mat, double *vi, double *vo);
//! compute the dot product of vector and matrix with level 2 BLAS routine
void dgemv_blas(int nr, int nc, double *mat, double *vi, double *vo);

#endif // SUM_H
