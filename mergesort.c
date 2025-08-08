#include "mergesort.h"
#include <stdlib.h>

void merge(int *vet, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = vet[inicio + i];
        trocas++;  // cópia para subvetor
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vet[meio + 1 + j];
        trocas++;  // cópia para subvetor
    }

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        comparacoes++;
        if (L[i] <= R[j]) {
            vet[k++] = L[i++];
            trocas++;
        } else {
            vet[k++] = R[j++];
            trocas++;
        }
    }

    while (i < n1) {
        vet[k++] = L[i++];
        trocas++;
    }

    while (j < n2) {
        vet[k++] = R[j++];
        trocas++;
    }

    free(L);
    free(R);
}

void mergeSort(int *vet, int inicio, int fim) {
    comparacoes++; // Verificação da recursão
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}
