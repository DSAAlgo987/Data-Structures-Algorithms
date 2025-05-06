#include <stdio.h>
#define INF 9999999
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
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = (newAns < ans) ? newAns : ans;
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    printf("The minimum cost is %d\n", tsp(1, 0));
    return 0;
}