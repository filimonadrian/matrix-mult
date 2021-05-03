/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include <string.h>
#include <cblas.h>
#include "utils.h"
/* resources:
    http://www.netlib.org/blas/cblas.h
    http://www.netlib.org/lapack/explore-html/de/da0/cblas_8h_source.html
    https://www.gnu.org/software/gsl/doc/html/blas.html#c.gsl_blas_dtrmm

*/

/* 
 * Add your BLAS implementation here
 */

void allocate_matrix(int N, double **AB, double **ABBt,
                        double **AtA, double **C) {

    *AB = calloc (N * N, sizeof (double));
    *ABBt = calloc (N * N, sizeof (double));
    *AtA = calloc (N * N, sizeof (double));
    *C = calloc (N * N, sizeof (double));
}


double* my_solver(int N, double *A, double *B) {
    double *AB, *ABBt, *AtA, *C;
    register int i, j;

    allocate_matrix(N, &AB, &ABBt, &AtA, &C);

    memcpy(C, B, N * N * sizeof(*C));
    cblas_dtrmm(CblasRowMajor,
                CblasLeft,
                CblasUpper,
                CblasNoTrans,
                CblasNonUnit,
                N, N,
                1.0, A, N,
                C, N);

    cblas_dtrmm(CblasRowMajor,
                CblasRight,
                CblasUpper,
                CblasTrans,
                CblasNonUnit,
                N, N,
                1.0, B, N,
                C, N);

    memcpy(AtA, A, N * N * sizeof(*A));
    cblas_dtrmm(CblasRowMajor,
                CblasLeft,
                CblasUpper,
                CblasTrans,
                CblasNonUnit,
                N, N,
                1.0, A, N,
                AtA, N);


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i * N + j] += AtA[i * N + j]; 
        }
    }

    free(AB);
    free(ABBt);
    free(AtA);
    return C;
}
