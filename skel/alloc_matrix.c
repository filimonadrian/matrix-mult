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

    int N = 10;
    double **AB, **ABBt, **AtA, **C = NULL;
    allocate_matrix(N, &AB, &ABBt, &AtA, &C);


    // C = malloc (N * sizeof (double *));
    // for (int i = 0; i < N; i++) {
    //     C[i] = malloc (N * sizeof (double));
    // }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = i;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lf ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}