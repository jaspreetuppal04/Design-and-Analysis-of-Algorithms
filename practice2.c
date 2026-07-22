#include<stdio.h>

struct item{
    int weight;
    int value;
};

void swap(struct item *a, struct item *b){
    struct item temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct item arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; i<n-1; i++){
            float r1 = (float) arr[i].value / arr[i].weight;
            float r2 = (float) arr[j].value / arr[j].weight;

            if(r1,r2){
                swap( &arr[i], &arr[j]);
            }
        }
    }
}

void fractionalKnapsack(struct item arr[], int n, int capacity){
    sort(arr, n);
    float totalValue = 0.0;

    for(int i=0; i<n; i++){
        if( capacity >= arr[i].weight){
            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        }else{
            totalValue += arr[i].value * ((float)capacity / arr[i].weight);
            break;
        }
    }
    return totalValue;
}

int main(){
    int n, capacity;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
}