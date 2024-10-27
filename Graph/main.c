#include <stdio.h> 
#include "Queue.h" 

int n;
int adj[10][10] , visited[10];

// (Breadth First Search)
// TC : O(n^2)
void BFS(int i){
    struct Queue q = createQueue(10);
    int u;
    // Initial step : 
    printf("%d " , i);
    visited[i] = 1;
    enqueue(&q , i);

    // Explore all it's adjacents 
    while(!isEmpty(&q)){
        u = dequeue(&q);
        for(int v = 1 ; v<=n ; v++){
            // check there is connection and visited or not 
            if(adj[u][v]==1 && visited[v] == 0){
                printf("%d ",v);
                visited[v] =1;
                enqueue(&q , v);
            }
        }
    }
}

void DFS(int v){
   if(visited[v] == 0){
        printf("%d ",v);
        visited[v] =1;
        // explore all it's adjacents
        for(int i = 1; i<=n ; i++){
            // if connection and not visited then enter 
            if(adj[v][i]== 1 && visited[i] == 0){
                DFS(i);
            }
        }
   }
}

int main(){
    int v;
    printf("\nEnter the no of vertices : ");
    scanf("%d" , &n);

    printf("\nEnter graph : \n");
    for(int i=1 ; i<=n ; i++){
        for(int j =1 ; j<=n;j++){
            printf("Enter connection between %d and %d :  " , i , j);
            scanf("%d" , &adj[i][j]);
            // Eptional
            if (i != j) {
                adj[j][i] = adj[i][j]; // Ensure undirected symmetry
            }
        }
    }

    // Initialize visited array as zero(0)
    for(int i = 1 ; i<=n ; i++){
        visited[i] = 0;
    }

    // printf("Enter the starting vertex : ");
    // scanf("%d" , &v);
    // BFS(v);
    
    printf("Enter the starting vertex : ");
    scanf("%d" , &v);
    DFS(v);

    

    return 0;
}