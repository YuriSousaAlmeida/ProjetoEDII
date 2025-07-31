void merge(int arr[], int l, int m, int r, long long int* comp, long long int* troca) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        (*comp)++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        (*troca)++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
        (*troca)++;
    }

    while (j < n2) {
        arr[k++] = R[j++];
        (*troca)++;
    }
}

void mergeSort(int arr[], int l, int r, long long int* comp, long long int* troca) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comp, troca);
        mergeSort(arr, m + 1, r, comp, troca);
        merge(arr, l, m, r, comp, troca);
    }
}

void mergeSortWrapper(int arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;
    mergeSort(arr, 0, n - 1, comp, troca);
}

