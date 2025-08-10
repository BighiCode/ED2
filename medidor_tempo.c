#include <time.h>

// Medir tempo de função com 2 argumentos: (int *v, int n)
double medirTempo2Args(void (*algoritmo)(int *, int), int *v, int n) {
    clock_t ti = clock();
    algoritmo(v, n);
    clock_t tf = clock();
    return (double)(tf - ti) / CLOCKS_PER_SEC;
}

// Medir tempo de função com 3 argumentos: (int *v, int inicio, int fim)
double medirTempo3Args(void (*algoritmo)(int *, int, int), int *v, int inicio, int fim) {
    clock_t ti = clock();
    algoritmo(v, inicio, fim);
    clock_t tf = clock();
    return (double)(tf - ti) / CLOCKS_PER_SEC;
}

// Medir tempo de função com parâmetro extra "max": (int *v, int n, int max)
double medirTempo3ArgsMax(void (*algoritmo)(int *, int, int), int *v, int n, int max) {
    clock_t ti = clock();
    algoritmo(v, n, max);
    clock_t tf = clock();
    return (double)(tf - ti) / CLOCKS_PER_SEC;
}
