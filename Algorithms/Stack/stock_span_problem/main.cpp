#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Stock Span Problem : Consecutive smaller or equal to before it (element);
 * IP: vector<int> arr
 * OP: vector<int> countOfConsecutiveSmallerEqualBeforeIt.
 * 
 * APPROACH 1: Brute Force: O(n^2)
 * APPROACH 2: Stack based: O(n)
 * 
 * Variation: NGL| Nearest Greater to Left
 */

// Aliases
using v = vector<int>;
using p = pair<int, int>;   // <NGL Ele, NGL idx>

// Brute Force: n^2
v stockSpanProblemBF(v &arr) {
    int n = arr.size();
    v ans(n, 1); // Initialize ans as 1, Initially 

    for(int i = 1; i < n; i++) {
        int count = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(arr[j] > arr[i]) {
                break;
            }
            count++;
        }
        ans[i] = count;
    }

    return ans;
}

// Stack Based: n
v NGL(v &arr) {
    int n = arr.size();
    v vec; // Store NGL idx
    stack<p> st; // <NGL Ele, NGL idx>
    
    // Iterate arr from left to right 
    for(int i = 0; i < n; i++) {
        if(st.empty()) {
            vec.push_back(-1);
        }
        else if(!st.empty() && st.top().first > arr[i]) {
            vec.push_back(st.top().second);
        }
        else if(!st.empty() && st.top().first <= arr[i]) {
            while(!st.empty() && st.top().first <= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                vec.push_back(-1);
            }
            else {
                vec.push_back(st.top().second);
            }
        }
        st.push({arr[i], i}); // Push Pair <NGL Ele, NGL idx>
    }

    return vec; 
}

// Time complexity: O(n + n)
v stockSpanProblem(v &arr) {
    v ans = NGL(arr); // n

    // Formula : i - NGL idx => ouput
    for(int i = 0; i < arr.size(); i++) { // n
        ans[i] = i - ans[i];
    }

    return ans;
}

void print(v &arr) {
    for(auto ele: arr) {
        cout << ele << " ";
    }
    cout << endl;
}


int main(){
    v arr = {100, 80, 60, 70, 60, 75, 85};

    v ans;
    ans = stockSpanProblemBF(arr);
    print(ans); // OP: 1 1 1 2 1 4 6

    ans = stockSpanProblem(arr);
    print(ans); // OP: 1 1 1 2 1 4 6
    
    return 0;
}