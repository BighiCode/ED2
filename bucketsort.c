#include "bucketsort.h"


typedef struct Node {
    int value;
    struct Node *next;
} Node;

void insertSorted(Node **head, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    trocas++; // alocação e inserção contam como troca

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
        trocas++; // inserção no início da lista
    } else {
        Node *current = *head;
        while (current->next != NULL && (++comparacoes && current->next->value < value)) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        trocas++; // inserção no meio ou fim da lista
    }
}

void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void bucketSort(int *vet, int n) {
    if (n <= 0) return;

    // 1. Encontra o máximo e o mínimo
    int min = vet[0], max = vet[0];
    for (int i = 1; i < n; i++) {
        comparacoes++;
        if (vet[i] < min) min = vet[i];
        comparacoes++;
        if (vet[i] > max) max = vet[i];
    }

    int bucketCount = n; // um bucket por elemento (pode ser ajustado)

    // 2. Cria vetor de buckets (listas encadeadas)
    Node **buckets = malloc(bucketCount * sizeof(Node*));
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = NULL;
    }

    // 3. Distribui elementos nos buckets
    for (int i = 0; i < n; i++) {
        int idx = (int)(((double)(vet[i] - min) / (max - min + 1)) * bucketCount);
        if (idx >= bucketCount) idx = bucketCount - 1;
        insertSorted(&buckets[idx], vet[i]);
    }

    // 4. Concatena buckets de volta no vetor
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        Node *current = buckets[i];
        while (current != NULL) {
            vet[index++] = current->value;
            trocas++; // cópia para o vetor
            current = current->next;
        }
        freeList(buckets[i]);
    }

    free(buckets);
}
