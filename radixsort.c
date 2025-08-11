#include "radixsort.h"
#include <stdlib.h>

// Função auxiliar para achar o maior elemento
int getMax(int *vet, int n) {
    int max = vet[0];
    for (int i = 1; i < n; i++) {
        comparacoes++;
        if (vet[i] > max) {
            max = vet[i];
            trocas++; // conta como troca de "maior"
        }
    }
    return max;
}

// Counting sort para um dígito específico
void countingSort(int *vet, int n, int exp, int *output) {
    int count[10] = {0};

    // Conta a ocorrência de cada dígito
    for (int i = 0; i < n; i++) {
        int dig = (vet[i] / exp) % 10;
        count[dig]++;
        comparacoes++; // iterar sobre todos os elementos
    }

    // Soma acumulativa
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída (estável)
    for (int i = n - 1; i >= 0; i--) {
        int dig = (vet[i] / exp) % 10;
        output[count[dig] - 1] = vet[i];
        count[dig]--;
        trocas++; // movimento real de dado
    }

    // Copia de volta para o vetor original
    for (int i = 0; i < n; i++) {
        vet[i] = output[i];
        trocas++;
    }
}

// Radix sort principal
void radixSort(int *vet, int n) {
    int max = getMax(vet, n);

    // Aloca o array de saída na heap (uma vez só)
    int *output = malloc(n * sizeof(int));
    if (!output) {
        fprintf(stderr, "Erro: falha ao alocar memoria para output.\n");
        exit(EXIT_FAILURE);
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(vet, n, exp, output);
    }

    free(output);
}
