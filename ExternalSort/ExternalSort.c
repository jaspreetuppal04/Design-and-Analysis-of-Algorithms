#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHUNK_SIZE 50000
#define MAX_FILES 100


// ---------------- MERGE FUNCTION ----------------

void merge(int arr[], int left, int mid, int right) {

    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}


// ---------------- MERGE SORT ----------------

void mergeSort(int arr[], int left, int right) {

    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


// ---------------- CREATE SORTED FILES ----------------

int createTempFiles(const char *filename) {

    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int *arr = (int *)malloc(CHUNK_SIZE * sizeof(int));

    int count = 0;
    int fileCount = 0;
    int num;

    while (fscanf(file, "%d", &num) == 1) {

        arr[count++] = num;

        if (count == CHUNK_SIZE) {

            mergeSort(arr, 0, count - 1);

            char tempName[20];
            sprintf(tempName, "temp_%d.txt", fileCount);

            FILE *temp = fopen(tempName, "w");

            for (int i = 0; i < count; i++)
                fprintf(temp, "%d ", arr[i]);

            fclose(temp);

            fileCount++;
            count = 0;
        }
    }

    // Remaining data
    if (count > 0) {

        mergeSort(arr, 0, count - 1);

        char tempName[20];
        sprintf(tempName, "temp_%d.txt", fileCount);

        FILE *temp = fopen(tempName, "w");

        for (int i = 0; i < count; i++)
            fprintf(temp, "%d ", arr[i]);

        fclose(temp);

        fileCount++;
    }

    free(arr);
    fclose(file);

    return fileCount;
}


// ---------------- MERGE TEMP FILES ----------------

void mergeTempFiles(int fileCount, const char *outputFile) {

    FILE *files[MAX_FILES];
    int values[MAX_FILES];
    int active[MAX_FILES];

    for (int i = 0; i < fileCount; i++) {

        char tempName[20];
        sprintf(tempName, "temp_%d.txt", i);

        files[i] = fopen(tempName, "r");

        if (fscanf(files[i], "%d", &values[i]) == 1)
            active[i] = 1;
        else
            active[i] = 0;
    }

    FILE *out = fopen(outputFile, "w");

    while (1) {

        int minIndex = -1;

        for (int i = 0; i < fileCount; i++) {

            if (active[i]) {

                if (minIndex == -1 || values[i] < values[minIndex])
                    minIndex = i;
            }
        }

        if (minIndex == -1)
            break;

        fprintf(out, "%d ", values[minIndex]);

        if (fscanf(files[minIndex], "%d", &values[minIndex]) != 1)
            active[minIndex] = 0;
    }

    for (int i = 0; i < fileCount; i++)
        fclose(files[i]);

    fclose(out);
}


// ---------------- MAIN ----------------

int main() {

    const char *inputFile =
    "/Users/jaspreetuppal/IDAA sem4/RandomGenerator/Random_Generators/random_nos_250k.txt";

    const char *outputFile = "sorted_output.txt";


    clock_t start = clock();


    int totalFiles = createTempFiles(inputFile);

    mergeTempFiles(totalFiles, outputFile);


    clock_t end = clock();


    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("External Sorting Completed\n");
    printf("Time taken: %f seconds\n", time_taken);


    return 0;
}
