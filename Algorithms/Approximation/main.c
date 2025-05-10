#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int primMST() {
    int key[N];
    bool mstSet[N];
    
    for (int i = 0; i < N; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;

    for (int count = 0; count < N - 1; count++) {
        int u = -1;

        for (int i = 0; i < N; i++) {
            if (!mstSet[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        mstSet[u] = true;

        for (int v = 0; v < N; v++) {
            if (dist[u][v] && !mstSet[v] && dist[u][v] < key[v]) {
                key[v] = dist[u][v];
            }
        }
    }

    int mstWeight = 0;
    for (int i = 1; i < N; i++) {
        mstWeight += key[i];
    }
    return mstWeight;
}

int main() {
    int approxCost = 2 * primMST();
    printf("Approximate cost: %d\n", approxCost);
    return 0;
}
