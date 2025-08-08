// Time complexity: O(n^2)
class Solution {
public:
    // Operations vector 
    vector<pair<int, int>> ops = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};

    // dp 
    vector<vector<double>> t;
    double solve(double A, double B){
        // If A and B being empty;
        if(A <= 0 && B <= 0){
            return 0.5; // Half of probability (1/2)
        }

        // If A being empty 
        if(A <= 0){
            return 1; // Prob.
        }

        // If B being empty 
        if(B <= 0){
            return 0; // Prob.
        }

        // Present in dp 
        if(t[A][B] != -1){
            return t[A][B];
        }

        // Perform operations randomly & calculate probability 
        double prob = 0.0;
        for(auto &p: ops){
            double A_taken = p.first;
            double B_taken = p.second;

            prob += solve(A - A_taken, B - B_taken);
        }

        return t[A][B] = 0.25 * prob;
    }
    double soupServings(int n) {
        // If n value is greater than 4k then the prob will be 1
        // n >= 4800 is a well-known safe threshold used in the official solutions
        if(n >= 4800){
            return 1.0; // Probability
        }
        t.resize(n+1, vector<double>(n+1, -1));
        return solve(n, n);
    }
};