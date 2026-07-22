#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 300000 // Number of random numbers to generate
#define FILENAME "random_desc_300k.txt"

// Comparator function for qsort to sort in descending order
int compare_descending(const void *a, const void *b) {
    // Cast pointers to int* and dereference them
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    // For descending order, return a negative value if a > b, positive if a < b
    if (int_a > int_b) return -1;
    if (int_a < int_b) return 1;
    return 0;
}

int main() {
    int numbers[COUNT];
    FILE *fp;

    // 1. Seed the random number generator with current time
    srand(time(NULL));

    // 2. Generate random numbers and store in an array
    for (int i = 0; i < COUNT; i++) {
        // Generate random numbers between 0 and RAND_MAX
        numbers[i] = rand() % 200000;
    }

    // 3. Sort the array in descending order using qsort
    // qsort(base, num of elements, size of each element, comparator function)
    qsort(numbers, COUNT, sizeof(int), compare_descending);

    // 4. Open a file for writing
    fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", FILENAME);
        return 1;
    }

    // 5. Write the sorted numbers to the file
    for (int i = 0; i < COUNT; i++) {
        fprintf(fp, "%d\n", numbers[i]);
    }

    // 6. Close the file
    fclose(fp);

    printf("Generated %d random numbers, sorted in descending order, and saved to %s\n", COUNT, FILENAME);

    return 0;
}
