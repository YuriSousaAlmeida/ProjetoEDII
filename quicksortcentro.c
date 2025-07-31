void quicksortCentroRec(int arr[], int inicio, int fim, long long int* comp, long long int* troca) {
    if (inicio >= fim) return;

    int centro = (inicio + fim) / 2;
    int pivo = arr[centro];
    int i = inicio, j = fim;

    while (i <= j) {
        while ((*comp)++, arr[i] < pivo) i++;
        while ((*comp)++, arr[j] > pivo) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = tmp;
            (*troca)++;
        }
    }

    if (inicio < j) quicksortCentroRec(arr, inicio, j, comp, troca);
    if (i < fim) quicksortCentroRec(arr, i, fim, comp, troca);
}

void quicksortCentro(int arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;
    quicksortCentroRec(arr, 0, n - 1, comp, troca);
}

