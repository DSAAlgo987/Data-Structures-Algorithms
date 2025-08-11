#include <bits/stdc++.h>
using namespace std;

// Brute force : n.n!
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end()); // Ensure all permutations are covered

        do {
            if (s[0] == '0') continue; // Skip leading zero numbers

            int num = stoi(s);
            // Power of two check
            if (num > 0 && (num & (num - 1)) == 0) {
                return true;
            }
        } while (next_permutation(s.begin(), s.end()));

        return false;
    }
};


// Optimized: nlgn (bcoz of the sorting)
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto convertString = [](int x){
            // Convert int to string
            string s = to_string(x);

            // Sort string as ASC
            sort(s.begin(), s.end());

            return s;
        };

        string target = convertString(n);

        for(int i = 0; i < 31; i++){
            if(convertString(1 << i) == target){
                return true; // Given number is a power of two
            }
        }

        return false;
    }
};