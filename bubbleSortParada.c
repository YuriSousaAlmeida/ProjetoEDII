void bubbleSortMelhorado(int arr[], int n, long long int* comp, long long int* trocas) {
    int trocou;
    for (int i = 0; i < n - 1; i++) {
        trocou = 0;
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++; // comparação
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                (*trocas)++; // troca
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

