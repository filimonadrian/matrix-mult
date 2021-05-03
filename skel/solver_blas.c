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

void allocate_matrix(int N, double **AB, double **ABBt,
                        double **AtA, double **C) {

    *AB = calloc (N * N, sizeof (**AB));
    *ABBt = calloc (N * N, sizeof (double));
    *AtA = calloc (N * N, sizeof (**AtA));
    *C = calloc (N * N, sizeof (**C));
}


double *my_solver(int N, double *A, double *B) {
    double *AB, *ABBt, *AtA, *C;
    register int i, j;

    allocate_matrix(N, &AB, &ABBt, &AtA, &C);

    /* AB = A * B */
    memcpy(AB, B, N * N * sizeof(*AB));
    cblas_dtrmm(CblasRowMajor,
                CblasLeft,
                CblasUpper,
                CblasNoTrans,
                CblasNonUnit,
                N, N, 1.0,
                A, N,
                AB, N);

    /* ABBt = A * B * B' = AB * B' */
    memcpy(ABBt, AB, N * N * sizeof(*AB));
    cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasTrans,
                N, N, N, 1.0,
                AB, N,
                B, N,
                0.0, ABBt, N);
    // cblas_dtrmm(CblasRowMajor,
    //             CblasRight,
    //             CblasUpper,
    //             CblasTrans,
    //             CblasNonUnit,
    //             N, N, 1,
    //             B, N,
    //             ABBt, N);

    /* AtA = A' * A */
    memcpy(AtA, A, N * N * sizeof(*A));
    cblas_dtrmm(CblasRowMajor,
                CblasLeft,
                CblasUpper,
                CblasTrans,
                CblasNonUnit,
                N, N, 1.0,
                A, N,
                AtA, N);


    /* C = AtA + ABBt */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i * N + j] = AtA[i * N + j] + ABBt[i * N + j];
        }
    }

    free(AB);
    free(ABBt);
    free(AtA);

    return C;
}
