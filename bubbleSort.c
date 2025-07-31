void bubbleSort(int arr[], int n, long long int* comp, long long int* trocas) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++; // comparação entre arr[j] e arr[j+1]
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                (*trocas)++; // houve troca
            }
        }
    }
}

