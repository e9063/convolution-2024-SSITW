#include <stdio.h>
#include <stdlib.h>
// #include <omp.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----

    int NR = NA - NF + 1;
    int *R = calloc(NR, sizeof(int));
    // double start = omp_get_wtime();
    for (int i = 0; i <= NA - NF; i++) {
        for (int j = 0; j < NF; j++) {
            R[i] += A[i + j] * F[NF - j - 1];
        }
    }
    // double end = omp_get_wtime();

    for (int i = 0; i < NR; i++) {
        printf("%d\n", R[i]);
    }

    // printf("sequential time : %f\n seconds", end - start);

    // ---- free memory ----
    free(R);
    free(F);
    free(A);
    // ---- end free ----
    return 0;
}

