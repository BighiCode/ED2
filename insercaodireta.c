#include "template.h"

void insercaoDireta(int *v, int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;

        // Conta ao menos uma comparação por iteração do while
        while (j >= 0 && (++comparacoes && v[j] > chave)) {
            v[j + 1] = v[j]; // deslocamento (considerado troca)
            trocas++;
            j--;
        }

        // Inserção da chave no lugar certo
        v[j + 1] = chave;
        trocas++; // conta a inserção da chave como uma troca
    }
}
