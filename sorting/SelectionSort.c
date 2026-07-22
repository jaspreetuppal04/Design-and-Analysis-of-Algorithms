#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void testSize(int n) {
    int *best = (int *)malloc(n * sizeof(int));
    int *avg = (int *)malloc(n * sizeof(int));
    int *worst = (int *)malloc(n * sizeof(int));
    int i;

    // Best: already sorted
    for (i = 0; i < n; i++) best[i] = i;

    // Worst: reverse sorted
    for (i = 0; i < n; i++) worst[i] = n - i;

    // Average: random
    for (i = 0; i < n; i++) avg[i] = rand();

    clock_t start, end;
    double t_best, t_avg, t_worst;

    start = clock();
    selectionSort(best, n);
    end = clock();
    t_best = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(avg, n);
    end = clock();
    t_avg = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(worst, n);
    end = clock();
    t_worst = (double)(end - start) / CLOCKS_PER_SEC;

    printf("n = %6d | Best: %8.4f | Avg: %8.4f | Worst: %8.4f sec\n",
           n, t_best, t_avg, t_worst);

    free(best);
    free(avg);
    free(worst);
}

int main() {
    srand(time(NULL));

    printf("Selection Sort Time Analysis\n");
    printf("-----------------------------------------------\n");

    testSize(10000);
    testSize(50000);
    testSize(100000);
    testSize(120000);
    testSize(200000);

    return 0;
}
