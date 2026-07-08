class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<long long> digits;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0)
                digits.push_back(digit);
            n = n / 10;
        }

        long long num = 0;
        long long sum = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            num = num * 10 + digits[i];
            sum += digits[i];
        }
        return num * sum;
    }
};