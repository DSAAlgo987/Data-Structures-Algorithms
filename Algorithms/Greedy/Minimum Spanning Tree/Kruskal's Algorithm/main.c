#include <stdio.h>

#define I 32767

int edges[3][9] = {
    {1, 1, 2, 2, 3, 4, 4, 5, 5},
    {2, 6, 3, 7, 4, 5, 7, 6, 7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};

int set[8] = {-1};

// (7) vertices -> 7-1 (6) edges
int t[2][6];

int included[9] = {0};

void unionOperation(int u, int v){
    if(set[u] < set[v]){
        set[u] += set[v];
        set[v] = u;
    }else{
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u){
    int x = u;

    while(set[x] > 0){
        x = set[x];
    }

    return x;
}

int main(){
    int i=0, j, u, v, k, min, n=7, e=9, sum=0;

    while(i < n-1){
        // Identify min cost edge
        min = I;
        for(j=0; j<e; j++){
            // selected min cost edge should not be included
            if(included[j] == 0 && edges[2][j] < min){
                min = edges[2][j];
                u = edges[0][j]; v = edges[1][j];
                k = j;
            }
        }

        // Check if there is a cycle is formed or not
        if(find(u) != find(v)){
            t[0][i] = u;
            t[1][i] = v;
            sum += min; // finding total cost
            i++;
            unionOperation(find(u) , find(v));
        }
        // update included array
        included[k] = 1;
    }

    for(i=0; i<n-1; i++){
        printf("(%d, %d)," , t[0][i],t[1][i]);
    }

    printf("\nTotal cost: %d",sum);

    return 0;
}

