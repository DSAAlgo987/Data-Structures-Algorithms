#include <bits/stdc++.h>
using namespace std;

/**
 * Lexigraphically same as alphabetical order for this always use ordered map
 */

char getMaxOccuringChar(string &s)
{
    map<char, int> mp;
    for (auto c : s)
    {
        mp[c]++;
    }

    char maxChar = '\0';
    int maxFreq = 0;

    for (auto i : mp)
    {
        if (i.second > maxFreq)
        {
            maxFreq = i.second;
            maxChar = i.first;
        }
    }

    return maxChar;
}

int main()
{
    string s = "sample";
    cout << getMaxOccuringChar(s);

    return 0;
}