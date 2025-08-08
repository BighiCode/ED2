#include "menu.h"
#include "file.h"

#include "bolha.h"//1 e 2
#include "insercaodireta.h"//3
#include "insercaoBinaria.h"//4
#include "shellSort.h"//5
#include "selecaodireta.h"//6
#include "heapsort.h"//7
#include "quicksortcentro.h"//8
#include "mergesort.h"//9
#include "radixsort.h"//10
#include "bucketsort.h"//11
#include "quicksortfim.h"//12
#include "quicksortmediana.h"//13

int main(void) {
    
    //tempo
    clock_t start, end;

    // Abre arquivos
    FILE *fd = fopen("gerador/d", "r");
    FILE *fc = fopen("gerador/c", "r");
    FILE *fr = fopen("gerador/r", "r");

    if (!fd || !fc || !fr) {
        perror("Erro ao abrir arquivos");
        return 1;
    }

    // Conta elementos
    int tamd = contarElementos(fd);
    int tamc = contarElementos(fc);
    int tamr = contarElementos(fr);

    // Verifica se todos têm dados
    if (tamd <= 0 || tamc <= 0 || tamr <= 0) {
        fprintf(stderr, "Erro: um dos arquivos está vazio ou inválido.\n");
        fclose(fd);
        fclose(fc);
        fclose(fr);
        return 1;
    }

    // Aloca vetores dinamicamente
    int *listaD = malloc(tamd * sizeof(int));
    int *listaC = malloc(tamc * sizeof(int));
    int *listaR = malloc(tamr * sizeof(int));
 
    //confere se houve erro na alocacao
    if (!listaD || !listaC || !listaR) {
        perror("Erro ao alocar memória");
        fclose(fd);
        fclose(fc);
        fclose(fr);
        free(listaD);
        free(listaC);
        free(listaR);
        return 1;
    }

    // Lê dados para os vetores
    for (int i = 0; i < tamd; i++) fscanf(fd, "%d", &listaD[i]);
    for (int i = 0; i < tamc; i++) fscanf(fc, "%d", &listaC[i]);
    for (int i = 0; i < tamr; i++) fscanf(fr, "%d", &listaR[i]);
    printf("arquivos lidos\n");
    

    // Cria vetores auxiliares para testar funções
    int *vetorAux1 = listaR;
    int tam = tamr;
    int inicio = 0;
    int fim = tam - 1;
    int *vetorAux2 = malloc(tam * sizeof(int));

    printf("vetores necessarios criados\n");

    copiaVetor(vetorAux1, vetorAux2, tam);
    printf("vetor auxiliar 2 copiado\n");

    start = clock();
    //testar função aqui ⬇️⬇️⬇️
    quicksortMediana(vetorAux2, inicio, fim);
    //testar função aqui ⬆️⬆️⬆️
    end = clock();

    //inrformação para o trabalho
    printf("tempo: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("tam: %d\ntrocas: %" PRIu64 "\ncomparacoes: %" PRIu64 "\n", tam,trocas, comparacoes);
    
    FILE *saida = fopen("saida.txt", "w");
    for (int i = 0; i < tam; i++)
    {
        fprintf(saida, "%d\n", vetorAux2[i]);
    }

    return 0;
}