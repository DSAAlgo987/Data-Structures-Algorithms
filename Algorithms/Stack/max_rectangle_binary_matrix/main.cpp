#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Identify Max Rectangle in Binary Matrix; (2D)
 * IP: vector<vector<int>> matrix;
 * OP: Return Max Rectangle in Binary Matrix (int);
 * VARIATION: MAH| Maximum Area/Rectangle Histogram (1D)
 * APPROACH: Convet 2d -> 1d -> MAH -> Return mx(MAH) -> O(n^2)
 */

// Aliases 
using v = vector<int>;
using vv = vector<v>;
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

    v right = NSR(arr);
    v left = NSL(arr);

    v width(n);
    v area(n);

    for(int i = 0; i < n; i++) {
        width[i] = right[i] - left[i] - 1;
        area[i] = arr[i] * width[i];
    }

    /**
     * max_element(first, last, comparator);
     * 
     * Return:
     * Returns Iterator of the max value
     * If not found then retun last 
     * To get the value use * (Pointer symbol)
     */

    return *max_element(area.begin(), area.end());
}

// MABM - n^2
int MABM(vv &mat) {
    v vec;
    int mx = INT_MIN;
    int n = mat.size();
    int m = mat[0].size();

    // Iterate first row of mat and push into vec
    for(int j = 0; j < m; j++) 
        vec.push_back(mat[0][j]);

    // Calculate MAH for that
    mx = MAH(vec);

    // Do this for remaining elements present in binary matrix
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) // Don't add just copy it 
                vec[j] = 0;
            else // if not 0 then add 1 to vec[j]
                vec[j] += 1;
        }

        // Then cacluate MAH for new vec 
        mx = max(mx, MAH(vec));
    }

    return mx;
}

int main() {
    vv mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };

    cout << MABM(mat) << endl; // OP: 8
}