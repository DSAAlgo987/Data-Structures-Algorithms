#include <bits/stdc++.h>
using namespace std;

// Auto keyword can be used in function parameter only in C++ 20 version

void printArray(vector<int> &v){
    for(auto i: v){
        cout << i << " ";
    }
}

void insort(vector<int> &v, int temp){
    // Base condition 
    if(v.size() == 0 || v[v.size()-1] <= temp){
        v.push_back(temp);
        return;
    }

    // Induction 
    int value = v[v.size() - 1];
    v.pop_back();

    insort(v, temp);

    v.push_back(value);
    return;
}

void sortArray(vector<int> &v){
    // Base condition 
    if(v.size() == 1){
        return;
    }

    // Induction 
    int temp = v[v.size() - 1];
    v.pop_back();
    sortArray(v);
    insort(v, temp);
}

int main(){
    vector<int> v = {0, 1, 5, 2};

    // Hypothesis
    sortArray(v);

    printArray(v);

    return 0;
}