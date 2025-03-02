#include <stdio.h>

struct Item{
    int profits;
    int weights;
    double ratio;
};

double getMaxProfit(int W, struct Item items[], int n){
    double totalValue = 0;
    struct Item temp;
    // Get ratio by profit/ weight
    for(int i = 0 ;i < n ;i++){
        items[i].ratio = (double)items[i].profits / items[i].weights;
    }

    // Select item based on the highest ratio 
    // Sort ratio in descending order
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(items[i].ratio < items[j].ratio){
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Iterate each items and pick highest ratio 
    for(int i = 0 ;i < n;i++){
        if(W == 0 ){ // if container is full
            break;
        }

        if(items[i].weights <= W){
            totalValue += items[i].profits;
            W-= items[i].weights;
        }else{
            totalValue += items[i].profits * ((double)W / items[i].weights);
            W = 0;
        }
    }

    return totalValue;
}


int main(){
    struct Item items[] = {
        {10, 2, 0},
        {5, 3, 0},
        {15, 5, 0},
        {7, 7, 0},
        {6, 1, 0},
        {18, 4, 0},
        {3, 1, 0}
    };

    int n = sizeof(items)/ sizeof(items[0]); // 7
    int m = 15; // Knapsack capacity

    double maxProfit = getMaxProfit(m, items, n);

    printf("\n Total profit: %.2f", maxProfit);

    return 0;
}