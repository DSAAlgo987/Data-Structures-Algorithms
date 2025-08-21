// TC: O(n) SC: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rotated(n, 0);

        for(int i = 0; i < n; i++) {
            rotated[(i + k) % n] = nums[i];
        }

        for(int i = 0; i < n; i++) {
            nums[i] = rotated[i];
        }
    }
};

// TC: O(n) , SC: O(1)
class Solution {
public:
    void reverse(vector<int> &nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // normalize k if k > n

        // Step 1: Reverse the whole array
        reverse(nums, 0, n - 1);

        // Step 2: Reverse first k elements
        reverse(nums, 0, k - 1);

        // Step 3: Reverse remaining n-k elements
        reverse(nums, k, n - 1);
    }
};
