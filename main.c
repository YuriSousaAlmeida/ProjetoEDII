#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Headers de todos os algoritmos
#include "bubbleSort.h"
#include "bubbleSortParada.h"
#include "insercaoDireta.h"
#include "insercaoBinaria.h"
#include "shellSort.h"
#include "selecaoDireta.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "radixSort.h"
#include "bucketSort.h"
#include "quicksortcentro.h"
#include "quicksortfim.h"
#include "quicksortmediana.h"

void gerarVetor(int arr[], int n, int tipo) {
    if (tipo == 1) {
        for (int i = 0; i < n; i++) arr[i] = rand() % 100 + 1;
    } else if (tipo == 2) {
        for (int i = 0; i < n; i++) arr[i] = i + 1;
    } else if (tipo == 3) {
        for (int i = 0; i < n; i++) arr[i] = n - i;
    } else {
        printf("Tipo inválido. Gerando vetor aleatório.\n");
        for (int i = 0; i < n; i++) arr[i] = rand() % 100 + 1;
    }
}

void imprimirVetor(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) destino[i] = origem[i];
}

// Struct para mapear nome + função com contadores
typedef struct {
    const char* nome;
    void (*sort)(int[], int, int*, int*);
    int contaComparacoes;
} AlgoritmoSort;

int main() {
    srand(time(NULL));
    int nVet, tipo;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &nVet);
	int* base = malloc(nVet * sizeof(int));
	int* copia = malloc(nVet * sizeof(int));


    printf("Escolha o tipo de vetor:\n1 - Aleatório\n2 - Crescente\n3 - Decrescente\nOpção: ");
    scanf("%d", &tipo);

    gerarVetor(base, nVet, tipo);
    printf("\nVetor original:\n");
    imprimirVetor(base, nVet);

    // Algoritmos que possuem contagem de comparações e trocas
    AlgoritmoSort algoritmos[] = {
        {"Bubble Sort", bubbleSort, 1},
        {"Bubble Sort com Parada", bubbleSortMelhorado, 1},
        {"Inserção Direta", insercaoDireta, 1},
        {"Inserção Binária", insercaoBinaria, 1},
        {"Shell Sort", shellSort, 1},
        {"Seleção Direta", selecaoDireta, 1},
        {"Heap Sort", heapSort, 1},
        {"Merge Sort", mergeSortWrapper, 1},
        {"Radix Sort", radixSort, 0},
        {"Bucket Sort", bucketSort, 0},
        {"Quicksort Centro", quicksortCentro, 1},
        {"Quicksort Fim", quicksortFim, 1},
        {"Quicksort Mediana", quicksortMediana, 1}
    };

    int total_algoritmos = sizeof(algoritmos) / sizeof(algoritmos[0]);

    for (int i = 0; i < total_algoritmos; i++) {
        copiarVetor(base, copia, nVet);
        long long int comp = 0, troca = 0;

        printf("\n%s:\n", algoritmos[i].nome);
        printf("Antes: ");
        //imprimirVetor(copia, nVet);

        clock_t start = clock();
        algoritmos[i].sort(copia, nVet, &comp, &troca);
        clock_t end = clock();

        printf("Depois: ");
        //imprimirVetor(copia, nVet);
        printf("Tempo: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

        if (algoritmos[i].contaComparacoes)
            printf("Comparações: %lld | Trocas: %lld\n", comp, troca);
        else
            printf("Movimentações: %lld (sem comparações diretas)\n", troca);
    }

    return 0;
}

