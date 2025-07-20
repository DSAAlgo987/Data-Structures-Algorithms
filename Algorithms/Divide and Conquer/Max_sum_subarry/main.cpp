#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int solve(vector<int>& arr, int low, int high) {
    if (low == high) return arr[low];

    int mid = (low + high) / 2;

    int left = solve(arr, low, mid);
    int right = solve(arr, mid + 1, high);
    int cross = maxCrossingSum(arr, low, mid, high);

    return max({left, right, cross});
}

int main() {
    vector<int> arr = {4, -3, 4, 1, -4, 6};
    int ans = solve(arr, 0, arr.size() - 1);
    cout << "Maximum Subarray Sum: " << ans << endl;
    return 0;
}
