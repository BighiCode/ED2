#include "cabecario.h"

#ifndef MEDIDOR_TEMPO_H
#define MEDIDOR_TEMPO_H

// Medidor de tempo para funções com assinatura: void funcao(int *vet, int tam);
double medirTempo2Args(void (*algoritmo)(int *, int), int *v, int n);

// Medidor de tempo para funções com assinatura: void funcao(int *vet, int inicio, int fim);
double medirTempo3Args(void (*algoritmo)(int *, int, int), int *v, int inicio, int fim);

// Medidor de tempo para funções com assinatura: void funcao(int *vet, int tam, int max);
double medirTempo3ArgsMax(void (*algoritmo)(int *, int, int), int *v, int n, int max);

// Medidor de tempo específico para bucketSort: void bucketSort(int *vet, int tam);
double medirTempoBucketSort(void (*algoritmo)(int *, int), int *v, int n);

#endif // MEDIDOR_TEMPO_H
