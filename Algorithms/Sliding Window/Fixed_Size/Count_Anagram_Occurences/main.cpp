#include <bits/stdc++.h>
using namespace std;

void solve(string &p, string &txt){
    unordered_map<char, int> winChar;

    // Count freq of each char of pat
    for(auto const &c: p){
        winChar[c]++;
    }

    int i = 0, j = 0, ans = 0, count = winChar.size();
    int k = p.size();

    // Sliding window
    while(j < txt.size()){
        // Calculation 
        if(winChar.find(txt[j]) != winChar.end()){
            winChar[txt[j]]--;
            if(winChar[txt[j]] == 0){
                count--;
            }
        }

        // Achieve window size
        if(j - i + 1 < k){
            j++;
        }
        // Hit window size
        else if(j - i + 1 == k){
            // Ans <- Calculation 
            if(count == 0){
                ans++;
            }

            // Slide window
            if(winChar.find(txt[i]) != winChar.end()){
                winChar[txt[i]]++;

                if(winChar[txt[i]] == 1){
                    count++;
                }
            }

            i++;
            j++;
        }
    }

    cout << "Ans: " << ans << endl;
}


int main(){
    string txt = "forxxorfxdofr", p = "for";

    solve(p, txt); 
    return 0;
}