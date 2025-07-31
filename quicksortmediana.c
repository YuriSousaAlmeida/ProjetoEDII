#include "quicksortMediana.h"

// Função auxiliar para calcular a mediana de três (interna)
static int medianaDeTres(int arr[], int inicio, int fim, long long int* comp, long long int* troca) {
    int meio = (inicio + fim) / 2;

    // Ordena os três elementos
    (*comp)++;
    if (arr[inicio] > arr[meio]) {
        int tmp = arr[inicio];
        arr[inicio] = arr[meio];
        arr[meio] = tmp;
        (*troca)++;
    }
    (*comp)++;
    if (arr[inicio] > arr[fim]) {
        int tmp = arr[inicio];
        arr[inicio] = arr[fim];
        arr[fim] = tmp;
        (*troca)++;
    }
    (*comp)++;
    if (arr[meio] > arr[fim]) {
        int tmp = arr[meio];
        arr[meio] = arr[fim];
        arr[fim] = tmp;
        (*troca)++;
    }

    // Move a mediana para a posição fim-1
    int tmp = arr[meio];
    arr[meio] = arr[fim - 1];
    arr[fim - 1] = tmp;
    (*troca)++;
    
    return arr[fim - 1];
}

// Insertion Sort para partições pequenas (interna)
static void insertionSort(int arr[], int inicio, int fim, long long int* comp, long long int* troca) {
    for (int i = inicio + 1; i <= fim; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= inicio && (++(*comp), arr[j] > chave)) {
            arr[j + 1] = arr[j];
            j--;
            (*troca)++;
        }
        arr[j + 1] = chave;
    }
}

// Função de particionamento (interna)
static int particiona(int arr[], int inicio, int fim, long long int* comp, long long int* troca) {
    int pivo = medianaDeTres(arr, inicio, fim, comp, troca);
    int i = inicio;
    int j = fim - 1;

    while (1) {
        while ((++(*comp), arr[++i] < pivo));
        while ((++(*comp), arr[--j] > pivo));
        if (i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            (*troca)++;
        } else {
            break;
        }
    }

    // Coloca o pivô na posição correta
    int tmp = arr[i];
    arr[i] = arr[fim - 1];
    arr[fim - 1] = tmp;
    (*troca)++;
    
    return i;
}

// Função recursiva principal (interna)
static void quickSortRecursivo(int arr[], int inicio, int fim, long long int* comp, long long int* troca) {
    // Usa insertion sort para pequenos subarrays
    if (fim - inicio + 1 <= 10) {
        insertionSort(arr, inicio, fim, comp, troca);
        return;
    }

    int p = particiona(arr, inicio, fim, comp, troca);
    quickSortRecursivo(arr, inicio, p - 1, comp, troca);
    quickSortRecursivo(arr, p + 1, fim, comp, troca);
}

// Função wrapper para manter interface consistente
void quicksortMediana(int arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;
    quickSortRecursivo(arr, 0, n - 1, comp, troca);
}
