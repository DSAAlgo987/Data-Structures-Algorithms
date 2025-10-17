#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Nearest Smaller to Left (NSL) 
 * IP: vector<int> arr;
 * OP: vector<int> arrOfSmallerElements
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
    // For first element

    for(int i = 1; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            // Next_element > Current_element
            if(arr[j] < arr[i]) {
                ans[i] = arr[j];
                found = true;
                break;
            } 
        }
        if(!found) {
            ans[i] = -1;
        }
    }

    return ans;
}
 
// Stack Based - n
v NGLOptimized(v &arr) {
    int n = arr.size();
    v ans;
    stack<int> st;

    // Iterate arr from backward direction 
    for(int i = 0; i < n; i++) {
        // 1. Stack is empty 
        if(st.size() == 0) {
            ans.push_back(-1);
        }

        // 2. St.top > arr[i] 
        else if(st.size() > 0 && st.top() < arr[i]) {
            ans.push_back(st.top());
        }

        // 3. st.top <= arr[i] 
        else if(st.size() > 0 && st.top() >= arr[i]) {
            // pop -> 1. st empty 2.st.top < arr[i]
            while(st.size() > 0 && st.top() >= arr[i]) {
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

    return ans;
}

int main(){
    v arr = {4, 5, 2, 10, 8};
    v ans;

    ans = NGL(arr);
    print(ans); // OP: -1 4 -1 2 2

    ans = NGLOptimized(arr);
    print(ans); // OP: -1 4 -1 2 2
    return 0;
}