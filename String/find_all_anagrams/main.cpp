#include <bits/stdc++.h>
using namespace std;

// n-m* klgk
vector<int> findAllAnagrams(string s, string p){
    int n = s.size();
    int m = p.size();
    vector<int> result;

    // Base case 
    if(n < m){
        return result;
    }

    // Sort p string 
    string sorted_p = p;
    sort(sorted_p.begin(), sorted_p.end()); // klgk

    for(int i = 0; i <= n - m; i++){        // n-m
        string window = s.substr(i, m);
        sort(window.begin(), window.end()); // n-m * klgk

        if(window == sorted_p){
            result.push_back(i);
        }
    }

    return result;
}

// n
vector<int> findAllAnagramsBetter(string s, string p){
    int n = s.size();
    int m = p.size();
    vector<int> result;

    // Base case 
    if(n < m){
        return result;
    }

    vector<int> sfreq(26, 0), pfreq(26, 0);

    // fill p freq 
    for(auto c: p){
        pfreq[c - 'a']++;
    }

    // sliding window 
    int  i = 0, j = 0;
    
    while(j < n){
        // Calculation 
        sfreq[s[j] - 'a']++;

        // achive wd size 
        if(j - i + 1 < m){
            j++;
        }
        // hit wd size 
        else if(j - i + 1 == m){
            // ans <- calculation
            if(sfreq == pfreq){
                result.push_back(i);
            }

            // slide window 
            sfreq[s[i] - 'a']--;
            i++;
            j++;
        }
    }
    
    return result;
}

int main(){
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> ans = findAllAnagramsBetter(s, p);
    cout << " [ ";
    for(auto i: ans){
        cout << i << "," ;
    }
    cout << " ]";
    return 0;
}