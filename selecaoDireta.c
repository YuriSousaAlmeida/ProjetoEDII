void selecaoDireta(int arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            (*comp)++;
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
            (*troca)++;
        }
    }
}

