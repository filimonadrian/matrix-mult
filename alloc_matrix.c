#include <stdlib.h>
#include <stdio.h>

void allocate_matrix(int N, double ***AB, double ***ABBt,
                        double ***AtA, double ***C) {

    *AB = calloc (N, sizeof (double));
    *ABBt = calloc (N, sizeof (double));
    *AtA = calloc (N, sizeof (double));
    *C = calloc (N, sizeof (double));

    for (int i = 0; i < N; i++) {
        *(*AB + i)= calloc (N, sizeof (double));
        *(*ABBt + i)= calloc (N, sizeof (double));
        *(*AtA + i) = calloc (N, sizeof (double));
        *(*C + i) = calloc (N, sizeof (double));
    }
}

int main(void) {

    // int N = 10;
    // double **AB, **ABBt, **AtA, **C = NULL;
    // allocate_matrix(N, &AB, &ABBt, &AtA, &C);


    // // C = malloc (N * sizeof (double *));
    // // for (int i = 0; i < N; i++) {
    // //     C[i] = malloc (N * sizeof (double));
    // // }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         C[i][j] = i;
    //     }
    // }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         printf("%lf ", C[i][j]);
    //     }
    //     printf("\n");
    // }

    int A[] = {1, 2, 3, 0, 4, 5, 0, 0, 6};
    int N = 3;
    int AtA[9];
    int i = 0, j = 0;

    for (int i = 0; i < N * N; i++)
        AtA[i] = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                AtA[i * N + j] += A[k * N + i] * 
            }
        }
    }


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            /* AtA[i * N + j] += ((A[i * N + j] * 1000) * (A[i * N + j] * 1000)) / 1000;
             */
            printf("%d ", A[i * N + j]);
            AtA[i * N + j] += A[i * N + j] * A[i * N + j];

        }
        printf("\n");
    }

    for (int i = 0; i < N * N; i++) {
        printf("%d ", AtA[i]);
    }
    return 0;
}