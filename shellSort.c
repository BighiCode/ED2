#include "shellSort.h"

void shellSort(int *vet, int tam) {
    for (int gap = tam / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tam; i++) {
            int temp = vet[i];
            int j = i;

            // Contabiliza comparações dentro do laço
            while (j >= gap && (++comparacoes && vet[j - gap] > temp)) {
                vet[j] = vet[j - gap];
                j -= gap;
                trocas++;
            }

            vet[j] = temp;
            if (j != i) trocas++; // Só conta como troca se `temp` foi inserido em nova posição
        }
    }
}