class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxOne = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                cnt = 0;
            }
            maxOne = max(maxOne, cnt);
        }

        return maxOne;
    }
};