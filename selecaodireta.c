#include "selecaodireta.h"

void selecaoDireta(int *vet, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tam; j++) {
            comparacoes++;
            if (vet[j] < vet[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = vet[i];
            vet[i] = vet[minIndex];
            vet[minIndex] = temp;
            trocas++;
        }
    }
}
