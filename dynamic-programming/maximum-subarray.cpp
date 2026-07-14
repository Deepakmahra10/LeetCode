class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = LLONG_MIN;
        long long currSum = 0;

        int start = 0;
        int ansStart = -1, ansEnd = -1;

        for (int i = 0; i < n; i++) {
            if (currSum == 0)
                start = i;
            currSum += nums[i];
            if (currSum > maxSum) {
                maxSum = currSum;
                ansStart = start;
                ansEnd = i;
            }

            if (currSum < 0) {
                currSum = 0;
                start = i + 1;
            }
        }
        return maxSum;
    }
};