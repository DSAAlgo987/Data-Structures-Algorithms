// Time complexity: O(n * n)

class Solution {
public:
    int n;
    vector<vector<int>> t;

    int child1Collect(vector<vector<int>>& fruits){
        int sum = 0;

        // Diagonal sum 
        for(int i = 0; i < n; i++){
            sum += fruits[i][i];
        }

        return sum;
    }

    int child2Collect(int i, int j, vector<vector<int>>& fruits){

        // base conditions 
        if(i >= n || j < 0 || j >= n){
            return 0;
        }

        if(i > j || i == j){
            return 0; 
        }

        if(i == n-1 && j == n-1){
            return 0; // Bcoz fruits[n-1][n-1] was already collected by child1
        }

        // Present in dp
        if(t[i][j] != -1){
            return t[i][j];
        }

        int bottomLeft = fruits[i][j] + child2Collect(i+1, j-1, fruits);
        int bottomDown = fruits[i][j] + child2Collect(i+1, j, fruits);
        int bottomRight = fruits[i][j] + child2Collect(i+1, j+1, fruits);

        return t[i][j] = max({bottomLeft, bottomDown, bottomRight});
    }

    int child3Collect(int i, int j, vector<vector<int>>& fruits){

        // base conditions 
        if(i < 0 || i >= n || j >= n){
            return 0;
        }

        if(i < j || i == j){
            return 0; 
        }

        if(i == n-1 && j == n-1){
            return 0; // Bcoz fruits[n-1][n-1] was already collected by child1
        }

        // Present in dp
        if(t[i][j] != -1){
            return t[i][j];
        }

        int upRight = fruits[i][j] + child3Collect(i - 1, j + 1, fruits);
        int right = fruits[i][j] + child3Collect(i, j + 1, fruits);
        int bottomRight = fruits[i][j] + child3Collect(i + 1, j + 1, fruits);

        return t[i][j] = max({upRight, right, bottomRight});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        // i and j is changing so the size of dp will be n * n 
        t.resize(n, vector<int>(n, -1)); // Initialize as -1

        int child1 = child1Collect(fruits);

        int child2 = child2Collect(0, n - 1, fruits);

        int child3 = child3Collect(n - 1, 0, fruits);

        return child1 + child2 + child3;
    }
};