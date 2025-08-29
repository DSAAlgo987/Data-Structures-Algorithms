// Time complexity: O(1)
class Solution {
public:
    long long flowerGame(int n, int m) {
        // oddN * evenM + evenN * oddM
        return ( 1LL * ((n + 1) / 2) * (m/2) + 1LL * (n/2) * ((m+1) /2));
    }
};