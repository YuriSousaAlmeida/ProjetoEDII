int buscaBinaria(int arr[], int item, int low, int high, long long int* comp) {
    if (high <= low) {
        (*comp)++;
        return (item > arr[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;
    (*comp)++;
    if (item == arr[mid])
        return mid + 1;
    (*comp)++;
    if (item > arr[mid])
        return buscaBinaria(arr, item, mid + 1, high, comp);
    return buscaBinaria(arr, item, low, mid - 1, comp);
}

void insercaoBinaria(int arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;

    for (int i = 1; i < n; i++) {
        int val = arr[i];
        int j = i - 1;
        int pos = buscaBinaria(arr, val, 0, j, comp);
        while (j >= pos) {
            arr[j + 1] = arr[j];
            (*troca)++;
            j--;
        }
        arr[pos] = val;
    }
}

