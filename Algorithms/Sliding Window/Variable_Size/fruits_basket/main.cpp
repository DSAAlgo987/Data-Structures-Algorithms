#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int totalFruit(vector<int>& fruits) {
	// constraint : We have only two baskets
	// base case
	if(fruits.size() <= 2) {
		return fruits.size();
	}

	int i = 0,j = 0, mx = 0;
	unordered_map<int, int> mp;

	while(j < fruits.size()) {
		// calculation
		mp[fruits[j]]++;

		// max 2 fruits types (1 valid, 2 valid , more than 2 invalid)
		if(mp.size() <= 2) {
			// ans <- calculation
			mx = max(mx, j - i + 1);
			j++;
		}
		else if(mp.size() > 2) {
			while(mp.size() > 2) {
				mp[fruits[i]]--;

				if(mp[fruits[i]] == 0) {
					mp.erase(fruits[i]);
				}
				i++;
			}
			j++;
		}
	}

	return mx;
}

int main()
{
	vector<int> fruits = {3, 3, 3,3};

	cout << totalFruit(fruits);
	return 0;
}