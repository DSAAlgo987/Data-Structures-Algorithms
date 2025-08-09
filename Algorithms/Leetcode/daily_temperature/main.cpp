/**
 * Brute force: 
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // Initialize with 0

        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                if(temperatures[i] < temperatures[j]){
                    ans[i] = j - i; 
                    break;
                }
            }
        }

        return ans;
    }
};

/**
 * Better :
 * Time complexity: O(n + n) 
 * space compexity: O(n)
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }
        return res;
    }
};