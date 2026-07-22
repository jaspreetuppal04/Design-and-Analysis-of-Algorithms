#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to read input from a file
int readFromFile(const char *filename, int **arr) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    int temp;
    // Count numbers
    while (fscanf(file, "%d", &temp) == 1) {
        count++;
    }
    rewind(file); // Reset file pointer

    // Allocate memory
    *arr = (int *)malloc(count * sizeof(int));
    if (!*arr) {
        perror("Error allocating memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Read numbers into array
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d", &(*arr)[i]);
    }

    fclose(file);
    return count;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int *arr = NULL;
    int size;
    const char *filename = 
    "/Users/jaspreetuppal/IDAA sem4/RandomGenerator/Random_Generators/random_desc_300k.txt";

    // Read input
    size = readFromFile(filename, &arr);

    printf("Original array from %s:\n", filename);

    // Measure time
    clock_t start = clock();
    mergeSort(arr, 0, size - 1);
    clock_t end = clock();


    // Calculate time in seconds
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken for sorting: %f seconds\n", time_taken);

    free(arr);

    return 0;
}