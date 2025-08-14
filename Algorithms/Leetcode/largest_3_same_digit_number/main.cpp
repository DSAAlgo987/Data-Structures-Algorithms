// Time complexity: O(n)
class Solution {
public:
    string largestGoodInteger(string num) {
        char prev = '\0';
        int count = 0;

        char maxD = '\0'; // No digit found yet

        for (auto c : num) {
            if (c == prev) {
                count++;
            } else {
                count = 1;
            }

            if (count == 3) {
                maxD = max(maxD, c);
            }
            prev = c;
        }

        if (maxD == '\0') return "";

        return string(3, maxD);
    }
};