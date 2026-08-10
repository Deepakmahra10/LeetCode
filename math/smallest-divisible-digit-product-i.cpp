class Solution {
public:
    int product_digit(int x) {
        if (x == 0)
            return 0;

        int ans = 1;
        while (x > 0) {
            ans *= x % 10;
            x /= 10;
        }
        return ans;
    }

    int smallestNumber(int n, int t) {
        for (int i = n; i < n + 10; i++) {
            if (product_digit(i) % t == 0)
                return i;
        }
        return 0;
    }
};