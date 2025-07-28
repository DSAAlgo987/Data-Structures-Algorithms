#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> temp;       // For Brute Force
    vector<int> prefixSum;  // For Optimized

public:
    // Constructor
    NumArray(vector<int>& nums) {
        // Store original array (for brute force)
        temp = nums;

        // Compute prefix sum (for optimized)
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            prefixSum.push_back(sum);
        }
    }

    // Brute Force: O(n) per query
    int sumRangeBrute(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += temp[i];
        }
        return sum;
    }

    // Optimized: O(1) per query using prefix sum
    int sumRangeOptimized(int left, int right) {
        if (left == 0) {
            return prefixSum[right];
        }
        return prefixSum[right] - prefixSum[left - 1];
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    NumArray obj(nums);

    // Sample queries
    cout << "Brute Force sumRange(1, 3): " << obj.sumRangeBrute(1, 3) << endl;
    cout << "Optimized sumRange(1, 3): " << obj.sumRangeOptimized(1, 3) << endl;

    cout << "Brute Force sumRange(0, 4): " << obj.sumRangeBrute(0, 4) << endl;
    cout << "Optimized sumRange(0, 4): " << obj.sumRangeOptimized(0, 4) << endl;

    return 0;
}
