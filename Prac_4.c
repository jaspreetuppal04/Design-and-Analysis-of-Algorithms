//make change

#include<stdio.h>

int main(){

    int amount;
    int coins[] = {20,10,5,2,1};
    int n = 5;

    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("Minimum coins required:\n");

    for(int i=0; i<n; i++){
        if(amount >= coins[i]){
            int count = amount/coins[i];
            printf("%d x %d\n", coins[i], count);
            amount = amount % coins[i];

        }
    }
    return 0;
}
