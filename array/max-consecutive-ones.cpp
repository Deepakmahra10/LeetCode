class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxOne = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                int cnt = 0;
                for (int j = i; j < n && nums[j] == 1; j++) {
                    cnt++;
                }
                maxOne = max(maxOne, cnt);
            }
        }
        return maxOne;
    }
};