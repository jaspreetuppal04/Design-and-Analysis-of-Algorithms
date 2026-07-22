#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 50000 // Number of random numbers to generate
#define FILENAME "random_asc_50k.txt"

// Comparator function for qsort to sort integers in ascending order
int compare_integers(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
    // A simpler way: return int_a - int_b;
}

int main() {
    int numbers[COUNT];
    int i;
    FILE *file_ptr;

    // Seed the random number generator with the current time to get different numbers each run
    srand(time(NULL));

    // 1. Generate random numbers and store them in an array
    for (i = 0; i < COUNT; i++) {
        // Generate random number in a specific range (e.g., 0 to 999)
        // Adjust the range by changing the modulo value (e.g., rand() % 100 for 0-99)
        numbers[i] = rand() % 500000;
    }

    // 2. Sort the array in ascending order using qsort()
    qsort(numbers, COUNT, sizeof(int), compare_integers);

    // 3. Open a file for writing
    file_ptr = fopen(FILENAME, "w");
    if (file_ptr == NULL) {
        printf("Error opening file %s\n", FILENAME);
        return 1;
    }

    // 4. Save the sorted numbers to the file
    for (i = 0; i < COUNT; i++) {
        fprintf(file_ptr, "%d\n", numbers[i]);
    }

    // 5. Close the file
    fclose(file_ptr);

    printf("Successfully generated %d random numbers, sorted them, and saved to %s\n", COUNT, FILENAME);

    return 0;
}
