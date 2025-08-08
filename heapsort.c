#include "heapsort.h"

void heapify(int *vet, int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n) {
        comparacoes++;
        if (vet[esquerda] > vet[maior]) {
            maior = esquerda;
        }
    }

    if (direita < n) {
        comparacoes++;
        if (vet[direita] > vet[maior]) {
            maior = direita;
        }
    }

    if (maior != i) {
        int temp = vet[i];
        vet[i] = vet[maior];
        vet[maior] = temp;
        trocas++;

        heapify(vet, n, maior);
    }
}

void heapsort(int *vet, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(vet, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;
        trocas++;

        heapify(vet, i, 0);
    }
}
