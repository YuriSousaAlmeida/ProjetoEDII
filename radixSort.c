#include "radixSort.h"

// Função auxiliar para encontrar o maior elemento do array
static int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

static void countingSort(int arr[], int n, int exp, long long int* troca) {
    int output[n];
    int count[10] = {0};

    // Conta a ocorrência de cada dígito
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calcula as posições corretas
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        (*troca)++; // Conta cada movimentação
    }

    // Copia de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n, long long int* comp, long long int* troca) {
    *troca = 0;  // Inicializa o contador de trocas
    *comp = 0;   // Radix Sort não faz comparações diretas
    
    // Encontra o número máximo para saber o número de dígitos
    int m = getMax(arr, n);

    // Aplica o counting sort para cada dígito
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp, troca);
    }
}
