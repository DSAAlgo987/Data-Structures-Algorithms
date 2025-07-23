#include <bits/stdc++.h>
using namespace std;

string toggleString(string s){
    for(auto &c: s){
        if(islower(c)){
            c = toupper(c);
        }else{
            c = tolower(c);
        }
    }

    return s;
}

/**toggle without using built in function 
    A -> 65 , a -> 97
    toggle logic : 97 - 67 = 32 
    'A' + 32 = 'a'
    'a' - 32 = 'A'
*/
string toggleStringBest(string s){
    for(auto &c: s){
        // is lower?
        // compare their ASCII values
        if(c >= 'a' && c<='z'){
            c = c - 32; // converts to upper
        }else{
            c = c + 32; // converts to lower
        }
    }

    return s;
}
int main(){
    string s = "abcDE";

    cout << toggleStringBest(s);
    return 0;
}