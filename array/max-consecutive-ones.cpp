class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxOne = 0;
        int cnt = 0;

        for (int num : nums) {
            if (num == 1) {
                cnt++;
            } else {
                cnt = 0;
            }
            
        }

        return maxOne;
    }
};