#include <bits/stdc++.h>
using namespace std;

void firstNegInt(vector<int> &arr, int n, int k){
    list<int> q;
    vector<int> res;

    int i = 0, j = 0;
    
    while(j < n){
        // calculation
        if(arr[j] < 0){
            q.push_back(arr[j]);
        }

        // acheive window size
        if(j - i + 1 < k){
            j++;
        }
        else if(j - i + 1 == k){ // maintain window size
            // ans <- calc 
            // edge case : no negative values
            if(q.empty()){
                res.push_back(0);
            }else {
                res.push_back(q.front());

                if(arr[i] == q.front()){
                    q.pop_front();
                }
            }

            // Slide window
            i++;
            j++;
        }
    }

    for(auto no: res){
        cout << no;
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    firstNegInt(arr, n, k);
    return 0;
}