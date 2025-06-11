#include <bits/stdc++.h>

using namespace std;

bool ispalindrome(string &str){
    int left = 0;
    int right = str.size() - 1;
    
    while(right > left){
        if(str[left] != str[right]){
            cout << "false" <<endl;
            return false;
        }
        right--;
        left++;
    }
    
    cout << "True" << endl;
    return true;
}


int main()
{
    string str = "A man, a plan, a canal: Panama";
    
    // Convert to lower and cleane string 
    string cleaned = "";
    
    for(char &c: str){
        if(isalnum(c)){
            cleaned += tolower(c);
        }
    }
    
    ispalindrome(cleaned);
    
    return 0;
}