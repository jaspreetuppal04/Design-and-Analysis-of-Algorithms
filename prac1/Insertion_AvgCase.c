#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void testSize(int n) {
   
    int *avg = (int *)malloc(n * sizeof(int));

    int i;
    clock_t start, end;
    double t_avg;

    
    // Average case: random numbers
    for (i = 0; i < n; i++) {
        avg[i] = rand();
    }


    // Measure average case
    start = clock();
    insertionSort(avg, n);
    end = clock();
    t_avg = (double)(end - start) / CLOCKS_PER_SEC;


    printf("n = %6d | Avg: %8.4f\n", n, t_avg);

    free(avg);
}

int main() {
    srand(time(NULL));

    printf("Insertion Sort Time Analysis\n");
    printf("-----------------------------------------------\n");

    testSize(10000);
    testSize(50000);
    testSize(100000);
    testSize(120000);
    testSize(200000);

    return 0;
}
