#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<int> &basket1, vector<int> &basket2)
{
    unordered_map<int, int> mp;
    int minElement = INT_MAX;

    // Step 1: Store b1 freq
    for (auto x : basket1)
    {
        mp[x]++;
        minElement = min(minElement, x);
    }

    // Step 2: Dec b2 freq
    for (auto x : basket2)
    {
        mp[x]--;
        minElement = min(minElement, x);
    }

    // Step 3: Store extra fruites in vector
    vector<int> finalList;

    for (auto it : mp)
    {
        int cost = it.first;
        int count = it.second;

        // Evenly distributed
        if (count == 0)
        {
            continue;
        }

        // Odd freq (impossible to balance)
        if (count % 2 != 0)
        {
            return -1;
        }

        // Distribute as per swap freq / 2
        for (int c = 1; c <= abs(count) / 2; c++)
        {
            finalList.push_back(cost);
        }
    }

    // Sort finalList vector in order to identify first min elements
    sort(finalList.begin(), finalList.end());

    // Calculate minCost
    long long minCost = 0;

    for (int i = 0; i < finalList.size() / 2; i++)
    {
        minCost += min(finalList[i], minElement * 2);
    }

    return minCost;
}

int main()
{
    vector<int> basket1 = {4, 2, 2, 2};
    vector<int> basket2 = {1, 4, 1, 2};

    cout << minCost(basket1, basket2);

    return 0;
}