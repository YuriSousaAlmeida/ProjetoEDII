void shellSort(int arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap; j -= gap) {
                (*comp)++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    (*troca)++;
                } else {
                    break;
                }
            }
            arr[j] = temp;
            (*troca)++;
        }
    }
}

