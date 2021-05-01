/*
 * Tema 2 ASC
 * 2021 Spring
 */
#include "utils.h"
#include <string.h>
/*
 * Add your unoptimized implementation here
 */


void allocate_matrix(int N, double **AB, double **ABBt,
                        double **AtA, double **C) {

    *AB = calloc (N * N, sizeof (double));
    *ABBt = calloc (N * N, sizeof (double));
    *AtA = calloc (N * N, sizeof (double));
    *C = calloc (N * N, sizeof (double));
}

double *my_solver(int N, double *A, double* B) {

    double *AB, *ABBt, *AtA, *C;
    int i, j, k;

    allocate_matrix(N, &AB, &ABBt, &AtA, &C);

    /* A * B*/
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = i; k < N; k++) {
                AB[i * N + j] += A[i * N + k] * B[k * N + j];
            }
        }
    }

    /* AB * B transpose */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                ABBt[i * N + j] += AB[i * N + k] * B[j * N + k];
            }
        }
    }

    /* A transpose * A */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                AtA[i * N + j] += A[k * N + i] * A[k * N + j];
            }
        }
    }

    /* C = */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i * N + j] += ABBt[i * N + j] + AtA[i * N + j];
        }
    }

    free(AB);
    free(ABBt);
    free(AtA);

    return C;
}
