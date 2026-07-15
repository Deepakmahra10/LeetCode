class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = n*(n+1);
        int evenSum = n*n;

        return __gcd(evenSum, oddSum);
    }
};