// Time complexity: O(Q)
class Solution {
public:
    int M = 1e9 + 7; // 10^9 + 7
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> result;
        // Include those numberse which are one and equal to the n and push into powers vector
        for(int i = 0; i < 31; i++){  // Constant time 
            if((n & (1 << i)) != 0){
                powers.push_back(1 << i); // Append as asc order
            }
        }

        // Perfrom queries operations on powers 
        for(auto q: queries){ // q.size()
            int start = q[0];
            int end = q[1];

            long product = 1;

            for(int i = start; i <= end; i++){ // constant time 
                product = (product * powers[i]) % M;
            }

            result.push_back(product);
        }

        return result;
    }
};
