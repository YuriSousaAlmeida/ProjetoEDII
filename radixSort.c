#include "radixSort.h"

// Fun��o auxiliar para encontrar o maior elemento do array
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

    // Conta a ocorr�ncia de cada d�gito
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calcula as posi��es corretas
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constr�i o array de sa�da
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        (*troca)++; // Conta cada movimenta��o
    }

    // Copia de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n, long long int* comp, long long int* troca) {
    *troca = 0;  // Inicializa o contador de trocas
    *comp = 0;   // Radix Sort n�o faz compara��es diretas
    
    // Encontra o n�mero m�ximo para saber o n�mero de d�gitos
    int m = getMax(arr, n);

    // Aplica o counting sort para cada d�gito
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp, troca);
    }
}
