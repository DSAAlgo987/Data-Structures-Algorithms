#include <bits/stdc++.h>
using namespace std;

void subset(string &str, int index, string &curr, set<string> &result) {
    if (index == str.size()) {
        result.insert(curr);
        return;
    }

    // Include current character
    curr.push_back(str[index]);
    subset(str, index + 1, curr, result);
    curr.pop_back();

    // Skip all duplicates of str[index]
    while (index + 1 < str.size() && str[index] == str[index + 1]) {
        index++;
    }

    // Exclude current character
    subset(str, index + 1, curr, result);
}

int main() {
    string str = "aab";
    sort(str.begin(), str.end()); // Important for skipping duplicates
    string curr = "";
    set<string> result;

    subset(str, 0, curr, result);

    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
