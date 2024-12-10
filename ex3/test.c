#include <stdio.h>
#include <stdlib.h>

void multMat1(int n, float *A, float *B, float *C) {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                printf("C[%d] += A[%d] * B[%d]\n", i + j * n, i + k * n, k + j * n);
}

void multMat2(int n, float *A, float *B, float *C) {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (k = 0; k < n; k++)
            for (j = 0; j < n; j++)
                printf("C[%d] += A[%d] * B[%d]\n", i + j * n, i + k * n, k + j * n);
}

void multMat3(int n, float *A, float *B, float *C) {
    int i, j, k;
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
            for (k = 0; k < n; k++)
                printf("C[%d] += A[%d] * B[%d]\n", i + j * n, i + k * n, k + j * n);
}

void multMat4(int n, float *A, float *B, float *C) {
    int i, j, k;
    for (j = 0; j < n; j++)
        for (k = 0; k < n; k++)
            for (i = 0; i < n; i++)
                printf("C[%d] += A[%d] * B[%d]\n", i + j * n, i + k * n, k + j * n);
}

void multMat5(int n, float *A, float *B, float *C) {
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                printf("C[%d] += A[%d] * B[%d]\n", i + j * n, i + k * n, k + j * n);
}

void multMat6(int n, float *A, float *B, float *C) {
    int i, j, k;
    for (k = 0; k < n; k++)
        for (j = 0; j < n; j++)
            for (i = 0; i < n; i++)
                printf("C[%d] += A[%d] * B[%d]\n", i + j * n, i + k * n, k + j * n);
}

int main() {
    int n = 4; // Tamanho da matriz, reduzido para teste
    float *A = (float *)malloc(n * n * sizeof(float));
    float *B = (float *)malloc(n * n * sizeof(float));
    float *C = (float *)malloc(n * n * sizeof(float));

    void (*orderings[])(int, float *, float *, float *) =
        {&multMat1, &multMat2, &multMat3, &multMat4, &multMat5, &multMat6};
    char *names[] = {"ijk", "ikj", "jik", "jki", "kij", "kji"};

    for (int i = 0; i < 6; i++) {
        printf("Acessos de memória na ordem %s:\n", names[i]);
        (*orderings[i])(n, A, B, C);
        printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}

