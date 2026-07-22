//fractional knapsack

#include <stdio.h>


struct Item {
    int weight;
    int value;
};


void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}


void sort(struct Item arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            float r1 = (float)arr[i].value / arr[i].weight;
            float r2 = (float)arr[j].value / arr[j].weight;

            if(r1 < r2) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}


float fractionalKnapsack(struct Item arr[], int n, int capacity) {

    sort(arr, n);   

    float totalValue = 0.0;

    for(int i = 0; i < n; i++) {

        if(capacity >= arr[i].weight) {
            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        }
        else {
            totalValue += arr[i].value * ((float)capacity / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    for(int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &arr[i].weight, &arr[i].value);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxProfit = fractionalKnapsack(arr, n, capacity);

    printf("Maximum value in knapsack = %.2f\n", maxProfit);

    return 0;
}