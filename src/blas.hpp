// for example see https://web.physics.utah.edu/~detar/phys6720/handouts/lapack.html
#ifdef __cplusplus
extern "C" {
#endif
    extern double ddot_(const int *n, const double *X, const int *incx, const double *Y, const int *incy);
	extern void dgemv_(const char *transa, const int *m, const int *n, const double *alpha, const double *A,  
		const int *lda, const double *X, const int *incx, const double *beta, double *y, const int *incy);
#ifdef __cplusplus
}
#endif
