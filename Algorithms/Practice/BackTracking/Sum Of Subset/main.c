#include <stdio.h>
#define MAX 100

void print(int subset[], int subsetSize){
    printf("Subset: {");

    for(int i = 0; i < subsetSize; i++){
        printf(" %d ", subset[i]);
    }

    printf("}\n\n");
}

void sumOfSubsetUtil(int wt[],int n, int m, int subset[], int subsetSize, int sum, int index){

    // Base condition 
    if(sum == m){
        print(subset, subsetSize);
        return;
    }

    // Iterate i to n and identify elements which are equal to sum 
    for(int i = index; i <= n; i++){
        // If current element + sum <= target then include  
        if(wt[i] + sum <= m){
            // Add subset array 
            subset[subsetSize] = wt[i]; 

            // Identify remaining elemtents
            sumOfSubsetUtil(wt, n, m, subset, subsetSize + 1, wt[i] + sum, i + 1);
        }
    }
}

void sumOfSubset(int wt[], int n, int m){
    int subset[MAX];
    sumOfSubsetUtil(wt, n, m, subset, 0, 0, 0);
}

int main(){
    int n, wt[MAX], m;

    printf("Enter size of the wt: ");
    scanf("%d", &n);

    printf("Enter WT elements: ");
    for(int i =0; i <n; i++){
        scanf("%d", &wt[i]);
    } 

    printf("Enter target sum: ");
    scanf("%d", &m);

    sumOfSubset(wt, n, m);
}