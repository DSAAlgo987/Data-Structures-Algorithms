#include <stdio.h>

void printSubset(int subSet[], int subsetSize){
    int i;
    printf("Subset: { "); 
    for (int i = 0; i < subsetSize; i++) { 
        printf("%d ", subSet[i]); 
    } 
    printf("}\n");
}

void sumOfSubsetUtil(int w[], int targetSum, int n, int subset[], int subsetSize,int sum, int index){

    // Base condition 
    if(sum == targetSum){
        printSubset(subset, subsetSize);
        return;
    }
    int i;
    for(i = index; i < n; i++){
        if(w[i] + sum <= targetSum){
            subset[subsetSize] = w[i];
            sumOfSubsetUtil(w, targetSum, n, subset, subsetSize+1, sum + w[i] , i + 1);
        }
    }

}

void sumOfSubset(int w[], int targetSum, int n){
    int subset[n];
    sumOfSubsetUtil(w, targetSum, n, subset,0, 0, 0);
}

int main(){
    int n, i;
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 

    int weights[n];
    printf("Enter the elements: "); 
    for(i = 0; i < n; i++){
        scanf("%d", &weights[i]);
    }

    int targetSum;
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    sumOfSubset(weights, targetSum, n);
}