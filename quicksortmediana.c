#include "quicksortmediana.h"

// Função auxiliar para trocar valores
static void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

// Função que retorna índice do pivô usando mediana de três
static int medianaDeTres(int *vet, int inicio, int fim) {
    int meio = inicio + (fim - inicio) / 2;

    comparacoes++;
    if (vet[inicio] > vet[meio]) troca(&vet[inicio], &vet[meio]);

    comparacoes++;
    if (vet[inicio] > vet[fim]) troca(&vet[inicio], &vet[fim]);

    comparacoes++;
    if (vet[meio] > vet[fim]) troca(&vet[meio], &vet[fim]);

    // Depois dos ajustes, o meio é a mediana
    return meio;
}

static int particionaMediana(int *vet, int inicio, int fim) {
    int pivoIndex = medianaDeTres(vet, inicio, fim);
    troca(&vet[pivoIndex], &vet[fim]);  // coloca pivô no fim

    int pivo = vet[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        comparacoes++;
        if (vet[j] < pivo) {
            i++;
            troca(&vet[i], &vet[j]);
        }
    }

    troca(&vet[i + 1], &vet[fim]);
    return i + 1;
}

void quicksortMediana(int *vet, int inicio, int fim) {
    comparacoes++; // para verificação da recursão
    if (inicio < fim) {
        int p = particionaMediana(vet, inicio, fim);
        quicksortMediana(vet, inicio, p - 1);
        quicksortMediana(vet, p + 1, fim);
    }
}
