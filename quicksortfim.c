#include "quicksortfim.h"

/* Assume que trocas e comparacoes são variáveis globais definidas em cabecario.h.
   Ex.: extern uint64_t trocas; extern uint64_t comparacoes;
*/

static void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    trocas++;
}

/* Insertion sort para subvetores pequenos */
static void insertion_small(int *vet, int inicio, int fim) {
    for (int i = inicio + 1; i <= fim; ++i) {
        int chave = vet[i];
        int j = i - 1;
        while (j >= inicio && (comparacoes++, vet[j] > chave)) {
            vet[j + 1] = vet[j];
            trocas++;
            j--;
        }
        vet[j + 1] = chave;
        trocas++;
    }
}

/* Retorna índice da mediana entre indices a,b,c.
   Incrementa comparacoes para cada comparação de valores. */
static int mediana_de_tres_indice(int *vet, int a, int b, int c) {
    /* Comparações mínimas para decidir a mediana */
    if ((comparacoes++, vet[a] > vet[b])) {
        if ((comparacoes++, vet[b] > vet[c])) return b;
        if ((comparacoes++, vet[a] > vet[c])) return c;
        return a;
    } else {
        if ((comparacoes++, vet[a] > vet[c])) return a;
        if ((comparacoes++, vet[b] > vet[c])) return c;
        return b;
    }
}

/* Partition usual, mas primeiro coloca mediana no fim como pivô */
int particionaFim(int *vet, int inicio, int fim) {
    int meio = inicio + (fim - inicio) / 2;
    int medIdx = mediana_de_tres_indice(vet, inicio, meio, fim);

    if (medIdx != fim) troca(&vet[medIdx], &vet[fim]);  /* mediana -> fim */

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

/* Quicksort com eliminação de recursão na partição maior e cutoff para insertion */
void quicksortFim(int *vet, int inicio, int fim) {
    while (inicio < fim) {
        /* Cutoff para pequenos subvetores */
        if (fim - inicio < 16) {
            insertion_small(vet, inicio, fim);
            return;
        }

        int p = particionaFim(vet, inicio, fim);

        /* Recurse na partição menor e continue iterativamente na maior */
        if (p - inicio < fim - p) {
            quicksortFim(vet, inicio, p - 1);  /* menor: esquerda */
            inicio = p + 1;                    /* continuar com direita (loop) */
        } else {
            quicksortFim(vet, p + 1, fim);     /* menor: direita */
            fim = p - 1;                       /* continuar com esquerda (loop) */
        }
    }
}
