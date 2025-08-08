#include "insercaoBinaria.h"

int buscaBinaria(int *v, int inicio, int fim, int chave) {
    int meio;
    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;
        comparacoes++;  // conta a comparação abaixo
        if (v[meio] == chave)
            return meio + 1;  // insere depois dos iguais
        else if (v[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return inicio;  // posição correta para inserir
}

void insercaoBinaria(int *v, int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        trocas++;  // pega a chave

        // busca a posição correta para inserir chave em v[0..i-1]
        int pos = buscaBinaria(v, 0, i - 1, chave);

        // desloca elementos para direita até abrir espaço na pos
        for (int j = i - 1; j >= pos; j--) {
            v[j + 1] = v[j];
            trocas++;  // conta cada deslocamento
        }

        // insere chave na posição correta
        v[pos] = chave;
        trocas++;  // conta a inserção da chave
    }
}