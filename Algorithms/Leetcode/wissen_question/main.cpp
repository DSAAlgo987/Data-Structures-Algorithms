#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
int solve(vector<int> &routes) {
    int n = routes.size();

    // Step 1: calcualte left sum and right sum 
    int leftSum = 0;
    int rightSum = 0;

    for(auto r: routes) {
        rightSum += r;
    }

    // Step 2: Start traversing each element and sum before current element is equal to sum after of current element (1 indexed based)
    for(int i = 0; i < n; i++) {
        // Remove ith calc from rightSum 
        rightSum -= routes[i];
        

        if(leftSum == rightSum) {
            return i + 1;
        }

        // Add ith calcl to rightSum 
        leftSum += routes[i];
    }

    // If there are no any sums are equal
    return -1;
}

// Time complexity: O(n)
vector<int> solve2(vector<int> &performers){
    int n = performers.size();

    // Note : array is sorted in ASC order 
    
    // Task: even indices should be greater than odd indices element 
    for(int i = 0; i < n - 1; i+=2) {
        // Swaping i <-> i+1 
        int temp = performers[i];
        performers[i] = performers[i+1];
        performers[i + 1] = temp;
    }

    return performers;
}

void displayVec(vector<int> &v) {
    for(auto n: v) {
        cout << n << " ";
    }

    cout << endl;
}

int main(){
    vector<int> arr = {2, 2, 5, 6, -2};

    cout << solve(arr) << endl;

    vector<int> performers = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ans = solve2(performers);

    displayVec(ans);
    return 0;
}