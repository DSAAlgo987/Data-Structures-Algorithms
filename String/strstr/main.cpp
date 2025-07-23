#include <bits/stdc++.h>
using namespace std;

// n
int strStr(string haystack, string needle)
{
    int k = needle.size();

    int i = 0, j = 0;
    string temp = "";
    while (j < haystack.size())
    {
        // calculation
        temp += haystack[j];

        // achieve window size
        if (j - i + 1 < k)
        {
            j++;
        }
        // hit window size
        else if (j - i + 1 == k)
        {
            // ans <- calculation
            if (temp == needle)
            {
                return i;
            }

            // slide window
            temp.erase(temp.begin()); // delete first char
            i++;
            j++;
        }
    }

    return -1;
}

int main()
{
    string s1 = "shahar", s2 = "har";
    int ans = strStr(s1, s2);

    cout << ans << endl;
    return 0;
}