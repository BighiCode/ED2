#include "quicksortfim.h"

int particionaFim(int *vet, int inicio, int fim) {
    int pivo = vet[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        comparacoes++;
        if (vet[j] < pivo) {
            i++;
            int temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            trocas++;
        }
    }

    int temp = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = temp;
    trocas++;

    return i + 1;
}

void quicksortFim(int *vet, int inicio, int fim) {
    comparacoes++; // condição da recursão
    if (inicio < fim) {
        int p = particionaFim(vet, inicio, fim);
        quicksortFim(vet, inicio, p - 1);
        quicksortFim(vet, p + 1, fim);
    }
}
