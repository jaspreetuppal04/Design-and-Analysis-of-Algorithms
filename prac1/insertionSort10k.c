#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

int main() {
    int arr[SIZE];
    int i, j, temp;

    // Generate 10,000 random positive numbers
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    // Insertion Sort (increasing order)
    for (i = 1; i < SIZE; i++) {
        temp = arr[i];
        j = i - 1;

        // Move elements greater than temp to one position ahead
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }

    // Print all 10,000 sorted numbers in increasing
    printf("Sorted 10,000 numbers in increasing order:\n\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d, ", arr[i]);
    }

    // // Print all 10,000 sorted numbers in decreasing
    // printf("Sorted 10,000 numbers in decreasing order:\n\n");
    // for (i = SIZE-1 ; i >= 0; i--) {
    //     printf("%d, ", arr[i]);
    // }

    return 0;
}
