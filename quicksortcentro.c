#include "quicksortcentro.h"

int particionaCentro(int *vet, int inicio, int fim) {
    int meio = inicio + (fim - inicio) / 2;
    int pivo = vet[meio];

    // Move o pivô para o fim
    int temp = vet[meio];
    vet[meio] = vet[fim];
    vet[fim] = temp;
    trocas++;

    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        comparacoes++;
        if (vet[j] < pivo) {
            i++;
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            trocas++;
        }
    }

    temp = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = temp;
    trocas++;

    return i + 1;
}

void quicksortCentro(int *vet, int inicio, int fim) {
    comparacoes++;  // Para a verificação da recursão
    if (inicio < fim) {
        int p = particionaCentro(vet, inicio, fim);
        quicksortCentro(vet, inicio, p - 1);
        quicksortCentro(vet, p + 1, fim);
    }
}
