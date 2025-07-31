void heapify(int arr[], int n, int i, long long int* comp, long long int* troca) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n) {
        (*comp)++;
        if (arr[esq] > arr[maior])
            maior = esq;
    }
    if (dir < n) {
        (*comp)++;
        if (arr[dir] > arr[maior])
            maior = dir;
    }

    if (maior != i) {
        int tmp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = tmp;
        (*troca)++;
        heapify(arr, n, maior, comp, troca);
    }
}

void heapSort(int arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, comp, troca);
    
    for (int i = n - 1; i > 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        (*troca)++;
        heapify(arr, i, 0, comp, troca);
    }
}

