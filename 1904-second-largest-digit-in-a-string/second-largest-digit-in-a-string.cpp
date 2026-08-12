class Solution {
public:
    int secondHighest(string s) {
    int highest = -1;
    int second = -1;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int digit = s[i] - '0';

            if (digit > highest) {
                second = highest;
                highest = digit;
            }
            else if (digit > second && digit != highest) {
                second = digit;
            }
        }
    }

    return second;
    }
};