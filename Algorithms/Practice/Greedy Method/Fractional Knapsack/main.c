#include <stdio.h>

// Time complexity : O(n^2)
// Optimize using quick sort : O(nlogn)

typedef struct {
    int profit;
    int weight;
    double ratio;
} Item;

double getMaxProfit(Item items[], int n, int W){
    double totalValue = 0;
    // Step 1: calculate ratio for each object
    for(int i = 0; i < n; i++){
        items[i].ratio = (double) items[i].profit / items[i].weight;
    }

    // Step 2: Sort items as descending order of  ratio 
    for(int i = 0; i < n-1; i++){
        for(int j = i; j < n; j++){
            if(items[j].ratio > items[i].ratio){
                Item temp = items[j];
                items[j] = items[i];
                items[i] = temp;
            }
        }
    }

    // Step 3: select item as per the highest ratio
    for(int i = 0; i < n; i++){
        // Base condition 
        if(W == 0){
            break;
        }

        // Calculate profit
        if(items[i].weight <= W){
            totalValue += items[i].profit;
            W -= items[i].weight;
        }else{
            totalValue += items[i].ratio * W;
            // We can also use this 
            // totalValue += items[i].profit * ((double) W / items[i].weight);
            W = 0;
        }
    }

    return totalValue;
}

int main(){
    Item items[]= {
        {10, 2, 0},
        {5, 3, 0},
        {15, 5, 0},
        {7, 7, 0},
        {6, 1, 0},
        {18, 4, 0},
        {3, 1, 0},
    };
    int n = sizeof(items) / sizeof(items[0]);
    double max;
    int W = 15;

    max = getMaxProfit(items, n, W);

    printf("Max Profit : %.2f", max);

}