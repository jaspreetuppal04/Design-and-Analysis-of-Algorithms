#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "random_nos_250k.txt"
#define NUMBERS_TO_GENERATE 250000
#define MAX_VALUE 500000

int main() {
    FILE *file_pointer;
    int i, random_num;


    srand(time(NULL));

    file_pointer = fopen(FILENAME, "w");

    if (file_pointer == NULL) {
        printf("Error: Could not open file %s for writing.\n", FILENAME);
        return 1;
    }

    printf("Generating %d random numbers and writing to %s...\n\n", NUMBERS_TO_GENERATE, FILENAME);


    for (i = 0; i < NUMBERS_TO_GENERATE; i++) {
        random_num = rand() % MAX_VALUE;

        printf("Number %d: %d\n", i + 1, random_num);

        fprintf(file_pointer, "%d\n", random_num);
    }

    fclose(file_pointer);

    printf("\nSuccessfully generated numbers and closed the file.\n");

    return 0;

}
