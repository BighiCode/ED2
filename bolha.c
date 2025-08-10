#include "bolha.h"

void ordenamentoBolha(int *vet, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                trocas++;
            }
            comparacoes++;
        }
    }
}

void ordenamentoBolhaCriterioParada(int *vet, int n) {
    bool trocou;

    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                trocou = true;
                trocas++;
                //printf("Trocas: %d\n", trocas);
            }
            comparacoes++;
        }

        // Se nenhuma troca aconteceu, o vetor já está ordenado
        if (!trocou) break;
    }
}

