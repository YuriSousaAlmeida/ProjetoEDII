void insercaoDireta(int arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;

    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0) {
            (*comp)++;
            if (arr[j] > chave) {
                arr[j + 1] = arr[j];
                (*troca)++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = chave;
    }
}

