#include <stdio.h>      // for printf
#include <string.h>     // for memset

#define N 7             // Number of keys

int DP[100][100];       // DP table to store minimum costs
int b[100][100];        // Table to store root positions
int nodes[] = {0, 1, 2, 3, 4, 5, 6, 7}; // Node values (0 unused)
int freq[] = {0, 4, 2, 1, 3, 5, 2, 1};  // Frequencies of nodes
int sums[10];           // Prefix sums of frequencies

// Function to return sum of frequencies from index `from` to `to`
int P(int from, int to) {
    return sums[to] - sums[from - 1];
}

// Recursive function to calculate minimal search cost
int rec(int from, int to) {
    if (from > to) return 0;           // Base case: invalid range
    if (from == to) return freq[from]; // Base case: single node
    if (DP[from][to] != -1) return DP[from][to]; // Use memoized result

    int optimal = 1 << 29; // Set optimal to a large number
    for (int i = from; i <= to; ++i) {
        // Try each node as root and calculate cost
        int current = rec(from, i - 1) + rec(i + 1, to) + P(from, to);
        if (current < optimal) {
            optimal = current;    // Update optimal cost
            b[from][to] = i;      // Save root for this range
        }
    }
    DP[from][to] = optimal; // Memoize result
    return optimal;
}

// Function to print root structure
void print(int from, int to) {
    if (from == to) b[from][to] = from;        // Leaf node
    if (b[from][to] == -1) return;             // No root defined
    printf("root between %d and %d: %c\n", from, to, (char)(b[from][to] + 'A' - 1)); // Print root
    print(from, b[from][to] - 1);  // Recur on left subtree
    print(b[from][to] + 1, to);    // Recur on right subtree
}

int main() {
    // Compute prefix sums of frequencies
    for (int i = 1; i <= N; ++i) {
        sums[i] = sums[i - 1] + freq[i];
    }

    // Initialize DP and b arrays to -1
    memset(DP, -1, sizeof(DP));
    memset(b, -1, sizeof(b));

    int res = rec(1, N); // Start DP from node 1 to N
    printf("Minimal value: %d\n", res); // Print minimal cost
    print(1, N); // Print structure of the tree
    return 0;
}
