/*!
 @file mymath.hpp
 @brief The file contains some mathmatical functions and routines
 @note The symbols suffixed by `_blas` will call the related Fortran BLAS rouinte.
 */
#ifndef SUM_H

//! compute sum from 0 up to n
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
