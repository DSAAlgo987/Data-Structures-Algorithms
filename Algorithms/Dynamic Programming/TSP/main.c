#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX
#define N 4 // Number of cities

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int dp[1 << N][N]; // dp[mask][i]

int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) {
        return dist[pos][0]; // Return to the starting city
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int city = 0; city < N; city++) {
        if (!(mask & (1 << city))) {
             // city not yet visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = (newAns < ans) ? newAns : ans;
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    printf("The minimum cost is %d\n", tsp(1, 0));
    return 0;
}