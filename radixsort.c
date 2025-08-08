#include "radixsort.h"

int getMax(int *vet, int n) {
    int max = vet[0];
    for (int i = 1; i < n; i++) {
        comparacoes++;
        if (vet[i] > max) {
            max = vet[i];
            trocas++;
        }
    }
    return max;
}

void countingSort(int *vet, int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(vet[i] / exp) % 10]++;
        trocas++; // preenchimento da contagem
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        trocas++; // soma acumulativa
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(vet[i] / exp) % 10] - 1] = vet[i];
        count[(vet[i] / exp) % 10]--;
        trocas++; // construção do output
    }

    for (int i = 0; i < n; i++) {
        vet[i] = output[i];
        trocas++; // cópia de volta para o vetor original
    }
}

void radixSort(int *vet, int n) {
    int max = getMax(vet, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        comparacoes++; // verificação do loop externo
        countingSort(vet, n, exp);
    }
}
