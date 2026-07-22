#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50000

int main() {
    int arr[SIZE];
    int i, j, temp;

    // Pick 50,000 random positive numbers
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand();   // non-negative integers
    }

    // Bubble Sort (increasing order)
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print all 50,000 sorted nos in increasing order
    // printf("Sorted 50,000 numbers in increasing order....\n\n");
    // for (i = 0; i < SIZE; i++) {
    //     printf("%d, ", arr[i]);
    // }

    //Print 50000 nos in decreasing order
    printf("Sorted 50,000 numbers in decreasing order...\n\n");
    for (i = SIZE - 1; i >= 0; i--) {
    printf("%d, ", arr[i]);
}
    return 0;
}
