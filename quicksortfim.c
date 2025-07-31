#include "quicksortFim.h"

// Função de particionamento (interna)
static int particiona(int arr[], int inicio, int fim, long long int* comp, long long int* troca) {
    int pivo = arr[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        (*comp)++;
        if (arr[j] <= pivo) {
            i++;
            // Troca elementos
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            (*troca)++;
        }
    }

    // Coloca o pivô na posição correta
    int tmp = arr[i + 1];
    arr[i + 1] = arr[fim];
    arr[fim] = tmp;
    (*troca)++;

    return i + 1;
}

// Função recursiva principal (interna)
static void quickSortRecursivo(int arr[], int inicio, int fim, long long int* comp, long long int* troca) {
    if (inicio < fim) {
        int pi = particiona(arr, inicio, fim, comp, troca);
        quickSortRecursivo(arr, inicio, pi - 1, comp, troca);
        quickSortRecursivo(arr, pi + 1, fim, comp, troca);
    }
}

// Função wrapper para manter interface consistente
void quicksortFim(int arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;
    quickSortRecursivo(arr, 0, n - 1, comp, troca);
}
