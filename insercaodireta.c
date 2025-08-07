#include "template.h"

void insercaoDireta(int *v, int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;

        // Desloca os maiores elementos para a direita
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        // Insere a chave na posição correta
        v[j + 1] = chave;
    }
}
