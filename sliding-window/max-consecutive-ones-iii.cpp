class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int i = 0;
        int zeroes = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == 0)
                zeroes++;
            if(zeroes > k) {
                if (nums[i] == 0) {
                    zeroes--;
                }
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};