class Solution {
public:
    long long solve(string& s, int i, long long num, int sign) {
        int n = s.size();

        // base case
        if (i >= n || !isdigit(s[i])) {
            return sign * num;
        }

        int digit = s[i] - '0';

        // overflow check
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        num = num * 10 + digit;

        return solve(s, i + 1, num, sign);
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // skip spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        return solve(s, i, 0, sign);
    }
};