#include <bits/stdc++.h>
using namespace std;

// Problem: Max 69 Number

/**
 * Methods:
 * to_string(number): Converts no -> string
 * stoi(string): Converts string -> no
 *
 * Time complexity: n
 * Space complexity : n
 */

// Greedy
int maximum69Number(int num)
{
    string s = to_string(num);

    for (auto &c : s)
    {
        if (c == '6')
        {
            c = '9';
            break;
        }
    }

    return stoi(s);
}

// Math based
int maximum69Number1(int num)
{
    int divisible = 1000;
    int output = 0;
    bool flag = false;
    while (num > 0)
    {
        int digit = num / divisible;
        if (digit == 6 && !flag)
        {
            digit = 9;
            flag = true;
        }
        output = output + (digit * divisible);

        num %= divisible;
        divisible /= 10;
    }

    return output;
}

int main()
{
    int num = 6996;

    int ans = maximum69Number(num);

    cout << ans << endl;
    return 0;
}