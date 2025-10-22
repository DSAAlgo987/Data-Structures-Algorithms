#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Mx Area Histogram | MAH 
 * IP: vector<int> arr;
 * OP: Return max area in Histogram (int)
 * APROACH: Stack -> O(n): 
 *  1. NSR Idx -> Right -> Reverse 
 *  2. NSL Idx -> left 
 *  3. Width -> width[i] = right[i] - left[i] - 1;
 *  4. Area -> area[i] = arr[i] * width[i];
 *  5. Return mx(area) 
 */

// Aliases 
using v = vector<int>;
using p = pair<int, int>; // <NSL|R Element, NSL|R Idx>

// NSL : n 
v NSL(v &arr) {
    int n = arr.size();
    stack<p> st;
    v left;

    // Iterate from left to right 
    for(int i = 0; i < n; i++) {
        // if Stack is empty 
        if(st.empty()) {
            left.push_back(-1);
        }
        // Stack is not empty && st.top < arr[i]
        else if(!st.empty() && st.top().first < arr[i]) {
            left.push_back(st.top().second);
        }
        // Stack is not empty && st.top >= arr[i]
        else if(!st.empty() && st.top().first >= arr[i]) {
            while(!st.empty() && st.top().first >= arr[i]) {
                st.pop();
            }

            // Stack is empty 
            if(st.empty()) {
                left.push_back(-1);
            }
            else {
                left.push_back(st.top().second);
            }
        }

        // Before moving next element push the current element 
        st.push({arr[i], i});
    }

    return left;
}

// NSR : n
v NSR(v &arr) {
    int n = arr.size();
    stack<p> st;
    v right;

    // Iterate from right to left 
    for(int i = n-1; i >= 0; i--) {
        // if Stack is empty 
        if(st.empty()) {
            right.push_back(n);
        }
        // Stack is not empty && st.top < arr[i]
        else if(!st.empty() && st.top().first < arr[i]) {
            right.push_back(st.top().second);
        }
        // Stack is not empty && st.top >= arr[i]
        else if(!st.empty() && st.top().first >= arr[i]) {
            while(!st.empty() && st.top().first >= arr[i]) {
                st.pop();
            }

            // Stack is empty 
            if(st.empty()) {
                right.push_back(n);
            }
            else {
                right.push_back(st.top().second);
            }
        }

        // Before moving next element push the current element 
        st.push({arr[i], i});
    }

    // Reverse right vector to get the exact the result
    reverse(right.begin(), right.end());

    return right;
}

// MAH: n
int MAH(v &arr) {
    int n = arr.size();

    // NSR Index
    v right = NSR(arr);

    // NSL Index
    v left = NSL(arr);

    // Caclulate width vector
    v width(n);
    for(int i = 0; i < n; i++) {
        width[i] = right[i] - left[i] - 1;
    }

    // Cacluate Area vector 
    v area(n);
    for(int i = 0; i < n; i++) {
        area[i] = arr[i] * width[i];
    }

    // Max function deasn't work with array and vector

    return *max_element(area.begin(), area.end());
}

int main() {
    v arr = {6, 2, 5, 4, 5, 1, 6};

    cout << MAH(arr) << endl; // OP: 12
    return 0;
}