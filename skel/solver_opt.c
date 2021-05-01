/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */

void allocate_matrix(int N, double **AB, double **ABBt,
                        double **AtA, double **C) {

    *AB = calloc (N * N, sizeof (double));
    *ABBt = calloc (N * N, sizeof (double));
    *AtA = calloc (N * N, sizeof (double));
    *C = calloc (N * N, sizeof (double));
}


double* my_solver(int N, double *A, double* B) {

    double *AB, *ABBt, *AtA, *C;
    register int i, j, k;

    allocate_matrix(N, &AB, &ABBt, &AtA, &C);

    /* A * B*/
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            register double sum = 0.0;
            for (k = i; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            AB[i * N + j] = sum;
        }
    }

    /* AB * B transpose */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            register double sum = 0.0;
            for (k = 0; k < N; k++) {
                sum += AB[i * N + k] * B[j * N + k];
            }
            ABBt[i * N + j] = sum;
        }
    }

    /* A transpose * A */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            double register sum = 0;
            for (k = i; k < N; k++) {
                sum += A[k * N + i] * A[k * N + j];
            }
            AtA[i * N + j] = sum;

        }
    }
    /* C = */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i * N + j] = ABBt[i * N + j] + AtA[i * N + j];
        }
    }

    free(AB);
    free(ABBt);
    free(AtA);

    return C;
}
