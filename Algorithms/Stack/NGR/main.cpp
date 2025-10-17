#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Nearest Greater to Right (NGR) | Next Largest Element
 * IP: vector<int> arr;
 * OP: vector<int> arrOfGreaterElements
 * 
 * APPROACH 1: Brute Force: O(n^2) 
 * APPROACH 2: Optimized : Stack O(n)
 */

// Aliases
using v = vector<int>;

void print(v &arr) {
    for(auto ele: arr) {
        cout << ele << " ";
    }

    cout << endl;
}

// Brute Force - n^2
v NGL(v &arr) {
    int n = arr.size();
    v ans(n, -1);
    bool found = false;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            // Next_element > Current_element
            if(arr[j] > arr[i]) {
                ans[i] = arr[j];
                found = true;
                break;
            }
        }
        if(!found) {
            ans[i] = -1;
        }
    }

    // For last element push -1

    return ans;
}
 
// Stack Based - n
v NGLOptimized(v &arr) {
    int n = arr.size();
    v ans;
    stack<int> st;

    // Iterate arr from backward direction 
    for(int i = n - 1; i >= 0; i--) {
        // 1. Stack is empty 
        if(st.size() == 0) {
            ans.push_back(-1);
        }

        // 2. St.top > arr[i] 
        else if(st.size() > 0 && st.top() > arr[i]) {
            ans.push_back(st.top());
        }

        // 3. st.top <= arr[i] 
        else if(st.size() > 0 && st.top() <= arr[i]) {
            // pop -> 1. st empty 2.st.top > arr[i]
            while(st.size() > 0 && st.top() <= arr[i]) {
                st.pop();
            }

            // stack is empty 
            if(st.size() == 0) {
                ans.push_back(-1);
            }
            else { // st.top > arr[i]
                ans.push_back(st.top());
            }
        }

        // Before moving to the next push current element -> stack
        st.push(arr[i]);
    }

    // Reverse ans to get the actual restul 
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    v arr = {1, 3, 2, 4};
    v ans;

    ans = NGL(arr);
    print(ans); // OP: 3 4 4 -1

    ans = NGLOptimized(arr);
    print(ans); // OP: 3 4 4 -1 
    return 0;
}