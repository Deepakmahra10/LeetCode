class Solution {
public:
    int helper(string& s, int i, int num, int sign) {
        if (i >= s.size() || !isdigit(s[i]))
            return (int)(sign * num);

        num = num * 10 + (s[i] - '0');

        if (sign * num <= INT_MIN)
            return INT_MIN;
        if (sign * num >= INT_MAX)
            return INT_MAX;

        return helper(s, i + 1, num, sign);
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ')
            i++;

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        return helper(s, i, 0, sign);
    }
};