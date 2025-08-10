#include "cabecario.h"
#include "file.h"
#include "medidor_tempo.h"
#include "menu.h"

#include "bolha.h"
#include "insercaodireta.h"
#include "insercaoBinaria.h"
#include "shellSort.h"
#include "selecaodireta.h"
#include "heapsort.h"
#include "quicksortcentro.h"
#include "mergesort.h"
#include "radixsort.h"
#include "bucketsort.h"
#include "quicksortfim.h"
#include "quicksortmediana.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

#define ARQUIVO_SAIDA "saida_metricas.txt"

#define N_FUNCS_2ARGS 9
#define N_FUNCS_3ARGS 4

extern uint64_t trocas;
extern uint64_t comparacoes;

// Funções que recebem (int *v, int n)
void (*funcoes2args[N_FUNCS_2ARGS])(int *, int) = {
    ordenamentoBolha,
    ordenamentoBolhaCriterioParada,
    insercaoDireta,
    insercaoBinaria,
    bucketSort,
    shellSort,
    radixSort,
    selecaoDireta,
    heapsort
};

char *nomes2args[N_FUNCS_2ARGS] = {
    "ordenamentoBolha",
    "ordenamentoBolhaCriterioParada",
    "insercaoDireta",
    "insercaoBinaria",
    "bucketSort",
    "shellSort",
    "radixSort",
    "selecaoDireta",
    "heapsort"
};

// Funções que recebem (int *v, int inicio, int fim)
void (*funcoes3args[N_FUNCS_3ARGS])(int *, int, int) = {
    quicksortCentro,
    mergeSort,
    quicksortMediana
};

char *nomes3args[N_FUNCS_3ARGS] = {
    "quicksortCentro",
    "mergeSort",
    "quicksortMediana"
};

static void testarFuncoes2args(int *vetorOriginal, int tamanho, const char *tipo, FILE *saida) {
    for (int i = 0; i < N_FUNCS_2ARGS; i++) {
        printf("\nfuncao 2 args\n");
        printf("Testando %s (%s)...\n", nomes2args[i], tipo);
        int *copia = malloc(tamanho * sizeof(int));
        if (!copia) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        copiaVetor(vetorOriginal, copia, tamanho);
        printf("\nvetor copiado\n");
        trocas = 0;
        comparacoes = 0;

        clock_t start = clock();
        funcoes2args[i](copia, tamanho);
        clock_t end = clock();

        double tempo = (double)(end - start) / CLOCKS_PER_SEC;

        fprintf(saida,
            "Algoritmo: %s | Tipo: %s | Tamanho: %d | Trocas: %" PRIu64
            " | Comparacoes: %" PRIu64 " | Tempo: %.6f\n",
            nomes2args[i], tipo, tamanho, trocas, comparacoes, tempo);
        fflush(saida);

        free(copia);
    }
}

static void testarFuncoes3args(int *vetorOriginal, int tamanho, const char *tipo, FILE *saida) {
    int inicio = 0;
    int fim = tamanho - 1;

    for (int i = 0; i < N_FUNCS_3ARGS; i++) {
        printf("\nfuncao 3 args\n");
        printf("Testando %s (%s)...\n", nomes3args[i], tipo);
        int *copia = malloc(tamanho * sizeof(int));
        if (!copia) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        copiaVetor(vetorOriginal, copia, tamanho);
        printf("\nvetor copiado\n");
        trocas = 0;
        comparacoes = 0;

        clock_t start = clock();
        funcoes3args[i](copia, inicio, fim);
        clock_t end = clock();

        double tempo = (double)(end - start) / CLOCKS_PER_SEC;

        fprintf(saida,
            "Algoritmo: %s | Tipo: %s | Tamanho: %d | Trocas: %" PRIu64
            " | Comparacoes: %" PRIu64 " | Tempo: %.6f\n",
            nomes3args[i], tipo, tamanho, trocas, comparacoes, tempo);
        fflush(saida);

        free(copia);
    }
}

int main(void) {
    FILE *fd = fopen("gerador/d", "r");
    FILE *fc = fopen("gerador/c", "r");
    FILE *fr = fopen("gerador/r", "r");

    if (!fd || !fc || !fr) {
        perror("Erro ao abrir arquivos");
        if (fd) fclose(fd);
        if (fc) fclose(fc);
        if (fr) fclose(fr);
        return EXIT_FAILURE;
    }

    int tamd = contarElementos(fd);
    int tamc = contarElementos(fc);
    int tamr = contarElementos(fr);

    rewind(fd);
    rewind(fc);
    rewind(fr);

    if (tamd <= 0 || tamc <= 0 || tamr <= 0) {
        fprintf(stderr, "Erro: um dos arquivos está vazio ou inválido.\n");
        fclose(fd); fclose(fc); fclose(fr);
        return EXIT_FAILURE;
    }

    int *listaD = malloc(tamd * sizeof(int));
    int *listaC = malloc(tamc * sizeof(int));
    int *listaR = malloc(tamr * sizeof(int));

    if (!listaD || !listaC || !listaR) {
        perror("Erro ao alocar memória");
        fclose(fd); fclose(fc); fclose(fr);
        free(listaD); free(listaC); free(listaR);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < tamd; i++) fscanf(fd, "%d", &listaD[i]);
    for (int i = 0; i < tamc; i++) fscanf(fc, "%d", &listaC[i]);
    for (int i = 0; i < tamr; i++) fscanf(fr, "%d", &listaR[i]);

    fclose(fd); fclose(fc); fclose(fr);

    FILE *saida = fopen(ARQUIVO_SAIDA, "w");
    if (!saida) {
        perror("Erro ao criar arquivo de saída");
        free(listaD);
        free(listaC);
        free(listaR);
        return EXIT_FAILURE;
    }

    testarFuncoes2args(listaD, tamd, "decrescente", saida);
    testarFuncoes3args(listaD, tamd, "decrescente", saida);

    testarFuncoes2args(listaC, tamc, "crescente", saida);
    testarFuncoes3args(listaC, tamc, "crescente", saida);

    testarFuncoes2args(listaR, tamr, "randomico", saida);
    testarFuncoes3args(listaR, tamr, "randomico", saida);

    fclose(saida);

    free(listaD);
    free(listaC);
    free(listaR);

    printf("Testes concluídos. Resultados gravados em %s\n", ARQUIVO_SAIDA);
    return EXIT_SUCCESS;
}
