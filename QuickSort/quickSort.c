#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ===============================
// Swap function
// ===============================
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ===============================
// Partition Function (Common)
// ===============================
int partition(int arr[], int low, int high, int pivotType) {

    // Move selected pivot to end first
    if (pivotType == 1) {              // Pivot at Start
        swap(&arr[low], &arr[high]);
    }
    else if (pivotType == 2) {         // Pivot at End
        // already at end → do nothing
    }
    else if (pivotType == 3) {         // Pivot at Middle
        int mid = low + (high - low) / 2;
        swap(&arr[mid], &arr[high]);
    }
    else if (pivotType == 4) {         // Pivot at Random
        int randIndex = low + rand() % (high - low + 1);
        swap(&arr[randIndex], &arr[high]);
    }

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// ===============================
// Quick Sort
// ===============================
void quickSort(int arr[], int low, int high, int pivotType) {

    if (low < high) {

        int pi = partition(arr, low, high, pivotType);

        quickSort(arr, low, pi - 1, pivotType);
        quickSort(arr, pi + 1, high, pivotType);
    }
}

// ===============================
// Read from file
// ===============================
int readFromFile(const char *filename, int **arr) {

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int count = 0, temp;

    while (fscanf(file, "%d", &temp) == 1)
        count++;

    rewind(file);

    *arr = (int *)malloc(count * sizeof(int));
    if (!*arr) {
        perror("Memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++)
        fscanf(file, "%d", &(*arr)[i]);

    fclose(file);
    return count;
}

// ===============================
// MAIN
// ===============================
int main() {

    srand(time(NULL));   // for random pivot

    int *arr = NULL;
    int size;

    const char *filename =
    "/Users/jaspreetuppal/IDAA sem4/RandomGenerator/Random_Generators/random_asc_50k.txt";

    size = readFromFile(filename, &arr);

    printf("Sorting %d elements...\n", size);

    // ---------------------------
    // Change this value to test:
    // 1 → Pivot Start
    // 2 → Pivot End
    // 3 → Pivot Middle
    // 4 → Pivot Random
    // ---------------------------
    int pivotType = 1;

    clock_t start = clock();

    quickSort(arr, 0, size - 1, pivotType);

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);

    free(arr);
    return 0;
}
