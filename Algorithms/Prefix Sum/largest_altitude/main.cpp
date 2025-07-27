#include <bits/stdc++.h>
using namespace std;

// Brute force (n^2)
int largestAltitude1(vector<int> &gain){
    int mx = 0;

    for(int i = 0; i < gain.size(); i++){
        int sum = 0;
        for(int j = 0; j <= i; j++){
            sum += gain[j];
        }
        mx = max(mx, sum);
    }

    return mx;
}

// Optimal (n)
int largestAltitude(vector<int> &gain)
{
    int start = 0, mx = 0;

    for (int i = 0; i < gain.size(); i++)
    {
        start += gain[i];
        mx = max(mx, start);
    }

    return mx;
}


int main()
{
    vector<int> gain = {-5, 1, 5, 0, -7};

    int maxAltitude = largestAltitude1(gain);

    cout << maxAltitude << endl;
    return 0;
}