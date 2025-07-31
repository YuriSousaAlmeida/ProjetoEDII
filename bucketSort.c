#include <stdlib.h>

void insertionSortBucket(float arr[], int n, long long int* comp, long long int* troca) {
    for (int i = 1; i < n; i++) {
        float val = arr[i];
        int j = i - 1;
        while (j >= 0) {
            (*comp)++;
            if (arr[j] > val) {
                arr[j + 1] = arr[j];
                (*troca)++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = val;
    }
}

void bucketSort(float arr[], int n, long long int* comp, long long int* troca) {
    *comp = 0;
    *troca = 0;

    int i, j, k;
    int numBuckets = 10;
    float **buckets = malloc(numBuckets * sizeof(float*));
    int *bucketSizes = calloc(numBuckets, sizeof(int));

    for (i = 0; i < numBuckets; i++)
        buckets[i] = malloc(n * sizeof(float));

    for (i = 0; i < n; i++) {
        int bi = arr[i] * numBuckets;
        if (bi >= numBuckets) bi = numBuckets - 1; // segurança
        buckets[bi][bucketSizes[bi]++] = arr[i];
    }

    for (i = 0; i < numBuckets; i++)
        insertionSortBucket(buckets[i], bucketSizes[i], comp, troca);

    k = 0;
    for (i = 0; i < numBuckets; i++)
        for (j = 0; j < bucketSizes[i]; j++)
            arr[k++] = buckets[i][j];

    for (i = 0; i < numBuckets; i++) free(buckets[i]);
    free(buckets);
    free(bucketSizes);
}

