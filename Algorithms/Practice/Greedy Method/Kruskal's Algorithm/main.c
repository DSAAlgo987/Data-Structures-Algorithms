#include <stdio.h>
#include <limits.h>

#define I INT_MAX

// Edges 
int edges[3][9] = {
    {1, 1, 2, 2, 3, 4, 4, 5, 5},
    {2, 6, 3, 7, 4, 5, 7, 6, 7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};

// Set for detecting cyclecs
int s[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

// Included for edge included or not 
int included[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

// Spanning tree
int t[2][6];

void unionSet(int u, int v){
    if(s[u] < s[v]){
        s[u] = s[u] + s[v];
        s[v] = u;
    }else{
        s[v] = s[v] + s[u];
        s[u] = v;
    }
}

int find(int u){
    int x = u;

    while(s[x] > 0){
        x = s[x];
    }
    return x;
}

int main(){
    int i , j, u, v, min, k;
    int n = 7;
    int sum = 0;

    i = 0;

    // Iterate till n-1
    while(i < n-1){
        // Identify min edge and not included
        min = I;
        for(j = 0; j < 9; j++){
            if(included[j] == 0 && edges[2][j] < min){
                min = edges[2][j];
                u = edges[0][j]; v = edges[1][j];
                k = j;
            }
        }

        // Check cycle 
        if(find(u) != find(v)){
            sum += min;
            t[0][i] = u; t[1][i] = v;
            unionSet(find(u), find(v));
            i++;
        }

        // Update included array 
        included[k] = 1;
    }

    // Print spanning tree 
    for(i = 0; i < n-1; i++){
        printf("(%d, %d) ", t[0][i], t[1][i]);
    }

    // Cost 
    printf("\nCost: %d", sum);

    return 0;
}